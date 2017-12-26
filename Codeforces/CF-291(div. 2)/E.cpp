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
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

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
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

const int dim=101;

const ll MOD = 1000000007ll;

class Matrix{
public:
    int mat[dim+2][dim+2];
    Matrix()
    {
        clrall(mat,0);
    }
    Matrix friend operator* (Matrix &A,Matrix &B)
    {
         Matrix ret;
         ll sum=0;
         for(int i=0;i<dim;i++)
         {
             for(int j=0;j<dim;j++)
             {
                 sum=0LL;
                 for(int k=0;k<dim;k++)
                 {
                     sum=sum+(((ll)A.mat[i][k]*(ll)B.mat[k][j])%MOD);
                     sum%=MOD;
                 }
                 ret.mat[i][j]=sum;
             }
         }
         return ret;
    }
    Matrix operator^(int P)
    {
        Matrix &ret=(*this),II;
        II=Matrix();
        for(int i=0;i<dim;i++) II.mat[i][i]=1;
        while(P)
        {
            if(P&1) II=(II*ret);
            if(P!=1) ret=ret*ret;
            P=P>>1;
        }
        ret=II;
        return ret;
    }
};

int dp[dim+7];
int cnt[dim+7];

int rec(int x)
{
    if(x==0) return dp[0]=1;
    int &ret = dp[x];
    if(ret!=-1) return ret;
    ret=1;
    for(int i=1;i<=100;i++)
    {
        if(i>x) break;
        if(cnt[i])
        {
            ret=ret+(((ll)cnt[i]*(ll)rec(x-i))%MOD);
            ret%=MOD;
        }
    }
    return ret;
}


int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    Matrix Base;
    int n,res,x;
    sf("%d %d",&n,&x);
    for(int i=0;i<n;i++)
    {
        sf("%d",&res);
        cnt[res]++;
    }
    clrall(dp,-1);
    if(x<=100)
    {
        pf("%d\n",rec(x));
    }
    else
    {
        clrall(dp,-1);
        for(int i=100;i>=0;i--) rec(i);
        clrall(Base.mat,0);
        Base.mat[0][0]=1;
        for(int i=1;i<100;i++) Base.mat[i][i+1]=1;
        Base.mat[100][0]=1;
        for(int i=1;i<=100;i++) Base.mat[100][i]=cnt[100-i+1];
        Base=Base^(x-100);
        res=0;
        for(int i=0;i<=100;i++)
        {
            res=res+(((ll)Base.mat[100][i]*(ll)dp[i])%MOD);
            res%=MOD;
        }
        pf("%d\n",res);
    }
    return 0;
}

/**
3 101
1 2 3
*/
























