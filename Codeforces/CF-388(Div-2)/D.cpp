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

const int MAX = 505000;

vector<int> pos[MAX];
vector<int> val[MAX];

vector<int> did;
vector<int> abb;

bool flag[MAX];

pair<int,int> go(vector<int> tmp)
{
    pair<int,int> ret=mp(0,-1);
    int m2=tmp[1];
    int m1=tmp[0];
//    deb(">>>>>>>>>>>",m1,m2);
    int m2pos=pos[m2].back();
//    deb("m2pos",m2pos);
    int m1pos=lower_bound(all(pos[m1]),m2pos)-pos[m1].begin();
    if(m1pos==SZ(pos[m1])||pos[m1][m1pos]>m2pos) m1pos--;
    if(m1pos>=0) {
        m1pos=pos[m1][m1pos];
        int tar=upper_bound(all(pos[m2]),m1pos)-pos[m2].begin();
        if(tar==SZ(pos[m2])) tar--;
        if(tar>=0&&pos[m2][tar]>m1pos) return mp(m2,val[m2][tar]);
    }
    return ret;
}

vector<int> valV;

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    int n,q,k,v,b;
    sf("%d",&n);
    for (int i=0;i<n;i++)
    {
        sf("%d %d",&v,&b);
        pos[v].psb(i);
        val[v].psb(b);
        valV.psb(v);
    }
    for(int i=n-1;i>=0;i--)
    {
        v=valV[i];
        if(!flag[v])
        did.psb(v);
        flag[v]=true;
    }
    clrall(flag,0);
    sf("%d",&q);
    while(q--)
    {
        sf("%d",&k);
        abb.clear();
        for(int i=0;i<k;i++)
        {
            sf("%d",&v);
            abb.psb(v);
            flag[v]=true;
        }

        vector<int> tmp;
        for(int i=0;i<SZ(did);i++)
        {
            if(SZ(tmp)==2) break;
            if(!flag[did[i]])
            {
                tmp.psb(did[i]);
            }
        }
        if(SZ(tmp)==0)
        {
            pf("0 0\n");
        }
        else if(SZ(tmp)==1)
        {
            pf("%d %d\n",tmp[0],val[tmp[0]][0]);
        }
        else
        {
            pair<int,int> ret=go(tmp);
            swap(tmp[0],tmp[1]);
            pair<int,int> ret2=go(tmp);
            if(ret2.sc>ret.sc) ret=ret2;
            pf("%d %d\n",ret.fs,ret.sc);
        }

        for(int i=0;i<k;i++)
        {
            v=abb[i];
            flag[v]=false;
        }
    }
    return 0;
}


/**
8
3 1
1 10
7 100
5 1000
2 10000
3 100000
7 1000000
2 10000000
2
2 1 3
3 1 5 7
*/

/**
6
1 10
2 100
3 1000
1 10000
2 100000
3 1000000
3
1 3
2 2 3
2 1 2
*/

/**
6
4 6
6 11
4 13
3 19
4 24
3 31
1
1 1
*/










