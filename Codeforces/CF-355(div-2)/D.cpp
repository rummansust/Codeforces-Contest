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

typedef pair<int,int> pii;

const int MAX = 305;

vector<pii > adj[MAX*MAX];

int dp[2][MAX][MAX];
int mat[MAX][MAX];

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    int n,m,p;
    sf("%d %d %d",&n,&m,&p);
    int pre=1,cur=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sf("%d",&mat[i][j]);
            adj[mat[i][j]].psb(mp(i,j));
            if(mat[i][j]==1)
            {
                dp[pre][i][j]=i+j;
            }
        }
    }
    int x,y,a,b,res;
    for(int i=2;i<=p;i++)
    {
        for(int j=0;j<SZ(adj[i]);j++)
        {
            x=adj[i][j].fs;
            y=adj[i][j].sc;
            dp[cur][x][y]=INT_MAX;
            for(int k=0;k<SZ(adj[i-1]);k++)
            {
                a=adj[i-1][k].fs;
                b=adj[i-1][k].sc;
                dp[cur][x][y]=min(dp[cur][x][y],dp[pre][a][b]+abs(x-a)+abs(y-b));
            }
        }
        swap(pre,cur);
    }
    res=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==p)
            {
                res=dp[pre][i][j];
                break;
            }
        }
        if(res!=-1) break;
    }
    pf("%d\n",res);
    return 0;
}








