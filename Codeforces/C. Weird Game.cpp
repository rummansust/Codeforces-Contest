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
    string s,t;
    int same=0,ss=0,tt=0,n;
    cin>>n;
    cin>>s>>t;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==t[i]&&s[i]=='1') same++;
        if(s[i]=='1') ss++;
        if(t[i]=='1') tt++;
    }
    ss-=(same)/2;
    tt-=(same+1)/2;
    if(ss<tt) tt-=((tt-ss)+1)/2;
    if(ss>tt) cout<<"First"<<endl;
    else if(tt>ss) cout<<"Second"<<endl;
    else cout<<"Draw"<<endl;
    return 0;
}






