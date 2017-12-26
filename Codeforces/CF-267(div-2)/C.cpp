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
#define oo (1LL<<62LL)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outE.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const int MAX = 5002;

ll sum[MAX];
ll dp[MAX][MAX];
int k,m,n;

ll rec(int pos,int rk)
{
    if(rk==0)
    {
        return 0;
    }
    if(pos>n) return -oo;
    ll &ret = dp[pos][rk];
    if(ret!=-1) return ret;
    ret=0;
    ll tmp;
    tmp=rec(pos+m,rk-1);
    if(tmp!=-oo&&pos+m-1<=n)
    {
        ret=tmp;
        ret+=sum[pos+m-1]-sum[pos-1];
    }
    tmp=rec(pos+1,rk);
    if(tmp!=-oo)
    {
        ret=max(ret,tmp);
    }
    return ret;
}

int main()
{
    __;
    cin>>n>>m>>k;
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    clrall(dp,-1);
    ll ret=rec(1,k);
    if(ret!=-oo) cout<<ret<<"\n";
    return 0;
}


















