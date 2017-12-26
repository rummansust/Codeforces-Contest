#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

#define casePrint PF("Case #%d: ",++cas);

bool bin_s(ll lo,ll hi,ll x,ll y,ll k)
{
    ll i,j;
    while(lo<=hi)
    {
        i=(lo+hi)/2;
        j=((x*i)/y);// - (x*i)/(x*y);
        if(i+j==k) return true;
        if(i+j<k) lo=i+1;
        else hi=i-1;
    }
    return false;
}


int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    ll x,y,n,k;
    ll xx,yy;
    __;
    while(cin>>n>>x>>y)
    {
        xx=y/__gcd(x,y);
        yy=x/__gcd(x,y);
        while(n--)
        {
            cin>>k;
            if(k%(xx+yy)==0 || k%(xx+yy)==xx+yy-1)
            {
                PF("Both\n");
                continue;
            }
            if(bin_s(1,k,xx,yy,k))
            {
                PF("Vanya\n");
            }
            else if(bin_s(1,k,yy,xx,k))
            {
                PF("Vova\n");
            }
        }

    }
    return 0;
}

















