#include <bits/stdc++.h>

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
#define oo (1<<29)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outE.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)





map<string,int> ID;

vector<string> val;
const int MAX = 200010;
vector<int> adj[MAX];
vector<int> nadj[MAX];
ll len[MAX];
ll cntR[MAX];

pair<int,ll> dp[MAX];



int id1,distime[MAX],height[MAX],color[MAX],group_id[MAX],com,num_com[MAX],in_degree[MAX],out_degree[MAX];
stack<int> S;

ll nlen[MAX],nrcnt[MAX];

void scc(int u)
{
    color[u]=1;
    S.push(u);
    distime[u]=height[u]=++id1;
    int v;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(color[v]==1) height[u]=min(height[u],distime[v]);
        else if(color[v]==0)
        {
            scc(v);
            height[u]=min(height[u],height[v]);
        }
    }
    if(height[u]==distime[u])
    {
        nlen[com]=len[u];
        nrcnt[com]=cntR[u];
        do
        {
            v=S.top();
            S.pop();
            color[v]=2;
            group_id[v]=com;
            num_com[com]++;
            if(nrcnt[com]>cntR[v])
            {
                nrcnt[com]=cntR[v];
            }
            else if(nrcnt[com]==cntR[v])
            {
                nlen[com]=min(len[v],nlen[com]);
            }
        }
        while(v!=u);
        com++;
    }
    return ;
}


pair<int,ll> rec(int u)
{
    pair<int,ll> &ret = dp[u],tmp;
    if(ret.fs!=-1) return ret;
    ret=mp(nlen[u],nrcnt[u]);
    int v,k=SZ(nadj[u]);
    for(int i=0;i<k;i++)
    {
        v=nadj[u][i];
        tmp=rec(v);
        if(tmp.sc<ret.sc)
        {
            ret=tmp;
        }
        else if(tmp.sc==ret.sc)
        {
            ret.fs=min(ret.fs,tmp.fs);
        }
    }
    return ret;
}

void Tolower(string &a)
{
    for(int i=0;i<SZ(a);i++) a[i]=(char) tolower(a[i]);
}

int main()
{
    __;
    int m,n;
    string a,b;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        Tolower(a);
        val.psb(a);
    }
    cin>>n;
    int id=1,ia,ib;
    while(n--)
    {
        cin>>a>>b;
        Tolower(a);
        Tolower(b);
        if(ID.find(a)==ID.end()) ID[a]=id++;
        if(ID.find(b)==ID.end()) ID[b]=id++;
        ia=ID[a];
        ib=ID[b];
        len[ia]=SZ(a);
        len[ib]=SZ(b);
        adj[ia].psb(ib);
        int cnt=0;
        for(int i=0;i<SZ(a);i++)
        {
            if(a[i]=='r') cnt++;
        }
        cntR[ia]=cnt;
        cnt=0;
        for(int i=0;i<SZ(b);i++)
        {
            if(b[i]=='r') cnt++;
        }
        cntR[ib]=cnt;
    }
    clrall(dp,-1);
    for(int i=1;i<id;i++)
    {
        if(distime[i]==0) scc(i);
    }
    for(int i=1;i<=id;i++)
    {
        int j;
        for(int k=0;k<SZ(adj[i]);k++)
        {
            j=adj[i][k];
            if(group_id[i]!=group_id[j])
            {
                in_degree[group_id[j]]++;
                nadj[group_id[i]].psb(group_id[j]);
            }
        }
    }
    for(int i=0;i<com;i++)
    {
        if(in_degree[i]==0) rec(i);
    }
    ll res=0,rcnt=0;
    pair<int,ll> tmp;
    for(int i=0;i<m;i++)
    {
        a=val[i];
        if(ID.find(a)==ID.end())
        {
            res+=SZ(a);
            int cnt=0;
            for(int i=0;i<SZ(a);i++)
            {
                if(a[i]=='r') cnt++;
            }
            rcnt+=cnt;
        }
        else
        {
            tmp=rec(group_id[ID[a]]);
            res+=tmp.fs;
            rcnt+=tmp.sc;
        }
    }
    cout<<rcnt<<" "<<res<<"\n";
    return 0;
}


















