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

int A[101000];

int main()
{
    __;
    int n;
    int k;
    while(cin>>n>>k)
    {
        if(k==1)
        {
            for(int i=n; i>0; i--)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
            continue;
        }
        else
        {
            int d=n-k;
            for(int i=n,j=1,jj=1,ii=n; i>0; i-=2,j+=2,jj++,ii--)
            {
                A[j]=ii;
                A[j+1]=jj;
            }
            for(int i=1; i<=k; i++)
            {
                cout<<A[i]<<" ";
            }
            if(k%2==0)
            {
                for(int i=A[k]+1; i<(n-k)+A[k]+1; i++)
                    cout<<i<<" ";
            }
            else
            {
                for(int i=A[k]-1; i>A[k]-1-(n-k); i--)
                    cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}


















