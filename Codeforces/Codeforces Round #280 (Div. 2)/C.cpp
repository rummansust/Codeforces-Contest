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

#define MAX 110000

pair<ll,ll> val[MAX];

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    ll n,r,avg,tot=0;
    __;
    cin>>n>>r>>avg;
    ll a,b;
    for(int i=0;i<n;i++)
    {
        cin>>val[i].sc>>val[i].fs;
        tot+=val[i].sc;
    }
    if(tot>=avg*n)
    {
        cout<<0<<"\n";
        return 0;
    }
    sort(val,val+n);
    ll cost=0,rem=avg*n-tot,have;
    for(int i=0;i<n;i++)
    {
        have=min(rem,r-val[i].sc);
        cost+=val[i].fs*have;
        rem-=have;
    }
    cout<<cost<<"\n";
    return 0;
}

















