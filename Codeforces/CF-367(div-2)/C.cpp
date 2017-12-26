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
#define EPS 1e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1ll<<58)
#define inf 0x3f3f3f3f
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define Read freopen("out.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false),cin.tie(0),cout.tie(0)

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

const int MAX = 100050;

char s[MAX];

int n;

ll dp[MAX][2];

string str[MAX];

int pre[4][MAX];

ll c[MAX];

void precal()
{
    clrall(pre,0);
    string a,b;
    pre[0][1]=1;
    pre[1][1]=1;
    pre[2][1]=1;
    pre[3][1]=1;
    for(int i=2;i<=n;i++)
    {
        a=str[i-1];
        b=str[i];
        if(b>=a) pre[0][i]=1;///p=0
        reverse(all(a));
        if(b>=a) pre[1][i]=1;
        reverse(all(b));
        if(b>=str[i-1]) pre[2][i]=1;///p=0
        if(b>=a) pre[3][i]=1;
//        deb(pre[0][i]);
//        deb(pre[1][i]);
//        deb(pre[2][i]);
//        deb(pre[3][i]);
//        deb(str[i],str[i-1],(str[i]>=str[i-1]));
    }
    return ;
}

ll rec(int i,int p)
{
    if(i>n) return 0;
    ll &ret = dp[i][p];
    if(ret!=-1) return ret;
    ret=oo;
    if(p==0)
    {
        if(pre[0][i])
        {
            ret=min(ret,rec(i+1,0));
        }
        if(pre[2][i])
        {
            ret=min(ret,rec(i+1,1)+c[i]);
        }
    }
    else
    {
        if(pre[1][i])
        {
            ret=min(ret,rec(i+1,0));
        }
        if(pre[3][i])
        {
            ret=min(ret,rec(i+1,1)+c[i]);
        }
    }
    return ret;
}

int main()
{
    #ifdef MAHDI
    Read;
//    Write;
    #endif // MAHDI
    sf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sf("%I64d",&c[i]);
    }
    for(int i=1;i<=n;i++)
    {
        sf("%s",&s);
        str[i]=s;
    }
    precal();
    clrall(dp,-1);
    ll ret=rec(1,0);
    pf("%I64d\n",ret>=oo?-1:ret);
    return 0;
}














