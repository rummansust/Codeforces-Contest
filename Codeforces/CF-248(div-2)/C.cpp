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
#define Write freopen("outM.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const int MAX = 100008;

ll val[MAX];
ll dval[MAX];
bool flag[MAX];
int n,m;
vector<ll> lr[MAX];
vector<ll> lrs[MAX];
ll tot[MAX];

ll f(ll tv,ll rv,ll inans)
{
    if(lr[rv].empty()) return inans;
    ll ret=0,prev,newv,a,b;
    int low=lower_bound(lr[rv].begin(),lr[rv].end(),tv)-lr[rv].begin();
    if(low==SZ(lr[rv]) || lr[rv][low]>tv) low--;
    low++;
    int up=SZ(lr[rv])-low;
    ll rt=tot[rv],lt=0LL;
    if(low)
    {
        lt=lrs[rv][low-1];
        rt-=lt;
    }
    newv=(((ll)low*tv)-lt)+(rt-((ll)up*tv));
    low=lower_bound(lr[rv].begin(),lr[rv].end(),rv)-lr[rv].begin();
    if(low==SZ(lr[rv]) || lr[rv][low]>rv) low--;
    low++;
    up=SZ(lr[rv])-low;
    rt=tot[rv];
    lt=0LL;
    if(low)
    {
        lt=lrs[rv][low-1];
        rt-=lt;
    }
    prev=(((ll)low*rv)-lt)+(rt-((ll)up*rv));
    ret=inans+(newv-prev);
    return ret;
}

int main()
{
    #ifdef rumman
    Read;
    Write;
    #endif // rumman
    int k;
    while(SF("%d %d",&k,&n)==2)
    {
        for(int i=0;i<=k;i++) lr[i].clear(),lrs[i].clear();
        clrall(flag,0);
        clrall(tot,0LL);
        ll ans=0;
        m=0;

        for(int i=0;i<n;i++)
        {
            SF("%I64d",&val[i]);
            if(i)
            {
                ans+=abs(val[i]-val[i-1]);
                if(val[i]!=val[i-1])
                {
                    lr[(int)val[i] ].psb(val[i-1]);
                    tot[(int)val[i] ]+=val[i-1];
                    lr[(int)val[i-1] ].psb(val[i]);
                    tot[(int)val[i-1] ]+=val[i];
                }
            }
            if(!flag[(int) val[i]])
            {
                dval[m++]=val[i];
                flag[(int) val[i]]=true;
            }
        }
        ll inans = ans;
        ll v;
        sort(dval,dval+m);
        for(int i=0;i<m;i++)
        {
            v=dval[i];
            sort(lr[v].begin(),lr[v].end());
            if(SZ(lr[v]))
            lrs[v].psb(lr[v][0]);
            for(int j=1;j<SZ(lr[v]);j++)
            {
                lrs[v].psb(lrs[v][j-1]+lr[v][j]);
            }
        }
        int m1,m2,lb,ub;
        ll f1,f2,res;
        sort(dval,dval+m);
        for(int i=0;i<m;i++)
        {
            lb=0,ub=SZ(lr[dval[i]])-1;
            if(ub<lb) continue;
            res=(ll) INFINITY;
            for(int j=0;j<50;j++)
            {
                m1=(2*lb+ub)/3;
                m2=(lb+2*ub)/3;
                f1=f(lr[dval[i]][m1],dval[i],inans);
                f2=f(lr[dval[i]][m2],dval[i],inans);
                res=min(res,min(f1,f2));
                if(f1<f2) ub=m2;
                else lb=m1;
            }
            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/**

8 14
3 6 1 4 4 4 7 8 4 3 6 2 1 6

9 15
8 5 9 2 4 1 8 3 9 3 8 7 8 6 8

8 14
3 6 1 4 4 4 7 8 4 3 6 2 1 6

*/

















