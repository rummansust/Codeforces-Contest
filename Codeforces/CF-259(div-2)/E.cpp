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

const int MAX = 100009;

bool parity[MAX],nparity[MAX],visited[MAX];
vector<int> adj[MAX];
vector<int> add;

void isSol(int u)
{
    visited[u]=true;
    int v;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(!visited[v])
        {
            isSol(v);
        }
    }
    return ;
}

void dfs(int u,int par)
{
    visited[u]=true;
    add.psb(u);
    nparity[u]=!nparity[u];
    int v;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(!visited[v])
        {
            dfs(v,u);
            add.psb(u);
            nparity[u]=!nparity[u];
        }
    }
    if(par!=-1)
    {
        if(parity[u]!=nparity[u])
        {
            add.psb(par);
            nparity[par]=!nparity[par];
            add.psb(u);
            nparity[u]=!nparity[u];
        }
    }
    else
    {
        if(parity[u]!=nparity[u] && !add.empty())
        {
            add.ppb();
            nparity[u]=!nparity[u];
        }
    }
    return ;
}

int main()
{
    int n,m,u,v;
    SF("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        SF("%d %d",&u,&v);
        adj[u].psb(v);
        adj[v].psb(u);
    }
    for(int i=1;i<=n;i++)
    {
        SF("%d",&parity[i]);
    }
    int cnt=0;
    int root=1;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]&&parity[i])
        {
            isSol(i);
            cnt++;
            if(cnt>1)
            {
                PF("-1\n");
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++) if(parity[i]) root=i;
    clrall(visited,0);
    dfs(root,-1);
    for(int i=1;i<=n;i++) assert(parity[i]==nparity[i]);
    PF("%d\n",SZ(add));
    for(int i=0;i<SZ(add);i++)
    {
        if(i) PF(" ");
        PF("%d",add[i]);
    }
    PF("\n");
    return 0;
}
