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
#define MAX 100020

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

bool color[MAX];
vector<int> v[10006];

void bfs(int s)
{
    queue<int> Q;
    Q.push(s);
    color[s]=true;
    while(!Q.empty())
    {
        s=Q.front();
        Q.pop();
        for(int i=0;i<v[s].size();i++)
        {
            int g=v[s][i];
            if(!color[g])
            {
                Q.push(g);
                color[g]=true;
            }
        }
    }
    return;
}

int main()
{
    int test,n,cas=0,m,u,vv;
    cin>>test;
    vector<int> first,second;
    while(test--)
    {
        cin>>n>>m;
        first.clear();
        second.clear();
        for(int i=0;i<=n;i++) v[i].clear();
        for(int i=0;i<m;i++)
        {
            cin>>u>>vv;
            v[u].psb(vv);
        }
        clr(color,0);
        for(int i=1;i<=n;i++)
        {
            if(!color[i])
            {
                first.psb(i);
                bfs(i);
            }
        }
        clr(color,0);
        for(int i=first.size()-1;i>-1;i--)
        {
            if(!color[first[i]])
            {
                second.psb(first[i]);
                bfs(first[i]);
            }
        }
        printf("Case %d: %d\n",++cas,min(first.size(),second.size()));
    }
    return 0;
}

