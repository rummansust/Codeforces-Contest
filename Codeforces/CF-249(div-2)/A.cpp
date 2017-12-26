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
    int n,m,v;
    vector<int> val;
    cin>>n>>m;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v;
        val.psb(v);
        sum+=val[i];
    }
    int cap,bus=0;
    while(sum>0)
    {
        cap=m;
        for(int i=0;i<SZ(val);i++)
        {
            if(val[i])
            {
                if(cap>=val[i]) cap-=val[i],val[i]=0;
                else break;
            }
        }
        sum-=m-cap;
        bus++;
    }
    cout<<bus<<endl;
    return 0;
}


















