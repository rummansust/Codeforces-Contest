#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<29)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outE.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const int MAX = 110000;

int tree[32][MAX*8];
int lazy[32][MAX*8];

void relax(int bit,int idx,int l,int r,int val)
{
    int mid=(l+r)>>1,nidx=(idx<<1);
    tree[bit][idx]=val;
    if(l!=r)
    {
        lazy[bit][nidx]=(mid-l+1);
        lazy[bit][nidx|1]=(r-mid);
    }
    lazy[bit][idx]=0;
    return ;
}

void update(int bit,int idx,int l,int r,int ql,int qr,int val)
{
    if(lazy[bit][idx])
    {
        relax(bit,idx,l,r,lazy[bit][idx]);
    }
    if(l>=ql&&r<=qr)
    {
        relax(bit,idx,l,r,val);
        return ;
    }
    if(l>qr||r<ql) return ;
    int mid=(l+r)>>1,nidx=(idx<<1);
    update(bit,nidx,l,mid,ql,qr,(mid-l+1));
    update(bit,nidx|1,mid+1,r,ql,qr,(r-mid));
    tree[bit][idx]=tree[bit][nidx]+tree[bit][nidx|1];
    return ;
}

int query(int bit,int idx,int l,int r,int ql,int qr)
{
    if(lazy[bit][idx])
    {
        relax(bit,idx,l,r,lazy[bit][idx]);
    }
    if(l>=ql&&r<=qr)
    {
        return tree[bit][idx];
    }
    if(l>qr||r<ql) return 0;
    int mid=(l+r)>>1,nidx=(idx<<1);
    int ret = query(bit,nidx,l,mid,ql,qr)+query(bit,nidx|1,mid+1,r,ql,qr);
    return ret;
}

struct point
{
    int l,r,q;
    point(){}
    point(int l,int r,int q):l(l),r(r),q(q){}
};

point info[MAX];

int main()
{
    Read;
    Write;
    __;
    int n,m,l,r,q;
    cin>>n>>m;
    for(int j=0;j<m;j++)
    {
        cin>>l>>r>>q;
        info[j]=point(l,r,q);
        for(int i=0;i<30;i++)
        {
            if((q&(1<<i)))
            {
                update(i,1,1,n,l,r,(r-l+1));
            }
        }
    }
    bool flag=true;

    for(int j=0;j<m && flag;j++)
    {
        l=info[j].l;
        r=info[j].r;
        q=info[j].q;
        for(int i=0;i<30 && flag;i++)
        {
            int ret=query(i,1,1,n,l,r);
            if((q&(1<<i)))
            {
                if(ret!=(r-l+1))
                {
                    flag=false;
                    break;
                }
            }
            else
            {
                if(ret==(r-l+1))
                {
                    flag=false;
                    break;
                }
            }
        }
    }
    if(flag)
    {
        cout<<"YES\n";
        for(int j=1;j<=n;j++)
        {
            q=0;
            for(int i=0;i<30;i++)
            {
                int ret=query(i,1,1,n,j,j);
                if(ret)
                {
                    q|=(1<<i);
                }
            }
            cout<<q<<" ";
        }
        cout<<"\n";
    }
    else cout<<"NO\n";
    return 0;
}


















