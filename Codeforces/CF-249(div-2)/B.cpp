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
#define Write freopen("outM.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

int main()
{
    #ifdef rumman
    Read;
    Write;
    #endif // rumman
    string n;
    int k;
    while(cin>>n>>k)
    {
        for(int i=0;i<SZ(n);i++)
        {
            int mx=n[i],pos=i;
            for(int j=i+1;j<min(SZ(n),i+k+1);j++)
            {
                if(mx<n[j]) mx=n[j],pos=j;
            }
            if(pos-i<=k)
            {
                for(int j=pos;j>i;j--) swap(n[j],n[j-1]);
                k-=(pos-i);
            }
        }
        cout<<n<<endl;
    }
    return 0;
}


















