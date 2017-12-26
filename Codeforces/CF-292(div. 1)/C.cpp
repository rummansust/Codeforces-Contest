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
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1ll<<61)
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

const int MAX1 = 200010;
const int MAX2 = 525288;

/// 1 based indexing


ll Rk[MAX1];
ll Lk[MAX1];
ll Di[MAX1];
ll Hi[MAX1];
tuple<ll,ll,ll> tree[MAX2];
int n;

void build(int,int);
void build(int,int,int);

void build(int l,int r)
{
    build(1,l,r);
    return ;
}

tuple<ll,ll,ll> Merge(tuple<ll,ll,ll> a,tuple<ll,ll,ll> b)
{
    tuple<ll,ll,ll> ret;
    get(ret,0) = max(get(a,0),get(b,0));
    get(ret,1) = max(get(a,1),get(b,1));
    get(ret,2) = max(get(a,0)+get(b,1),max(get(a,2),get(b,2)));
    return ret;
}

void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx]=mt(Hi[l]-Di[l-1],Hi[l]+Di[l-1],-oo);
        return ;
    }
    int mid=(l+r)>>1,nidx=(idx<<1);
    build(nidx,l,mid);
    build(nidx|1,mid+1,r);
    tree[idx]=Merge(tree[nidx],tree[nidx|1]);
    return ;
}

ll query(int,int);
tuple<ll,ll,ll> query(int,int,int,int,int);


ll query(int ql,int qr)
{
    tuple<ll,ll,ll> ret = query(1,1,n,ql,qr);
    return get(ret,2);
}

tuple<ll,ll,ll> query(int idx,int l,int r,int ql,int qr)
{
    if(l>r || ql>qr || l>qr || r<ql) return mt(-oo,-oo,-oo);
    if(l>=ql && r<=qr)
    {
        return tree[idx];
    }
    int mid=(l+r)>>1,nidx=(idx<<1);

    tuple<ll,ll,ll> lres = query(nidx,l,mid,ql,qr);
    tuple<ll,ll,ll> rres = query(nidx|1,mid+1,r,ql,qr);

    return Merge(lres,rres);
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    int q;
    SF("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        SF("%I64d",&Di[i]);
        Di[n+i]=Di[i];
    }
    for(int i=1;i<=n;i++)
    {
        SF("%I64d",&Hi[i]);
        Hi[i]<<=1ll;
        Hi[n+i]=Hi[i];
    }
    n<<=1;
    for(int i=1;i<=n;i++)
    {
        Di[i]+=Di[i-1];
    }
    int a,b;
    build(1,n);
    while(q--)
    {
        SF("%d %d",&a,&b);
        PF("%I64d\n",(a>b)?query(b+1,a-1):query(b+1,a+(n>>1)-1));
    }
    return 0;
}













