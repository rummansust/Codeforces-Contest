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

vector<ll> resv;

ll power(ll val,ll p)
{
    ll ret=1LL;
    while(p--)
    {
        ret*=val;
    }
    return ret;
}

bool isOk(ll x,ll sum)
{
    if(x<=0LL || x>=1000000000LL) return false;
    ll sm=0;
    while(x)
    {
        sm+=x%10LL;
        x/=10LL;
    }
    return sm==sum;
}

int main()
{
    ll a,b,c,x;
    cin>>a>>b>>c;
    for(ll i=1;i<=81;i++)
    {
        x=b*power(i,a)+c;
        if(isOk(x,i))resv.psb(x);
    }
    sort(resv.begin(),resv.end());
    cout<<SZ(resv)<<endl;
    for(int i=0;i<SZ(resv);i++)
    {
        if(i) cout<<" ";
        cout<<resv[i];
    }
    cout<<endl;
    return 0;
}

















