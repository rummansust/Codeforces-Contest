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

const int MAX = 1000100;

int Left[MAX];
int Right[MAX];
multiset<int> myset,t;

map<int,int> tmp;
int val[MAX];

int tree[2097152+100];

int update(int indx,int l,int r,int pt)
{
    if(l==r)
    {
        tree[indx]++;
        return 0;
    }
    int mid = (l+r)/2,idx=indx*2;
    if(mid>=pt)
    {
        update(idx,l,mid,pt);
    }
    else
    {
        update(idx+1,mid+1,r,pt);
    }
    tree[indx]=tree[idx]+tree[idx+1];
    return 0;
}

int query(int indx,int l,int r,int ql,int qr)
{
    if(l>qr||r<ql||l>r) return 0;
    if(l>=ql&&r<=qr) return tree[indx];
    int mid = (l+r)/2,idx=indx*2;
    return query(idx,l,mid,ql,qr)+query(idx+1,mid+1,r,ql,qr);
}

int main()
{
    int n;
    SF("%d",&n);
    for(int i=0;i<n;i++)
    {
        SF("%d",&val[i]);
        tmp[val[i]]++;
        Left[i]=tmp[val[i] ];
    }
    tmp.clear();
    for(int i=n-1;i>-1;i--)
    {
        tmp[val[i]]++;
        Right[i]=tmp[val[i] ];
    }
    int num;
    ll sum=0;
    for(int i=n-1;i>-1;i--)
    {
        num=Left[i];
        int tt = query(1,0,n,0,num-1);
        sum+=(ll) tt;
        update(1,0,n,Right[i]);
    }
    cout<<sum<<endl;
    return 0;
}


















