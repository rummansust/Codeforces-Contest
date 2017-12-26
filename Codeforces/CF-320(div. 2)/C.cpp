#include<bits/stdc++.h>

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

ll MulModL(ll B,ll P,ll M)
{
    ll R=0;
    while(P>0)
    {
        if((P&1ll)==1)
        {
            R=(R+B);
            if(R>=M) R-=M;
        }
        P>>=1ll;
        B=(B+B);
        if(B>=M) B-=M;
    }
    return R;
}
ll MulModD(ll B, ll P,ll M)
{
    ll I=((long double)B*(long double)P/(long double)M);
    ll R=B*P-M*I;
    R=(R%M+M)%M;
    return R;
}
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

typedef pair<ll,ll> point;

bool dot(point a,point b)
{
    return (a.fs*b.sc-a.sc*b.fs)>=0;
}

int main()
{
    ll p,q;

    cin>>p>>q;

    bool ret=dot(mp(p,q),mp(1,1));
    if(!ret)
    {
        cout<<-1;
        return 0;
    }

    ll a=p;
    ll b=q;
    ll x=a-b;
    double res=1.0e10;
    bool flag=false;
    if(x%(2ll*b)==0)
    {
        flag=true;
        res=b;
    }
    else
    {
        if(x>2ll*b)
        {
            flag=true;
            ll t=x/(2*b);
            res=min(res,1.0*b+(((x%(2*b))*1.0))/(t*2.0));
        }
    }
    x=a+b;
    if(x%(2ll*b)==0)
    {
        flag=true;
        res=b;
    }
    else
    {
        if(x>2ll*b)
        {
            flag=true;
            ll t=x/(2*b);
            res=min(res,1.0*b+(((x%(2*b))*1.0))/(t*2.0));
        }
    }

    if(!flag)
    {
        cout<<-1;
        return 0;
    }

    PF("%.12lf",res);

    return 0;
}













