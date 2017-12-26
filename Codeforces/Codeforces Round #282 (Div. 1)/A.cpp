#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

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
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

#define casePrint PF("Case #%d: ",++cas);

int rr[100005];
int lr[100005];
int tl[100005];

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    string s;
    __;
    cin>>s;
    vector<int> res;
    int cntr=0,cnth=0,cntl=0,flag=true;
    for(int i=SZ(s)-1;i>-1;i--)
    {
        if(s[i]=='(') cntr++;
        else if(s[i]==')') cntl++;
        if(s[i]=='#') res.psb(1),cnth++;
    }
    int Left=cntr-cntl-cnth;
    if(Left<0)
    {
        cout<<-1<<"\n";
        return 0;
    }
    res[cnth-1]=res[cnth-1]+Left;
    int sum=0;
    for(int i=0,j=0;i<SZ(s);i++)
    {
        if(s[i]=='#') sum+=res[j++];
        else if(s[i]=='(') sum--;
        else sum++;
        if(sum>0)
        {
            flag=false;
            break;
        }
    }
    if(sum!=0) flag=false;
    if(flag)
    {
        for(int i=0;i<cnth;i++)
        {
            cout<<res[i]<<"\n";
        }
    }
    else cout<<"-1\n";
    return 0;
}

















