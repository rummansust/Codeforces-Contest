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

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }
ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }
ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

int grid[850][850];
struct data{
    int a,b,sum;
    data(){}
    data(int a,int b,int sum):a(a),b(b),sum(sum){}
    bool operator < (const data &x) const{
        return sum<x.sum;
    }
};

int n,N;
int main()
{
    SF("%d",&N);
    n=N*2;
    priority_queue<data> pq;
    int flag[805];
    clrall(flag,-1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            SF("%d",&grid[i][j]);
            grid[j][i]=grid[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            pq.push(data(i,j,grid[i][j]));
        }
    }
    while(!pq.empty())
    {
        int u,v,sum;
        u=pq.top().a;
        v=pq.top().b;
        sum=pq.top().sum;
        pq.pop();
        if(flag[u]==-1 && flag[v]==-1)
        {
            flag[u]=v+1;
            flag[v]=u+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        PF("%d%c",flag[i]," \n"[i==n-1]);
    }
    return 0;
}













