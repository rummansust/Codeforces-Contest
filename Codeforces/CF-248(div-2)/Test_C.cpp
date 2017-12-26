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
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outT.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector <int> p[100005];
int a[100005];

int main()
{
    Read;
    Write;
    int n,m;
    while(cin>>n>>m)
    {
        rep(i,n+1)p[i].clear();
        rep(i,m)cin>>a[i];
        long long ans = 0;
        for(int i=1;i<m;i++)
            ans += abs(a[i]-a[i-1]);
        for(int i=0;i<m;i++)
        {
            if(i!=0 && a[i]!=a[i-1])
                p[a[i]].push_back(a[i-1]);
            if(i!=m-1 && a[i]!=a[i+1])
                p[a[i]].push_back(a[i+1]);
        }
        long long ret = ans;
        for(int i=1;i<=n;i++)
        {
            if(p[i].size() > 0)
            {
                sort(p[i].begin(),p[i].end());
                int tmp = p[i][p[i].size()/2];
                long long na = ans;
                for(int j=0;j<p[i].size();j++)
                    na = na - abs(i-p[i][j]) + abs(tmp-p[i][j]);
                ret = min(ret,na);
            }
        }
        cout << ret << endl;
    }
}
