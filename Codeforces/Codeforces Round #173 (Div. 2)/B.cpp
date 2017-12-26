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

int main()
{
    vector<pair<int,int> > v;
    int cnt,n,a,b;
    string s,t;
    cin>>n;
    if(n==1)
    {
        cin>>a>>b;
        if(a<b)
        {
            cout<<"A"<<endl;
            return 0;
        }
        else
        {
            cout<<"G"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.psb(make_pair(a,b));
    }
    a=0,b=0;
    if(v[0].first<=500) s+="A",a=v[0].first;
    else if(v[0].second<=500) s+="G",b=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(abs(a+v[i].first-b)<=500) s+="A",a+=v[i].first;
        else if(abs(a-(v[i].second+b))<=500) s+="G",b+=v[i].second;
        else if(abs(b-(v[i].first+a))<=500) s+="A",a+=v[i].first;
        else if(abs(b+v[i].second-a)<=500) s+="G",b+=v[i].second;
    }
    if(abs(a-b)>500) cout<<-1<<endl;
    else if(s.size()==n) cout<<s<<endl;
    else cout<<-1<<endl;
    return 0;
}
