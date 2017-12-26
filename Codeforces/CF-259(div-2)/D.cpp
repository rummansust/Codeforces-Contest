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

vector<int> prime;
bool isPrime[100];
int val[101];
int dp[1<<12+7][101];

int n;

int rec(int mask,int pos)
{
    if(pos==n) return 0;
    int &ret = dp[mask][pos];
    if(ret!=-1) return ret;
    ret=(int) INFINITY;
    for(int i=1;i<38;i++)
    {
        int flag=true;
        for(int j=0;j<12;j++)
        {
            if((mask&(1<<j)) && (i%prime[j]==0))
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            int nmask=mask;
            for(int j=0;j<12;j++)
            {
                if(i%prime[j]==0)
                {
                    nmask|=(1<<j);
                }
            }
            ret=min(ret,rec(nmask,pos+1)+(int)abs(val[pos]-i));
        }
    }
    return ret;
}

vector<int> res;

void path(int mask,int pos)
{
    if(pos==n) return ;
    int ret = dp[mask][pos];
    int tmp;
    for(int i=1;i<32;i++)
    {
        int flag=true;
        for(int j=0;j<12;j++)
        {
            if((mask&(1<<j)) && (i%prime[j]==0))
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            int nmask=mask;
            for(int j=0;j<12;j++)
            {
                if(i%prime[j]==0)
                {
                    nmask|=(1<<j);
                }
            }
            tmp=rec(nmask,pos+1)+(int)abs(val[pos]-i);
            if(tmp==ret)
            {
                res.psb(i);
                path(nmask,pos+1);
                return ;
            }
        }
    }
    return ;
}

int main()
{
    prime.psb(2);
    for(int i=3;i<38;i++)
    {
        for(int j=2;j<i;j++)
        {
            if(i%j==0) break;
            if(j==i-1) prime.psb(i);
        }
    }
//    cout<<SZ(prime)<<endl;
    clrall(dp,-1);
    cin>>n;
    for (int i=0;i<n ; i++)
    {
        cin>>val[i];
    }
    int ret=rec(0,0);
    path(0,0);
//    cout<<ret<<endl;
    for(int i=0;i<SZ(res);i++)
    {
        cout<<res[i]<<" ";
    }
    puts("");
    return 0;
}


















