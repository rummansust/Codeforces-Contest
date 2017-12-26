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

const int MOD = 1e9+7;

const int MAX = 4*(1e5)+100;

int dp[MAX];

bool flag;

int solve(int h,int S,int R,int G)
{
    flag=false;
    int K=(h*(h+1))/2;
    memset(dp,-1,sizeof(int)*(K+5));
    dp[0]=1;
    for(int i=1;i<=h;i++)
    {
        for(int j=K;j>=i;j--)
        {
            if(dp[j-i]!=-1)
            {
                if(dp[j]==-1) dp[j]=0;
                dp[j]=(dp[j]+dp[j-i])%MOD;
            }
        }
    }
    int ret=0;
    int E=min(R,K);
    for(int i=0;i<=E;i++)
    {
        int j=K-i;
        if(j>G) continue;
        if(dp[i]==-1) continue;
        flag=true;
        ret=(ret+dp[i])%MOD;
    }
    return ret;
}

int main()
{
    int r,g;
    int h;
    cin>>r>>g;
    int k=(r+g);
    for(h=0;(h*(h+1))<=2*k;h++);
    h--;
    int lo=0,hi=h,mid,res=0,ans=0;
    while(lo<=hi)
    {
        mid=(lo+hi)>>1;
        int ret=solve(mid,k,r,g);
        if(flag)
        {
            lo=mid+1;
            if(res<mid)
            {
                res=mid;
                ans=ret;
            }
        }
        else hi=mid-1;
    }

    cout<<ans<<"\n";
    return 0;
}

/**
100000 100000
774536264
*/

















