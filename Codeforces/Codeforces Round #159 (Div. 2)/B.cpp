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
#define psb(b) push_back(b)
#define ppb() pop_back()
#define oo 100000000000000000LL
#define swap(x,y) {int t;(t)=(x);(x)=(y);(y)=(t);}
#define for_i(s,n) for(int i=(s);i<(n);(i)++)
#define for_j(s,n) for(int (j)=(s);(j)<(n);(j)++)
#define for_k(s,n) for(int (k)=(s);(k)<(n);(k)++)
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

struct point
{
    int x,y;
};

void add(string &a,int n,string l)
{
    while(n--)
    {
        a+=l;
    }
    return ;
}

point made_string(int p,int q)
{
    string a;
    point pv;
    bool red=true,blue=false;
    int mv=0;
    while(p&&q)
    {
        if(mv&1)
        {
            if(red)
            {
                q--;
                red=false;
                blue=true;
                a+="b";
            }
            else
            {
                p--;
                blue=false;
                red=true;
                a+="r";
            }
        }
        else
        {
            if(red)
            {
                p--;
                a+="r";
            }
            else
            {
                q--;
                a+="b";
            }
        }
        mv++;
    }
    if(p) add(a,p,"r");
    else add(a,q,"b");
    char ch=a[0];
    pv.x=pv.y=0;
    for(int i=1;i<a.size();i++)
    {
        if(ch==a[i]) pv.x++;
        else
        {
            pv.y++;
            ch=a[i];
        }
    }
    return pv;
}

int main()
{
    int n,m;
    cin>>n>>m;
    point a=made_string(n,m);
    point b=made_string(m,n);
    if(a.x>b.x) cout<<a.x<<" "<<a.y<<endl;
    else cout<<b.x<<" "<<b.y<<endl;
    return 0;
}
