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
    char mat[200][200];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        mat[i][j]='*';
        int mid=(n+1)/2;
    for(int i=1;i<=n;i++)
    {
        int st,en;
        if(i<=mid)
        st=mid-i+1,en=mid+i-1;
        else st=mid-(n-i),en=mid+(n-i);
        for(;st<=en;st++) mat[i][st]='D';
        for(int j=1;j<=n;j++) PF("%c",mat[i][j]);
        puts("");
    }
    return 0;
}


















