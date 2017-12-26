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
#define oo (1ll<<61)
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

map<ll,ll> mgcd;
ll dp[305][4000];
bool vp[305][4000];
int id;
int n;
ll L[305];
ll C[305];

ll rec(int pos,ll gcd)
{
    if(mgcd.count(gcd)==0) mgcd[gcd]=(id++);
    int sgcd=mgcd[gcd];
    if(pos==n)
    {
        if(gcd==1) return 0;
        return oo;
    }
    ll &ret=dp[pos][sgcd];
    bool &vet=vp[pos][sgcd];
    if(vet) return ret;
    vet=true;
    ret=oo;
    ret=min(ret,rec(pos+1,gcd));
    ret=min(ret,rec(pos+1,__gcd(gcd,L[pos]))+C[pos]);
    return ret;
}

int main()
{
    SF("%d",&n);
    for(int i=0;i<n;i++) SF("%I64d",&L[i]);
    for(int i=0;i<n;i++) SF("%I64d",&C[i]);
    for(int i=n-1;i>-1;i--) rec(i,0);
    ll res=rec(0,0);
    if(res>=oo) res=-1;
    PF("%I64d\n",res);
    return 0;
}












