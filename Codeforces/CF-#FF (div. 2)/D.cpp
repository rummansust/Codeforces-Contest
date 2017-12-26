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

priority_queue<int> row,col;

const int MAX = 1050;

ll ansRow[MAX*MAX],ansCol[MAX*MAX];
ll sumRow[MAX],sumCol[MAX];

ll preCal[MAX*MAX];

ll grid[MAX][MAX];

int main()
{
    ll n,m,k,p;
    cin>>n>>m>>k>>p;
    for(ll i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            SF("%I64d",&grid[i][j]);
            sumCol[j]+=grid[i][j];
            sumRow[i]+=grid[i][j];
        }
    }
    for(ll i=1;i<=n;i++)
    {
        row.push(sumRow[i]);
    }
    for(ll i=1;i<=m;i++)
    {
        col.push(sumCol[i]);
    }
    ll best;
    for(ll i=1;i<=k;i++)
    {
        best=row.top();
        row.pop();
        ansRow[i]=best+ansRow[i-1];
        best-=m*p;
        row.push(best);
    }
    for(ll i=1;i<=k;i++)
    {
        best=col.top();
        col.pop();
        ansCol[i]=best+ansCol[i-1];
        best-=n*p;
        col.push(best);
    }
    preCal[k+1]=-(ll) INFINITY;
    for(ll i=0;i<=k;i++)
    {
        preCal[i]=(ansRow[i]+ansCol[k-i]) - (i)*(k-i)*p;
        preCal[k+1]=max(preCal[k+1],preCal[i]);
    }
    sort(preCal,preCal+k+1);
    cout<<preCal[k+1]<<endl;
    return 0;
}
/*
2 2 5 2
1 3
2 4
*/












