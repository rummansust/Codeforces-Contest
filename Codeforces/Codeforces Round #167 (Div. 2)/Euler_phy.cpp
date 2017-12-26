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
#define MAX 201001

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

unsigned long long EP[MAX],CEP[MAX];
bool sieve[MAX];

void sieve_fun()
{
    int n=MAX;
    for(int i=1;i<n;i++) EP[i]=i;
    for(int i=2;i<n;i++)
    {
        if(!sieve[i])
        {
            EP[i]--;
            if(i<n/i)
            {
                for(int j=(i<<1);j<n;j+=i)
                {
                    sieve[j]=true;
                    EP[j]=(EP[j]*(i-1))/i;
                }
            }
        }
    }
    return ;
}

void csum()
{
    int n=MAX;
    for(int i=1;i<n;i++)
    {
        for(int j=(i<<1);j<n;j+=i)
        {
            CEP[j]+=(i*EP[j/i]);
        }
    }
    return ;
}

int main()
{
    write_;
    int x;
    sieve_fun();
    csum();
    for(int x=898;x<899;x++)
    {
        ll res=0;
        for(int i=2;i<=x;i++) res+=CEP[i],cout<<CEP[i]<<endl;
        cout<<res<<" "<<x;
    }
    return 0;
}
