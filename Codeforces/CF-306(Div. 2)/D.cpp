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

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.fs==b.fs) return a.sc>b.sc;
    return a.fs<b.fs;
}

int main()
{
    #ifdef I_AM_HD
//    Read;
//    Write;
    #endif // I_AM_HD
    /**
        Don't use cin, cout.
    */
    int n;
    cin>>n;
    if(n&1)
    {
        deb("YES");
        int k=n-1;
        int N=n;
        n=2*n-1;
        vector< pair<int,int> > edge;
        for(int i=1;i<=k;i++)
        {
            for(int j=i+1;j<=k;j++)
            {
                edge.psb(mp(i,j));
            }
        }
        for(int i=1,j=k+1;i<=(k>>1);i++,j+=2)
        {
            edge.psb(mp(i,j));
            edge.psb(mp(i,j+1));
        }
        for(int i=(k>>1)+1,j=k+1;i<=k;i++,j+=2)
        {
            edge.psb(mp(i,j));
            edge.psb(mp(i,j+1));
        }

        vector<pair<int,int> > tmp;
        for(int i=k+1;i<=(k<<1);i++)
        {
            tmp.psb(mp(N-3,i));
            edge.psb(mp(i,n));
        }
        for(int i=k+1,p;i<=(k<<1);i++)
        {
            sort(all(tmp),cmp);
            p = SZ(tmp);
            int curN=tmp[p-1].sc;
            int curW=tmp[p-1].fs;
            for(int j=p-2;j>-1 && curW>0;j--)
            {
                int nowN=tmp[j].sc;
                int nowW=tmp[j].fs;
                if(nowW>0&&curW>0)
                {
                    nowW--;
                    curW--;
                    tmp[j].fs=nowW;
                    edge.psb(mp(curN,nowN));
                }
                else break;
            }
            tmp[p-1].fs=curW;
        }

        edge.psb(mp(n,n+1));
        for(int i=1;i<=k;i++)
        {
            for(int j=i+1;j<=k;j++)
            {
                edge.psb(mp(i+n+1,j+n+1));
            }
        }
        for(int i=1,j=k+1;i<=(k>>1);i++,j+=2)
        {
            edge.psb(mp(i+n+1,j+n+1));
            edge.psb(mp(i+n+1,j+1+n+1));
        }
        for(int i=(k>>1)+1,j=k+1;i<=k;i++,j+=2)
        {
            edge.psb(mp(i+n+1,j+n+1));
            edge.psb(mp(i+n+1,j+1+n+1));
        }

        tmp.clear();
        for(int i=k+1+n+1;i<=(k<<1)+n+1;i++)
        {
            tmp.psb(mp(N-3,i));
            edge.psb(mp(n+1,i));
        }
        for(int i=k+1+n+1,p;i<=(k<<1)+n+1;i++)
        {
            sort(all(tmp),cmp);
            p = SZ(tmp);
            int curN=tmp[p-1].sc;
            int curW=tmp[p-1].fs;
            for(int j=p-2;j>-1 && curW>0;j--)
            {
                int nowN=tmp[j].sc;
                int nowW=tmp[j].fs;
                if(nowW>0&&curW>0)
                {
                    nowW--;
                    curW--;
                    tmp[j].fs=nowW;
                    edge.psb(mp(curN,nowN));
                }
                else break;
            }
            tmp[p-1].fs=curW;
        }

        for(int i=0;i<SZ(edge);i++)
        {
            deb(edge[i].fs,edge[i].sc);
        }
    }
    else deb("NO");
    return 0;
}

























