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
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<endl;}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

const int MAX = 1000010;

struct node{
    ll s,os,es,us;
    int o,e;
    bool sf,ff,sff;
    node(){}
};

#define __mid int mid=(l+r)>>1,nidx=(idx<<1)

node tree[MAX<<2];

void Merge(int idx)
{
    tree[idx].s=tree[idx<<1].s+tree[(idx<<1)|1].s;
    tree[idx].o=tree[idx<<1].o+tree[(idx<<1)|1].o;
    tree[idx].e=tree[idx<<1].e+tree[(idx<<1)|1].e;
    return ;
}

void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx].s=l;
        tree[idx].us=0;
        tree[idx].os=0;
        tree[idx].es=0;
        tree[idx].o=(l&1);
        tree[idx].e=((l&1)==0);
        tree[idx].sf=false;
        tree[idx].ff=false;
        tree[idx].sff=false;
        return ;
    }
    __mid;
    build(nidx,l,mid);
    build(nidx|1,mid+1,r);
    Merge(idx);
}

void relaxSum(int idx,int l,int r,ll v)
{
//    deb("insum",l,r,v);
    tree[idx].s+=(ll)(r-l+1) * v;
    __mid;
    if(v&1)
    {
//        deb("jahsdkhasd");
        tree[idx].sff=true;
        swap(tree[idx].os,tree[idx].es);
        swap(tree[idx].o,tree[idx].e);
    }
    if(l!=r)
    {
        tree[nidx].us+=v;
        tree[nidx].sf=true;
        tree[nidx|1].us=v;
        tree[nidx|1].sf=true;
        if(tree[idx].sff)
        {
            tree[nidx].sff=!tree[nidx].sff;
            tree[nidx|1].sff=!tree[nidx|1].sff;
        }
    }
    tree[idx].us=0;
    tree[idx].sf=false;
    tree[idx].sff=false;
    return ;
}

void relaxSFF(int idx,int l,int r)
{
//    deb("insff",l,r);
    __mid;
    swap(tree[idx].os,tree[idx].es);
    swap(tree[idx].o,tree[idx].e);
    if(l!=r)
    {
        tree[nidx].sff=!tree[nidx].sff;
        tree[nidx|1].sff=!tree[nidx|1].sff;
    }
    tree[idx].sff=false;
    return ;
}

void relaxFF(int idx,int l,int r,ll v1,ll v2)
{
//    deb("inff",l,r);
    __mid;
    tree[idx].s+=(tree[idx].o*v1 + tree[idx].e*v2);
    if(l!=r)
    {
        tree[nidx].os+=v1;
        tree[nidx].es+=v2;
        tree[nidx].ff=true;
        tree[nidx|1].os+=v1;
        tree[nidx|1].es+=v2;
        tree[nidx|1].ff=true;
    }
    tree[idx].ff=false;
    tree[idx].os=0;
    tree[idx].es=0;
    return ;
}

int n,x,ql,qr;

void update1(int idx,int l,int r)
{
    if(l>r||l>qr||r<ql) return ;
    if(tree[idx].sf) relaxSum(idx,l,r,tree[idx].us);
    if(tree[idx].sff) relaxSFF(idx,l,r);
    if(tree[idx].ff) relaxFF(idx,l,r,tree[idx].os,tree[idx].es);
    if(l>=ql&&r<=qr)
    {
        relaxSum(idx,l,r,x+n);
        return ;
    }
    __mid;
    update1(nidx,l,mid);
    update1(nidx|1,mid+1,r);
    Merge(idx);
    return ;
}

void update2(int idx,int l,int r)
{
    if(l>r||l>qr||r<ql) return ;
    if(tree[idx].sf) relaxSum(idx,l,r,tree[idx].us);
    if(tree[idx].sff) relaxSFF(idx,l,r);
    if(tree[idx].ff) relaxFF(idx,l,r,tree[idx].os,tree[idx].es);
    if(l>=ql&&r<=qr)
    {
        relaxFF(idx,l,r,n-1,1);
        return ;
    }
    __mid;
    update2(nidx,l,mid);
    update2(nidx|1,mid+1,r);
    Merge(idx);
    return ;
}

int query(int idx,int l,int r,int k)
{
    if(tree[idx].sf) relaxSum(idx,l,r,tree[idx].us);
    if(tree[idx].sff) relaxSFF(idx,l,r);
    if(tree[idx].ff) relaxFF(idx,l,r,tree[idx].os,tree[idx].es);
    deb("inquery1",tree[idx].s,tree[idx].us,tree[idx].os,tree[idx].es,l,r);
    deb("inquery2",tree[idx].o,tree[idx].e);
    if(l==r)
    {
        return (tree[idx].s%n)+1;
    }
    __mid;
    if(k<=mid) return query(nidx,l,mid,k);
    else return query(nidx|1,mid+1,r,k);
}

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    int q,t;
    scanf("%d %d",&n,&q);
    ql=0;
    qr=n-1;
    build(1,0,n-1);
    while(q--)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d",&x);
            update1(1,0,n-1);
        }
        else update2(1,0,n-1);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d%c",query(1,0,n-1,i)," \n"[i==n-1]);
    }
    return 0;
}










