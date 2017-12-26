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


const int MAX = 101000;

vector<ll> val;
int par[MAX];

pair<int,int> tree[3*MAX*8];
map<ll,int> ID;

void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx]=mp(0,-1);
        return ;
    }
    int mid=(l+r)>>1,nidx=(idx<<1);
    build(nidx,l,mid);
    build(nidx|1,mid+1,r);
    tree[idx]=mp(0,-1);
    return ;
}

void print(int idx,int l,int r)
{
    if(l==r)
    {
        cout<<l<<" "<<r<<" "<<tree[idx].fs<<endl;
        return ;
    }
    int mid=(l+r)>>1,nidx=(idx<<1);
    print(nidx,l,mid);
    print(nidx|1,mid+1,r);
    cout<<l<<" "<<r<<" "<<tree[idx].fs<<" "<<mid<<endl;
    return ;
}

pair<int,int> query(int idx,int l,int r,int ql,int qr)
{
    if(l>r || l>qr || r<ql) return mp(0,-1);
    if(l>=ql&&r<=qr) return tree[idx];
    int mid=(l+r)>>1,nidx=(idx<<1);
    pair<int,int> q1=query(nidx,l,mid,ql,qr);
    pair<int,int> q2=query(nidx|1,mid+1,r,ql,qr);
    if(q1.fs<q2.fs) return q2;
    return q1;
}

void update(int idx,int l,int r,int p,int val,int ip)
{
    if(l==r)
    {
        tree[idx]=mp(val,ip);
        return ;
    }
    int mid=(l+r)>>1,nidx=(idx<<1);
    if(p<=mid) update(nidx,l,mid,p,val,ip);
    else update(nidx|1,mid+1,r,p,val,ip);
    pair<int,int> mx=tree[nidx];
    if(mx.fs<tree[nidx|1].fs) mx=tree[nidx|1];
    tree[idx]=mx;
    return ;
}

void dfs(int u,bool f)
{
    if(u==-1) return ;
    dfs(par[u],true);
    cout<<u+1;
    if(f) cout<<" ";
    return ;
}

int main()
{
    __;
    int n;
    ll v,d;
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>v;
        val.psb(v);
        ID[v]=ID[v-d]=ID[v+d]=0;
    }
    int N=1;
    for(map<ll,int> :: const_iterator it = ID.begin();it!=ID.end();it++)
    {
        ID[(it->fs)]=N++;
    }
    clrall(par,-1);
    build(1,0,N);
    int l,r,cur;
    int ans=0,pos=-1;
    for(int i=0;i<n;i++)
    {
        v=val[i];
        l=ID[v-d];
        r=ID[v+d];
        cur=ID[v];
        pair<int,int> q1=query(1,0,N,0,l);
        pair<int,int> q2=query(1,0,N,r,N);
        if(q1.fs+1<q2.fs+1) swap(q1,q2);
        if(q1.fs+1>ans)
        {
            ans=q1.fs+1;
            pos=i;
        }
        par[i]=q1.sc;
        update(1,0,N,cur,q1.fs+1,i);
    }
    cout<<ans<<"\n";
    dfs(pos,0);
    cout<<"\n";
    return 0;
}


















