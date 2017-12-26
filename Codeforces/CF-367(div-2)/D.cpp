/////////////////////////////////////////////////////////////////////////////////
///// problem name : LOJ - 1269 - Consecutive Sum                           /////
///// author : Rumman Mahmud                                                /////
///// SUST CSE 2011331034                                                   /////
/////////////////////////////////////////////////////////////////////////////////


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
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

#define LOCAL_TEST true
#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define clrint(name,val,s) memset(name,(val),sizeof(int)*s);
#define Assign(name,val) name.assign(val+1,vector<int>())
#define EPS 10e-6
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<30)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("outputM.txt","w",stdout)
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
int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

#define MAX 500001

struct trie
{
    int cand[2];
    trie()
    {
        clrall(cand,-1);
    }
};

trie tree[MAX*32+7];
ll csum;

int tot_node;

void insert_trie(int root,ll val)
{
    int i,j,k;
    int fbit;
    rvp(i,0,32)
    {
        fbit=(int) ((val>>(ll) i)&1LL);
        if(tree[root].cand[fbit]==-1)
        {
            tree[root].cand[fbit] = ++tot_node;
        }
        root = tree[root].cand[fbit];
    }
    return ;
}

int delete_trie(int root,ll val,int i)
{
    if(i==-1) return 0;
    int fbit;
    fbit=(int) ((val>>(ll) i)&1LL);
    if(tree[root].cand[fbit]==-1) return 0;
    int chld=delete_trie(tree[root].cand[fbit],val,i-1);
    if(chld==0)
    {
        tree[root].cand[fbit]=-1;
    }
    int nchld=0;
    if(tree[root].cand[fbit]!=-1) nchld++;
    if(tree[root].cand[!fbit]!=-1) nchld++;
    return nchld;
}

ll solve(int root,ll cval)
{
    ll res=0;
    int fbit,cbit;
    int i,j,k;
    rvp(i,0,32)
    {
        fbit=(int) ((cval>>(ll) i)&1LL);
        cbit=!(fbit);
        if(tree[root].cand[fbit]!=-1)
        {
            if(fbit) res|=(1LL << (ll) i);
            root=tree[root].cand[fbit];
        }
        else
        {
            if(cbit) res|=(1LL << (ll) i);
            root=tree[root].cand[cbit];
        }
    }
    return res;
}

ll max_val(ll val)
{
    int i,j,k;
    ll ret=0;
    int gbit;
    rvp(i,0,32)
    {
        gbit=(int) ((val>>(ll) i)&1LL);
        if(!gbit) ret|=(1LL << (ll) i);
    }
    return ret;
}

map<ll,int> mpp;

int main()
{
    ll val;
    int test,cas=0,i,j,k,n,q;
    ll ansmx,ansmn;

    rep(i,0,MAX*32) tree[i]=trie();
    tot_node=0;
    csum=0LL;
    ansmx=0LL;
    sf("%d",&q);

    insert_trie(0,csum);
    char ch;
    rep(i,1,q+1)
    {
        sf(" %c %I64d",&ch,&csum);
        if(ch=='+')
        {
            insert_trie(0,csum);
            mpp[csum]++;
        }
        else if(ch=='-')
        {
            mpp[csum]--;
            if(mpp[csum]==0)
                delete_trie(0,csum,31);
        }
        else
        {
            val=max_val(csum);
            ansmx=(solve(0,val) xor csum);
            pf("%I64d\n",ansmx);
        }
    }
    return 0;
}
















