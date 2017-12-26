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

char arr[100009];

int main()
{
    #ifdef I_AM_HD
//    Read;
//    Write;
    #endif // I_AM_HD
    /**
        Don't use cin, cout.
    */
    SF("%s",&arr);
    string str=arr;
    int n=SZ(str);
    int ab=0,ba=0,i;
    for(i=0;i<n-1;i++)
    {
        if(str[i]=='A'&&str[i+1]=='B')
        {
            i+=2;
            ab=1;
            for(;i<n-1;i++)
            {
                if(str[i]=='B'&&str[i+1]=='A')
                {
                    ba=1;
                    i=n;
                    break;
                }
            }
        }
    }
    if(ab&&ba)
    {
        deb("YES");
        return 0;
    }
    ab=ba=0;
    for(i=0;i<n-1;i++)
    {
        if(str[i]=='B'&&str[i+1]=='A')
        {
            i+=2;
            ba=1;
            for(;i<n-1;i++)
            {
                if(str[i]=='A'&&str[i+1]=='B')
                {
                    ab=1;
                    i=n;
                    break;
                }
            }
        }
    }
    if(ab&&ba)
    {
        deb("YES");
        return 0;
    }
    deb("NO");
    return 0;
}








































