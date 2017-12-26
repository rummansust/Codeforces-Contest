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
#define PI 2.0*acos(0.0)

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
    double r1,r2,r3,c1,c2,c3,a,b,c,ar1,ar2,ar3,atr;
    int test,cas=0;
    cin>>test;
    while(test--)
    {
        cin>>r1>>r2>>r3;
        a=r1+r2;b=r2+r3;c=r3+r1;
        double s=(a+b+c)/2;
        atr=sqrt(s*(s-a)*(s-b)*(s-c));
        c1=((b*b)+(c*c)-(a*a))/(2*b*c);
        c1=acos(c1)*(180/PI);
        c2=((a*a)+(c*c)-(b*b))/(2*a*c);
        c2=acos(c2)*(180/PI);
        c3=180-(c1+c2);
        ar1=(r1*r1*c1*PI)/360;
        ar2=(r2*r2*c2*PI)/360;
        ar3=(r3*r3*c3*PI)/360;
        printf("Case %d: %lf\n",++cas,atr-ar1-ar2-ar3);
    }
    return 0;
}
