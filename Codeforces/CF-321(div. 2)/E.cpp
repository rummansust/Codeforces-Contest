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
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<"\n";}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

/// 1 based;

const int MAX = 100070;

int tenMod[2][MAX+7];
int tenPr[2][MAX+7];
const ll p1=59272331ll;
const ll p2=84592337ll;

struct info{
    ll h1,h2;
    int lazy;
    bool vis;
    info(){}
    info(ll h1,ll h2,int lazy,bool vis)
    {
        this->h1=h1;
        this->h2=h2;
        this->lazy=lazy;
        this->vis=vis;
    }
};

info stree[(MAX<<2) + 7];
int val[MAX+7];
char str[MAX+7];

void build(int idx,int l,int r)
{
    if(l==r)
    {
        stree[idx]=info(val[l],val[l],0,false);
        return ;
    }
    int mid=(l+r)>>1,nidx=(idx<<1);
    build(nidx,l,mid);
    build(nidx|1,mid+1,r);
    stree[idx].h1=( stree[nidx|1].h1 + ( (stree[nidx].h1*tenPr[0][r-mid]) % p1 ) )%p1;
    stree[idx].h2=( stree[nidx|1].h2 + ( (stree[nidx].h2*tenPr[1][r-mid]) % p2 ) )%p2;
    return ;
}

void relax(int idx,int l,int r,int v)
{
    int e=(r-l+1);
    int mid=(l+r)>>1,nidx=(idx<<1);
    stree[idx].h1=(v*tenMod[0][e-1])%p1;
    stree[idx].h2=(v*tenMod[1][e-1])%p2;
    if(l!=r)
    {
        stree[nidx].lazy = v;
        stree[nidx].vis = true;
        stree[nidx|1].lazy = v;
        stree[nidx|1].vis = true;
    }
    stree[idx].vis=false;
    return ;
}

void update(int idx,int l,int r,int ql,int qr,int v)
{
    if(stree[idx].vis)
    {
        relax(idx,l,r,stree[idx].lazy);
    }
    if(l>qr || r<ql) return ;
    if(l>=ql&&r<=qr)
    {
        relax(idx,l,r,v);
        return ;
    }
    int mid=(l+r)>>1,nidx=(idx<<1);
    update(nidx,l,mid,ql,qr,v);
    update(nidx|1,mid+1,r,ql,qr,v);
    stree[idx].h1=( stree[nidx|1].h1 + ( (stree[nidx].h1*tenPr[0][r-mid]) % p1 ) )%p1;
    stree[idx].h2=( stree[nidx|1].h2 + ( (stree[nidx].h2*tenPr[1][r-mid]) % p2 ) )%p2;
    return ;
}

struct pll
{
    ll xx,yy,el;
    pll(){}
    pll(ll x,ll y,ll e)
    {
        this->xx=x;
        this->yy=y;
        this->el=e;
    }
};

pll query(int idx,int l,int r,int ql,int qr)
{
    if(stree[idx].vis)
    {
        relax(idx,l,r,stree[idx].lazy);
    }
    if(l>qr || r<ql) return pll(0,0,0);
    if(l>=ql&&r<=qr)
    {
        return pll(stree[idx].h1,stree[idx].h2,r-l+1);
    }
    int mid=(l+r)>>1,nidx=(idx<<1);
    bool lson=false,rson=false;
    pll lret=pll(0,0,0),rret=pll(0,0,0),ret=pll(0,0,0);
    if(mid>=ql)
    {
        lson=true;
        lret=query(nidx,l,mid,ql,qr);
    }
    if(mid+1<=qr)
    {
        rson=true;
        rret=query(nidx|1,mid+1,r,ql,qr);
    }
    if(lson&&rson)
    {
        ret.xx=(rret.xx + ( (lret.xx*tenPr[0][rret.el]) % p1))%p1;
        ret.yy=(rret.yy + ( (lret.yy*tenPr[1][rret.el]) % p2))%p2;
        ret.el=lret.el+rret.el;
    }
    else
    {
        ret=lson?lret:rret;
    }
    return ret;
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    tenMod[0][0]=tenMod[1][0]=1;
    tenPr[0][0]=tenPr[1][0]=1;
    ll pr1=1;
    ll pr2=1;
    for(int i=1;i<MAX;i++)
    {
        pr1*=10; pr1%=p1;
        pr2*=10; pr2%=p2;
        tenPr[0][i]=pr1;
        tenPr[1][i]=pr2;
        tenMod[0][i]=(tenMod[0][i-1]+pr1)%p1;
        tenMod[1][i]=(tenMod[1][i-1]+pr2)%p2;
    }
    int n,m,k;
    sf("%d %d %d",&n,&m,&k);
    sf(" %s",&str);
    for(int i=0;i<n;i++)
    {
        val[i+1]=str[i]-'0';
    }
    build(1,1,n);
    int t,l,r,d;
    int q=m+k;
    pll ret1,ret2;
    while(q--)
    {
        sf(" %d %d %d %d",&t,&l,&r,&d);
        if(t==1)
        {
            update(1,1,n,l,r,d);
        }
        else
        {
            ret1=query(1,1,n,l,r-d);
            ret2=query(1,1,n,l+d,r);
            if(ret1.xx==ret2.xx && ret1.yy==ret2.yy)
            {
                pf("YES\n");
            }
            else pf("NO\n");
        }
    }
    return 0;
}














