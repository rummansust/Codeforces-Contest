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

const int MAX = 110000;
const ll M = 1000000007ll;

ll dp[MAX];
ll K;

ll rec(int k)
{
    if(k<0) return 0ll;
    if(k==0) return 1ll;
    ll &ret = dp[k];
    if(ret!=-1) return ret;
    ret=0ll;
    ret=rec(k-1);
    ret=(ret+rec(k-K))%M;
    return ret;
}

int main()
{
    __;
    int T;
    cin>>T>>K;
    clrall(dp,-1);
    rec(100000);
    for(int i=1;i<=100000;i++) dp[i]=(dp[i]+dp[i-1])%M;
    int a,b;
    while(T--)
    {
        cin>>a>>b;
        ll res = ((dp[b]-dp[a-1])%M);
        if(res<0) res+=M;
        cout<<res<<"\n";
    }
    return 0;
}

/**
1 48096
95515 99613
*/
















