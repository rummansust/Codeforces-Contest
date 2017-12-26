#include <bits/stdc++.h>

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
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

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

using namespace std;
#define SZ1 100001000
#define SZ2 5771456
#define MAXD 500

char sieve[(SZ1>>3)+7];
int prime[SZ2];

void bit_sieve()
{
    int i,j,k,r;
    prime[0]=2;
    k=1;
    int lim=(int)sqrt(SZ1)+1;
    sieve[0>>3]|=(1<<(0&7));
    sieve[1>>3]|=(1<<(1&7));

    for(int j=4;j<SZ1;j+=2)
        sieve[j>>3]|=(1<<(j&7));

    for(i=3; i<SZ1; i+=2)
    {
        if(!(sieve[i>>3]&(1<<(i&7))))
        {
            prime[k++]=i;
            if(i<lim)
            {
                r=i<<1;
                for(j=i*i; j<SZ1; j+=r)
                {
                    sieve[j>>3]|=(1<<(j&7));
                }
            }
        }
    }
    return;
}

bool isprime(int n)
{
    int tn=n;
    for(int i=0;(ll) prime[i]*(ll) prime[i]<=(ll)n;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0) n/=prime[i];
        }
    }
    return tn==n;
}

int main()
{
    bit_sieve();
    int n;
    cin>>n;
    if(isprime(n))
    {
        cout<<1<<"\n";
        cout<<n<<"\n";
        return 0;
    }
    if(n&1)
    {
        if(isprime(n-2))
        {
            deb(2);
            deb(2,n-2);
            return 0;
        }
        int a,b,c;
        deb(3);
        for(int i=n;i>n-MAXD && i>2;i--)
        {
            if(isprime(i))
            {
                c=i;
                n-=c;
                break;
            }
        }
        int p=(n>>1)+1;
        for(int i=0; prime[i]<p; i++)
        {
            a=prime[i];
            b=n-prime[i];
            if(b>SZ1-10)
            {
                if(isprime(b))
                {
                    deb(a,b,c);
                    return 0;
                }
            }
            else if(!(sieve[b>>3]&(1<<(b&7))))
            {
                deb(a,b,c);
                return 0;
            }
        }
    }
    else
    {
        int a,b;
        int p=(n>>1)+1;
        deb(2);
        for(int i=0; prime[i]<p; i++)
        {
            a=prime[i];
            b=n-prime[i];
            if(b>SZ1-10)
            {
                if(isprime(b))
                {
                    deb(a,b);
                    return 0;
                }
            }
            else if(!(sieve[b>>3]&(1<<(b&7))))
            {
                deb(a,b);
                return 0;
            }
        }
    }
    return 0;
}
