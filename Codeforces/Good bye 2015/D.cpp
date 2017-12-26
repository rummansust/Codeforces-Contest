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
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 1<<25
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

///pass a vector to a funtion: funtion (vector <data type> &vector name);
///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<"\n";}

#define MAX 5010

string text;
int revSA[MAX],SA[MAX];
int cnt[MAX] , nxt[MAX];
bool bh[MAX],b2h[MAX];
int LCP[MAX];


bool cmp(const int &i,const int &j)
{
    return text[i]<text[j];
}

void sortFirstChar(int n)
{
    /// sort for the first char  ...
    for(int i =0 ; i<n ; i++)
        SA[i] = i;
    sort(SA,SA+n ,cmp);

    ///indentify the bucket ........
    for(int i=0 ; i<n ; i++)
    {
        bh[i] = (i==0  || text[SA[i]]!=text[SA[i-1]]);
        b2h[i] = false;
    }
    return;
}

int CountBucket(int n)
{
    int bucket = 0;
    for(int i =0 ,j; i<n ; i=j)
    {
        j = i+1;
        while(j<n && bh[j]==false) j++;
        nxt[i] = j;
        bucket++;
    }
    return bucket;
}

void SetRank(int n)
{
    for(int i = 0 ; i<n ; i=nxt[i])
    {
        cnt[i] = 0;
        for(int j =i ; j<nxt[i] ; j++)
        {
            revSA[SA[j]] = i;
        }
    }
    return;
}

void findNewRank(int l,int r,int step)
{
    for(int j = l  ; j<r ; j++)
    {
        int pre = SA[j] - step;
        if(pre>=0)
        {
            int head = revSA[pre];
            revSA[pre] = head+cnt[head]++;
            b2h[revSA[pre]] = true;
        }
    }
    return;
}

void findNewBucket(int l,int r,int step)
{
    for(int j = l  ; j<r ; j++)
    {
        int pre = SA[j] - step;
        if(pre>=0 && b2h[revSA[pre]])
        {
            for(int k = revSA[pre]+1 ; b2h[k] && !bh[k] ; k++) b2h[k] = false;
        }
    }
    return;
}

void buildSA(int n)
{
    ///start sorting in logn step ...
    sortFirstChar(n);
    for(int h =1 ; h<n ; h<<=1)
    {
        if(CountBucket(n)==n) break;
        SetRank(n);
        /// cause n-h suffix must be sorted
        b2h[revSA[n-h]] = true;
        cnt[revSA[n-h]]++;

        for(int i = 0 ; i<n ; i=nxt[i])
        {
            findNewRank(i,nxt[i] , h);
            findNewBucket(i , nxt[i] , h);
        }
        ///set the new sorted suffix array ...
        for(int i =0 ; i<n ; i++)
        {
            SA[revSA[i]] = i;
            bh[i] |= b2h[i]; ///new bucket ....
        }
    }
    return;
}

void buildLCP(int n)
{
    int len = 0;
    for(int i = 0 ;i<n ; i++)
        revSA[SA[i]] = i;
    for(int i =0 ; i< n ; i++)
    {
        int k = revSA[i];
        if(k==0)
        {
            LCP[k] = 0;
            continue;
        }
        int j = SA[k-1];
        while(text[i+len]==text[j+len]) len++;
        LCP[k] = len;
        if(len) len--;
    }
    return;
}

void printSA(int n)
{
    for(int i=0;i<n;i++) printf("%2d ",SA[i]),cout<<text.substr(SA[i])<<endl;
    puts("");
    for(int i=1;i<n;i++) printf("%2d\n",LCP[i]);
    puts("");
    return ;
}

int tree[MAX*4];

void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx]=LCP[l];
        return ;
    }
    int mid=(l+r)>>1,nidx=(idx<<1);
    build(nidx,l,mid);
    build(nidx+1,mid+1,r);
    tree[idx]=min(tree[nidx],tree[nidx+1]);
    return ;
}
int query(int idx,int l,int r,int ql,int qr)
{
    if(r<ql||l>qr||ql>qr||l>r) return oo;
    if(l>=ql&&r<=qr) return tree[idx];
    int mid=(l+r)>>1,nidx=(idx<<1);
    return min(query(nidx,l,mid,ql,qr),query(nidx+1,mid+1,r,ql,qr));
}

char str[MAX];

int n;
const int MOD = 1000000007;
int dp[MAX][MAX];
int sp[MAX][MAX];

inline int add(int a,int b)
{
    int n=a+b;
    if(n>=MOD) return n-MOD;
    else if(n<0) return n+MOD;
    else return n;
}

int main()
{
    sf("%d",&n);
    sf("%s",&str);
    text=str;
    buildSA(n);
    buildLCP(n);
    build(1,0,n-1);
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=1;
        sp[1][i]=1;
    }
    int a,b,c,d,m;
    for(int c=2;c<=n;c++)
    {
        for(int d=c;d<=n;d++)
        {
            a=max(2*c-d-1,0);
            b=c-1;
            if(str[c-1]!='0')
            {
                dp[c][d]=add(sp[b][b],-sp[a][b]);
                a=2*c-d-1;
                if(a>0)
                {
                    m=query(1,0,n-1,revSA[a-1]+1,revSA[c-1]);
                    if(m<d-c+1 && str[a+m-1]<str[c+m-1])
                    {
                        dp[c][d]=add(dp[c][d],dp[a][b]);
                    }
                }
            }
            sp[c][d]=add(sp[c][d],sp[c-1][d]);
            sp[c][d]=add(sp[c][d],dp[c][d]);
        }
    }
    int ret=0;
    for(int i=1;i<=n;i++) ret=add(ret,dp[i][n]);
    pf("%d\n",ret);
    return 0;
}
















