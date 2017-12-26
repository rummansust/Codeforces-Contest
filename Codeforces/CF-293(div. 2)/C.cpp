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
#define Write freopen("in.txt","w",stdout)
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

const int MAX = 100050;

vector<int> apps[MAX];
pair<int,int> pos[MAX];
int n,m,k;

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    int val;
    SF("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        SF("%d",&val);
        apps[i/k].psb(val);
        pos[val]=mp(i/k,SZ(apps[i/k])-1);
    }
    ll ans=0;
    int curapps,curpos,preapps,prepos,pval;
    for(int i=0;i<m;i++)
    {
        SF("%d",&val);
        ans+=pos[val].fs+1;
        curapps=pos[val].fs;
        curpos=pos[val].sc;
        if(curapps==0 && curpos==0) continue;
        if(curpos==0)
        {
            preapps=curapps-1;
            prepos=SZ(apps[preapps])-1;
        }
        else
        {
            preapps=curapps;
            prepos=curpos-1;
        }
        pval=apps[preapps][prepos];
        apps[preapps][prepos]=val;

        pos[pval]=mp(curapps,curpos);

        apps[curapps][curpos]=pval;

        pos[val]=mp(preapps,prepos);

        int L= (n/k) +(n%k!=0);
//        deb("::::::::::::::\n");
//        for(int i=0;i<L;i++)
//        {
//            for(int j=0;j<SZ(apps[i]);j++)
//            {
//                cout<<apps[i][j]<<" \n"[j==SZ(apps[i])-1];
//            }
//        }
//        deb("::::::::::::::\n");
    }
    cout<<ans<<"\n";
//    PF("%d\n",ans);
    return 0;
}













