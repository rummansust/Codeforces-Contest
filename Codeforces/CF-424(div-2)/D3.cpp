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
#define mem(name,val) memset(name,(val),sizeof(name));
#define ll long long
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false),cin.tie(0)

///V^2*E Complexity
///number of augment path * (V+E)
///Base doesn't matter

const int INF = 2000000000;
const int MAXN = 3010;///total nodes
const int MAXM = 5000000;///total edges

int N,edges;
int last[MAXN],prv[MAXM],head[MAXM];
int Cap[MAXM],Flow[MAXM];
int dist[MAXN];
int nextEdge[MAXN];///used for keeping track of next edge of ith node

queue<int> Q;

void init(int N)
{
    edges=0;
    memset(last,-1,sizeof(int)*N);
}

//cap=capacity of edges , flow = initial flow
inline void addEdge(int u,int v,int cap,int flow)
{
    head[edges]=v;
    prv[edges]=last[u];
    Cap[edges]=cap;
    Flow[edges]=flow;
    last[u]=edges++;

    head[edges]=u;
    prv[edges]=last[v];
    Cap[edges]=0;
    Flow[edges]=0;
    last[v]=edges++;
}

inline bool dinicBfs(int S,int E,int N)
{
    int from=S,to,cap,flow;
    memset(dist,0,sizeof(int)*N);
    dist[from]=1;
    while(!Q.empty()) Q.pop();
    Q.push(from);
    while(!Q.empty())
    {
        from=Q.front();Q.pop();
        for(int e=last[from];e>=0;e=prv[e])
        {
            to=head[e];
            cap=Cap[e];
            flow=Flow[e];
            if(!dist[to] && cap>flow)
            {
                dist[to]=dist[from]+1;
                Q.push(to);
                ///Important
//                if(to==E) return true;
                ///Need to be sure
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
    for(;nextEdge[from]>=0;nextEdge[from]=prv[e])
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
ll x[MAXN],y[MAXN];
ll arr[MAXN][MAXN];

int go(int n,int m,ll v)
{
    int src=n+m,snk=n+m+1,N=n+m+2;
    init(N+1);
    for(int i=0;i<n;i++) addEdge(src,i,1,0);
    for(int j=0;j<m;j++) addEdge(j+n,snk,1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]<=v)
            {
                addEdge(i,j+n,1,0);
//                cout<<i<<" "<<j<<" "<<arr[i][j]<<" "<<v<<endl;
            }
        }
    }
    int k=maxFlow(src,snk,N);
//    cout<<k<<endl;
    return k;
}

ll solve(int n,int m)
{
    ll lo=0,hi=1e10,mid,res=1e15;
    while(lo<=hi)
    {
        mid=(lo+hi)>>1ll;
        if(go(n,m,mid)==n)
        {
            res=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return res;
}


int main()
{
    ll n,m,p;
    __;
    cin>>n>>m>>p;
    for (ll i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for (ll i=0;i<m;i++)
    {
        cin>>y[i];
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            arr[i][j]=abs(x[i]-y[j])+abs(y[j]-p);
//            cout<<arr[i][j]<<" ";
        }
//        cout<<"\n";
    }
    cout<<solve(n,m)<<"\n";
    return 0;
}















