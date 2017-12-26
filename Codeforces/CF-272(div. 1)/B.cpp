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

struct data
{
    int a,b,c,d;
    data(){}
    data(int a,int b,int c,int d):a(a),b(b),c(c),d(d) {}
};

const int MAX = 100500;

data info[MAX];

int main()
{
    __;
    int n,k;
    cin>>n>>k;
    info[0]=data(1,2,3,5);
    int mx;
    for(int i=1;i<n;i++)
    {
        info[i]=data(info[i-1].a+6,info[i-1].b+6,info[i-1].c+6,info[i-1].d+6);
    }
    mx=info[n-1].d*k;
    cout<<mx<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<info[i].a*k<<" "<<info[i].b*k<<" "<<info[i].c*k<<" "<<info[i].d*k<<"\n";
    }
    return 0;
}


















