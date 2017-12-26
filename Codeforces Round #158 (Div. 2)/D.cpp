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

#define clr(name,val) memset(name,val,sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back(b)
#define ppb() pop_back()
#define oo 100000000000000000LL
#define swap(x,y) {int t;t=x;x=y;y=t;}
#define for_i(s,n) for(int i=s;i<n;i++)
#define for_j(s,n) for(int j=s;j<n;j++)
#define for_k(s,n) for(int k=s;k<n;k++)
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
    vector<ll> vec;
    ll mn=10000000000L,num;
    int pos;
    int n,x;
    cin>>n>>x;
    x--;
    int tm=10000000;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        vec.psb(num);
        if(mn>num) mn=num;
    }
    for(int i=0;i<n;i++)
    {
        if(vec[i]==mn)
        {
            int tt=x-i;
            if(tt<0) tt+=n;
            if(tm>tt) tm=tt,pos=i;
        }
    }
    ll ball=(ll) n*mn;

    if(vec[x]!=mn)
    {
        for(int i=0;i<n;i++) vec[i]-=mn;
        if(pos>x)
        {
            for(int i=pos+1;i<n;i++) vec[i]-=1L,ball++;
            for(int i=0;i<=x;i++) vec[i]-=1L,ball++;
        }
        else for(int i=pos+1;i<=x;i++) vec[i]-=1L,ball++;
    }
    else for(int i=0;i<n;i++) vec[i]-=mn;
    vec[pos]=ball;
    for(int i=0;i<n;i++)
    {
        if(i) cout<<" ";
        cout<<vec[i];
    }
    cout<<endl;
    return 0;
}
