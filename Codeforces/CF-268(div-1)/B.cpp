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

const int MAX = 200500;
int inp[MAX];
int out[MAX];
bool flag[MAX];
map<ll,int> ID;
map<ll,int> hasInp;

namespace hopcroftKarp{
    #define MAXN 100011
    #define MAXE 200011
    #define INF (1<<28)
    int ptr[MAXN],next[MAXE],zu[MAXE];
    int n,m,match[MAXN],D[MAXN],q[MAXN];
    void init(int _n){
        n=_n;
        m=0;
        memset(ptr,~0,sizeof(int)*(n+1));
    }
    void add_edge(int u,int v){
        next[m]=ptr[u];ptr[u]=m;zu[m]=v;++m;
    }
    bool bfs(){
        int u,v;
        register int i;
        int qh=0, qt=0;
        for(i=1; i<=n; i++){
            if(!match[i]){
                D[i]=0;
                q[qt++]=i;
            }
            else D[i]=INF;
        }
        D[0]=INF;
        while(qh<qt){
            u=q[qh++];
            if(u!=0){
                for(i=ptr[u]; ~i; i=next[i]){
                    v=zu[i];
                    if(D[match[v]]==INF){
                        D[match[v]]=D[u]+1;
                        q[qt++]=match[v];
                    }
                }
            }
        }
        return D[0]!=INF;
    }
    bool dfs(int u){
        int v;
        register int i;
        if(u){
            for(i=ptr[u]; ~i; i=next[i]){
                v=zu[i];
                if(D[match[v]]==D[u]+1){
                    if(dfs(match[v])){
                        match[v]=u;
                        match[u]=v;
                        return true;
                    }
                }
            }
            D[u]=INF;
            return false;
        }
        return true;
    }
    int run(){
        int matching=0;
        register int i;
        while(bfs())
            for(i=1; i<=n; i++)
                if(!match[i] && dfs(i))
                    matching++;
        return matching;
    }
    void call(int N,ll a,ll b){
        int x,y;
        ll vx,vy;
        for(int i=1;i<=N;i++)
        {
            if(flag[i]) continue;
            x=i;
            y=match[x];
            vx=inp[i];
            vy=inp[y];
            if(vx+vy==a)
            {
                out[x]=out[y]=0;
            }
            else out[x]=out[y]=1;
            flag[x]=flag[y]=true;
        }
        for(int i=1;i<=N;i++)
        {
            if(i!=1) cout<<" ";
            cout<<out[i];
        }
        cout<<"\n";
        return ;
    }
    #undef MAXN
    #undef INF
};


int main()
{
    ll a,b;
    int n;
    __;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];
        hasInp[inp[i]]=i;
    }
    ll x,rx,tx;
    int p=0;
    hopcroftKarp::init(n);
    for(int i=1;i<=n;i++)
    {
        x=inp[i];
        rx=a-x;
        tx=b-x;
        if(hasInp.find(rx)!=hasInp.end())
        {
            hopcroftKarp::add_edge(i,hasInp[rx]);
        }
        if(hasInp.find(tx)!=hasInp.end())
        {
            hopcroftKarp::add_edge(i,hasInp[tx]);
        }
    }
    int cnt=hopcroftKarp::run();
    if(2*cnt>=(n))
    {
        cout<<"YES\n";
        hopcroftKarp::call(n,a,b);
    }
    else cout<<"NO\n";
    return 0;
}
















