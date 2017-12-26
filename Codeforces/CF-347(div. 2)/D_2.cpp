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
#include <utility>
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
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
#define MAX          100055  //number of nodes(yes/no nodes)

int vis[MAX],n,m;

vector<pair<int,int> > elist[MAX];
vector<int> part[3];
vector<int> ans;

bool dfs(int u,int s,int c)
{
    if(vis[u]) return vis[u]==s;
    vis[u]=s;
    part[s].psb(u+1);
    int v,cl;
    for(int i=0;i<SZ(elist[u]);i++)
    {
        v=elist[u][i].fs;
        cl=elist[u][i].sc;
        if(!dfs(v,cl==c?s:s^3,c)) return false;
    }
    return true;
}

bool solve(int c)
{
    int p;
    ans.clear();
    clrall(vis,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        part[1].clear();
        part[2].clear();
        if(!dfs(i,1,c)) return false;
        p=1;
        if(SZ(part[1])>SZ(part[2])) p=2;
        ans.insert(ans.end(),part[p].begin(),part[p].end());
    }
    return true;
}

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    sf("%d %d",&n,&m);
    int u,v,cl;
    char c;
    for (int i=0;i<m ; i++)
    {
        sf(" %d %d %c",&u,&v,&c);
        u--;    v--;
        cl=(c=='B');
        elist[u].psb(mp(v,cl));
        elist[v].psb(mp(u,cl));
    }
    int r=-1;
    vector<int> res;
    if(solve(0))
    {
        res=ans;
        r=SZ(res);
    }
    if(solve(1))
    {
        if(r==-1 || SZ(res)>SZ(ans))
        {
            res=ans;
            r=SZ(res);
        }
    }
    pf("%d\n",r);
    for(int i=0;i<SZ(res);i++)
    {
        pf("%d%c",res[i]," \n"[r==i+1]);
    }
    return 0;
}










