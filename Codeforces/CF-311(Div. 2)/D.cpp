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
#define SF scanf
#define PF printf
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

const int MAX = 100009;

vector<int> adj[MAX];

int col[MAX];

bool bfs(int u,ll &cnt,ll &zer,ll &one)
{
    int v;
    col[u]=0;
    cnt=1;
    zer=1;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(int i=0;i<SZ(adj[u]);i++)
        {
            v=adj[u][i];
            if(col[v]==-1)
            {
                col[v]=!col[u];
                if(col[v]) one++;
                else zer++;
                Q.push(v);
                cnt++;
            }
            else if(col[u]==col[v]) return true;
        }
    }
    return false;
}

int main()
{
    ll n,m;
    int u,v;
    SF("%I64d %I64d",&n,&m);
    if(m==0)
    {
        PF("3 %I64d\n",(n*(n-1)*(n-2))/6);
    }
    else
    {
        while(m--)
        {
            SF("%d %d",&u,&v);
            adj[u].psb(v);
            adj[v].psb(u);
        }
        clrall(col,-1);
        bool flag=false;
        ll O=0,T=0,mxN=0;
        ll res=0;

        for(int i=1;i<=n;i++)
        {
            if(col[i]==-1)
            {
                ll cnt=0;
                ll zer=0,one=0;
                flag=bfs(i,cnt,zer,one);
                if(flag) break;
                mxN=max(mxN,cnt);
                if(cnt==1) O++;
                else if(cnt==2) T++;
                else res+=(zer*(zer-1))/2 + (one*(one-1))/2;
            }
        }
        if(flag)
        {
            PF("0 1\n");
        }
        else if(mxN==2)
        {
            PF("2 %I64d\n",2*T*(T-1) + T*O);
        }
        else
        {
            PF("1 %I64d\n",res);
        }
    }
    return 0;
}


/**
11 11
1 2
1 3
2 4
3 4
4 5
5 6
6 3
7 8
8 9
9 10
10 11
*/










