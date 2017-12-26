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

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

vector<int> adj[26];
char str[105];
int deg[100];
int col[100];

string Name[101];

int main()
{
//    Read;
//    Write;
    int n;
    while(SF("%d",&n)==1)
    {
        clrall(col,0);
        clrall(deg,0);
        for(int i=0;i<26;i++) adj[i].clear();
        for(int i=0;i<n;i++)
        {
            SF("%s",str);
            Name[i]=str;
        }
        bool flag2=false;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                bool flag=true;
                int k=0;
                for(k=0;k<min(SZ(Name[i]),SZ(Name[j]));k++)
                {
                    if(Name[i][k]==Name[j][k]) continue;
                    adj[(Name[i][k]-'a')].psb(Name[j][k]-'a');
                    deg[(Name[j][k]-'a')]++;
                    flag=false;
                    break;
                }
                if(flag)
                {
                    if(SZ(Name[i])>SZ(Name[j]))
                    {
                        PF("Impossible\n");
                        flag2=true;
                        break;
                    }
                }
            }
            if(flag2) break;
        }
        if(flag2) continue;
        queue<int> Q;
        bool cycle=false;
        vector<int> res;
        for(int i=0;i<26;i++) if(deg[i]==0) Q.push(i),col[i]=true,res.psb(i);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            for(int i=0;i<SZ(adj[u]);i++)
            {
                int v=adj[u][i];
                if(deg[v]>0)
                {
                    deg[v]--;
                    if(deg[v]==0)
                    {
                        Q.push(v);
                        res.psb(v);
                        col[v]=true;
                    }
                }
            }
        }
        for(int i=0;i<26;i++) if(deg[i]) cycle=true;
        if(cycle)
        {
            PF("Impossible\n");
        }
        else
        {
            for(int i=0;i<26;i++)
            {
                if(!col[i]) res.psb(i);
            }
            for(int i=0;i<SZ(res);i++)
            {
                PF("%c",(char)(res[i]+'a'));
            }
            PF("\n");
        }
    }
    return 0;
}











