#include <bits/stdc++.h>

using namespace std;

#define __ std::ios_base::sync_with_stdio (false)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define clean(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second

ll BigMod(ll B,ll P,ll M){ ll R=1; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}/// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}

//int dx[]= {0,0,1,-1};
//int dy[]= {-1,1,0,0};
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};
//int dy[]= {0,1,1,1,0,-1,-1,-1};
//int dx[]={1,1,2,2,-1,-1,-2,-2};
//int dy[]={2,-2,1,-1,2,-2,1,-1};

int main()
{
    #ifdef I_AM_HD
//    Read;
    Write;
    #endif // I_AM_HD
    /**
        Don't use cin, cout.
    */
    ll N,S,T;
    int cnt=1;
    srand(time(NULL));
//    while(cnt--)
    {
//        N=rand()%500000+1;
        N=500000;
        double meanC=0;
//        cin>>N;
        for(int i=0;i<20;i++)
        {
            double C,minC=1.0e16;
            ll mS=1,mT=N;
            ll P=rand()%100007,Q;
            int cntBit = 0;
            for(int i=0;i<P;i++)
            {
                Q=rand();
                Q&=3;
                if(Q) cntBit++;
            }
            P=(double)(1.0*N*cntBit/(1.0*P));
            //P=rand()%250000+1;
            if(i>18) P=250000;
            Q=N-P;
            int toss=rand();
            if(toss&1) swap(P,Q);
            for(T=1;T<=N;T++)
            {
                S=N/T+(N%T!=0);
                S=(S<2?2:S);
                C=2.0*S*(P+Q) + 1.0*T*P + 1.0*T*Q*(log10(S)/log10(2.0));
//                if(i>18) C=4.0*S + 1.0*T + 1.0*T*(log10(S)/log10(2.0));
//                PF("S : %8lld T : %8lld %10.3lf %10.3lf\n",S,T,C,(log10(S)/log10(2.0)));
                if(C<minC)
                {
                    minC=C;
                    mS=S;
                    mT=T;
                }
            }
            meanC+=minC;
            PF("N : %8lld \tmS : %8lld \tmT : %8lld \tP : %8lld \tQ : %8lld \tcomplexity : %8.3lf\n",N,mS,mT,P,Q,minC);
        }
//        deb(mS,mT,minP);
        PF("mean Complexity : %.3lf\n",meanC/20.0);
    }
    return 0;
}













