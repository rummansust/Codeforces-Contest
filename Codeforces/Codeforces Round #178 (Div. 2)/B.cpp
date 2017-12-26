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
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)

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

struct edge
{
    int ti,wi;
    edge() {};
    edge(int ti,int wi) : ti(ti),wi(wi) {}
};

bool comp(edge a,edge b)
{
    if(a.wi==b.wi) return a.ti>b.ti;
    return a.wi>b.wi;
}

edge v[103];
int n;
int dp[103][233][233];

int rec(int pos,int ts,int ws)
{
    if(ws>200) return oo;
    if(pos==n)
    {
        if(ts>=ws) return ts;
        return oo;
    }
    int &ret=dp[pos][ts][ws];
    if(ret!=-1) return ret;
    ret=oo;
    ret=min(ret,rec(pos+1,ts+v[pos].ti,ws));
    ret=min(ret,rec(pos+1,ts,ws+v[pos].wi));
    return ret;
}

int main()
{
    int i,j,t,w;
    cin>>n;
    rep(i,0,n)
    {
        cin>>t>>w;
        v[i]=edge(t,w);
    }
    sort(v,v+n,comp);
    clr(dp,-1);
    int res=rec(0,0,0);
    cout<<res<<endl;
    return 0;
}
