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

ll val[500000];
ll a[500000];
ll b[500000];
int par[500000];

int main()
{
    __;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    if(m==1)
    {
        cout<<n<<endl;
        return 0;
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    int k=0;

    for(int i=1;i<m;i++)
    {
        val[k++]=b[i]-b[i-1];
    }
    val[k++]=10e16;
    for(int i=1;i<n;i++)
    {
        val[k++]=a[i]-a[i-1];
    }
    int p=0;
    par[0]=0;
    int cnt=0;
    for(int i=1;i<k;i++)
    {
        while(p>0&&val[i]!=val[p]) p=par[p-1];
        if(val[i]==val[p]) p++;
        par[i]=p;
        if(p>=m-1) cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}


















