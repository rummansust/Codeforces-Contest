#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> paii;
typedef pair< ll, ll > pall;

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
#define Read freopen("autocomplete.txt","r",stdin)
#define Write freopen("autocompleteout.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month
#define lim 3000100 //total number of characters
struct trie{
  int adj[3];
  bool flag;
  trie()
  {
      clrall(adj,-1);
      flag=false;
  }
};
int nodeindx;
trie node[lim];

void maketrie( string &text)
{
    int now,nodein=0;
    ///int nodeno,string &st,int pos
    int indx;
    for(indx=0; text[indx]!='\0' ; indx++)
    {
        now = (text[indx]-'a');
        if(node[nodein].adj[now]==-1)
        {
            node[nodein].adj[now]=++nodeindx;///child created
            node[nodeindx]=trie();
        }
        nodein = node[nodein].adj[now];
    }
    node[nodein].flag=true;
    return ;
}

bool resflag;
void find_trie(int pos,int flag,string &text,int nodein)
{
    if(text[pos]=='\0')
    {
        if(node[nodein].flag && flag)
        {
            resflag=true;
            return ;
        }
        return ;
    }
    int now=text[pos]-'a';
    if(resflag) return ;
    if(node[nodein].adj[now]!=-1)
    {
        find_trie(pos+1,flag,text,node[nodein].adj[now]);
    }
    if(resflag) return ;
    if(flag==0)
    {
        for(int i=0;i<3;i++)
        {
            if(now!=i)
            {
                if(node[nodein].adj[i]!=-1)
                {
                    if(resflag) return ;
                    find_trie(pos+1,1,text,node[nodein].adj[i]);
                }
            }
        }
    }
    return ;
}


void initialize()
{
    nodeindx=0;
    node[nodeindx]=trie();
}

int main()
{
    string inp;
    int n,m;
    __;
    cin>>n>>m;
    initialize();
    for(int i=0;i<n;i++)
    {
        cin>>inp;
        maketrie(inp);
    }
    for(int i=0;i<m;i++)
    {
        cin>>inp;
        resflag=false;
        find_trie(0,0,inp,0);
        if(resflag)
        {
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}













