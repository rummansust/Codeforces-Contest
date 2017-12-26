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

int m1[]= {366,31,28,31,30,31,30,31,31,30,31,30,31};

struct edge
{
    int s,e,np;
    edge() {}
    edge(int s,int e,int np):s(s),e(e),np(np) {}
};
vector<edge> v;

int main()
{
//    read_;
//    write_;
    int csum[20];
    clr(csum,0);
    csum[0]=366;
    for(int i=1; i<13; i++)
    {
        csum[i]+=csum[i-1]+m1[i];
    }
    int n;
    cin>>n;
    int m,d,p,t;

    for_i(0,n)
    {
        cin>>m>>d>>p>>t;
        int s,e;
        e=(csum[m-1]+d)-1;
        s=(e-t)+1;
//        cout<<s<<" "<<e<<endl;
        v.psb(edge(s,e,p));
    }
    bool color[200];
    clr(color,0);
    int r1=0,r2=0;
    for(int i=0; i<n; i++)
    {
        int sum=v[i].np;
        bool flag=0;
        for(int j=i+1; j<n; j++)
        {
//            int ms=max(v[i].s,v[j].s),me=min(v[i].e,v[j].e);
            int a=v[i].s,b=v[i].e,c=v[j].s,d=v[j].e;
            if((a>=c&&a<=d)||(b>=c&&b<=d)||(c>=a&&c<=b)||(d>=a&&d<=b))
            {
                cout<<i<<" "<<j<<" "<<v[j].np<<endl;//<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                flag=1;
                sum+=v[j].np;
                color[i]=true;
                color[j]=true;
            }
//            else cout<<i<<" "<<j<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        }
        if(flag)
        {
            cout<<sum<<endl;
            r1=max(r1,sum);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(!color[i])
        {
            r2=max(r2,v[i].np);
        }
    }
    cout<<max(r1,r2)<<endl;
    return 0;
}
