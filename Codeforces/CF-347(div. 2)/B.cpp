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

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    string s;
    getline(cin,s);
    int p=1,m=0,n=0;
    for(int i=0;i<SZ(s);i++)
    {
        if(s[i]=='+') p++;
        else if(s[i]=='-') m++;
        else if(s[i]<='9'&&s[i]>='0') n=n*10+(s[i]-'0');
    }
    if(p==1&&m==0)
    {
        deb("Possible");
        deb(n,"=",n);
        return 0;
    }
    if(m==0)
    {
        ;
    }
    bool flag=false;
    int lim=(n*p),a,b;
    for(int j=p;j<=lim;j++)
    {
        a=j;
        b=a-n;
        if(b<0) continue;
        int d=a/p;
        int ma=a%p;
        if(d>n||d<1) continue;
        if(ma&&(d+1>n||d+1<1)) continue;
        int e=0;
        int mb=0;
        if(m)
        {
            e=b/m;
            mb=b%m;
            if(e>n||e<1) continue;
            if(mb&&(e+1>n||e+1<1)) continue;
        }
//        deb(a,b,p,m,d,e);
        queue<int> pos;
        queue<int> neg;
        int t=(ma*(d+1)+(p-ma)*d)-(mb*(e+1)+(m-mb)*e);
        if(t!=n) continue;
        if(t>n) break;
        for(int i=0;i<ma;i++) pos.push(d+1);
        for(int i=ma;i<p;i++) pos.push(d);
        for(int i=0;i<mb;i++) neg.push(e+1);
        for(int i=mb;i<m;i++) neg.push(e);
        deb("Possible");
        for(int i=0;i<SZ(s);i++)
        {
            if(i==0)
            {
                int t=pos.front();
                pos.pop();
                pf("%d",t);
            }
            else
            {
                if(s[i]=='?')
                {
                    if(s[i-2]=='+')
                    {
                        int t=pos.front();
                        pos.pop();
                        pf("%d",t);
                    }
                    else if(s[i-2]=='-')
                    {
                        int t=neg.front();
                        neg.pop();
                        pf("%d",t);
                    }
                    else pf("%c",s[i]);
                }
                else pf("%c",s[i]);
            }
        }
        pf("\n");
        return 0;
    }
    pf("Impossible\n");
    return 0;
}










