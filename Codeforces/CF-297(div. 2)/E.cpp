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

ll S;
ll sol;
ll F[20];
vector<ll> val;
int N,Nl,Nr,K;
map<ll,ll> mpp[2][26];

void bcktrk(int pos,ll V,int k,int id)
{
    if(k>K) return ;
    if(V==S)
    {
        sol++;
    }
    mpp[id][k][V]++;
    for(int i=pos+1;i<Nl;i++)
    {
        if(val[i]<20 && V<=S-F[val[i]])
        {
            bcktrk(i,V+F[val[i]],k+1,id);
        }
        if(V+val[i]<=S)
        {
            bcktrk(i,V+val[i],k,id);
        }
    }
    return ;
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    ll v;
    int n;
    cin>>n>>K>>S;
    F[0]=1;
    for(ll i=1;i<20;i++)
    {
        F[i]=F[i-1]*i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>v;
        val.psb(v);
    }
    sort(allr(val));
    N=SZ(val);
    Nl=N/2;
    Nr=Nl;
    for(int i=0;i<Nl;i++)
    {
        if(val[i]<20 && F[val[i]]<=S)
        {
            bcktrk(i,F[val[i]],1,0);
        }
        if(val[i]<=S)
        {
            bcktrk(i,val[i],0,0);
        }
    }
    Nl=N;
    for(int i=Nr;i<N;i++)
    {
        if(val[i]<20 && F[val[i]]<=S)
        {
            bcktrk(i,F[val[i]],1,1);
        }
        if(val[i]<=S)
        {
            bcktrk(i,val[i],0,1);
        }
    }
    for(int i=0;i<=K;i++)
    {
        for(map<ll,ll> :: const_iterator it = mpp[0][i].begin();it!=mpp[0][i].end();it++)
        {
            ll lv = (it->fs);
            ll lc = (it->sc);
            for(int j=K-i;j>-1;j--)
            {
                ll rc=mpp[1][j].count(S-lv);
                if(!rc) continue;
                rc=mpp[1][j][S-lv];
                sol+=lc*rc;
            }
        }
    }
    deb(sol);
    return 0;
}
/**
25 25 165442200211452
3 4 5 1 2 4 6 5 7 8 9 7 4 6 5 2 1 4 8 9 6 4 5 7 6
*/

/**
12 12 320
3 4 5 1 2 4 6 5 7 8 9 7
*/












