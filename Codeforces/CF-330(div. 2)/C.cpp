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


const ll MOD = 1000000007ll;

const int MAX = 100009;
char str[MAX];

ll a[MAX];
ll b[MAX];

int main()
{
    int n,k;
    sf("%d %d",&n,&k);
    int t=n/k;
    for(int i=0;i<t;i++)
    {
        sf("%I64d",&a[i]);
    }
    for(int i=0;i<t;i++)
    {
        sf("%I64d",&b[i]);
    }
    ll l=1,r=1;
    for(int i=0;i<k;i++) l*=10ll;
    for(int i=1;i<k;i++) r*=10ll;
    l--;
    r--;
    ll res=0,tot,md1,md2,tmp,md3,md4;
    for(int i=0;i<t;i++)
    {
        tot=l/a[i] + 1;
        md1=l%a[i];
        md2=b[i]%a[i];
        for(int j=1;j<k;j++)
        {
            md2*=10ll;
            md2%=a[i];
        }
        tmp=r/a[i] + 1;
        md3=(a[i]-md2)%a[i];
        md4=r%a[i];
        if(md3>md4) tmp--;
//        deb(r,md3,md4,tot,tmp,tot-tmp);
        tot-=tmp;
        if(i)
        {
            res*=tot;
            res%=MOD;
        }
        else res=tot%MOD;
    }
    pf("%I64d\n",res);
    return 0;
}

/*
Tested By UVa problems
495 Fibonacci Freeze
500! Big Factorial
424 Integer Inquiry
10106 Product
10929 You can say 11
Tested By Google Code Jam
Code jam'10 Qual Round B Problem
*/
