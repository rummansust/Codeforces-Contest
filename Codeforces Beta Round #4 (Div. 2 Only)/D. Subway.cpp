#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define clr(name,val) memset(name,(val),sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 10000000
#define for_i(s,n) for(int i=(s);i<(n);(i)++)
#define for_j(s,n) for(int (j)=(s);(j)<(n);(j)++)
#define for_k(s,n) for(int (k)=(s);(k)<(n);(k)++)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)
#define MAX 1000002000

///next_permutation  next_permutation (s.begin(),s.end())
///reverse(a,a+n);
///binary_search(first,last);
///vector erase v.erase(v.begin()+position);
///map map<int , int > data;
///map clear  data.clear();
///map iterator>>>> map <int,vector <int> >::const_iterator it;
///find an element in map (colour.find(nd)==colour.end());//if it return true this
///mean the element is'nt in the map.
///pass a vector to a funtion: funtion (vector <data type> &vector name);
///make_pair  point=make_pair(i,j);
///access pair value point.first;point.second;

using namespace std;

///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

int u,flag=false;
int color[3100];
queue<int> Q;
vector<int> adj[3100];

void bfs()
{
    int u,v;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            v=adj[u][i];
            if(color[v]==-1)
            {
                color[v]=0;
                color[v]=color[u]+1;
                Q.push(v);
            }
        }
    }
    return ;
}
int visited[3010];

void dfs(int par,int cur)
{
    visited[cur]=1;
    for(int i=0;i<adj[cur].size();i++)
    {
        int v=adj[cur][i];
        if(v!=par)
        {
            if(v==u)
            {
                flag=true;
            }
            if(!flag&&!visited[v])
            {
                dfs(cur,v);
            }
            if(flag)
            {
                Q.push(cur);
                color[cur]=0;
                return ;
            }
        }
    }
    return ;
}

int main()
{
    int n,x,y;
    cin>>n;
    clr(color,-1);
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        adj[x].psb(y);
        adj[y].psb(x);
    }
    for(int i=1;i<=n;i++)
    {
        u=i;
        clr(visited,0);
        dfs(-1,i);
        if(!Q.empty()) break;
    }
    bfs();
    for(int i=1;i<=n;i++)
    {
        if(i-1) cout<<" ";
        cout<<color[i];
    }
    cout<<endl;
    return 0;
}
