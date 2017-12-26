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
#define Write freopen("1206M.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

char mat[2005][2005];
int num[2005][2005];
int deg[2005*2005];

int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
vector<int> adj[2005*2005];

int matching[2005*2005];

int main()
{
    #ifdef MAHDI
    Read;
    Write;
    #endif // rumman
    string str[]={"><","<>","^v","v^"};
    int n,m;
    int i,j,k,ni,nj;
    clrall(matching,-1);
    SF("%d %d",&n,&m);
    int a=0,l=0,r=0,u,v,w;
    for(int i=0;i<n;i++)
    {
        SF("%s",&mat[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]!='*')
            {
                num[i][j]=a++;
                if((i+j)&1) l++;
                else r++;
            }
        }
    }
    if(l!=r)
    {
        PF("Not unique\n");
        return 0;
    }
    for( i=0;i<n;i++)
    {
        for( j=0;j<m;j++)
        {
            if(mat[i][j]=='*') continue;
            for( k=0;k<4;k++)
            {
                ni=i+dx[k];
                nj=j+dy[k];
                if(ni<0||ni==n||nj<0||nj==m||mat[ni][nj]=='*') continue;
                u=num[i][j];
                v=num[ni][nj];
                adj[u].psb(v);
                deg[u]++;
            }
        }
    }

    queue<int> Q;
    for( i=0;i<a;i++)
    {
        if(deg[i]==0)
        {
            PF("Not unique\n");
            return 0;
        }
        if(deg[i]==1)
        {
            Q.push(i);
        }
    }
    if(a && Q.empty())
    {
        PF("Not unique\n");
        return 0;
    }

    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        if(!deg[u]||matching[u]!=-1) continue;
        for( i=0;i<SZ(adj[u]);i++)
        {
            v=adj[u][i];
            if(deg[v]||matching[u]!=-1)
            {
                deg[v]=0;
                for( j=0;j<SZ(adj[v]);j++)
                {
                    w=adj[v][j];
                    if(w==u||matching[w]!=-1) continue;
                    if(deg[w]) deg[w]--;
                    if(deg[w]==0)
                    {
                        PF("Not unique\n");
                        return 0;
                    }
                    if(deg[w]==1)
                    {
                        Q.push(w);
                    }
                }
                matching[v]=u;
                matching[u]=v;
                a-=2;
                if(a==0) break;
                break;
            }
        }
        if(a==0) break;
    }
    if(a!=0)
    {
        PF("Not unique\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]!='.') continue;
            u=num[i][j];
            v=matching[u];
            for( k=0;k<4;k++)
            {
                ni=i+dx[k];
                nj=j+dy[k];
                if(ni<0||ni==n||nj<0||nj==m||mat[ni][nj]=='*') continue;
                if(num[ni][nj]==v)
                {
                    mat[i][j]=str[k][0];
                    mat[ni][nj]=str[k][1];
                    break;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        PF("%s\n",mat[i]);
    }
    return 0;
}
















