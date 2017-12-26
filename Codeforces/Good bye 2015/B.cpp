#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<list>
#include<algorithm>
#include<stack>
#include<assert.h>

#define LOCAL_TEST true
#define SZ(x) ((int)x.size())
#define clr(name,val) memset(name,(val),sizeof(name));
#define Assign(name,val) name.assign(val+1,vector<int>())
#define EPS .000000001
#define ll long long
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo ((int)(INT_MAX))
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)

using namespace std;

int compare(string a,string b)
{
    if(a==b) return 0;
    if(SZ(a)==SZ(b))
    {
        for(int i=0; i<SZ(a); i++)
        {
            if(a[i]>b[i]) return 1;
            else if(a[i]<b[i]) return -1;
        }
        return -1;
    }
    if(SZ(a)>SZ(b)) return 1;
    return -1;
}
string string_add(string b,string a)
{
    if(SZ(a)>SZ(b)) swap(a,b);
    a=string((SZ(b)-SZ(a)),'0')+a;
    int carry=0,add;
    string res;
    for(int i=SZ(a)-1; i>-1; i--)
    {
        add=(int)(a[i]-'0')+(int)(b[i]-'0')+carry;
        carry=add/10;
        res+=(add%10)+'0';
    }
    if(carry) res+=carry+'0';
    reverse(res.begin(),res.end());
    return res;
}
string string_mul(string a,string b)
{
    if(SZ(a)>SZ(b)) swap(a,b);
    string res,tres;
    int l=0,carry,mul;
    for(int i=SZ(a)-1; i>-1; i--)
    {
        tres=string(l,'0');
        carry=0;
        for(int j=SZ(b)-1; j>-1; j--)
        {
            mul=(int)(a[i]-'0')*(int)(b[j]-'0')+carry;
            carry=mul/10;
            tres+=(mul%10)+'0';
        }
        if(carry) tres+=carry+'0';
        reverse(tres.begin(),tres.end());
        res=string_add(tres,res);
        l++;
    }
    return res;
}
void cut_leading_zero(string &res)
{
    int i;
    for(i=0; i<SZ(res); i++)
    {
        if(res[i]!='0') break;
    }
    res=res.substr(i);
    if(!SZ(res)) res="0";
    return;
}
ll big_mod(ll a,ll p,ll MOD)
{
    if(p==0) return 1L;
    ll ret=big_mod(a,p/2,MOD);
    ret=((ret*ret)%MOD+MOD)%MOD;
    if(p%2) ret=((ret*a)%MOD+MOD)%MOD;
    return ret;
}
ll power(ll a,ll p)
{
    if(p==0) return 1L;
    ll ret=power(a,p/2);
    ret=(ret*ret);
    if(p%2) ret=(ret*a);
    return ret;
}
int fastMax(int x, int y)
{
    return (((y-x)>>(32-1))&(x^y))^y;
}
int fastMin(int x, int y)
{
    return (((y-x)>>(32-1))&(x^y))^x;
}
///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

int ind[80],len;
ll dp[80][2][2][4];
///first -> no of soln. second no of zeros.
ll rec(int pos,bool lz,bool flag,int ok,ll v=0)
{
    if(pos<0)
    {
        if(ok==1) return 1;
        else return 0;
    }
    ll &ret = dp[pos][lz][flag][ok];
    if(ret!=-1LL) return ret;
    ret=0;
    int mx=flag?ind[pos]:1;
    bool nflag,nlz;
    for(int i=0; i<=mx; i++)
    {
        if(lz&&i==0) nlz=true;
        else nlz=false;
        if(i==mx&&flag) nflag=true;
        else nflag=false;
        ret+=rec(pos-1,nlz,nflag,min(2,ok+(nlz==false && i==0)),v+i*(1ll<<pos));
    }
    return ret;
}

int main()
{
    ll a,b;
    int test,cas=0,mx;
    ll tmp;
    ll res;
    cin>>a>>b;
    len=0;
    while(b)
    {
        ind[len++]=b%2;
        b/=2;
    }
    clr(dp,-1LL);
    tmp=rec(len-1,true,true,0);
    res=tmp;
    a=a-1;
    if(a>0)
    {
        len=0;
        clr(dp,-1LL);
        while(a)
        {
            ind[len++]=a%2;
            a/=2;
        }
        tmp=rec(len-1,true,true,0);
        res-=tmp;
    }
    cout<<res<<endl;
    return 0;
}













