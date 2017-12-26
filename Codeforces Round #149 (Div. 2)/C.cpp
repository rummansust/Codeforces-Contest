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
#define psb(b) push_back(b)
#define ppb() pop_back()
#define oo 100000000000000000LL
#define swap(x,y) {int t;t=x;x=y;y=t;}
#define for_i(s,n) for(int i=s;i<n;i++)
#define for_j(s,n) for(int j=s;j<n;j++)
#define for_k(s,n) for(int k=s;k<n;k++)
#define MAX 100099

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
ll rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
ll cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

map<pair<ll,ll>,ll> data;
map<ll,pair<ll,ll> >arr;

ll bfs(ll s1,ll s2,ll e1,ll e2)
{
    ll c,r;
    c=r=1000000001L;
    queue<ll> Q;
    Q.push(s1);Q.push(s2);
    pair<ll , ll> mpoint,point;
    mpoint = make_pair(s1,s2);
    data[point]=0L;
    while(!Q.empty())
    {
        s1=Q.front();Q.pop();
        s2=Q.front();Q.pop();
        mpoint=make_pair(s1,s2);
        for(int i=0;i<8;i++)
        {
            ll t1=s1+(ll) rr[i];
            ll t2=s2+(ll) cc[i];
            point = make_pair(t1,t2);
            if(arr.find(t1)==arr.end()) continue;
            else
            {
                if((t1>-1L&&t1<r)&&(t2>=arr[t1].first&&t2<=arr[t1].second))
                {
                    if(data.find(point)==data.end())
                    {
                        data[point]=data[mpoint]+1L;
                        if(t1==e1&&t2==e2) return data[point];
                        Q.push(t1);
                        Q.push(t2);
                    }
                }
            }
        }
    }
    return -1L;
}

int main()
{
    ll x1,y1,x2,y2,r,a,b;
    cin>>x1>>y1>>x2>>y2;
    int n;
    cin>>n;
    int node=n;
    pair<ll,ll> point;
    while(node--)
    {
        cin>>r>>a>>b;
        point = make_pair(a,b);
        if(arr.find(r)==arr.end())
        {
            arr[r]=point;
            continue;
        }
        arr[r].first=arr[r].first<a?arr[r].first:a;
        arr[r].second=arr[r].second<b?b:arr[r].second;
    }
    ll cnt=bfs(x1,y1,x2,y2);
    if(cnt!=-1L) cout<<cnt<<endl;
    else cout<<-1<<endl;
    return 0;
}
