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

const int MAX = 200009;
map<int,int> mpp;
int tree[MAX<<2];

#define mson int nidx=(idx<<1),mid=(l+r)>>1

void update(int idx,int l,int r,int p,int v)
{
    if(l==r)
    {
        tree[idx]=max(tree[idx],v);
        return ;
    }
    mson;
    if(p<=mid) update(nidx,l,mid,p,v);
    else update(nidx+1,mid+1,r,p,v);
    tree[idx]=max(tree[nidx],tree[nidx+1]);
    return ;
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(l>r || ql>qr) return 0;
    if(l>=ql&&r<=qr)
    {
        return tree[idx];
    }
    if(l>qr||r<ql) return 0;
    mson;
    return max(query(nidx,l,mid,ql,qr),query(nidx+1,mid+1,r,ql,qr));
}

vector<int> a;
set<int> b;

int pos[MAX];

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif
    int c,n;
    sf("%d",&n);
    for(int i=0;i<n;i++)
    {
        sf("%d",&c);
        b.insert(c);
        a.psb(c);
    }
    int id=1;
    for(auto& it : b)
    {
        mpp[(it)]=id++;
    }
    clrall(tree,0);
    clrall(pos,0);
    int col=1;
    for(int i=n-1;i>-1;i--)
    {
        int x=i+1;
        int y=query(1,1,id,0,mpp[a[i]]-1);
        if(y>=x)
        {
            pos[i]=y-1;
        }
        else
        {
            x=i+1;
            y=x;
            pos[i]=y-1;
        }
        update(1,1,id,mpp[a[i]],i+1);
    }
    int ymx=-1,res=0;
    for(int i=0;i<n;i++)
    {
        if(ymx<i) res++;
        ymx=max(ymx,pos[i]);
    }
    deb(res);
    return 0;
}













