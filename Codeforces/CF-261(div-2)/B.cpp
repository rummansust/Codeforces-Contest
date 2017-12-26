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

map<int,int> id;
vector<int> beauty;
map<int,int> tmp;

ll check(int n,int mid)
{
    ll cnt=0;
    int findv;
    for(int i=0;i<n;i++)
    {
        if(tmp.find(beauty[i])!=tmp.end()) continue;
        findv=beauty[i]-mid;
        if(id.find(findv)!=id.end() && tmp.find(findv)==tmp.end())
        {
            if(findv!=beauty[i])
            {
                cnt+=( (ll) id[findv] * (ll) id[beauty[i] ]);
            }
            else
            {
                cnt+=( (ll) id[findv]*((ll) id[findv] - 1LL)  ) / 2LL;
            }
            tmp[beauty[i] ]=1;
            tmp[findv ]=1;
        }
        findv=beauty[i]+mid;
        if(id.find(findv)!=id.end() && tmp.find(findv)==tmp.end())
        {
            if(findv!=beauty[i])
            {
                cnt+=( (ll) id[findv] * (ll) id[beauty[i] ]);
            }
            else
            {
                cnt+=( (ll) id[findv]*((ll) id[findv] - 1LL)  ) / 2LL;
            }
            tmp[beauty[i] ]=1;
            tmp[findv ]=1;
        }
    }
    return cnt;
}

int main()
{
    int lb=0,ub=1000000009;
    int n;
    int val;
    SF("%d",&n);
    for(int i=0;i<n;i++)
    {
        SF("%d",&val);
        beauty.psb(val);
        id[val]++;
    }
    sort(beauty.begin(),beauty.end());
    int dif=beauty[n-1]-beauty[0];
    ll ret=check(n,dif);
    cout<<dif<<" "<<ret<<endl;
    return 0;
}


















