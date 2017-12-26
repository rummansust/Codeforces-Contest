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
#define oo 1000000000050ll
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
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<endl;}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

const int MAX = 1000050;

int hm2[MAX];
int hm1[MAX];

int sign_(ll a,ll b)
{
    if(a<0 && b>0) return -1;
    if(a>0 && b<0) return -1;
    return 1;
}

ll Floor(ll a,ll b)
{
    ll F=a/b + (!(a%b == 0))*(sign_(a,b) < 0?-1:0);
    return F;
}

ll Ceil(ll a,ll b)
{
    ll C=a/b + (!(a%b == 0))*(sign_(a,b) < 0?0:1);
    return C;
}

ll EGCD(ll a,ll b,ll &X,ll &Y)
{
    if(b==0)
    {
        X=1;
        Y=0;
        return a;
    }
    ll x=-(a/b),PX,r;
    r=EGCD(b,a%b,X,Y);
    PX=X;
    X=Y;
    Y=(Y*x)+(PX);
    return r;
}

vector<pair<ll,ll> > find_all_solution_in_range(ll a,ll b,ll c,ll mina,ll maxa,ll minb,ll maxb)
{
    ll x0,y0,x1,y1,x,y;
    ll g=EGCD(a,b,x0,y0);
    if(g && c%g) return vector<pair<ll,ll> >();
    vector<pair<ll,ll> > retSol;
    if(a==0 && b==0)
    {
        if(c==0)
            for(ll T1=mina;T1<=maxa;T1++)
                for(ll T2=minb;T2<=maxb;T2++)
                {
                    retSol.psb(mp(T1,T2));
                    return retSol;
                }
        return retSol;
    }
    else if(a==0)
    {
        if(c/b>=minb&&c/b<=maxb)
            for(ll T=mina;T<=maxa;T++)
            {
                retSol.psb(mp(T,c/b));
                return retSol;
            }
        return retSol;
    }
    else if(b==0)
    {
        if(c/a>=mina&&c/a<=maxa)
            for(ll T=minb;T<=maxb;T++)
            {
                retSol.psb(mp(c/a,T));
                return retSol;
            }
        return retSol;
    }
    x1=(c/g)*x0;
    y1=(c/g)*y0;
    ll minT1,maxT1, minT2,maxT2,minT,maxT,a1,b1;
    a1=b/g;
    b1=a/g;
    minT1=Ceil(mina-x1,a1);
    maxT1=Floor(y1-minb,b1);
    minT2=Ceil(y1-maxb,b1);
    maxT2=Floor(maxa-x1,a1);
    minT=max(minT1,minT2);
    maxT=min(maxT1,maxT2);
    for(ll T=minT;T<=maxT;T++)
    {
        x=x1+a1*T;
        y=y1-b1*T;
        if(x<mina||x>maxa || y<minb||y>maxb) continue;
        retSol.psb(mp(x1+a1*T , y1-b1*T));
        break;
    }
    for(ll T=maxT;T>minT;T--)
    {
        x=x1+a1*T;
        y=y1-b1*T;
        if(x<mina||x>maxa || y<minb||y>maxb) continue;
        retSol.psb(mp(x1+a1*T , y1-b1*T));
        break;
    }
    return retSol;
}

int val1[MAX];
int val2[MAX];

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    ll m,x1,x2,y1,y2,a1,a2,h1,h2;
    cin>>m;
    cin>>h1>>a1;
    cin>>x1>>y1;
    cin>>h2>>a2;
    cin>>x2>>y2;
    ll s1=-1,r1=1,s2=-1,r2=1;
    hm1[h1]=r1;
    val1[r1]=h1;
    hm2[h2]=r2;
    val2[r2]=h2;
    for(int i=1;;i++)
    {
        h1=(x1*h1+y1)%m;
        if(hm1[h1])
        {
            val1[r1+1]=h1;
            break;
        }
        r1++;
        hm1[h1]=r1;
        val1[r1]=h1;
        if(h1==a1) s1=r1;
    }
    for(int i=1;;i++)
    {
        h2=(x2*h2+y2)%m;
        if(hm2[h2])
        {
            val2[r2+1]=h2;
            break;
        }
        r2++;
        hm2[h2]=r2;
        val2[r2]=h2;
        if(h2==a2) s2=r2;
    }

    ll cl1,cl2;
    cl1=r1-hm1[h1]+1;
    cl2=r2-hm2[h2]+1;
    if(s1==-1 || s2==-1)
    {
        cout<<-1<<"\n";
        return 0;
    }
    if(s1==s2)
    {
        cout<<(s1-1)<<"\n";
        return 0;
    }
    ll res=oo;
    if(val1[s2]==a1) res=s2;
    if(val2[s1]==a2) res=min(res,s1);
    if(res!=oo)
    {
        cout<<res-1<<"\n";
        return 0;
    }
    if(s1<hm1[h1] || s2<hm2[h2])
    {
        cout<<-1<<"\n";
        return 0;
    }
    ll a=cl1,b=cl2,c=(s1>s2?s1-s2:s2-s1);
    if(s1>s2) swap(a,b),swap(s1,s2),swap(cl1,cl2);
    b=-b;
    ll maxa=oo,mina=0;
    ll maxb=oo,minb=0;
    ll sa=1;
    ll sb=1;
    ll tmp;
    if(a<0)
    {
        a=-a;
        tmp=mina;
        mina=-maxa;
        maxa=-tmp;
        sa=-1;
    }
    if(b<0)
    {
        b=-b;
        tmp=minb;
        minb=-maxb;
        maxb=-tmp;
        sb=-1;
    }
    vector<pair<ll,ll> > retsol = find_all_solution_in_range(a,b,c,mina,maxa,minb,maxb);
    if(retsol.empty())
    {
        cout<<"-1\n";
        return 0;
    }
    ll ans1=retsol[0].fs*sa*cl1+s1,ans2=retsol[0].sc*sb*cl2+s2;
    if(ans1==ans2)
    {
        if(SZ(retsol)==1) cout<<ans1-1<<"\n";
        else
        {
            ll ans3=retsol[1].fs*sa*cl1+s1,ans4=retsol[1].sc*sb*cl2+s2;
            if(ans3==ans4)
            {
                ans1=min(ans1,ans3);
                cout<<ans1-1<<"\n";
            }
            else
            {
                cout<<"-1\n";
            }
        }
    }
    else
    {
        if(SZ(retsol)==2)
        {
            ll ans3=retsol[1].fs*sa*cl1+s1,ans4=retsol[1].sc*sb*cl2+s2;
            if(ans3==ans4)
            {
                cout<<ans3-1<<"\n";
            }
            else
            {
                cout<<"-1\n";
            }
        }
        else cout<<"-1\n";
    }
    return 0;
}

/**
IN:

129081
128454 36771
116353 2940
95311 22200
579 118683

OUT:

68409

*/



/**

29
4 0
1 1
25 20
16 0

*/




