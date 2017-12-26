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

int tree[32][MAX];

struct point
{
    int l,r,q;
    point(){}
    point(int l,int r,int q):l(l),r(r),q(q){}
};

point info[MAX];

int main()
{
//    Read;
//    Write;
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
                tree[i][l]++;
                tree[i][r+1]--;
            }
        }
    }
    for(int i=0;i<30;i++)
    {
        for(int j=1;j<=n;j++)
        {
            tree[i][j]+=tree[i][j-1];
        }
    }
    for(int i=0;i<30;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(tree[i][j])
            {
                tree[i][j]=1;
            }
        }
    }
    for(int i=0;i<30;i++)
    {
        for(int j=1;j<=n;j++)
        {
            tree[i][j]+=tree[i][j-1];
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
            int ret=tree[i][r]-tree[i][l-1];
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
                int ret=tree[i][j]-tree[i][j-1];
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


















