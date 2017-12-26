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

typedef pair<int,int> pii;
vector<string> mov;
pii sq[3];
int idx[1000];
char grid[1000][1000];
int res=0;

bool checkW(int id,int mask)
{
    pii tmp[3];
    for(int i=0;i<3;i++)
    {
        tmp[i]=sq[idx[mov[id][i]]];
        if((mask>>i)&1) swap(tmp[i].fs,tmp[i].sc);
    }
    if(tmp[0].fs==tmp[1].fs && tmp[1].fs==tmp[2].fs && (tmp[0].fs==(tmp[0].sc+tmp[1].sc+tmp[2].sc)))
    {
        res=tmp[0].fs;
        for(int j=0;j<tmp[0].sc;j++)
        {
            for(int k=0;k<res;k++)
            {
                grid[j][k]=mov[id][0];
            }
            grid[j][res]='\0';
        }
        for(int j=tmp[0].sc;j<tmp[0].sc+tmp[1].sc;j++)
        {
            for(int k=0;k<res;k++)
            {
                grid[j][k]=mov[id][1];
            }
            grid[j][res]='\0';
        }
        for(int j=tmp[0].sc+tmp[1].sc;j<tmp[0].sc+tmp[1].sc+tmp[2].sc;j++)
        {
            for(int k=0;k<res;k++)
            {
                grid[j][k]=mov[id][2];
            }
            grid[j][res]='\0';
        }
        return true;
    }
    return false;
}

bool checkM(int id,int mask)
{
    pii tmp[3];
    for(int i=0;i<3;i++)
    {
        tmp[i]=sq[idx[mov[id][i]]];
        if((mask>>i)&1) swap(tmp[i].fs,tmp[i].sc);
    }
    if(tmp[0].fs+tmp[1].fs==tmp[2].fs && tmp[0].sc==tmp[1].sc && tmp[0].sc+tmp[2].sc == tmp[0].fs+tmp[1].fs)
    {
        res=tmp[2].fs;
        for(int j=0;j<tmp[0].sc;j++)
        {
            for(int k=0;k<tmp[0].fs;k++)
            {
                grid[j][k]=mov[id][0];
            }
        }
        for(int j=0;j<tmp[0].sc;j++)
        {
            for(int k=tmp[0].fs;k<res;k++)
            {
                grid[j][k]=mov[id][1];
            }
            grid[j][res]='\0';
        }
        for(int j=tmp[0].sc;j<res;j++)
        {
            for(int k=0;k<res;k++)
            {
                grid[j][k]=mov[id][2];
            }
            grid[j][res]='\0';
        }
        return true;
    }
    return false;
}

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman

    idx['A']=0;
    idx['B']=1;
    idx['C']=2;

    mov.psb("ABC");
    mov.psb("ACB");
    mov.psb("BCA");
    mov.psb("BAC");
    mov.psb("CAB");
    mov.psb("CBA");

    for(int i=0;i<3;i++)
    {
        sf("%d %d",&sq[i].fs,&sq[i].sc);
    }

    /**
    A
    B
    C
    */
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<8;j++)
        {
            bool f = checkW(i,j);
            if(f)
            {
                pf("%d\n",res);
                for(int l=0;l<res;l++)
                {
                    pf("%s\n",grid[l]);
                }
                return 0;
            }
            f = checkM(i,j);
            if(f)
            {
                pf("%d\n",res);
                for(int l=0;l<res;l++)
                {
                    pf("%s\n",grid[l]);
                }
                return 0;
            }
        }
    }

    pf("-1\n");

    return 0;
}














