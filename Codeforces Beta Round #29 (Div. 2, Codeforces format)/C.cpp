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
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)
#define MAX

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

vector<int> v[1<<17];
vector<int> vv;
int visited[1<<17];

map<int,int> data,rdata;

int prr,nod;

void dfs1(int u,int pcol)
{

    visited[u]=pcol+1;
    if(prr<visited[u])
    {
        prr=visited[u];
        nod=u;
    }
    for(int i=0;i<v[u].size();i++)
    {
        int p=v[u][i];
        if(visited[p]==0)
        {
//            cout<<"here "<<rdata[u]<<" : "<<pcol+1<<endl;
//            cout<<">> "<<rdata[p]<<endl;
            dfs1(p,visited[u]);
        }
    }
    return ;
}

void dfs(int u,int par)
{
    vv.psb(rdata[u]);
    for(int i=0;i<v[u].size();i++)
    {
        int p=v[u][i];
        if(p!=par)
        {
            dfs(p,u);
        }
    }
    return ;
}


int main()
{
    int n,x,y,k=-1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(data.find(x)==data.end()) data[x]=++k,rdata[k]=x;
        if(data.find(y)==data.end()) data[y]=++k,rdata[k]=y;
        v[data[x]].psb(data[y]);
        v[data[y]].psb(data[x]);
    }
    dfs1(0,0);
    dfs(nod,-1);
    for(int i=0;i<vv.size();i++)
    {
        if(i) cout<<" ";
        cout<<vv[i];
    }
    cout<<endl;
    return 0;
}
