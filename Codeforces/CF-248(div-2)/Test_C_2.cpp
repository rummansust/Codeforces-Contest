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
#define Write freopen("outM2.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const int MAX = 100008;

ll val[MAX];
ll dval[MAX];
bool flag[MAX];
int n,m;

ll f(int pos,ll rv)
{
    int tv=dval[pos];
    ll ret=0,a,b;
    for(int i=1;i<n;i++)
    {
        a=val[i];
        b=val[i-1];
        if(a==rv) a=tv;
        if(b==rv) b=tv;
        ret+=abs(a-b);
    }
    return ret;
}

int main()
{
    Read;
    Write;
    int k;
    while(SF("%d %d",&k,&n)==2)
    {
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            SF("%I64d",&val[i]);
            if(i) ans+=abs(val[i]-val[i-1]);
            if(!flag[(int) val[i]])
            {
                dval[m++]=val[i];
                flag[(int) val[i]]=true;
            }
        }
        int m1,m2,lb,ub;
        ll f1,f2,res;
        sort(dval,dval+m);
        for(int i=0;i<m;i++)
        {
            lb=0,ub=m-1;
            res=(ll) INFINITY;
            for(int j=0;j<m;j++)
            {
                f1=f(j,dval[i]);
                res=min(f1,res);
            }
            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}
