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
#define clrall(name,val) memset(name,(val),sizeof(name))
#define EPS 1e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define inf 0x3f3f3f3f
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false),cin.tie(0),cout.tie(0)

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

ll BigModML(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=MulModL(R,B,M); } P/=2; B=MulModL(B,B,M); } return R; } /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<"\n";}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
const int MAX = 54;

int mat[MAX][MAX];

char grd[MAX][MAX];

int flag[MAX][MAX];


vector<pair<int,pair<int,int> > > info;

int com,n,m;

void dfs(int x,int y)
{
    if(x<0||x==n||y<0||y==m||grd[x][y]=='*') return ;
    if(flag[x][y]) return ;
    flag[x][y]=1;
    com++;
    for(int i=0;i<4;i++)
    {
        dfs(x+dx[i],y+dy[i]);
    }
    return ;
}

void dfs2(int x,int y)
{
    if(x<0||x==n||y<0||y==m||grd[x][y]=='*') return ;
    grd[x][y]='*';
    for(int i=0;i<4;i++)
    {
        dfs2(x+dx[i],y+dy[i]);
    }
    return ;
}


int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    int k;
    sf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++) sf("%s",&grd[i]);
    for(int i=0;i<n;i++)
    {
        if(grd[i][0]=='.'&&flag[i][0]==0)
        {
            com=0;
            dfs(i,0);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(grd[i][m-1]=='.'&&flag[i][m-1]==0)
        {
            com=0;
            dfs(i,m-1);
        }
    }
    for(int i=0;i<m;i++)
    {
        if(grd[0][i]=='.'&&flag[0][i]==0)
        {
            com=0;
            dfs(0,i);
        }
    }
    for(int i=0;i<m;i++)
    {
        if(grd[n-1][i]=='.'&&flag[n-1][i]==0)
        {
            com=0;
            dfs(n-1,i);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grd[i][j]=='.'&&flag[i][j]==0)
            {
                com=0;
                dfs(i,j);
                info.psb(mp(com,mp(i,j)));
            }
        }
    }
    sort(all(info));
    int p=SZ(info)-k;
    int res=0;
    for(int i=0;i<p;i++)
    {
        res+=info[i].fs;
        dfs2(info[i].sc.fs,info[i].sc.sc);
    }
    pf("%d\n",res);
    for(int i=0;i<n;i++) pf("%s\n",grd[i]);
    return 0;
}














