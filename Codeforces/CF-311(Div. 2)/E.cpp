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


template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

///pass a vector to a funtion: funtion (vector <data type> &vector name);
///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

#define MAX 5020

string text;

int grid[MAX][MAX];

int solve(int i,int j)
{
    if(i>j) return 1;
    if(grid[i][j]) return grid[i][j];
    grid[i][j]=2;
    if(text[i]==text[j])
    {
        grid[i][j]=solve(i+2,j-2);
    }
    solve(i+1,j);
    solve(i,j-1);
    return grid[i][j];
}

int range[MAX];

#define lim 13000100 //total number of characters

struct trie{
  int adj[2];
  int cnt,sum;
  trie()
  {
      clrall(adj,-1);
      cnt=0;
      sum=0;
  }
};
int nodeindx;
trie node[lim];
int n,m,cnt;

void initialize()
{
    nodeindx=0;
    node[nodeindx]=trie();
}

void maketrie(int st,int en)
{
    int now,nextnode=0;
    for(int indx=st; indx<=en ; indx++)
    {
        now = (text[indx]-'a');
        if(node[nextnode].adj[now]==-1)
        {
            node[nextnode].adj[now]=++nodeindx;///child created
            node[nodeindx]=trie();
        }
        nextnode = node[nextnode].adj[now];
        if(grid[st][indx]==1)
        {
            node[nextnode].cnt++;
            node[nextnode].sum++;
        }
    }
    return ;
}

int rec(int nextnode)
{
    if(nextnode==-1) return 0;
    node[nextnode].sum+=rec(node[nextnode].adj[0])+rec(node[nextnode].adj[1]);
    return node[nextnode].sum;
}

void solution(int nextnode,int k)
{
    if(nextnode==-1)
    {
        return ;
    }
    if(node[nextnode].cnt<k)
    {
        k-=node[nextnode].cnt;
    }
    else
    {
        return ;
    }
    int curnode=node[nextnode].adj[0];
    if(curnode!=-1)
    {
        if(node[curnode].sum<k) k-=node[curnode].sum;
        else
        {
            PF("a");
            solution(curnode,k);
            return ;
        }
    }
    curnode=node[nextnode].adj[1];
    if(curnode!=-1)
    {
        if(node[curnode].sum<k) k-=node[curnode].sum;
        else
        {
            PF("b");
            solution(curnode,k);
            return ;
        }
    }
    return ;
}

int main()
{
    char arr[MAX];
    SF("%s",&arr);
    int n,k;
    n=strlen(arr);
    text=arr;
    for(int i=0;i<n;i++) grid[i][i]=true;
    solve(0,n-1);
    for(int i=0;i<n;i++)
    {
        maketrie(i,n-1);
    }
    rec(0);
    SF("%d",&k);
    solution(0,k);
    PF("\n");
    return 0;
}














