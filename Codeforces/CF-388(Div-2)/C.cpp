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

const int MAX = 230000;

int t[2][MAX*10];

string s;

#define mson int mid=(l+r)>>1,nidx=idx<<1

void build(int idx,int l,int r)
{
    if(l==r)
    {
        t[0][idx]=s[l]=='D';
        t[1][idx]=s[l]=='R';
        return ;
    }
    mson;
    build(nidx,l,mid);
    build(nidx+1,mid+1,r);
    t[0][idx]=t[0][nidx]+t[0][nidx+1];
    t[1][idx]=t[1][nidx]+t[1][nidx+1];
    return;
}

void update(int idx,int l,int r,int p,int id)
{
    if(l==r)
    {
        t[id][idx]=0;
        return ;
    }
    mson;
    if(p<=mid)
    update(nidx,l,mid,p,id);
    else
    update(nidx+1,mid+1,r,p,id);
    t[id][idx]=t[id][nidx]+t[id][nidx+1];
    return;
}

int querys(int idx,int l,int r,int p,int q,int id)
{
    if(l>r||l>q||r<p) return 0;
    if(l>=p&&r<=q) return t[id][idx];
    mson;
    return querys(nidx,l,mid,p,q,id)+querys(nidx+1,mid+1,r,p,q,id);
}

int querys(int idx,int l,int r,int v,int id)
{
//    deb(idx,id,l,r,v,t[id][idx]);
    if(l==r) return l;
    mson;
    if(t[id][nidx]>=v) return querys(nidx,l,mid,v,id);
    else return querys(nidx+1,mid+1,r,v-t[id][nidx],id);
}

bool flag[MAX];

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
//    __;
    int n;
    cin>>n;
    cin>>s;
    build(1,0,n-1);
    int i=0;
    while(true)
    {
        if(!flag[i])
        {
            int id=(s[i]=='R');
            int ts0=querys(1,0,n-1,0,n-1,0);
            int ts1=querys(1,0,n-1,0,n-1,1);
            if(ts0==0)
            {
                deb("R");
                return 0;
            }
            if(ts1==0)
            {
                deb("D");
                return 0;
            }
            int sm=querys(1,0,n-1,0,i,!id);
            int ts=querys(1,0,n-1,0,n-1,!id);
            int p;
            if(sm<ts)
            {
                p=querys(1,0,n-1,sm+1,!id);
            }
            else
            {
                p=querys(1,0,n-1,sm,!id);
            }
//            deb(id,p,sm,ts);
//            getchar();
            update(1,0,n-1,p,!id);
            flag[p]=true;
        }
        ++i;
        i%=n;
    }
    return 0;
}














