#include <bits/stdc++.h>

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
#define oo (1<<29)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outE.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const int MAX = 100005;

vector<pair<int,int> > pos;

int val[MAX];

int main()
{
    int n;
    SF("%d",&n);
    int st=1,en=1;
    val[0]=-1;
    val[n+1]=(int) INFINITY;
    for(int i=1;i<=n;i++)
    {
        SF("%d",&val[i]);
    }
    for(int i=2;i<=n;i++)
    {
        if(val[i]<=val[i-1])
        {
            pos.psb(mp(st,en));
            st=i;
        }
        else en=i;
    }
    pos.psb(mp(st,en));
    int res=0;
    for(int i=0;i<SZ(pos);i++)
    {
        res=max(res,pos[i].sc-pos[i].fs+1+(SZ(pos)>1));
    }
    for(int i=1;i<SZ(pos);i++)
    {
        int w1=pos[i-1].sc-pos[i-1].fs+1;
        int w2=pos[i].sc-pos[i].fs+1;
        if(w1==1||w2==1) res=max(res,w1+w2);
        else
        {
            if(val[pos[i-1].sc-1]+1<val[pos[i].fs] || val[pos[i-1].sc]+1<val[pos[i].fs+1]) res=max(res,w1+w2);
        }
    }
    cout<<res<<endl;
    return 0;
}


















