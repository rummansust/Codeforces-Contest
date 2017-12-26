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

const int MAXN = 101000;

struct data
{
    int fs,sc,idx;
    data(){}
    data(int f,int s,int i):fs(f),sc(s),idx(i) {}
};

vector<data> adj[MAXN];
pair<int,int> dist[MAXN];
pair<int,int> par[MAXN];
int child[MAXN];
map<pair<int,int> ,int> mpp;


int main()
{
    int n,m,u,v,c,zero=0,one=0,k1,k2;
    SF("%d %d",&n,&m);
    clrall(dist,-1);
    while(m--)
    {
        SF("%d %d %d",&u,&v,&c);
        k1=SZ(adj[v]);
        k2=SZ(adj[u]);
        adj[u].psb(data(v,c,k1));
        adj[v].psb(data(u,c,k2));
        zero+=(!c);
        one+=(c);
    }
    queue<int> Q;
    dist[1]=mp(0,0);
    par[1]=mp(-1,-1);
    Q.push(1);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(int i=0;i<SZ(adj[u]);i++)
        {
            v=adj[u][i].fs;
            c=adj[u][i].sc;
            if(dist[v].fs==-1 || dist[v].fs>dist[u].fs+1)
            {
                dist[v].fs=dist[u].fs+1;
                dist[v].sc=dist[u].sc+(!c);
                Q.push(v);
                par[v]=mp(u,i);
            }
            else if(dist[v].fs==dist[u].fs+1)
            {
                if(dist[v].sc>dist[u].sc+(!c))
                {
                    dist[v].sc=dist[u].sc+(!c);
                    Q.push(v);
                    par[v]=mp(u,i);
                }
            }
        }
    }
    int tot=(2*dist[n].sc+one-dist[n].fs);
    PF("%d\n",tot);
    int from,to,pidx,cidx;
    from=n;
    while(from!=1)
    {
        to=par[from].fs;
        pidx=par[from].sc;
        cidx=adj[to][pidx].idx;
        c=adj[to][pidx].sc+2;
        adj[to][pidx].sc=c;
        adj[from][cidx].sc=c;
        from=to;
    }
    for(int u=1;u<=n;u++)
    {
        for(int i=0;i<SZ(adj[u]);i++)
        {
            v=adj[u][i].fs;
            c=adj[u][i].sc;
            if(c==2||c==1)
            {
                if(!mpp.count(mp(u,v)) && !mpp.count(mp(v,u)))
                {
                    mpp[mp(u,v)]=(!(c-2));
                }
            }
        }
    }
    for(map<pair<int,int>,int>::const_iterator it=mpp.begin(); it!=mpp.end(); it++ )
    {
        PF("%d %d %d\n",(it->fs).fs,(it->fs).sc,(it->sc));
    }
    return 0;
}












