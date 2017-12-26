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

int dp[30][30];
bool rec(int odd,int even,bool p)
{
    if(even<0||odd<0) return 0;
    if(odd==1)
    {
        return !p;
    }
    int &ret=dp[odd][even];
    if(ret!=-1) return ret;
    bool a,b;
    if(odd&&!even)
    {
        ret=rec(odd-1,even,!p);
    }
    else if(!odd&&even)
    {
        ret=rec(odd+1,even-1,!p);
    }
    else
    {
        a=rec(odd-1,even,!p);
        b=rec(odd+1,even-1,!p);
        if(p) ret=(a&b);
        else ret=(a|b);
    }
    return ret;
}
int main()
{
    map<char,int> data;
    string s;
    int n=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        data[s[i]]++;
    }
    map<char,int> :: const_iterator it;
    int bcnt=0,jcnt=0;
    for(it=data.begin();it!=data.end();it++)
    {
        if((it->second)%2) bcnt++;
        else jcnt++;
    }
    clr(dp,-1);
    if(bcnt<2) cout<<"First"<<endl;
    else
    {
        if(rec(bcnt,jcnt,0))
        {
            cout<<"First"<<endl;
        }
        else cout<<"Second"<<endl;
    }
    return 0;
}
