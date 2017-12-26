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
#define oo 10000000000.0
#define for_i(s,n) for(int i=(s);i<(n);(i)++)
#define for_j(s,n) for(int (j)=(s);(j)<(n);(j)++)
#define for_k(s,n) for(int (k)=(s);(k)<(n);(k)++)
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

double cheak=oo;
pair<int,int> res;

int cheak_(int lb,int ub,int x,int y,int b)
{
    int a=(lb+ub+1)/2;
    if(abs(x*1.0/y*1.0-a*1.0/b*1.0)<cheak) return true;
    return false;
}

void bin_(int lb,int ub,int x,int y,int b)
{
    while(lb<ub)
    {
        int a=(lb+ub+1)/2;
        if(abs(x*1.0/y*1.0-a*1.0/b*1.0)<cheak)
        {
            cheak=abs(x*1.0/y*1.0-a*1.0/b*1.0);
            res.first=a;
            res.second=b;
        }
        if(cheak_(lb,a,x,y,b))
        {
            ub=a;
        }
        else lb=a;
    }
    if(abs(x*1.0/y*1.0-ub*1.0/b*1.0)<cheak)
    {
        cheak=abs(x*1.0/y*1.0-ub*1.0/b*1.0);
        res.first=ub;
        res.second=b;
    }
    return ;
}

int main()
{
    int x,y,a,b,n;
    cin>>x>>y>>n;
    for(int i=1;i<=n;i++)
    {
        bin_(0,(i*x/y),x,y,i);
    }
    cout<<res.first<<"/"<<res.second<<endl;
    return 0;
}
