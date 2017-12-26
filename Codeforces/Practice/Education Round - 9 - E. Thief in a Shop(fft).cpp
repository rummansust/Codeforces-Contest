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

#define pi acos(-1)
#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name))
#define EPS 1e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define inf 0x3f3f3f3f
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false),cin.tie(0),cout.tie(0)

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

ll BigModML(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=MulModL(R,B,M); } P/=2; B=MulModL(B,B,M); } return R; } /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<"\n";}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

typedef vector<int> vi;

//*************************************************My Code Starts Here*********************************************************************************
// nlogn complexity
// memory complexity 12n
/* application
   1. multiplying two arrays.
   2. multiplying two long(string) numbers.
*/
// i-th index mean coefficient of i-th power


struct cmplx{
    double r,i;

    inline cmplx(){r=i=0.0;}
    inline cmplx(double x){r=x,i=0.0;}
    inline cmplx(double x,double y){r=x,i=y;}

    inline void operator+= (const cmplx &q){r+=q.r,i+=q.i;}
    inline void operator-= (const cmplx &q){r-=q.r,i-=q.i;}

    inline cmplx operator+ (const cmplx &q){
        return cmplx(r+q.r,i+q.i);
    }
    inline cmplx operator- (const cmplx &q){
        return cmplx(r-q.r,i-q.i);
    }
    inline cmplx operator* (const cmplx &q){
        return cmplx(r*q.r-i*q.i,r*q.i+i*q.r);
    }
};

typedef cmplx base;


void fft(vector<base> &a,bool invert) //invert=true means inverse FFT
{
    int n=(int)a.size();

    for(int i=1,j=0;i<n;++i)
    {
        int bit=n>>1;
        for(; j>=bit; bit>>=1) j-=bit;
        j+=bit;
        if(i<j) swap(a[i],a[j]);
    }

    for(int len=2;len<=n;len<<=1)
    {
        double ang=2*pi/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for(int i=0; i<n; i+=len)
        {
            base w(1);
            for(int j=0;j<len/2;++j)
            {
                base u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w=w*wlen;
            }
        }
    }
    if (invert)
        for (int i=0;i<n;++i) a[i].r/=n;
    return ;
}

void multiply (vi &a, vi &b)
{
    vector<base> fa(all(a)),fb(all(b));
    size_t n = 1;
    while (n<max(a.size(),b.size())) n<<=1; //making it a power of 2
    n <<= 1; //making double size(2*n)
    fa.resize(n),fb.resize(n);

    fft(fa,false),fft(fb,false);
    for (size_t i=0;i<n;++i)
        fa[i]=fa[i]*fb[i];
    fft(fa,true); //inverse fft

    for (size_t i=0;i<n;++i)
    {
        if(i<SZ(a)) a[i]=(int(fa[i].r+0.5)>0);
        else a.psb((int(fa[i].r+0.5)>0));
    }
    return ;
}

int a[1010];

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    vector<int> p,r,q;
    int n,k;
    sf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        sf("%d",&a[i]);
    }
    sort(a,a+n);
    int b=a[0];
    int m=0,mx=0;
    for(int i=0;i<n;i++)
    {
        a[i]-=b;
        mx=max(a[i],mx);
//        if(a[i]) m++;
    }
    p.resize(mx+1,0);
    r.resize(mx+1,0);
    r[0]=1;
    for(int i=0;i<n;i++)
    {
        p[a[i]]=1;
    }
    p[0]=1;
    m=k;
    while(m)
    {
        if(m&1)
        {
            multiply(r,p);
        }
        multiply(p,p);
        m>>=1;
    }
    int f=0;
    for(int i=0;i<SZ(r);i++)
    {

        if(r[i])
        {
            if(f) pf(" ");
            f=1;
            pf("%d",i+b*k);
        }
    }
    pf("\n");
    return 0;
}

/**
998244353
70383776563201ll
7340033
*/












