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
    __;
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> val;
    int t;
    for(int i=1;i<=m+1;i++)
    {
        cin>>t;
        val.psb(t);
    }
    int kaboom;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        t=val[i-1];
        kaboom=val[m];
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(((t>>i)&1) != ((kaboom>>i)&1)) p++;
        }
        if(p<=k) cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}


















