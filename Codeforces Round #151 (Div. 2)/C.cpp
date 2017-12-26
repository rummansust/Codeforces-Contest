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

vector<int> v[1300];

map<ll,int> data;

int main()
{
    int n,arr[100],m,pos;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(i<m)
        {
            v[i].psb(arr[i]);
            data[arr[i]]=0;
            pos=i;
        }
    }
    pos++;
    bool flag=false;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            ll sum=0L;
            for(int k=i; k<=j; k++)
            {
                sum+=(ll) arr[k];
            }
            if(data.find(sum)==data.end())
            {
                for(int k=i; k<=j; k++)
                {
                    if(pos<m)
                        v[pos].psb(arr[k]);
                    else
                    {
                        flag=true;
                        break;
                    }
                }
                pos++;
                data[sum]=0;
            }
            if(flag) break;
        }
        if(flag) break;
    }
    for(int i=0; i<m; i++)
    {
        cout<<v[i].size();
        for(int j=0; j<v[i].size(); j++)
        {
            cout<<" "<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}
