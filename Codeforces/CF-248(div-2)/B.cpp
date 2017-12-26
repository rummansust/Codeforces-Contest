#include <bits/stdc++.h>

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
#define oo (1<<29)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outE.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const int MAX = 100008;

ll val[MAX],type[MAX][2];

int main()
{
    int n;
    SF("%d",&n);
    for (int i=1;i<=n ;i++ )
    {
        SF("%I64d",&val[i]);
        type[i][0]=val[i]+type[i-1][0];
    }
    sort(val+1,val+n+1);
    for (int i=1;i<=n ;i++ )
    {
        type[i][1]=val[i]+type[i-1][1];
    }
    int t,l,r;
    SF("%d",&n);
    while(n--)
    {
        SF("%d %d %d",&t,&l,&r);
        t--;
        PF("%I64d\n",type[r][t]-type[l-1][t]);
    }
    return 0;
}


















