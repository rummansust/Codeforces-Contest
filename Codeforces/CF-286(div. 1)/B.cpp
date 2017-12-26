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

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

///1 based graph + component

const int MAX = 100050;
int res;

int id,distime[MAX],height[MAX],color[MAX],group_id[MAX],com,num_com[MAX],in_degree[MAX],out_degree[MAX];
vector<int> adj[MAX];
vector<int> nadj[MAX];
stack<int> S;

void init(int n)
{
    id=0,com=0;
    while(!S.empty()) S.pop();
    for(int i=0;i<=n;i++) adj[i].clear();
    return ;
}

void scc(int u)
{
    color[u]=1;
    S.push(u);
    distime[u]=height[u]=id++;
    int v;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(color[v]==1) height[u]=min(height[u],distime[v]);
        else if(color[v]==0)
        {
            scc(v);
            height[u]=min(height[u],height[v]);
        }
    }
    if(height[u]==distime[u])
    {
        com++;
        do
        {
            v=S.top();
            S.pop();
            color[v]=2;
            group_id[v]=com;
            num_com[com]++;
        }
        while(v!=u);
    }
    return ;
}

void TarjanSCC(int n)
{
    clrall(color,0);
    clrall(num_com,0);
    for(int i=1;i<=n;i++) if(!color[i]) scc(i);
    return ;
}

int cycle,add;

int dfs(int u,int c)
{
    if(color[u] && color[u]!=c) add=1;
    if(color[u]) return 0;
    color[u]=c;
    if(num_com[u]>1) cycle+=num_com[u]-1;
    int ret=1;
    for(int i=0;i<SZ(nadj[u]);i++)
    {
        int v=nadj[u][i];
//        deb("edge : ",u,v);
        ret+=dfs(v,c);
    }
    return ret;
}

int indeg[MAX];
vector<int> node;

void toposort(int n)
{
    int u,v;
    queue<int> Q;
    for(int i=1;i<=n;i++) if(indeg[i]==0) Q.push(i);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        if(color[u]) continue;
        color[u]=true;
        node.psb(u);
        for(int i=0;i<SZ(nadj[u]);i++)
        {
            v=nadj[u][i];
            if(indeg[v]>0)
            {
                indeg[v]--;
                if(indeg[v]==0) Q.push(v);
            }
        }
    }
    return ;
}

int main()
{
    int n,test,cas=0,u,v,m,in,out;
    scanf("%d %d",&n,&m);
    init(n);
    clrall(indeg,0);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].psb(v);
    }
    TarjanSCC(n);
    for(u=1;u<=n;u++)
    {
        for(int i=0;i<SZ(adj[u]);i++)
        {
            v=adj[u][i];
            if(group_id[u]!=group_id[v])
            {
                indeg[group_id[v]]++;
                nadj[group_id[u]].psb(group_id[v]);
            }
        }
    }
    clrall(color,0);
    toposort(com);
    clrall(color,0);
    for(int i=0;i<SZ(node);i++)
    {
        u=node[i];
        if(color[u]==0)
        {
            cycle=0;
            add=0;
            res+=dfs(u,i+1)-1+cycle+((bool) cycle)+add;
        }
    }
    PF("%d\n",res);
    return 0;
}
/*
8 6
6 1
4 1
6 3
4 3
1 3
4 6

3 3
1 2
1 3
4 3

*/
