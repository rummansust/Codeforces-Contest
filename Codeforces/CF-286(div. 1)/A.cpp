#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

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
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)


ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

const int MAXN = 30000;

map<int,int> mpp[30100];
int mppp[30100][1010];
bool vis[30100][1010];
int col[30100];
int mx;
vector<int> val;

int dfs(int u,int prejump)
{
    if(u>mx) return 0;
    if(prejump<=0) return 0;
    if(mpp[u].find(prejump)!=mpp[u].end()) return mpp[u][prejump];
    mpp[u][prejump]=0;
    int ret=0,add=col[u];
    ret=max(ret,dfs(u+prejump,prejump)+add);
    ret=max(ret,dfs(u+prejump+1,prejump+1)+add);
    ret=max(ret,dfs(u+prejump-1,prejump-1)+add);
    return mpp[u][prejump]=ret;
}

int dfs2(int u,int prejump)
{
    if(u>mx) return 0;
    if(prejump<=0) return 0;
    if(vis[u][prejump]) return mppp[u][prejump];
    mppp[u][prejump]=0;
    vis[u][prejump]=1;
    int ret=0,add=col[u];
    ret=max(ret,dfs2(u+prejump,prejump)+add);
    ret=max(ret,dfs2(u+prejump+1,prejump+1)+add);
    ret=max(ret,dfs2(u+prejump-1,prejump-1)+add);
    return mppp[u][prejump]=ret;
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    int n,d,v;
    SF("%d %d",&n,&d);
    int cnt=0;

    for(int i=0;i<n;i++) SF("%d",&v),val.psb(v),mx=max(v,mx),col[v]++;
    if(d<=1000) cnt=dfs2(d,d);
    else cnt=dfs(d,d);
    PF("%d\n",cnt);
    return 0;
}



















