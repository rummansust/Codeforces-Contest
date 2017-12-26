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
#define SF scanf
#define PF printf
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
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

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

const int MAX = 2010;

int n;
int H,T[MAX];
int Lid[MAX],Rid[MAX];
double P,dp[MAX][MAX][2][2];
bool vp[MAX][MAX][2][2];
/**
Due to the wind, when a tree is cut down,
it either falls left with probability p,
or falls right with probability 1 - p.
*/

/**
left --> 0
right --> 1
*/

double rec(int l,int r,int fl,int fr,int lpos,int rpos)
{
    if(l>r||lpos>=rpos) return 0;
    double &ret = dp[l][r][fl][fr];
    bool &vet = vp[l][r][fl][fr];
    if(vet) return ret;
    vet=true;
    ret=0;
    ///choose left
    ///falls right
    int nl=min(r,Rid[l]);
    int pa=T[l],pb=min(T[nl]+H,rpos);
    ret+=(1.0-P)*(max(0,pb-pa)*1.0);
    ret+=(1.0-P)*rec(nl+1,r,1,fr,pb,rpos);
    ///falls left
    pa=T[l];pb=max(lpos,pa-H);
    ret+=P*(max(0,pa-pb)*1.0);
    ret+=P*rec(l+1,r,0,fr,pa,rpos);

    ///choose right
    ///falls left
    int nr=max(l,Lid[r]);
    pa=T[r],pb=max(T[nr]-H,lpos);
    ret+=P*(max(0,pa-pb)*1.0);
    ret+=P*rec(l,nr-1,fl,0,lpos,pb);
    ///falls right
    pa=T[r];pb=min(rpos,pa+H);
    ret+=(1.0-P)*(max(0,pb-pa)*1.0);
    ret+=(1.0-P)*rec(l,r-1,fl,1,lpos,pa);

    ret/=2.0;
    return ret;
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    sf("%d %d %lf",&n,&H,&P);
    int idx;
    ll totd;
    for(int i=1;i<=n;i++) sf("%d",&T[i]);
    sort(T+1,T+n+1);
    Lid[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(T[i]-T[i-1]<H) Lid[i]=Lid[i-1];
        else Lid[i]=i;
    }
    Rid[n]=n;
    for(int i=n-1;i>0;i--)
    {
        if(T[i+1]-T[i]<H) Rid[i]=Rid[i+1];
        else Rid[i]=i;
    }
    double res=rec(1,n,1,0,T[1]-H,T[n]+H);
    pf("%.12lf\n",res);
    return 0;
}















