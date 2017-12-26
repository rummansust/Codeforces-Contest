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
    int val,in;
    edge(){}
    edge(int v,int in) : val(v),in(in){}
    bool operator < (const edge& x) const
    {
        return x.val<val;
    }
};

int main()
{
    read_;
    write_;
    int n,num;
    vector<edge> v;
    map<int,int> data;
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        cin>>num;
        v.psb(edge(num,i+1));
        data[num]++;
    }
    sort(v.begin(),v.end());
    map<int,int> :: const_iterator it;
    for(it=data.begin();it!=data.end();it++)
    {
        if((it->second)%2)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[2*i].in<<" "<<v[2*i+1].in<<endl;
    }
    return 0;
}
