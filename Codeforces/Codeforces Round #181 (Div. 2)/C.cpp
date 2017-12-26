#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define clr(name,val) memset(name,(val),sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 10000000
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)
#define MOD 1000000007

using namespace std;

ll x,y;

ll big_mod(ll a,ll b,ll m)
{
    if(b==0) return 1;
    x=big_mod(a,b/2,m);
    y=x%m;
    x=(y*y)%m;
    if(b%2==1) x=(x*a)%m;
    return x;
}

bool cheak(ll p,ll a,ll b)
{
    while(p)
    {
        if(p%10 != a&&p%10 != b) return false;
        p/=10;
    }
    return true;
}

ll fact[1000010];

int main()
{
    fact[0]=1;
    for(ll i=1;i<1000005;i++) fact[i]=(i*fact[i-1])%MOD;
    ll a,b,n,res,rr=0;
    cin>>a>>b>>n;
    for(int i=0;i<=n;i++)
    {
        ll p=a*i+b*(n-i);
        if(cheak(p,a,b))
        {
            ll ina,inb;
            ina=big_mod(fact[i],MOD-2,MOD);
            inb=big_mod(fact[n-i],MOD-2,MOD);
            rr=(rr+(((ina*inb)%MOD)*fact[n]))%MOD;
        }
    }
    cout<<rr<<endl;
    return 0;
}
