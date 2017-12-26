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

vector<ll> val;
vector<ll> sum;
vector<ll> pos;
vector<ll> cnt(100050,0);

vector<int> par;

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    int n;
    int vv;
    __;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>vv;
        val.psb(vv);
        sum.psb(0);
        pos.psb(0);
    }
    sort(all(val));
    sum[0]=val[0];
    int res=0,mxres=0;
    for(int i=1;i<n;i++)
    {
        sum[i]+=sum[i-1]+val[i];
    }
    cnt[0]++;
    deb(0);

    for(int i=1;i<n;i++)
    {
        if(sum[i-1]<=val[i])
        {
            pos[i]=0;
            cnt[0]++;
            deb(0);
            continue;
        }
        int lo=0,hi=i-1,mid,bad=i;
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            if(sum[i-1]-sum[mid]<=val[i])
            {
                hi=mid-1;
                bad=min(bad,mid+1);
            }
            else lo=mid+1;
        }
        cnt[bad]++;
        deb(bad);
    }

    int ptr=0;

    for(int i=1;i<n;i++)
    {
        res=cnt[0];
        mxres=max(res,mxres);
        int id=pos[i-1];
        if(ptr<id) cnt[id]--;
        else cnt[0]--;
        ptr++;
        cnt[0]+=cnt[ptr];
    }
    res=cnt[0];
    mxres=max(res,mxres);

    deb(mxres);

    return 0;
}

/**

4
2 6 7 14

answer : 3
*/

/**
10
2 3 4 5 6 7 8 8 8 9
*/









