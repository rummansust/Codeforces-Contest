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


vector<int> adj[50000];
map<string , int> mpp;
map<int , string> rpp;
int indeg[50000];

int main()
{
    int q;
    int u,v,n=0;
    __;
    cin>>q;
    string a,b;
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        if(mpp.find(a)==mpp.end())
        {
            mpp[a]=n;
            rpp[n]=a;
            n++;
        }
        if(mpp.find(b)==mpp.end())
        {
            mpp[b]=n;
            rpp[n]=b;
            n++;
        }
        u=mpp[a];
        v=mpp[b];
        indeg[v]++;
        adj[u].psb(v);
    }
    vector<pair<string,string> > res;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)
        {
            a=rpp[i];
            u=i;
            while(SZ(adj[u])>0)
            {
                v=adj[u][0];
                b=rpp[v];
                u=v;
            }
            res.psb(mp(a,b));
        }
    }
    cout<<SZ(res)<<"\n";
    sort(all(res));
    for(int i=0;i<SZ(res);i++)
    {
        cout<<res[i].fs<<" "<<res[i].sc<<"\n";
    }
    return 0;
}












