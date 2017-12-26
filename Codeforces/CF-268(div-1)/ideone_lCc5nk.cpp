//Md. Khairullah Gaurab
//CSE, SUST 20th
//gaurab.cse.sust@gmail.com
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>

#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define all(a) (a.begin(),a.end())
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=a; i>=b; ++i)
#define mp(a,b) make+pair(a,b)
#define fs first
#define sc second
#define unq(vec) stbale_sort(vec.begin(),vec.end());\
                 vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));

using namespace std;
const int INF = 2000000000;
const int SZ = 100000;

typedef long long Long;
typedef double dd;

Long sum(Long N)
{
    if(N/10==0) return N*(N+1)/2;
    int i = 0;
    Long n = N;
    while(n/10!=0)
    {
        i++;
        n/=10;
    }
    int p = pow(10,i);

    return ((n*45*i*p/10) + n*(n-1)*p/2 + n*(N%p + 1) + sum(N%p));
}

int main(int arc, const char **argv)
{
    for(int A=1;A<100;A++)
    {
        cout<<A<<" "<<A+10-1<<" "<<sum(A+10-1)-sum(A-1)<<endl;
    }
    return 0;
}
