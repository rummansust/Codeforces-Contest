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

//0 based
vector<int> adj[2*MAX]; //2*MAX for true and false argument(only adj should be cleared)
int col[2*MAX],low[2*MAX],tim[2*MAX],timer;
int group_id[2*MAX],components;//components=number of components, group_id = which node belongs to which node
bool ans[MAX]; //boolean assignment ans
stack<int>S;

void scc(int u)
{
    int i,v,tem;
    col[u]=1;
    low[u]=tim[u]=timer++;
    S.push(u);
    for(i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(col[v]==1)
            low[u]=min(low[u],tim[v]);
        else if(col[v]==0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }

    //SCC checking...
    if(low[u]==tim[u])
    {
        do
        {
            tem=S.top();S.pop();
            group_id[tem]=components;
            col[tem]=2; //Completed...
        }while(tem!=u);
        components++;
    }
}

int TarjanSCC(int n) //n=nodes (some change may be required here)
{
    int i;
    timer=components=0;
    clrall(col,0);
    while(!S.empty()) S.pop();
    for(i=0;i<n;i++) if(col[i]==0) scc(i);
    return components;
}

//double nodes needed normally
bool TwoSAT(int n) //n=nodes (some change may be required here)
{
    TarjanSCC(n);
    int i;
    for(i=0;i<n;i+=2)
    {
        if(group_id[i]==group_id[i+1])
            return false;
        if(group_id[i]<group_id[i+1]) //Checking who is lower in Topological sort
            ans[i/2]=true;
        else ans[i/2]=false;
    }
    return true;
}

void add(int ina,int inb)
{
    adj[ina].psb(inb);
}

int complement(int n)
{
    return n^1;
}

void init(int n)
{
    for(int i=0;i<n;i++)
        adj[i].clear();
}

vector<pair<int,int> > elist[MAX];
int n,m;


int solve(int c,vector<int> &node)
{
    init(2*n);
    int s,u,v,cl,nu,nv;
    for(u=0;u<n;u++)
    {
        s=SZ(elist[u]);
        nu=2*u;
        for(int i=0;i<s;i++)
        {
            v=elist[u][i].fs;
            cl=elist[u][i].sc;
            nv=2*v;
            if(cl==c)
            {
                add(nu,nv);
                add(nu^1,nv^1);
            }
            else
            {
                add(nu,nv^1);
                add(nu^1,nv);
            }
        }
    }
    if(TwoSAT(2*n))
    {
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(ans[i])
            {
                res++;
                node.psb(i+1);
            }
        }
        return res;
    }
    return oo;
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
    vector<int> node[2],resv;
    int res1=solve(0,node[0]);
    int res2=solve(1,node[1]);
    resv=node[0];
    if(res1>res2) resv=node[1];
    int tot=SZ(resv);
    if(tot)
    {
        pf("%d\n",tot);
        for(int i=0;i<tot;i++)
        {
            pf("%d%c",resv[i]," \n"[i==tot-1]);
        }
    }
    else
    {
        pf("-1\n");
    }
    return 0;
}










