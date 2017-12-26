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

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    int n,l;
    int mx=0;
    vector<int> v;
    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.psb(k);

    }
    sort(all(v));
    for(int i=1;i<SZ(v);i++)
    {
        mx=max(mx,(v[i]-v[i-1]));
    }
    mx=max(2*v[0],mx);
    mx=max(2*l-2*v[n-1],mx);
    PF("%.12lf\n",mx/2.0);
    return 0;
}

















