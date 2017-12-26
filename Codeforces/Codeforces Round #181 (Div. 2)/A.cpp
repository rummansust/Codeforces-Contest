
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


int main()
{
    vector<int> v,a,b,c;
    int n;
    int num;
    cin>>n;
    int ncnt=0,zcnt=0;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        if(num<0) ncnt++;
        if(num==0) zcnt++;
        else
        v.psb(num);
    }
    n=n-zcnt;
    sort(v.begin(),v.end());
    int it=0;
    if(ncnt&1)
    {
        a.psb(v[0]);
        for(it=it+1; it<n; it++) b.psb(v[it]);
    }
    else
    {
        a.psb(v[0]);
        c.psb(v[1]);
        for(it=it+2; it<n; it++) b.psb(v[it]);
    }
    for(int i=0;i<zcnt;i++) c.psb(0);
    cout<<a.size();
    for(int i=0; i<a.size(); i++)
    {
        cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<b.size();
    for(int i=0; i<b.size(); i++)
    {
        cout<<" ";
        cout<<b[i];
    }
    cout<<endl;
    cout<<c.size();
    for(int i=0; i<c.size(); i++)
    {
        cout<<" ";
        cout<<c[i];
    }
    cout<<endl;
    return 0;
}
