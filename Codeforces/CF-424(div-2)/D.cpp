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
#define Write freopen("1206M.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

//*************************************************My Code Starts Here*********************************************************************************
//Esqrt(V) Complexity
//0 Based
//Edge from set a to set b
const int MAXN1 = 1010; //nodes in set a
const int MAXN2 = 2010; //nodes in set b
const int MAXM = 5000000; //number of edges

int n1, n2, edges, last[MAXN1], prv[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1]; //matching of set b
bool used[MAXN1], vis[MAXN1]; //vis is cleared in each dfs

// n1 = number of nodes in set a, n2 = number of nodes in set b
void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    prv[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prv[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prv[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || (!vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int augmentPath() {
    bfs();
    fill(vis, vis + n1, false);
    int f = 0;
    for (int u = 0; u < n1; ++u)
        if (!used[u] && dfs(u))
            ++f;
    return f;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        int f = augmentPath();
        if (!f)
            return res;
        res += f;
    }
}
ll x[MAXN2],y[MAXN2];
ll arr[MAXN2][MAXN2];

int go(int n,int m,ll v)
{
    init(n+1,m+1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]<=v)
            {
                addEdge(i,j);
//                cout<<i<<" "<<j<<" "<<arr[i][j]<<" "<<v<<endl;
            }
        }
    }
    int k=maxMatching();
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















