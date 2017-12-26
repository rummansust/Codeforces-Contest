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
#define MAX 100050

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

ll dp[MAX][4];

ll ncr(ll n,ll r)
{
    if(n==r||r==0) return 1L;
    if(r==1) return n;
    ll &ret=dp[n][r];
    if(ret!=-1) return ret;
    ret=ncr(n-1,r-1)+ncr(n-1,r);
    return ret;
}

int rec(ll n)
{
    if(n==0) return 0;
    if(n%2==0) return rec(n/2);
    else return rec(n/2)+1;
}

int main()
{
//    read_;
    ll n;
    clr(dp,-1);
    map<ll,ll> data;
    cin>>n;
    ll num;
    ll cnt;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        cnt=rec(num);
//        cout<<i<<"  "<<cnt<<endl;
        data[cnt]++;
    }
    map<ll,ll> :: const_iterator it;
    ll sum=0;
    for(it=data.begin();it!=data.end();it++)
    {
        if((it->second) > 1)
        {
//            cout<<(it->second)<<endl;
            sum+=(ncr((it->second),2));
        }
    }
    cout<<sum<<endl;
    return 0;
}
