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
#include <utility>
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
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

const int MAX = 300050;

int parEdge[MAX];
ll dist[MAX];

struct data
{
    int v,en;
    ll w;
    data(){}
    data(int v,int en,ll w):v(v),en(en),w(w){}
};

struct pdata
{
    int u;
    ll cost;
    pdata(){}
    pdata(int u,ll cost):u(u),cost(cost){}
    bool operator < (const pdata &x) const
    {
        return x.cost<cost;
    }
};

vector<data> adj[MAX];
ll edgeList[MAX];


void djk(int u)
{
    int v,en;
    ll cost;
    priority_queue<pdata> Q;
    Q.push(pdata(u,0));
    dist[u]=0;
    while(!Q.empty())
    {
        u=Q.top().u;
        Q.pop();
        int k=SZ(adj[u]);
        for(int i=0;i<k;i++)
        {
            v=adj[u][i].v;
            en=adj[u][i].en;
            cost=adj[u][i].w;
            if(dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                parEdge[v]=en;
                Q.push(pdata(v,dist[v]));
            }
            else if(dist[v]==dist[u]+cost)
            {
                int pen = parEdge[v];
                ll w = edgeList[pen];
                if(w>cost)
                {
                    dist[v]=dist[u]+cost;
                    parEdge[v]=en;
                    Q.push(pdata(v,dist[v]));
                }
            }
        }
    }
    return ;
}


int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    int n,m,u,v;
    ll w;
    __;
    cin>>n>>m;
    clrall(parEdge,-1);
    for(int i=0;i<=n+5;i++) dist[i]=(1ll<<60);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        adj[u].psb(data(v,i,w));
        adj[v].psb(data(u,i,w));
        edgeList[i]=w;
    }
    cin>>u;
    djk(u);
    w=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(parEdge[i]!=-1)
        {
            cnt++;
            w+=edgeList[parEdge[i]];
        }
    }
    deb(w);
    for(int i=1;i<=n;i++)
    {
        if(parEdge[i]!=-1)
        {
            cnt--;
            cout<<parEdge[i]+1<<" \n"[cnt==0];
        }
    }
    return 0;
}













