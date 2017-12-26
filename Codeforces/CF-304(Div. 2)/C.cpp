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

map<stack<int> , int> mppa,mppb;

int print(stack<int> a,stack<int> b)
{
    while(!a.empty()) cout<<a.top()<<" ",a.pop();
    cout<<"\n";
    while(!b.empty()) cout<<b.top()<<" ",b.pop();
    cout<<"\n";
    cout<<"\n";
    return 0;
}

pair<int,int> rec(stack<int> a,stack<int> b)
{
    if(mppa.count(a) && mppb.count(b)) return mp(-1,-1);
//    print(a,b);
    mppa[a]=1;
    mppb[b]=1;
    if(a.empty()) return mp(0,2);
    if(b.empty()) return mp(0,1);
    int av=a.top(),bv=b.top();
    a.pop();
    b.pop();
    if(av>bv)
    {
        stack<int> tmp;
        while(!a.empty()) tmp.push(a.top()),a.pop();
        a.push(av);
        a.push(bv);
        while(!tmp.empty()) a.push(tmp.top()),tmp.pop();
    }
    else
    {
        stack<int> tmp;
        while(!b.empty()) tmp.push(b.top()),b.pop();
        b.push(bv);
        b.push(av);
        while(!tmp.empty()) b.push(tmp.top()),tmp.pop();
    }
    pair<int,int> ret = rec(a,b);
    ret.fs++;
    return ret;
}


int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    int n;
    __;
    cin>>n;
    int k1,k2;
    stack<int> a,b;
    cin>>k1;
    stack<int> tmp;
    while(k1--)
    {
        cin>>k2;
        tmp.push(k2);
    }
    while(!tmp.empty())
    {
        a.push(tmp.top());
        tmp.pop();
    }
    cin>>k1;
    while(k1--)
    {
        cin>>k2;
        tmp.push(k2);
    }
    while(!tmp.empty())
    {
        b.push(tmp.top());
        tmp.pop();
    }
    pair<int,int> ret=rec(a,b);
    if(ret.sc==-1)
    {
        deb(-1);
        return 0;
    }
    deb(ret.fs,ret.sc);
    return 0;
}













