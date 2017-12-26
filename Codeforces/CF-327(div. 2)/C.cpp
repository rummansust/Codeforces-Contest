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
#define Write freopen("out2.txt","w",stdout)
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

const int MAX = 500007;

int arr[MAX];

int main()
{
    #ifdef rumman
    Read;
    Write;
    #endif
    int n;
    int v;
    while(sf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
        {
            sf("%d",&v);
            arr[i]=v;
        }
        int st=-1,ans=0,cnt=0;
        vector<pair<int,int> > range;
        for(int i=1;i<n-1;i++)
        {
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1])
            {
                if(st==-1) st=i;
                cnt++;
            }
            else
            {
                if(cnt)
                {
                    range.psb(mp(st,i-1));
                    ans=max((cnt+1)/2,ans);
                }
                cnt=0;
                st=-1;
            }
        }
        if(cnt)
        {
            range.psb(mp(st,n-2));
            ans=max((cnt+1)/2,ans);
        }
        for(int i=0;i<SZ(range);i++)
        {
            int u=arr[range[i].fs-1],v=arr[range[i].sc+1];
            if(u==v && u==1)
            {
                for(int j=range[i].fs;j<=range[i].sc;j++) arr[j]=1;
            }
            else if(u==v && u==0)
            {
                for(int j=range[i].fs;j<=range[i].sc;j++) arr[j]=0;
            }
            else if(u==0)
            {
                sort(arr+range[i].fs,arr+range[i].sc+1);
            }
            else if(u==1)
            {
                sort(arr+range[i].fs,arr+range[i].sc+1);
                reverse(arr+range[i].fs,arr+range[i].sc+1);
            }
        }
        deb(ans);
        for(int i=0;i<n;i++)
        {
            pf("%d ",arr[i]);
        }
        deb("");
    }
    return 0;
}

/**
20
1 0 0 1 0 1 1 0 0 1 1 0 0 1 1 0 1 0 1 0

my output(WA) :
1
1 0 0 0 1 1 1 0 0 1 1 0 0 1 1 1 0 1 0 0
*/












