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
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("input.txt","r",stdin)
#define Write freopen("output.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

int dp[205][40010][2];

int height[205];

int n,limr,limg,sum;

int rec(int pos,int red,int flag)
{

    if(red>limr) return oo;
    if(pos>n)
    {
//        cout<<red<<" "<<sum-red<<endl;
        if(sum-red>limg) return oo;
        return 0;
    }
    int &ret = dp[pos][red][flag];
    if(ret!=-1) return ret;
    ret=oo;
    int cost=min(height[pos-1],height[pos]);
    if(flag==0)
    {
//        cout<<"cost : "<<cost<<endl;
        ret=min(ret,rec(pos+1,red+height[pos],flag));
        ret=min(rec(pos+1,red,!flag)+cost,ret);
    }
    else
    {
//        cout<<"cost2 : "<<cost<<endl;
        ret=min(ret,rec(pos+1,red+height[pos],!flag)+cost);
        ret=min(rec(pos+1,red,flag),ret);
    }
    return ret;
}

int main()
{
    __;
    Read;
    Write;
    cin>>n;
    cin>>limr>>limg;
    sum=0;
    height[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>height[i];
        sum+=height[i];
    }
    clrall(dp,-1);
    int ret=rec(1,0,0);
    if(ret>=oo) ret=-1;
    cout<<ret<<"\n";
    return 0;
}


















