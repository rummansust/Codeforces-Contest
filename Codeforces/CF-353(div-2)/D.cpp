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

const int MAX = 100060;
map<int,int> mpp;

int cnt[MAX];
int res[MAX];
int tree[2][MAX<<2];

void update(int idx,int l,int r,int x,int id,int v)
{
    if(l==r)
    {
        tree[id][idx]=v;
        return ;
    }
    int mid=(l+r)>>1,nidx=idx<<1;
    if(x<=mid) update(nidx,l,mid,x,id,v);
    else update(nidx+1,mid+1,r,x,id,v);
    tree[idx][idx]=tree[id][nidx]+tree[id][nidx+1];
    return ;
}

int query(int idx,int l,int r,int ql,int qr,int id)
{
    if(l>r||ql>qr||l>qr||r<ql) return 0;
    if(l>=ql&&r<=qr) return tree[id][idx];
    int mid=(l+r)>>1,nidx=idx<<1;
    return query(nidx,l,mid,ql,qr,id)+query(nidx+1,mid+1,r,ql,qr,id);
}

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    clrall(cnt,0);
    vector<int> tmp,rval;
    int v;
    set<int> com;
    int n;
    sf("%d",&n);
    for(int i=0;i<n;i++)
    {
        sf("%d",&v);
        rval.psb(v);
        tmp.psb(v);
    }
    sort(all(tmp));
    for(int i=0;i<n;i++)
    {
        mpp[tmp[i]]=i+1;
    }
    clrall(tree,0);
    v=mpp[rval[0]];
    update(1,1,n,v,0,1);
    update(1,1,n,v,1,1);
    int ql,qr;
    for(int i=1;i<n;i++)
    {
        v=mpp[rval[i]];
        auto it = com.lower_bound(v);
        if(it==com.begin())
        {
            ql=1;
            qr=v;
        }
        else
        {
            auto it1=it;
            it1--;
            ql=(*it1)+1;
            qr=v;
        }
        int g=getVal(ql,qr,0);
        if(g!=-1)
        {
            update(1,1,n,g,0,0);
            res[i]=tmp[g-1];
            cnt[g]--;
            if(cnt[g]==-2)
            {
                com.insert(g);
            }
            update(1,1,n,v,0,1);
            update(1,1,n,v,1,1);
            continue;
        }

    }
    return 0;
}










