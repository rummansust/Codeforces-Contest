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
#define oo (1ll<<60)
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
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

int EQ(long double x) {
    if(fabs(x)<EPS) return 0;
    else if(x>0) return 1;
    else return -1;
}

const int MAX = 205000;

ll sum[MAX];
ll sum2[MAX];
ll val[MAX];
vector<int> adj[MAX];

int st[MAX];
int en[MAX];

int tim=0,n;

ll segment[MAX*8];

ll build_segment_tree(int ind,int Q1,int Q2)
{
    if(Q1==Q2)
    {
        segment[ind]=sum2[Q1];
        return segment[ind];
    }
    ll p=build_segment_tree(2*ind,Q1,(Q1+Q2)/2);
    ll q=build_segment_tree(2*ind+1,((Q1+Q2)/2)+1,Q2);
    segment[ind]=max(p,q);
    return segment[ind];
}

ll update(int ind,int Q1,int Q2,int p,ll v)
{
    if(Q1==Q2)
    {
        segment[ind]=v;
        return segment[ind];
    }
    ll q;
    if(p<=(Q1+Q2)/2) q=update(2*ind,Q1,(Q1+Q2)/2,p,v);
    else q=update(2*ind+1,((Q1+Q2)/2)+1,Q2,p,v);
    segment[ind]=q;
    return segment[ind];
}

ll find_query_min(int ind,int left,int right,int Q1,int Q2)
{
    if(left>Q2||right<Q1||left>right) return -oo;
    if(left>=Q1&&right<=Q2) return segment[ind];
    int mid=(left+right)/2;
    ll p=find_query_min(ind*2,left,mid,Q1,Q2);
    ll q=find_query_min(ind*2+1,mid+1,right,Q1,Q2);
    return max(p,q);
}

void dfs1(int u,int p)
{
    tim++;
    st[u]=tim;
    sum[u]+=val[u];
    int m=SZ(adj[u]),v;
    for (int i=0;i<m;i++)
    {
        v=adj[u][i];
        if(v==p) continue;
        dfs1(v,u);
        sum[u]+=sum[v];
    }
    en[u]=tim;
    return ;
}

ll res;

void dfs2(int u,int p)
{
    update(1,1,n,st[u],-oo);
    ll tmp=max(find_query_min(1,1,n,1,st[u]-1),find_query_min(1,1,n,en[u]+1,n));
    if(tmp>-oo)
    {
        res=max(res,sum[u]+tmp);
    }
    int m=SZ(adj[u]),v;
    for (int i=0;i<m;i++)
    {
        v=adj[u][i];
        if(v==p) continue;
        dfs2(v,u);
    }
    update(1,1,n,st[u],sum[u]);
    return ;
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    res=-oo;
    sf("%d",&n);
    for (int i=0;i<n;i++)
    {
        sf("%I64d",&val[i+1]);
    }
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        sf("%d %d",&u,&v);
        adj[u].psb(v);
        adj[v].psb(u);
    }
    dfs1(1,1);
    for (int i=1;i<=n;i++)
    {
        sum2[st[i]]=sum[i];
    }
    build_segment_tree(1,1,n);
    dfs2(1,1);
    if(res<=-oo) deb("Impossible");
    else deb(res);
    return 0;
}
/**
10
-3 0 1 -3 2 1 2 5 3 1
6 2
10 3
10 5
2 7
3 4
8 2
8 10
4 9
1 9
*/













