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

ll BigMod(ll B,ll P,ll M)
{
    ll R=1;    /// (B^P)%M
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

int main()
{
#ifdef rumman
//    Read;
//    Write;
#endif
    set< pair<int,int> > range;

    int n,k,a,m,x;

    SF("%d %d %d %d",&n,&k,&a,&m);

    int res=-1;
    range.insert(mp(1,n));
    int p=(n+1)/(a+1),d,np;
    for(int i=0; i<m; i++)
    {
        SF("%d",&x);
//        deb("x",x);
        auto lb=range.lower_bound(mp(x,x));
        if(lb!=range.end())
        {
            int l=(*lb).fs;
            int r=(*lb).sc;
//            deb(l,r);
            if(l<=x&&r>=x)
            {
                range.erase(lb);
                int cd=r-l+1;
                np=p-((cd+1)/(a+1));
//                deb(np,l,x-1);
                if(l<=x-1)
                {
                    range.insert(mp(l,x-1));
                    d=x-l;
                    np=np+((d+1)/(a+1));
//                    deb(np);
                }
                if(r>=x+1)
                {
                    range.insert(mp(x+1,r));
                    d=r-x;
                    np=np+((d+1)/(a+1));
                }
                if(np<k&&res==-1)
                {
                    res=i+1;
                }
//                deb(p,np,l,r);
                p=np;
            }
            else if(!range.empty())
            {
                lb--;
                int l=(*lb).fs;
                int r=(*lb).sc;
//                deb(l,r);
                if(l<=x&&r>=x)
                {
                    range.erase(lb);
                    int cd=r-l+1;
                    np=p-((cd+1)/(a+1));
//                deb(np,l,x-1);
                    if(l<=x-1)
                    {
                        range.insert(mp(l,x-1));
                        d=x-l;
                        np=np+((d+1)/(a+1));
//                    deb(np);
                    }
                    if(r>=x+1)
                    {
                        range.insert(mp(x+1,r));
                        d=r-x;
                        np=np+((d+1)/(a+1));
                    }
                    if(np<k&&res==-1)
                    {
                        res=i+1;
                    }
//                deb(p,np,l,r);
                    p=np;
                }
            }
        }
        else if(!range.empty())
        {
            lb--;
            int l=(*lb).fs;
            int r=(*lb).sc;
//            deb(l,r);
            if(l<=x&&r>=x)
            {
                range.erase(lb);
                int cd=r-l+1;
                np=p-((cd+1)/(a+1));
//                deb(np,l,x-1);
                if(l<=x-1)
                {
                    range.insert(mp(l,x-1));
                    d=x-l;
                    np=np+((d+1)/(a+1));
//                    deb(np);
                }
                if(r>=x+1)
                {
                    range.insert(mp(x+1,r));
                    d=r-x;
                    np=np+((d+1)/(a+1));
                }
                if(np<k&&res==-1)
                {
                    res=i+1;
                }
//                deb(p,np,l,r);
                p=np;
            }
        }
    }
    PF("%d\n",res);
    return 0;
}













