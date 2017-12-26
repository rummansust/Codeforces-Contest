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

int cnt[2500];
bool col[2500][2500];
pair<int,int> val[2500];
pair<int,int> val2[2500];
pair<int,int> val3[2500];

int main()
{
    clrall(cnt,0);
    clrall(col,0);
    int v;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v;
        cnt[v]++;
        val[i]=mp(v,i);
        val2[i]=mp(v,i);
        val3[i]=mp(v,i);
    }
    sort(val+1,val+n+1);
    sort(val2+1,val2+n+1);
    sort(val3+1,val3+n+1);
    int a=-1,b=-1;
    for(int i=2;i<=n;i++)
    {
        if(val[i-1].fs==val[i].fs)
        {
            swap(val2[i-1],val2[i]);
            swap(val3[i-1],val3[i]);
            col[i][i-1]=1;
            break;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(val2[i-1].fs==val2[i].fs&&col[i][i-1]!=1)
        {
            swap(val3[i-1],val3[i]);
            break;
        }
    }
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(val[i].sc!=val2[i].sc)
        {
            flag++;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(val2[i].sc!=val3[i].sc)
        {
            flag++;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(val[i].sc!=val3[i].sc)
        {
            flag++;
            break;
        }
    }
    if(flag==3)
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
        {
            cout<<val[i].sc<<" ";
        }
        cout<<"\n";
        for(int i=1;i<=n;i++)
        {
            cout<<val2[i].sc<<" ";
        }
        cout<<"\n";
        for(int i=1;i<=n;i++)
        {
            cout<<val3[i].sc<<" ";
        }
        cout<<"\n";
    }
    else cout<<"NO\n";

    return 0;
}


















