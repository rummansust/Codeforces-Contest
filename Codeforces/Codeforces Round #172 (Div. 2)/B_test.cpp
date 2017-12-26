#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define clr(name,val) memset(name,(val),sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 1000000000.0
#define for_i(s,n) for(int i=(s);i<(n);(i)++)
#define for_j(s,n) for(int (j)=(s);(j)<(n);(j)++)
#define for_k(s,n) for(int (k)=(s);(k)<(n);(k)++)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)

using namespace std;

int main()
{
    int x,y,n,ma=(1<30),mb=(1<<30);
    double mndif=oo;
    cin>>x>>y>>n;
    for(int a=0,b=1;b<=n;)
    {
        double f1=(x*1.0/y*1.0),f2=(a*1.0/b*1.0),dif=abs(f1-f2);
        if(dif<mndif)
        {
            mndif=dif;
            ma=a;
            mb=b;
        }
        if(f1>f2)
        {
            a++;
        }
        else if(f1<f2) b++;
        else break;
    }
    cout<<ma<<"/"<<mb<<endl;
    return 0;
}
