#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <sstream>

#define clr(a,x) memset(a,x,sizeof(a));
#define ll long long
#define pb(b) push_back(b)
#define oo 100000000000000000LL
#define SZ 100050

//reverse(a,a+n);
//binary_search(first,last);
//vector erase v.erase(v.begin(),position);
//map map<int , int > data;
//map clear  data.clear();

using namespace std;
//bool colour[210][210];
//int rr[]= {-1,-1,0,0,1,1};
//int cc[]= {-1,0,-1,1,0,1};
//int rr[]= {0,0,1,-1};/*4 side move*/
//int cc[]= {-1,1,0,0};/*4 side move*/
//int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

int main()
{
    ll num,n,cnt=0;
    vector<ll> v,vt;
    cin>>n;
    while(n--)
    {
        cin>>num;
        v.pb(num);
        vt.pb(num);
    }
    sort(vt.begin(),vt.end());
    for(ll i=0;i<v.size();i++)
    {
        if(v[i]!=vt[i]) cnt++;
    }
    if(cnt==0||cnt==2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
