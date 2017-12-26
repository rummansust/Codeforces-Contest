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

#define SZ(x) ((ll)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name))
#define EPS 1e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF prllf
#define sf scanf
#define pf prllf
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

//ll dx[]= {-1,-1,0,0,1,1};
//ll dy[]= {-1,0,-1,1,0,1};
//ll dx[]= {0,0,1,-1};/*4 side move*/
//ll dy[]= {-1,1,0,0};/*4 side move*/
//ll dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//ll dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//ll dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//ll dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

//*************************************************My Code Starts Here*********************************************************************************
//Andrei Lopatin
//return minimum cost (multiply -1 in each entry for maximum cost)
//1 based (0 is used for algorithm)
//Complexity O(n^2*m) or O(n^3)
#define rows 1005
#define clms 2005
ll arr[rows][clms]; //main matrix
ll  u[rows], v[clms]; //used for labeling
ll p[clms] , way[clms]; //p = match , way = the augmenting path

//n = number of rows
//m = number of columns
//n<=m

const ll INF = (ll)1e15;
ll hungarian(ll n,ll m) {

    clrall(p,0);
    clrall(u,0);
    clrall(v,0);
    for ( ll i = 1 ; i <= n ; ++ i ) {
        p [ 0 ] = i ;
        ll j0 = 0 ;
        vector < ll > minv ( m + 1 , INF ) ;
        vector < bool > used ( m + 1 , false ) ;
        do { //works like bfs
            used [ j0 ] = true ;
            ll i0 = p [ j0 ],  j1 ;
            ll delta = INF;
            for ( ll j = 1 ; j <= m ; ++ j )
                if ( ! used [ j ] ) {
                    ll cur = arr [ i0 ] [ j ] - u [ i0 ] - v [ j ] ;
				if ( cur < minv [ j ] )
					minv [ j ] = cur,  way [ j ] = j0 ;
				if ( minv [ j ] < delta )
					delta = minv [ j ] ,  j1 = j ;
                }

            //matrix doesn't change here
            for ( ll j = 0 ; j <= m ; ++ j )
                if ( used [ j ] )
                    u [ p [ j ] ] += delta,  v [ j ] -= delta ;
                else
                    minv [ j ] -= delta ;
            j0 = j1 ;
            } while ( p [ j0 ] != 0 ) ;
        do {
                ll j1 = way [ j0 ] ;
                p [ j0 ] = p [ j1 ] ;
                j0 = j1 ;
            } while ( j0 ) ;

    }

    return -v[0]; //minimum cost is stored here
}

ll x[rows],y[clms];

int main()
{
    ll n,m,p;
//    __;
    cin>>n>>m>>p;
    for (ll i=0;i<n;i++)
    {
        cin>>x[i];
    }
//    random_shuffle(x,x+n);
    for (ll i=0;i<m;i++)
    {
        cin>>y[i];
    }
//    random_shuffle(y,y+m);
    ll k=max(n,m)+1;
    for(ll i=0;i<k;i++)
    {
        for(ll j=0;j<k;j++)
        {
            arr[i][j]=INF;
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            arr[i+1][j+1]=abs(x[i]-y[j])+abs(y[j]-p);
            cout<<arr[i+1][j+1]<<" ";
        }
        cout<<"\n";
    }
    deb(hungarian(n,m));
    return 0;
}

/**
100   4 900  25 900 900
900 100   9 900 900 900
900 900 100 900 900   1
900 900 900 100 900 900
900 900 900 900 100 900
900 900 900 900 900 100
*/














