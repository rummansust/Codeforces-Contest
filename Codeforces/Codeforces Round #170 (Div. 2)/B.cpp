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

string sol;
bool flag;
vector<char> v;
map<string,int> data;

bool comp(string a,string b)
{
    if(a.size()==b.size()) return a<b;
    else return a.size()<b.size();
}

void rec(int n,int pos)
{
    if(pos==n)
    {
        string s;
        for(int i=0;i<v.size();i++)
        {
            s+=v[i];
        }
        if(data.find(s)==data.end())
        {
            sol=s;
            flag=false;
        }
        return ;
    }
    if(flag)
    {
        for(int i=0;i<26;i++)
        {
            v.psb((char)('a'+i));
            if(flag)
            rec(n,pos+1);
            v.ppb();
        }
    }
    return ;
}

int main()
{
    int n=0;
    string s,ts;
    cin>>n;
    for(int k=0; k<n; k++)
    {
        cin>>s;
        for(int i=0; i<s.size(); i++)
        {
            for(int j=i,l=1; j<s.size(); j++,l++)
            {
                if(data.find(s.substr(i,l))==data.end())
                {
                    data[s.substr(i,l)]++;
                }
            }
        }
    }
    flag=true;
    for(int i=1;flag==true;i++)
    {
        flag=true;
        rec(i,0);
    }
    cout<<sol<<endl;
    return 0;
}
