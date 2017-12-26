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
#define swap(x,y,t) {(t)=(x);(x)=(y);(y)=(t);}
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

bool cheak_zero(string &str)
{
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!='0') return false;
    }
    return true;
}

int main()
{
    string str,res,tmp;
    char giv;
    while(cin>>giv>>str)
    {
        if(giv=='0'&&cheak_zero(str)) break;
        res.clear();
        tmp.clear();
        for(int i=0;i<str.size();i++)
        {
            if(str[i]!=giv) tmp+=str[i];
        }
        bool flag=true;

        for(int i=0;i<tmp.size();i++)
        {
            if(flag)
            {
                if(tmp[i]!='0') flag=false;
            }
            if(!flag) res+=tmp[i];
        }
        if(res.empty()) cout<<"0"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
