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
#define Write freopen("out1.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const int MAX = 1000005;

vector<int> mvec;
bool M[MAX];

int main()
{
    #ifdef rumman
    Read;
    Write;
    #endif // rumman
    int n,v;
    int ans=0,p=0;
    int i,j;
    SF("%d",&n);
    for(i=0;i<n;i++)
    {
        SF("%d",&v);
        if(M[v]) continue;
        M[v]=true;
        mvec.psb(v);
        p=max(v,p);
    }
    sort(all(mvec));
    int k,ii,jj,flag,ss=SZ(mvec);
    vector<int> :: const_iterator s=mvec.begin(),e=mvec.end();
    for(i=0;i<ss;i++)
    {
        ii=mvec[i];
        for(k=(ii<<1) ; k <= p+ii ;k += ii)
        {
            j=lower_bound(s,e,k)-s;
            j--;
            if(j<0) continue;
            jj=mvec[j];
            if(ii<=jj) ans=max(ans,(jj%ii));
            if(jj==p) break;
        }
    }
    PF("%d\n",ans);
    return 0;
}


















