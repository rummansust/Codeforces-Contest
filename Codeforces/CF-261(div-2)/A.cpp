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
    int a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1!=a2 && b1!=b2)
    {
        if(abs(a2-a1) != abs(b2-b1))
        {
            cout<<-1<<endl;
            return 0;
        }
        cout<<a1<<" "<<b2<<" "<<a2<<" "<<b1<<endl;
    }
    else if(a1==a2)
    {
        cout<<a1+abs(b1-b2)<<" "<<b1<<" "<<a2+abs(b1-b2)<<" "<<b2<<endl;
    }
    else

    {
        cout<<a1<<" "<<b1+abs(a1-a2)<<" "<<a2<<" "<<b2+abs(a1-a2)<<endl;
    }
    return 0;
}


















