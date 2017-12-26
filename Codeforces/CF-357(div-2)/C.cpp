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

vector<pair<string,int> > res;

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    priority_queue<int, std::vector<int>, std::greater<int> > Q;
    char arr[100];
    string str,rem="removeMin",ins="insert",gem="getMin";
    int x,xp;
    int n;
    sf("%d",&n);
    while(n--)
    {
        sf("%s",&arr);
        str=arr;
        if(str!=rem)
        {
            sf("%d",&x);
            if(str==ins)
            {
                res.psb(mp(str,x));
                Q.push(x);
            }
            else
            {
                if(Q.empty())
                {
                    res.psb(mp(ins,x));
                    Q.push(x);
                    res.psb(mp(gem,x));
                }
                else
                {
                    while(!Q.empty())
                    {
                        xp=Q.top();
                        if(xp==x) break;
                        else if(xp<x)
                        {
                            Q.pop();
                            res.psb(mp(rem,0));
                        }
                        else
                        {
                            res.psb(mp(ins,x));
                            Q.push(x);
                            break;
                        }
                    }
                    if(Q.empty())
                    {
                        res.psb(mp(ins,x));
                        Q.push(x);
                    }
                    res.psb(mp(gem,x));
                }
            }
        }
        else
        {
            if(Q.empty())
            {
                res.psb(mp(ins,1));
            }
            else Q.pop();
            res.psb(mp(rem,0));
        }
    }
    pf("%d\n",SZ(res));
    for(int i=0;i<SZ(res);i++)
    {
        pf("%s",res[i].fs.c_str());
        if(res[i].fs!=rem)
        {
            pf(" %d",res[i].sc);
        }
        pf("\n");
    }
    return 0;
}










