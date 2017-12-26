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

struct edge
{
    int x1,x2,y1,y2;
    edge(){}
    edge(int a,int b,int c,int d):x1(a),y1(b),x2(c),y2(d){}
};

int main()
{
    int x,y;
    cin>>x>>y;
    bool flag=true;
    vector<edge> v;
    int a=0,b=0,c=0,d=0,i;
    for(int k=1;k<250;k++)
    {
        i=k;
        if(!(k&1)) i=-k;
        for(int j=1;j<=2;j++)
        {
            if(j&1)
            {
                c+=i;
                v.psb(edge(a,b,c,d));
                a=c;
            }
            else
            {
                d+=i;
                v.psb(edge(a,b,c,d));
                b=d;
            }
        }
    }
    for(i=0;i<v.size();i++)
    {
        if((min(v[i].x1,v[i].x2)<=x&&x<=max(v[i].x1,v[i].x2))&&(min(v[i].y1,v[i].y2)<=y&&y<=max(v[i].y1,v[i].y2)))
        {
            break;
        }
    }
    cout<<i<<endl;
    return 0;
}
