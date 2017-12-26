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

#define clr(name,val) memset(name,(val),sizeof(name));
#define SF scanf
#define PF printf

using namespace std;

#define MAX 100005

int par[MAX],grandpar[MAX],val_id[MAX],subtree[MAX],level[MAX],id,vis[MAX];
int tree[MAX<<2],root;
vector<int> adj[MAX];

int ROOT[MAX];

inline int dfs(int u)
{
    vis[u]=true;
    int v;
    subtree[u]=1;
    ROOT[u]=root;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(par[v]^(-1)) continue;
        par[v]=u;
        level[v]=level[u]+1;
        subtree[u]+=dfs(v);
    }
    return subtree[u];
}

inline void construct_paths(int u)
{
    int mxvl,node,v;
    mxvl=node=-1;
    val_id[u]=id++;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(mxvl<subtree[v] && v^par[u])
        {
            node=v;
            mxvl=subtree[v];
        }
    }
    if(!(mxvl^(-1))) return ;
    grandpar[node]=grandpar[u];
    construct_paths(node);
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(v^node && v^par[u])
        {
            grandpar[v]=v;
            construct_paths(v);
        }
    }
    return ;
}

inline void update(int ind,int l,int r,int point,int value)
{
    if(!(l^r))
    {
        tree[ind]=value;
        return ;
    }
    int mid=(l+r)>>1,indt=ind<<1;
    if(mid>=point) update(indt,l,mid,point,value);
    else update(indt|1,mid+1,r,point,value);
    tree[ind]=tree[indt]+tree[indt|1];
    return ;
}

inline int query(int ind,int l,int r,int QL,int QR)
{
    if(l==QL&&r==QR) return tree[ind];
    int mid=(l+r)>>1,indt=ind<<1;
    if(QR<=mid) return query(indt,l,mid,QL,QR);
    if(QL>mid) return query(indt|1,mid+1,r,QL,QR);
    else
    {
        return query(indt,l,mid,QL,mid)+query(indt|1,mid+1,r,mid+1,QR);
    }
}

inline int kthquery(int ind,int l,int r,int QL,int QR,int k)
{
    if(l==r) return l;
    int mid=(l+r)>>1,indt=ind<<1;
    if(QR<=mid) return kthquery(indt,l,mid,QL,QR,k);
    else if(QL>mid) return kthquery(indt|1,mid+1,r,QL,QR,k);
    else
    {
        int a=query(indt,l,mid,QL,mid);
        if(a>=k) return kthquery(indt,l,mid,QL,mid,k);
        else return kthquery(indt|1,mid+1,r,mid+1,QR,k-a);
    }
}

inline void level_up(int u,int v,int &res,int n)
{
    int i,j;
    res=0;
    while(grandpar[u]!=grandpar[v])
    {
        if(level[grandpar[u]]>level[grandpar[v]]) swap(u,v);
        i=val_id[grandpar[v]];
        j=val_id[v];
        res+=query(1,0,n-1,i,j);
        v=par[grandpar[v]];
    }
    if(val_id[u]>val_id[v]) swap(u,v);
    res+=query(1,0,n-1,val_id[u],val_id[v]);
    return ;
}

typedef pair<int,int> pii;

vector<pair<int,int> > info;

bool cmp(const pii& a,const pii& b)
{
    return val_id[a.fs]<val_id[b.fs];
}

int flag[MAX];

vector<int> ans;

int deg[MAX];

int main()
{
    int n,m,test,cas=0,q,ch,u,v,res;
    SF("%d %d",&n,&m);
    clr(par,-1);
    clr(flag,0);
    clr(level,0);
    clr(vis,0);
    id=0;
    for(int i=0;i<m;i++)
    {
        SF("%d %d",&u,&v);
        u--;
        v--;
        adj[u].psb(v);
        deg[v]++;
    }
    for(int i=0;i<n;i++)
    {
        SF("%d",&v);
        v--;
        info.psb(mp(i,v));
    }

    for(int i=0;i<n;i++)
    {
        if(vis[i]||deg[i]) continue;
        root=i;
        par[root]=root;
        grandpar[root]=root;

        dfs(root);
        construct_paths(root);
    }
    sort(all(info),cmp);
//    for(int i=0;i<n;i++)
//    {
//        PF("%d %d\n",info[i].fs+1,info[i].sc+1);
//    }
    bool nosol=false;
    for(int i=0;i<n;i++)
    {
        v=info[i].fs;
        u=ROOT[v];
        ch=info[i].sc;
        if(v!=ch)
        {
            level_up(u,v,res,n);
            if(res)
            {
                res=kthquery(1,0,n-1,val_id[u],val_id[v],res);
                if(res!=val_id[info[i].sc])
                {
//                    deb(u+1,v+1,res+1,val_id[info[i].sc]+1);
                    nosol=true;
                    break;
                }
            }
        }
        update(1,0,n-1,val_id[ch],1);
        if(flag[ch]==0)
            ans.psb(ch+1);
        flag[ch]=1;
    }
    if(nosol) pf("-1\n");
    else
    {
        pf("%d\n",SZ(ans));
        reverse(all(ans));
        for(int i=0;i<SZ(ans);i++)
        {
            pf("%d\n",ans[i]);
        }
    }
    return 0;
}

/**
5 4
1 2
1 3
2 4
3 5
1 2 1 2 1
*/












