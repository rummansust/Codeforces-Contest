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

const int MAX = 100005;

ll dp[MAX][3];

ll point[MAX];

ll cnt[MAX];

vector<pair<ll,ll> > val;

int N;

ll rec(int pos,int pre)
{
    if(pos==N) return 0;
    ll &ret = dp[pos][pre];
    if(ret!=-1LL) return ret;
    ret=0LL;
    if(pre && pos>0 && val[pos-1].fs+1==val[pos].fs)
    {
        ret=rec(pos+1,!pre);
    }
    else
    {
        ret=max(ret,rec(pos+1,0));
        ret=max(ret,rec(pos+1,1)+point[pos]);
    }
    return ret;
}

int main()
{
    int n;
    int v;
    SF("%d",&n);
    for(int i=0;i<n;i++)
    {
        SF("%d",&v);
        cnt[v]++;
    }
    for(int i=0;i<MAX;i++)
    {
        if(cnt[i]) val.psb(mp(i,cnt[i]));
    }
    N=SZ(val);

    for(int i=0;i<N;i++)
    {
        point[i]=val[i].fs*val[i].sc;
    }
    clrall(dp,-1LL);
    cout<<rec(0,0)<<endl;
    return 0;
}


















