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
#define oo 0x3f3f3f3f
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
int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

const int MAX = 1050;

char mat[MAX][MAX];

int d[4][MAX][MAX];
bool vis[MAX][MAX];

int sd[4][4];
int n,m;

struct qnode
{
    int x,y,w;
    qnode() {}
    qnode(int x,int y,int w):x(x),y(y),w(w) {}
    bool operator < (const qnode &n) const
    {
        return w>n.w;
    }
};
priority_queue<qnode> Q;

void dfs(int x,int y,int id)
{
    if(vis[x][y]) return ;
    vis[x][y]=true;
    Q.push(qnode(x,y,0)); d[id][x][y]=0;
    sd[id][mat[x][y]-'0']=0;
    int nx,ny,k;
    for(int i=0;i<4;i++)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx<0||ny<0||nx==n||ny==m || mat[nx][ny]=='#' || mat[nx][ny]=='.') continue;
        dfs(nx,ny,id);
    }
    return ;
}

void bfs(int id,char cid)
{
    while(!Q.empty()) Q.pop();
    clrall(vis,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]==cid && !vis[i][j]) {
                dfs(i,j,id);
            }
        }
    }
    int x,y,nx,ny;
    while(!Q.empty()) {
        x=Q.top().x;
        y=Q.top().y;
        Q.pop();
        if(mat[x][y]!='.' && mat[x][y] !='#')
        {
            sd[id][mat[x][y]-'0']=min(sd[id][mat[x][y]-'0'],d[id][x][y]);
        }
        for(int i=0;i<4;i++)
        {
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx<0||ny<0||nx==n||ny==m) continue;
            if(mat[nx][ny]=='#' || d[id][nx][ny]<=d[id][x][y]+(mat[nx][ny]=='.')) continue;
            d[id][nx][ny]=d[id][x][y]+(mat[nx][ny]=='.');
            Q.push(qnode(nx,ny,d[id][nx][ny]));
        }
    }
    return ;
}

void print(int id)
{
    puts(":::::::::::::::::::::::::::");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(d[id][i][j]<oo) pf("%2d",d[id][i][j]);
            else pf("%2d",-1);
        }
        puts("");
    }
    puts(":::::::::::::::::::::::::::");
    return ;
}

int solve()
{
    int ret=oo;
    for(int i=1;i<4;i++)
        for(int j=i+1;j<4;j++)
            if(sd[i][j]>=oo) return -1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]=='#') continue;
            for(int a=1;a<4;a++)
            {
                for(int b=1;b<4;b++)
                {
                    for(int c=1;c<4;c++)
                    {
                        if(a==b || b==c || a==c) continue;
                        if(d[a][i][j]>=oo || d[b][i][j]>=oo || d[c][i][j]>=oo) continue;
                        ret=min(ret,(d[a][i][j]+d[b][i][j]-(mat[i][j]=='.'))+d[c][i][j]-(mat[i][j]=='.'));
                    }
                }
            }
        }
    }
    return ret;
}

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif
    clrall(d,oo);
    clrall(sd,oo);
    for(int i=0;i<4;i++) sd[i][i]=0;
    sf("%d %d",&n,&m);
    for(int i=0;i<n;i++) sf(" %s",&mat[i]);
    for(int i=1;i<4;i++) bfs(i,i+'0');
//    for(int i=1;i<4;i++) print(i);
    int ret = solve();
    pf("%d\n",ret);
    return 0;
}


/**
4 4
1...
.222
....
...3
*/











