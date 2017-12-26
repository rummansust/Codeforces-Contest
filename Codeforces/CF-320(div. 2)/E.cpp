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


const int MAX = 200009;

double val[MAX];
int n;

double getRet(double m)
{
    double sum=0;
    double res=0;
    //deb("::::::::::::::::::::::::::::::");
    for(int i=1; i<=n; i++)
    {
        sum+=(val[i]-m);
        //deb(val[i]-m);
        res=max(res,fabs(val[i]-m));
    }
    res=max(res,fabs(sum));
    sum=0;
    double s=1.0;
    for(int i=1; i<=n; i++)
    {
        sum+=(val[i]-m)*s;
        //deb("sum:",sum);
        if(sum<0.0)
        {
            sum=0;
        }
        res=max(res,sum);
    }
    //deb("res:",res);
    s=-1.0;
    sum=0;
    for(int i=1; i<=n; i++)
    {
        sum+=(val[i]-m)*s;
        //deb("sum:",sum);
        if(sum<0.0)
        {
            sum=0;
        }
        res=max(res,sum);
    }
    //deb("res:",res);
    //deb("::::::::::::::::::::::::::::::");
    return res;
}

int main()
{
    SF("%d",&n);
    int v;
    double sum=0;
    for(int i=1; i<=n; i++)
    {
        SF("%d",&v);
        val[i]=v;
    }
    double res=0;
    int cnt=200;
    double lo=-2.0e10,hi=2.0e10,m1,m2;
    while(cnt--)
    {
        m1=(2.0*lo+hi)/3.0;
        m2=(lo+hi*2.0)/3.0;
        double r1=getRet(m1),r2=getRet(m2);
        if(r1<r2)
        {
            res=r1;
            hi=m2;
        }
        else
        {
            res=r2;
            lo=m1;
        }
    }
    PF("%.12lf",res);
    return 0;
}













