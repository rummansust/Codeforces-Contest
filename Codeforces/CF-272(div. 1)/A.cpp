#include <bits/stdc++.h>

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
#define oo (1<<29)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outE.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const ll MOD = 1000000007;

int main()
{
    ll a,b;
    cin>>a>>b;
    if(b==1)
    {
        cout<<0<<"\n";
        return 0;
    }
    ll ans=0;
    ll n;
    ll tmp;
    ll I=500000004LL;

    ll tmp2=(a*(a+1))%MOD;
    tmp2=(tmp2*I)%MOD;
    tmp=(tmp2*b)%MOD;
    tmp+=a;
    tmp%=MOD;
    ans=tmp;
    for(ll i=2;i<b;i++)
    {
        ans=(ans+(i*tmp)%MOD)%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}


















