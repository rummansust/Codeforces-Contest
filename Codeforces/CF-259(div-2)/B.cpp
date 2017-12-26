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

vector<int> val;
int v,n;

int main()
{
    SF("%d",&n);
    for(int i=0;i<n;i++)
    {
        SF("%d",&v);
        val.psb(v);
    }
    int cnt=1,tt=1;
    vector<int> ttt;
    v=val[0];
    int res=-1;
    for(int i=1;i<SZ(val);i++)
    {
        if(v>val[i])
        {
            cnt++;
            if(cnt>2)
            {
                cout<<-1<<endl;
                return 0;
            }
            ttt.psb(tt);
            tt=1;
        }
        else tt++;
        v=val[i];
    }
//    cout<<cnt<<endl;
    if(cnt>1)
    {
        if(val[n-1]>val[0])
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    if(cnt==1) cout<<0<<endl;
    else
    {
        cout<<tt<<endl;
    }
    return 0;
}


















