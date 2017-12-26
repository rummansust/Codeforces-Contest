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
#define SF scanf
#define PF printf
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

#define casePrint PF("Case #%d: ",++cas);

int dp[101][902];

int l;
vector<int> ans;

int rec(int pos,int sum)
{
    if(sum<0) return 0;
    if(pos==l)
    {
        return (sum==0);
    }
    int &ret = dp[pos][sum];
    if(ret!=-1) return ret;
    ret=0;
    int st=(pos==0)?1:0;
    for(int i=st;i<10;i++)
    {
        ret|=rec(pos+1,sum-i);
    }
    return ret;
}

void prec(int pos,int sum)
{
    if(sum<0) return ;
    if(pos==l)
    {
        return ;
    }
    int st=(pos==0)?1:0;
    for(int i=st;i<10;i++)
    {
        if(rec(pos+1,sum-i))
        {
            ans.psb(i);
            prec(pos+1,sum-i);
            return ;
        }
    }
    return ;
}

int dp2[101][902];

vector<int> ans2;

int rec2(int pos,int sum)
{
    if(sum<0) return 0;
    if(pos==l)
    {
        return (sum==0);
    }
    int &ret = dp2[pos][sum];
    if(ret!=-1) return ret;
    ret=0;
    int st=9;
    for(int i=st;i>-1;i--)
    {
        ret|=rec2(pos+1,sum-i);
    }
    return ret;
}

void prec2(int pos,int sum)
{
    if(sum<0) return ;
    if(pos==l)
    {
        return ;
    }
    int st=9;
    for(int i=st;i>-1;i--)
    {
        if(rec2(pos+1,sum-i))
        {
            ans2.psb(i);
            prec2(pos+1,sum-i);
            return ;
        }
    }
    return ;
}


int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    __;
    int s;
    clrall(dp,-1);
    clrall(dp2,-1);
    cin>>l>>s;
    if(l*9<s)
    {
        cout<<-1<<" "<<-1<<"\n";
        return 0;
    }
    if(l==1)
    {
        cout<<s<<" "<<s<<"\n";
        return 0;
    }
    if(rec(0,s)&&rec2(0,s))
    {
        prec(0,s);
        prec2(0,s);
        for(int i=0;i<l;i++) cout<<ans[i];
        cout<<" ";
        for(int i=0;i<l;i++) cout<<ans2[i];
        cout<<"\n";
    }
    else{
        cout<<-1<<" "<<-1<<"\n";
        return 0;
    }
    return 0;
}

















