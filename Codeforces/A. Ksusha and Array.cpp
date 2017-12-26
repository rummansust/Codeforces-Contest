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
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)


using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    int arr[300010];
    arr[0]=1;
    for(int i=1;i<str.size();i++)
    {
        if(str[i]=='.')
        arr[i]=arr[i-1]+1;
        else arr[i]=arr[i-1];
    }
    for(int i=k;i<str.size();i++)
    {
        if(str[i]=='.')
        {
            int dif=((i-k)-1<0)?arr[i]-1:arr[i]-arr[(i-k)-1]-1;
            if(!dif)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}












