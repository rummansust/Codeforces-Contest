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

int main()
{
    int n;
    ll x,y;
    cin>>n;
    ll mnx,mny,mxx,mxy;
    cin>>x>>y;
    mnx=mxx=x;
    mny=mxy=y;
    n--;
    while(n--)
    {
        cin>>x>>y;
        mxx=max(x,mxx);
        mxy=max(y,mxy);
        mnx=min(x,mnx);
        mny=min(y,mny);
    }
    ll xx=mxx-mnx;
    ll yy=mxy-mny;
    ll mm=max(xx,yy);
    ll res=mm*mm;
    cout<<res<<"\n";
    return 0;
}


















