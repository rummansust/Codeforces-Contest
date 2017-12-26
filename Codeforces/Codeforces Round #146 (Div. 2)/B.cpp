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
#define MAX 1050
#define SZ 530
#define MX 1000005

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

bool sieve[MAX];
int prime[SZ];
ll data[MX];
void sieve_fun()
{
    int k=-1,r;
    prime[++k]=2;
    for(int i=3;i<MAX;i+=2)
    {
        if(!sieve[i])
        {
            prime[++k]=i;
            r=i<<1;
            if(i<MAX/i)
            {
                for(int j=i*i;j<MAX;j+=r)
                sieve[i]=true;
            }
        }
    }
    return;
}

int pre_call(int n)
{
    int sq=sqrt(n)+1,sum=1,cnt;
    for(int i=0;prime[i]<sq;i++)
    {
        if(!(n%prime[i]))
        {
            cnt=1;
            while(!(n%prime[i]))
            {
                n/=prime[i];
                cnt++;
            }
            sum*=cnt;
        }
        sq=sqrt(n)+1;
    }
    if(n>1) sum=sum<<1;
    return sum;
}

int main()
{
    sieve_fun();
    ll sum=0L,a,b,c,cnt=0L;
    clr(data,0L);
    cin>>a>>b>>c;
    for(ll i=1L;i<=a;i++)
    {
        for(ll j=1L;j<=b;j++)
        {
            ll q=i*j;
            for(ll k=1L;k<=c;k++)
            {
                ll p=q*k;
                if(!data[p])
                {
                    data[p]=pre_call(p);
                    sum+=data[p];
                }
                else
                sum+=data[p];
            }
        }
    }
    cout<<(sum%1073741824L)<<endl;
    return 0;
}
