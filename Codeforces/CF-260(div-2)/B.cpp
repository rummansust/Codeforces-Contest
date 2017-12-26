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

vector<int> res[10];

int main()
{
    res[1].psb(1);
    res[1].psb(1);
    res[1].psb(1);
    res[1].psb(1);

    res[2].psb(1);
    res[2].psb(2);
    res[2].psb(4);
    res[2].psb(3);

    res[3].psb(1);
    res[3].psb(3);
    res[3].psb(4);
    res[3].psb(2);

    res[4].psb(1);
    res[4].psb(4);
    res[4].psb(1);
    res[4].psb(4);


    string s;
    cin>>s;
    int M=(s[0]-'0')%4;
    for(int i=1;i<SZ(s);i++)
    {
        M=(s[i]-'0')+M*10;
        M%=4;
    }
    int ret=res[1][M]+res[2][M]+res[3][M]+res[4][M];
    ret%=5;
    cout<<ret<<endl;
    return 0;
}


















