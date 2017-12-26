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
//    Write;
    #endif // I_AM_HD
    /**
        Don't use cin, cout.
    */

    int arr[20],n,l,r,x;
    cin>>n>>l>>r>>x;
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);

    int lim=(1<<n);
    int ans=0;
    for(int i=3;i<lim;i++)
    {
        int tp=__builtin_popcount(i);
        if(tp>1)
        {
            int dif=0,tot=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    tot+=arr[j];
                }
            }
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    dif=-arr[j];
                    break;
                }
            }
            for(int j=n-1;j>-1;j--)
            {
                if(i&(1<<j))
                {
                    dif+=arr[j];
                    break;
                }
            }
            if(tot>=l&&tot<=r&&dif>=x) ans++;
        }
    }
    deb(ans);
    return 0;
}













