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

ll L,R;

int dp[62][2][2];

int rec(int pos,int stflag,int enflag)
{
    if(pos==-1) return 0;
    int &ret=dp[pos][stflag][enflag];
    if(ret!=-1) return ret;
    ret=0;
    int st=(stflag==true?0:(int)((L>>(ll)pos)&1ll));
    int en=(enflag==true?1:(int)((R>>(ll)pos)&1ll));
    for(int i=st;i<=en;i++)
    {
        int nstflag=stflag;
        int nenflag=enflag;
        if(stflag==false && i>st) nstflag=true;
        if(enflag==false && i<en) nenflag=true;
        ret=max(ret,rec(pos-1,nstflag,nenflag)+i);
    }
    return ret;
}


ll res;

void path(int pos,int stflag,int enflag)
{
    if(pos==-1) return ;
    int ret=rec(pos,stflag,enflag);
    int st=(stflag==true?0:(int)((L>>(ll)pos)&1ll));
    int en=(enflag==true?1:(int)((R>>(ll)pos)&1ll));
    for(int i=st;i<=en;i++)
    {
        int nstflag=stflag;
        int nenflag=enflag;
        if(stflag==false && i>st) nstflag=true;
        if(enflag==false && i<en) nenflag=true;
        int tmp=rec(pos-1,nstflag,nenflag)+i;
        if(tmp==ret)
        {
            res|=((ll)i<<(ll)pos);
            path(pos-1,nstflag,nenflag);
            return ;
        }
    }
}

int main()
{
    __;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>L>>R;
        if(L>R) swap(L,R);
        clrall(dp,-1);
        int ret=rec(61,0,0);
        res=0ll;
        path(61,0,0);
        cout<<res<<"\n";
    }
    return 0;
}


















