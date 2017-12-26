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

vector<int> adj[120],lan[120];

bool color[120];

void bfs(int u)
{
    queue<int> Q;
    color[u]=true;
    Q.push(u);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(!color[v])
            {
                Q.push(v);
                color[v]=true;
            }
        }
    }
    return ;
}

int main()
{
    int n,m,k,ai,njana=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(!k) njana++;
        for(int j=0;j<k;j++)
        {
            cin>>ai;
            lan[i].psb(ai);
        }
    }
    bool flag;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            flag=false;
            for(int k=0;k<lan[i].size();k++)
            {
                for(int l=0;l<lan[j].size();l++)
                {
                    if(lan[i][k]==lan[j][l])
                    {
                        adj[i].psb(j);
                        adj[j].psb(i);
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!color[i])
        {
            bfs(i);
            cnt++;
        }
    }
    if(njana==cnt) cout<<cnt<<endl;
    else
    cout<<cnt-1<<endl;
    return 0;
}
