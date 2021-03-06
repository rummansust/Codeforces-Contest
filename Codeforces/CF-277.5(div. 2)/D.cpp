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

#define casePrint PF("Case #%d: ",++cas);

const int MAX = 3050;
int mat[MAX][MAX];
int tot[MAX][MAX];

vector<int> par[MAX];
vector<int> adj[MAX];

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    int n,m;
    int u,v;
    __;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        u--;
        v--;
        mat[v][u]=1;
        par[v].psb(u);
        adj[u].psb(v);
    }
    for(int i=0;i<n;i++)
    {
        int k=SZ(adj[i]);
        for(int j=0;j<k;j++)
        {
            for(int l=j+1;l<k;l++)
            {
                tot[adj[i][j]][adj[i][l]]++;
                tot[adj[i][l]][adj[i][j]]++;
            }
        }
    }
    int k;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        k=SZ(par[i]);
        for(int j=0;j<k;j++)
        {
            for(int l=j+1;l<k;l++)
            {
                res+=tot[par[i][j]][par[i][l]];
                if(mat[par[i][j]][i]&&mat[par[i][l]][i]) res--;
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}

















