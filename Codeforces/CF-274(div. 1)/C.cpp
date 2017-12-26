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


const int MAX = 5005;
const int M = 1000000007;

int dp[MAX][MAX];

int main()
{
    int n,k,a,b;
    cin>>n>>a>>b>>k;
    dp[a][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(a<b&&i>=b) continue;
        if(a>b&&i<=b) continue;
        dp[i][0]+=dp[i-1][0];
    }
    for(int kk=1;kk<=k;kk++)
    {
        for(int j=1;j<=n;j++)
        {
            int l,r;
            if(a<b)
            {
                l=1;
                r=(j+b-1)/2;
                if(j>=b) break;
            }
            else
            {
                l=(b+j)/2 + 1;
                r=n;
                if(j<=b) continue;
            }
            dp[j][kk]=((dp[r][kk-1]-dp[l-1][kk-1])%M-(dp[j][kk-1]-dp[j-1][kk-1])%M)%M;
            if(dp[j][kk]<0) dp[j][kk]+=M;
        }
        for(int i=1;i<=n;i++)
        {
            if(a<b&&i>=b) continue;
            if(a>b&&i<=b) continue;
            dp[i][kk]+=dp[i-1][kk];
            dp[i][kk]%=M;
        }
    }
    int ret=0;
    int l,r;
    if(a<b) ret=(dp[b-1][k]%M);
    else ret=(dp[n][k]-dp[b][k])%M;
    if(ret<0) ret+=M;
    cout<<ret<<endl;
    return 0;
}

/**
5000 1 5000 5000
5000 5000 1 5000
*/
















