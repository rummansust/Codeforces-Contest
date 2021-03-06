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

vector<pair<ll,ll> > range[2];
vector<pair<ll,ll> > vRange;

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif
    ll h,q;
    ll l,r;
    ll lvl,t,mn=1,mx=1;
    int s0,s1;
    SF("%I64d %I64d",&h,&q);
    for(int i=2;i<=h;i++)
    {
        mn*=2ll;
        mx*=2ll;
        mx++;
    }
    while(q--)
    {
        SF("%I64d %I64d %I64d %I64d",&lvl,&l,&r,&t);
        for(int i=lvl+1;i<=h;i++)
        {
            l*=2ll;
            r*=2ll;
            r++;
        }
        range[t].psb(mp(l,r));
    }
    s0=SZ(range[0]);
    s1=SZ(range[1]);
    l=mn,r=mx;
    for(int i=0;i<s1;i++)
    {
        if(range[1][i].fs>r||range[1][i].sc<l)
        {
            PF("Game cheated!\n");
            return 0;
        }
        l=max(l,range[1][i].fs);
        r=min(r,range[1][i].sc);
    }
    sort(all(range[0]));
    ll rp=mn-1,nl,nr;
    for(int i=0;i<s0;i++)
    {
        if(range[0][i].sc<=rp) continue;
        if(range[0][i].fs>rp)
        {
            nl=max(l,rp+1);
            nr=min(r,range[0][i].fs-1);
            if(nl<=nr) vRange.psb(mp(nl,nr));
        }
        rp=max(rp,range[0][i].sc);
    }
    if(rp<mx)
    {
        nl=max(l,rp+1);
        nr=min(r,mx);
        if(nl<=nr) vRange.psb(mp(nl,nr));
    }
    sort(all(vRange));
    vRange.resize(distance(vRange.begin(),unique(all(vRange))));
    int s=SZ(vRange);
    if(s==0)
    {
        PF("Game cheated!\n");
        return 0;
    }
    if(s==1 && vRange[0].fs==vRange[0].sc)
    {
        PF("%I64d\n",vRange[0].fs);
    }
    else
    {
        PF("Data not sufficient!\n");
    }
    return 0;
}













