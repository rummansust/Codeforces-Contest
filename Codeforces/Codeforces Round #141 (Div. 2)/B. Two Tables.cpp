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
#define pb(b) push_back(b)
#define oo 100000000000000000LL
#define swap(x,y) {int t;t=x;x=y;y=t;}
#define for_i(s,n) for(int i=s;i<n;i++)
#define for_j(s,n) for(int j=s;j<n;j++)
#define for_k(s,n) for(int k=s;k<n;k++)
#define MAX 52
///next_permutation  next_permutation (s.begin(),s.end())
///reverse(a,a+n);
///binary_search(first,last);
///vector erase v.erase(v.begin()+position);
///map map<int , int > data;
///map clear  data.clear();
///map iterator>>>> map <int,vector <int> >::const_iterator it;
///find an element in map (colour.find(nd)==colour.end());//if it return true this
///mean the element is'nt in the map.
///pass a vector to a funtion: funtion (vector <data type> *vector name);

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
    string a[MAX],b[MAX],s;
    ll ar,ac,br,bc,x,y;
    cin>>ar>>ac;
    for(ll i=0;i<ar;i++)
    {
        s.clear();
        cin>>s;
        a[i]=s;
    }
    cin>>br>>bc;
    for(ll i=0;i<br;i++)
    {
        s.clear();
        cin>>s;
        b[i]=s;
    }
    ll val=0L;
    for(ll p=-50; p<=50; p++)
    {
        for(ll q=-50; q<=50; q++)
        {
            ll sum=0L;
            for(ll i=0; i<ar; i++)
            {
                for(ll j=0; j<ac; j++)
                {
                    if((i+p>-1&&i+p<br)&&(j+q>-1&&j+q<bc))
                    {
//                        cout<<"->>>"<<a[i][j]<<" "<<b[i+p][j+q]<<endl;
                        sum+=(a[i][j]-'0')*(b[i+p][j+q]-'0');
                    }
                }
            }
//            cout<<sum<<":"<<" p: "<<p<<" q: "<<q<<endl;
            if(val<sum)
            {
//                cout<<"hello "<<val<<" "<<sum<<endl;
                val=sum;
                x=p;y=q;
            }
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
