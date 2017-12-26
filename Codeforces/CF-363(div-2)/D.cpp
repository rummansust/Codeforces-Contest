#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define clr(name,val) memset(name,(val),sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 10000000
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)

using namespace std;
template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<"\n";}

const int MAX = 200009;
int par[MAX+5];
bool mark[MAX+5];
int vis[MAX+5];

int main()
{
    int n,u,v,w=-1,res=0,x=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&u);
        par[i]=u;
        if(u==i) w=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        v=i;
        vis[v]=1;
        u=par[i];
        while(u!=v&&vis[u]==0)
        {
            v=u;
            vis[v]=1;
            u=par[u];
        }
        if(vis[u]==1)
        {
            mark[v]=true;
            x=v;
        }
        v=i;
        vis[v]=2;
        u=par[i];
        while(u!=v&&vis[u]==1)
        {
            v=u;
            vis[v]=2;
            u=par[u];
        }
    }
    if(w!=-1)
    {
        for(int i=1;i<=n;i++)
        {
            if(mark[i]&&par[i]!=w)
            {
                res++;
                par[i]=w;
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(mark[i])
            {
                res++;
                par[i]=x;
            }
        }
    }
    printf("%d\n",res);
    for(int i=1;i<=n;i++)
    {
        printf("%d%c",par[i]," \n"[i==n]);
    }
    return 0;
}

/*
1
8 8
2 3 11
0 1 10
0 2 2
1 3 6
2 7 5
7 4 7
2 5 9
5 6 1
*/
