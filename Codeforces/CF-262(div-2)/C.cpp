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

const int MAX = 272144;

int tree[MAX*4];
int lazy[MAX*4];

void build(int ind,int l,int r)
{
    if(l==r)
    {
        SF("%d",&tree[ind]);
        return ;
    }
    int mid=(l+r)>>1,indxn=(ind<<1);
    build(indxn,l,mid);
    build(indxn+1,mid+1,r);
    tree[ind]=min(tree[indxn],tree[indxn+1]);
    return ;
}

void relax(int ind,int l,int r,int val)
{
    tree[ind]+=val;
    int indx=(ind<<1);
    if(l!=r)
    {
        lazy[indx]+=val;
        lazy[indx+1]+=val;
    }
    lazy[ind]=0;
    return ;
}

void update(int ind,int l,int r,int ql,int qr)
{
    if(lazy[ind])
    {
        relax(ind,l,r,lazy[ind]);
    }
    if(l>qr || r<ql) return ;
    if(l>=ql && r<=qr)
    {
        relax(ind,l,r,1);
        return ;
    }
    int mid=(l+r)>>1,indx=(ind<<1);
    update(indx,l,mid,ql,qr);
    update(indx+1,mid+1,r,ql,qr);
    tree[ind]=min(tree[indx],tree[indx+1]);
    return ;
}

int query1(int ind,int l,int r,int ql,int qr)
{
    if(lazy[ind])
    {
        relax(ind,l,r,lazy[ind]);
    }
    if(l>qr || r<ql) return (int) (INFINITY);
    if(l>=ql && r<=qr)
    {
        return tree[ind];
    }
    int mid=(l+r)>>1,indx=(ind<<1);
    return min(query1(indx,l,mid,ql,qr),query1(indx+1,mid+1,r,ql,qr));
}


int query2(int ind,int l,int r,int ter)
{
    if(lazy[ind])
    {
        relax(ind,l,r,lazy[ind]);
    }
    if(l==r) return l;
    int mid=(l+r)>>1,indx=(ind<<1);
    if(lazy[indx])
    {
        relax(indx,l,mid,lazy[indx]);
    }
    if(lazy[indx+1])
    {
        relax(indx+1,mid+1,r,lazy[indx+1]);
    }
    if(tree[indx]==ter)
    {
        return query2(indx,l,mid,ter);
    }
    else
    {
        return query2(indx+1,mid+1,r,ter);
    }
}


int main()
{
    int n,m,w,ter,terPos,st,en;
    SF("%d %d %d",&n,&m,&w);
    build(1,0,n-1);
    while(m--)
    {
        ter=query1(1,0,n-1,0,n-1);
        terPos=query2(1,0,n-1,ter);
        if(terPos+w-1<n)
        {
            update(1,0,n-1,terPos,terPos+w-1);
        }
        else
        {
            st=(n-w);
            en=n-1;
            update(1,0,n-1,st,en);
        }
    }
    PF("%d\n",query1(1,0,n-1,0,n-1));
    return 0;
}


















