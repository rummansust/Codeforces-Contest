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

vector<pair<int,int> > range;

int lps[200005];

string str;
void kmp(int ter)
{
    int len=SZ(str);
    lps[0]=0;
    int k=0;
    for(int i=1;i<len;i++)
    {
        while(k>0 && str[i]!=str[k]) k=lps[k-1];
        if(str[k]==str[i]) k++;
        lps[i]=k;
        if(k>=ter)
        {
            range.psb(mp((i-ter+1)-ter,i-ter));
        }
    }
    return ;
}


int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    __;
    string a,b;
    cin>>a>>b;
    str=b+"#"+a;
    kmp(SZ(b));
    cout<<SZ(a)<<endl;
    for(int i=0;i<SZ(range);i++)
    {
        cout<<range[i].fs<<" "<<range[i].sc<<endl;
    }
    return 0;
}

















