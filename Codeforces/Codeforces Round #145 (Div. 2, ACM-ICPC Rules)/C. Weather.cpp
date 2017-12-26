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

#define clr(name,val) memset(name,val,sizeof(name));
#define EPS .000000001
#define ll long long
#define pb(b) push_back(b)
#define oo 100000000000000000LL
#define swap(x,y) {int t;t=x;x=y;y=t;}
#define for_i(s,n) for(int i=s;i<n;i++)
#define for_j(s,n) for(int j=s;j<n;j++)
#define for_k(s,n) for(int k=s;k<n;k++)

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

struct data
{
    ll rc,lc,nm;
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector <data> v;
    vector <ll> vt;
    data tmp;
    ll n,num,zero,pc,nc;
    while(cin>>n)
    {
        v.clear();vt.clear();
        zero=pc=0L;
        for(ll i=0L;i<n;i++)
        {
            cin>>num;
            vt.pb(num);
            if(num==0L)
            {
                tmp.lc=pc+zero;
                tmp.rc=0L;
                tmp.nm=0L;
                v.pb(tmp);
                zero++;
            }
            else if(num>0L)
            {
                pc++;
                tmp.nm=num;
                tmp.lc=pc+zero;
                tmp.rc=0L;
                v.pb(tmp);
            }
            else
            {
                tmp.nm=num;
                tmp.lc=pc+zero;
                tmp.rc=0L;
                v.pb(tmp);
            }
        }
        zero=nc=0L;
        for(ll i=n-1L;i>-1;i--)
        {
            if(vt[i]<0L)
            {
                v[i].rc=nc+zero;
                nc++;
            }
            else if(vt[i]>0L)
            {
                v[i].rc=nc+zero;
            }
            else
            {
                zero++;
                v[i].rc=nc+zero;
            }
        }
        ll minc=oo;
        if(v[n-1].nm<0L)
        {
            v[n-1].rc=1L;
//            v[n-1].lc=(n-1-v[n-1].lc);
        }
        if(v[0].nm>0L)
        {
            v[0].lc=1L;
//            v[0].rc=(n-1-v[0].rc);
        }
        for(ll i=0L;i<n;i++)
        {
//                cout<<v[i].nm<<" "<<v[i].lc<<" "<<v[i].rc<<endl;
                minc=min(minc,v[i].lc+v[i].rc);
        }
        cout<<minc<<endl;
    }
    return 0;
}
