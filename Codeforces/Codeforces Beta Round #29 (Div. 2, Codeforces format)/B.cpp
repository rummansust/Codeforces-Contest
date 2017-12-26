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
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
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
    int v[3009];
    clr(v,0);
    int l,d,vel,g,r,typ;
    double res,tres,wait;
    cin>>l>>d>>vel>>g>>r;
    for(int i=g+1;i<2005;i++)
    {
        int j;
        for(j=i;j<i+r;j++)
        {
            v[j]=1;
        }
        i=j+g-1;
    }
    res=(d*1.0/vel*1.0);
    typ=(int) ceil(res);
    tres=((l-d)*1.0/vel*1.0);
    double ttres=((l)*1.0/vel*1.0);
    if(v[typ]||((double)typ==res&&v[typ+1]))
    {
        if((double)typ==res) wait=0.0;
        int p;
        for(p=typ;v[p]==1;p--)
        {
            if(v[p]==0) break;
        }
        wait+=(double) (p*1.0+r*1.0);
        printf("%lf\n",tres+wait);
    }
    else printf("%lf\n",ttres);
    return 0;
}
