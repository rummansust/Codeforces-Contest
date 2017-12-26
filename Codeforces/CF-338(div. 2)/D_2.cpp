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
#define __ std::ios_base::sync_with_stdio (false),cin.tie(0),cout.tie(0)

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

ll N;
const int maxn = 200110;
const int MAX = 200110;
const ll mod = 1e9 + 7;
const ll mod2 = 2 * (mod - 1);
ll index[maxn], L[maxn], R[maxn];
int num, pri[maxn], vis[maxn];
vector<int>have[maxn];

ll getresult(ll A, ll n, ll k)
{
    ll b = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            b = (b*A) % k;
        }
        n = n >> 1;
        A = (A*A) % k;
    }
    return b;
}

void solve(int cishu, int n)
{
    int temp;
    temp = cishu;
    index[temp] = (index[temp] + n) % mod2;
}

int mpp[MAX];

int main()
{
    int x;
    ll k, n, ans;
    memset(index, 0, sizeof(index));
    scanf("%d",&N);
    int mx=0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &x);
        mpp[x]++;
        mx=max(mx,x);
    }
    for(int i=1;i<MAX;i++)
    {
        solve(i,mpp[i]);
    }
    int p = 1;
    N=mx+1;
    L[0] = R[N + 1] = 1;
    for (int i = 1; i <= N; i++)
        L[i] = L[i - 1] * (index[i] + 1) % mod2;
    for (int i = N; i >= 1; i--)
        R[i] = R[i + 1] * (index[i] + 1) % mod2;
    ans = 1;
    for (int i = 1; i <= N; i++)
    {
        if(mpp[i]==0) continue;
        ll pr=i;
        k = L[i - 1] * R[i + 1] % mod2;
        n = index[i] * (index[i] + 1) / 2 % mod2;
        ans = ans*getresult(pr, n*k%mod2,mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
