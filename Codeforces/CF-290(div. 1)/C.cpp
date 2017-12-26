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
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


///V^2*E Complexity
///number of augment path * (V+E)
///Base doesn't matter

const int INF = 2000000000;
const int MAXN = 210;///total nodes
const int MAXM = 44100;///total edges

int N,edges;
int last[MAXN],prev[MAXM],head[MAXM];
int Cap[MAXM],Flow[MAXM];
int dist[MAXN];
int nextEdge[MAXN];///used for keeping track of next edge of ith node

queue<int> Q;

void init(int N)
{
    edges=0;
    memset(last,-1,sizeof(int)*(N+1));
}

//cap=capacity of edges , flow = initial flow
inline void addEdge(int u,int v,int cap,int flow)
{
    head[edges]=v;
    prev[edges]=last[u];
    Cap[edges]=cap;
    Flow[edges]=flow;
    last[u]=edges++;

    head[edges]=u;
    prev[edges]=last[v];
    Cap[edges]=0;
    Flow[edges]=0;
    last[v]=edges++;
}

inline bool dinicBfs(int S,int E,int N)
{
    int from=S,to,cap,flow;
    memset(dist,0,sizeof(int)*(N+1));
    dist[from]=1;
    while(!Q.empty()) Q.pop();
    Q.push(from);
    while(!Q.empty())
    {
        from=Q.front();Q.pop();
        for(int e=last[from];e>=0;e=prev[e])
        {
            to=head[e];
            cap=Cap[e];
            flow=Flow[e];
            if(!dist[to] && cap>flow)
            {
                dist[to]=dist[from]+1;
                Q.push(to);
            }
        }
    }
    return (dist[E]!=0);
}

inline int dfs(int from,int minEdge,int E)
{
    if(!minEdge) return 0;
    if(from==E) return minEdge;
    int to,e,cap,flow,ret;
    for(;nextEdge[from]>=0;nextEdge[from]=prev[e])
    {
        e=nextEdge[from];
        to=head[e];
        cap=Cap[e];
        flow=Flow[e];
        if(dist[to]!=dist[from]+1) continue;
        ret=dfs(to,min(minEdge,cap-flow),E);
        if(ret)
        {
            Flow[e]+=ret;
            Flow[e^1]-=ret;
            return ret;
        }
    }
    return 0;
}

int dinicUpdate(int S,int E)
{
    int flow=0;
    while(int minEdge = dfs(S,INF,E))
    {
        if(minEdge==0) break;
        flow+=minEdge;
    }
    return flow;
}

int maxFlow(int S,int E,int N)
{
    int totFlow=0;
    while(dinicBfs(S,E,N))
    {
        for(int i=0;i<=N;i++) nextEdge[i]=last[i];/// update last edge of ith node
        totFlow+=dinicUpdate(S,E);
    }
    return totFlow;
}
#define SZ1 21000

bool P[SZ1];

void sieve()
{
    int i,j,r;
    int lim=(int)sqrt(SZ1)+1;
    P[0]=P[1]=true;
    for(int i=4;i<SZ1;i+=2) P[i]=true;
    for(i=3; i<SZ1; i+=2)
    {
        if(!P[i])
        {
            if(i<lim)
            {
                r=i<<1;
                for(j=i*i; j<SZ1; j+=r)
                {
                    P[j]=true;
                }
            }
        }
    }
    return;
}

vector<vector<int> > res;
vector<int> ans;
bool col[210];

void dfs(int u,int src,int snk,int par,int p)
{
    if(col[u]) return ;
    ans.psb(u);
    col[u]=true;
    int v;
    for(int e=last[u];e>=0;e=prev[e])
    {
        v=head[e];
        if(v==src||v==snk||v==par||(Cap[e^p]-Flow[e^p])) continue;
        dfs(v,src,snk,u,!p);
    }
    return ;
}

int main(void)
{
    sieve();
    int n,src,snk,val[201];
    SF("%d",&n);
    src=0;
    snk=n+1;
    int N=n+1;
    init(N);
    for(int i=0;i<n;i++)
    {
        SF("%d",&val[i]);
        if(val[i]&1) addEdge(src,i+1,2,0);
        else addEdge(i+1,snk,2,0);
    }
    for(int i=0;i<n;i++)
    {
        if(val[i]&1)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i || (val[j]&1) || P[val[i]+val[j]]) continue;
                addEdge(i+1,j+1,1,0);
            }
        }
    }
    int ret = maxFlow(src,snk,N);
    if(ret!=n)
    {
        puts("Impossible");
    }
    else
    {
        int tot=0;
        for(int i=0;i<n;i++)
        {
            if(!col[i+1] && (val[i]&1))
            {
                ans.clear();
                dfs(i+1,src,snk,i+1,0);
                if(!ans.empty())
                {
                    tot++;
                    res.psb(ans);
                }
            }
        }
        PF("%d\n",tot);
        for(int i=0;i<tot;i++)
        {
            PF("%d",SZ(res[i]));
            for(int j=0;j<SZ(res[i]);j++)
            {
                PF(" %d",res[i][j]);
            }
            puts("");
        }
    }
    return 0;
}















