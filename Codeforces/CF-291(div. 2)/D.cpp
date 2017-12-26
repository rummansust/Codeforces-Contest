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
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
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

struct data{
    int val[5];
    data()
    {
        clrall(val,0);
    }
};

const int MAX = 100070;
data tree[262144+100];
data info[MAX];

void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx]=info[l];
        return ;
    }
    int mid=(l+r)>>1,nidx=(idx<<1);
    build(nidx,l,mid);
    build(nidx|1,mid+1,r);
    for(int i=0;i<5;i++)
        tree[idx].val[i]=max(tree[nidx].val[i],tree[nidx|1].val[i]);
    return ;
}

data query(int idx,int l,int r,int ql,int qr)
{
    if(l>r || ql>qr || l>qr || r<ql) return data();
    if(l>=ql && r<=qr) return tree[idx];
    int mid=(l+r)>>1,nidx=(idx<<1);
    data lq=query(nidx,l,mid,ql,qr);
    data rq=query(nidx|1,mid+1,r,ql,qr);
    data mq;
    for(int i=0;i<5;i++)
    {
        mq.val[i]=max(lq.val[i],rq.val[i]);
    }
    return mq;
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    __;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        info[i]=data();
        for(int j=0;j<m;j++)
        {
            cin>>info[i].val[j];
        }
    }
    clrall(tree,0);
    build(1,0,n-1);
    int ans=0;
    data resq;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        int lo=i;
        int hi=n-1;
        int mid,pos=-1;
        data qres;
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            data mq=query(1,0,n-1,i,mid);
            sum=0;
            for(int i=0;i<5;i++) sum+=mq.val[i];
            if(sum<=k)
            {
                pos=mid;
                lo=mid+1;
                qres=mq;
            }
            else hi=mid-1;
        }
        if(pos>=0)
        {
            if(ans<(pos-i+1))
            {
                resq=qres;
                ans=(pos-i+1);
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<resq.val[i]<<" \n"[i==m-1];
    }
    return 0;
}













