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
#include <utility>
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
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

#define midx int mid=(l+r)>>1,nidx=idx<<1

const int MAX = 200100;
pair<int,int> tree[MAX*3];

int a[MAX],b[MAX];

void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx]=mp(a[l],b[l]);
        return ;
    }
    midx;
    build(nidx,l,mid);
    build(nidx+1,mid+1,r);
    tree[idx].fs=max(tree[nidx].fs,tree[nidx+1].fs);
    tree[idx].sc=min(tree[nidx].sc,tree[nidx+1].sc);
    return ;
}

pair<int,int> query(int idx,int l,int r,int ql,int qr)
{
    if(l>=ql&&r<=qr)
    {
        return tree[idx];
    }
    midx;
    if(mid>=qr) return query(nidx,l,mid,ql,qr);
    else if(mid+1<=ql) return query(nidx+1,mid+1,r,ql,qr);
    else
    {
        pair<int,int> p1,p2;
        p1=query(nidx,l,mid,ql,qr);
        p2=query(nidx+1,mid+1,r,ql,qr);
        return mp(max(p1.fs,p2.fs),min(p1.sc,p2.sc));
    }
}

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    int n;
    sf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        sf("%d",&b[i]);
    }
    build(1,1,n);
    int l,r,lo,hi,mid;
    pair<int,int> p;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        l=n+1;
        lo=1,hi=i;
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            p=query(1,1,n,mid,i);
            if(p.fs-p.sc==0) l=mid, hi=mid-1;
            else if(p.fs-p.sc>0) lo=mid+1;
            else hi=mid-1;
        }
        r=0;
        lo=1,hi=i;
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            p=query(1,1,n,mid,i);
            if(p.fs-p.sc==0) r=mid, lo=mid+1;
            else if(p.fs-p.sc>0) lo=mid+1;
            else hi=mid-1;
        }
        if(r-l+1>0) res+=(ll) (r-l+1);
    }
    pf("%I64d\n",res);
    return 0;
}










