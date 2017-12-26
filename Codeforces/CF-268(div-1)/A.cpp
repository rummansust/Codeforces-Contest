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
    int n;
    while(cin>>n)
    {
        bool flag=false;
        if(n<4)
        {
            cout<<"NO\n";
            continue;
        }
        if(n==4)
        {
            cout<<"YES\n";
            cout<<"1 * 2 = 2\n";
            cout<<"2 * 3 = 6\n";
            cout<<"6 * 4 = 24\n";
            continue;
        }
        cout<<"YES\n";
        if((n&1)==0)
        {

            cout<<"1 * 2 = 2\n";
            cout<<"2 * 3 = 6\n";
            cout<<"6 * 4 = 24\n";
            int cnt=0;
            for(int i=5;i<n;i+=2)
            {
                cout<<i+1<<" - "<<i<<" = "<<"1\n";
                flag=true;
                cnt++;
            }
            for(int i=1;i<cnt;i++)
            {
                cout<<"1 * 1 = 1\n";
            }
            if(flag)
            cout<<"24 * 1 = 24\n";
        }
        else
        {
            cout<<"5 - 2 = 3\n";
            cout<<"3 - 1 = 2\n";
            cout<<"2 * 3 = 6\n";
            cout<<"6 * 4 = 24\n";
            int cnt=0;
            for(int i=6;i<n;i+=2)
            {
                cout<<i+1<<" - "<<i<<" = "<<"1\n";
                flag=true;
                cnt++;
            }
            for(int i=1;i<cnt;i++)
            {
                cout<<"1 * 1 = 1\n";
            }
            if(flag)
            cout<<"24 * 1 = 24\n";

        }
    }
    return 0;
}


















