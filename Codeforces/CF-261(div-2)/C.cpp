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

vector<vector<int> > out;
vector<int> V;
int N,K,D;
bool flag;

void rec(int pos)
{
    if(pos==D)
    {
        out.psb(V);
        if(SZ(out)==N)
        {
            flag=true;
        }
        return ;
    }
    for(int i=1;i<=K;i++)
    {
        V.psb(i);
        if(flag) return ;
        rec(pos+1);
        if(flag) return ;
        V.ppb();
    }
    return ;
}

int main()
{
    SF("%d %d %d",&N,&K,&D);
    flag=false;
    rec(0);
    if(SZ(out)!=N) puts("-1");
    else
    {
        for(int i=0;i<D;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(j) PF(" ");
                PF("%d",out[j][i]);
            }
            puts("");
        }
    }
    return 0;
}


















