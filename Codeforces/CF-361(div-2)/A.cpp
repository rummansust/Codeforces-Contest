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


int arr[100][100];
pair<int,int> loc[100];
bool flag;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void rec(vector<pair<int,int> > v)
{
    vector<pair<int,int> > t;
    pair<int,int> q;
    for(int k=0;k<4;k++)
    {
        t=v;
        bool f=true;
        for(int i=0;i<SZ(t);i++)
        {
            q=t[i];
            q.fs+=dx[k];
            q.sc+=dy[k];
            if(q.fs<0||q.sc<0||arr[q.fs][q.sc]==0)
            {
                f=false;
                break;
            }
            t[i]=q;
        }
        if(f)
        {
            flag=true;
            return ;
        }
    }
    return ;
}

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    loc[1]=mp(0,0);
    loc[2]=mp(0,1);
    loc[3]=mp(0,2);
    loc[4]=mp(1,0);
    loc[5]=mp(1,1);
    loc[6]=mp(1,2);
    loc[7]=mp(2,0);
    loc[8]=mp(2,1);
    loc[9]=mp(2,2);
    loc[0]=mp(3,1);
    clrall(arr,0);
    for(int i=0;i<10;i++)
    {
        arr[loc[i].fs][loc[i].sc]=i+1;
    }
    vector<pair<int,int> > v;
    int n;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        v.psb(loc[s[i]-'0']);
    }
    flag=0;
    rec(v);
    if(flag) puts("NO");
    else puts("YES");
    return 0;
}










