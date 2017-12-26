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

const int MAXN = 1000;
const int MAXO = 130;
const int MAXD = 8;


int pos[MAXD+1][MAXN+7];
int tot[MAXD+1][MAXN+7];
int val[MAXN+7];
int n;

void init(){
    for(int i=0;i<=MAXD;i++){
        for(int j=0;j<=MAXN+5;j++){
            pos[i][j]=n;
        }
    }
    clrall(tot,0);
    return ;
}

int dp[MAXN+7][(1<<8)+7];

int m;
const int lim=(1<<8)-1;

int rec(int p,int mask){
    if(mask==lim) return 0;
    if(p>=n) return -oo;
    int &ret = dp[p][mask];
    if(ret!=-1) return ret;
    ret=-oo;
    int d=val[p],rp,tmp;
    if(!(mask&(1<<d))){
        rp=tot[d][p]-m+1;
        if(rp>0){
            tmp=rec(pos[d][rp],mask|(1<<d));
            if(tmp>=0){
                ret=max(ret,tmp+m);
            }
        }
        rp=tot[d][p]-m+2;
        if(rp>0){
            tmp=rec(pos[d][rp],mask|(1<<d));
            if(tmp>=0){
                ret=max(ret,tmp+m-1);
            }
        }
    }
    ret=max(ret,rec(p+1,mask));
    return ret;
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    sf("%d",&n);
    int ret=0,f[10];
    clrall(f,0);
    for (int i=0;i<n;i++)
    {
        sf("%d",&val[i]);
        val[i]--;
        if(!f[val[i]]) ret++;
        f[val[i]]=1;
    }
    init();
    for(int i=0;i<MAXD;i++){
        int cnt=0;
        for(int j=n-1;j>=0;j--){
            tot[i][j]=tot[i][j+1];
            if(val[j]==i)
            {
                cnt++;
                pos[i][cnt]=j;
                tot[i][j]++;
            }
        }
    }

    for(int i=2;i<=MAXO;i++){
        m=i;
        clrall(dp,-1);
        ret=max(ret,rec(0,0));
    }
    pf("%d\n",ret);

    return 0;
}

/**
21
1 1 1 5 5 5 2 2 3 3 6 6 4 4 4 7 7 7 8 8 2
*/
/**
17
1 1 5 5 2 2 3 3 6 6 4 4 7 7 8 8 2
*/












