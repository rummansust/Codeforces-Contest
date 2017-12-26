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

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define clrint(name,val,s) memset(name,(val),sizeof(int)*s);
#define Assign(name,val) name.assign(val+1,vector<int>())
#define EPS 10e-6
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1LL<<30)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("input.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

using namespace std;

template<class T>inline T Max(T a,T b){return a>b?a:b;}
template<class T>inline T Min(T a,T b){return a>b?b:a;}
template<class T>inline T _GCD(T a,T b){if(b==0) return a;return _GCD(b,a%b);}
template<class T>inline T _LCM(T a,T b){T g=_GCD(a,b);return ((a/g)*b);}
template<class T>inline T big_mod(T a,T p,T MOD){if(p==0) return 1;T ret=big_mod(a,p/2,MOD);ret=(ret*ret)%MOD;if(ret<0) ret+=MOD;if(p%2) ret=(ret*a)%MOD;if(ret<0) ret+=MOD;return ret;}
template<class T>inline T power(T a,T p){if(p==0) return 1;ll ret=power(a,p/2);ret=(ret*ret);if(p%2) ret=(ret*a);return ret;}
template<class T0,class T1,class T2>inline T1 string_mod_ll(T0 s,T1 mm,T2 Sz){T1 n=0;for(int i=0;i<Sz;i++){n=n*10+(ll)(s[i]-'0');n%=mm;}return n;}

int compare(string a,string b){if(a==b) return 0;if(SZ(a)==SZ(b)){for(int i=0; i<SZ(a); i++){if(a[i]>b[i]) return 1;else if(a[i]<b[i]) return -1;}return -1;}if(SZ(a)>SZ(b)) return 1;return -1;}
string string_add(string b,string a){if(SZ(a)>SZ(b)) swap(a,b);a=string((SZ(b)-SZ(a)),'0')+a;int carry=0,add;string res;for(int i=SZ(a)-1; i>-1; i--){add=(int)(a[i]-'0')+(int)(b[i]-'0')+carry;carry=add/10;res+=(add%10)+'0';}if(carry) res+=carry+'0';reverse(res.begin(),res.end());return res;}
string string_mul(string a,string b){if(SZ(a)>SZ(b)) swap(a,b);string res,tres;int l=0,carry,mul;for(int i=SZ(a)-1; i>-1; i--){tres=string(l,'0');carry=0;for(int j=SZ(b)-1; j>-1; j--){mul=(int)(a[i]-'0')*(int)(b[j]-'0')+carry;carry=mul/10; tres+=(mul%10)+'0'; }if(carry) tres+=carry+'0';reverse(tres.begin(),tres.end());res=string_add(tres,res);l++;}return res;}
void cut_leading_zero(string &res){int i;for(i=0; i<SZ(res); i++){if(res[i]!='0') break;}res=res.substr(i);if(!SZ(res)) res="0";return;}

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


#define MAX 401000

char text[MAX];

char str[205000];

int solve(int l1,int r1,int l2,int r2,int n)
{
    int ql,qr,match=0;
    int ps=(r1-l1+1);
    int ret=0;
    for(int i=l1,j=l2;i<=r1;i++,j++)
    {
        if(text[i]!=text[j])
        {
            ret=1;
            break;
        }
    }
    if(ret==0) return true;
    if(match>=ps) return true;
    if(ps&1)
    {
        return false;
    }
    else
    {
        int m1=(l1+r1)>>1,m2=(l2+r2)>>1;
        ret = (solve(l1,m1,l2,m2,n) && solve(m1+1,r1,m2+1,r2,n));
        if(ret) return true;
        ret = (solve(l1,m1,m2+1,r2,n) && solve(m1+1,r1,l2,m2,n));
        return ret;
    }
}

int main()
{
    SF("%s",text);
    int ns=strlen(text);
    SF("%s",str);
    text[ns]='#';
    for(int i=0;i<ns;i++)
    {
        text[i+ns+1]=str[i];
    }
    text[2*ns+1]='\0';
    int n=strlen(text);
    if(solve(0,ns-1,ns+1,n-1,n))
    {
        PF("YES\n");
    }
    else PF("NO\n");
    return 0;
}













