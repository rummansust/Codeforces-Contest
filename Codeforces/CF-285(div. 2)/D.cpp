#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

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
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

const int MAXN = 554288;

struct STREE
{
    int tree[MAXN];
    void init()
    {
        clrall(tree,0);
        return ;
    }
    void build(int idx,int l,int r)
    {
        if(l==r)
        {
            tree[idx]=1;
            return ;
        }
        int mid=(l+r)>>1,nidx=(idx<<1);
        build(nidx,l,mid);
        build(nidx|1,mid+1,r);
        tree[idx]=tree[nidx]+tree[nidx|1];
        return ;
    }
    void update(int idx,int l,int r,int k,int v)
    {
        if(l==r)
        {
            tree[idx]=v;
            return ;
        }
        int mid=(l+r)>>1,nidx=(idx<<1);
        if(k<=mid) update(nidx,l,mid,k,v);
        else update(nidx|1,mid+1,r,k,v);
        tree[idx]=tree[nidx]+tree[nidx|1];
        return ;
    }
    int querytot(int idx,int l,int r,int x,int y)
    {
        if(l>y||r<x||l>r||x>y) return 0;
        if(l>=x&&r<=y) return tree[idx];
        int mid=(l+r)>>1,nidx=(idx<<1),ret=0;
        ret+=querytot(nidx,l,mid,x,y);
        ret+=querytot(nidx|1,mid+1,r,x,y);
        return ret;
    }
    int querykth(int idx,int l,int r,int k)
    {
        if(l==r) return l;
        int mid=(l+r)>>1,nidx=(idx<<1);
        if(tree[nidx]>=k) return querykth(nidx,l,mid,k);
        else return querykth(nidx|1,mid+1,r,k-tree[nidx]);
        return -1;
    }
};

int main()
{
    int n,val;
    vector<int> F,S,N;
    SF("%d",&n);
    STREE atree,btree;
    atree.init();
    atree.build(1,0,n-1);
    btree.init();
    btree.build(1,0,n-1);
    for(int i=0;i<n;i++)
    {
        SF("%d",&val);
        F.psb(atree.querytot(1,0,n-1,0,val-1));
        atree.update(1,0,n-1,val,0);
    }
    for(int i=0;i<n;i++)
    {
        SF("%d",&val);
        S.psb(btree.querytot(1,0,n-1,0,val-1));
        btree.update(1,0,n-1,val,0);
    }
    for(int i=0;i<n;i++) N.psb(0);
    int carry=0;
    for(int i=n-1,j=1;i>-1;i--,j++)
    {
        N[i]=(F[i]+S[i]+carry)%j;
        carry=(F[i]+S[i]+carry)/j;
    }
    STREE soltree;
    soltree.init();
    soltree.build(1,0,n-1);
    for(int i=0;i<n;i++)
    {
        val=soltree.querykth(1,0,n-1,N[i]+1);
        cout<<val<<" \n"[i==n-1];
        soltree.update(1,0,n-1,val,0);
    }
    return 0;
}












