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
#define oo 10000000
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)

using namespace std;

struct set_
{
    int par,rank_,member;
    set_(int p,int r,int m):par(p),rank_(r),member(m){}
};

vector<set_> dset;

void make_set(int n)
{
    for(int i=0;i<=n;i++) dset.psb(set_(i,0,1));
    return ;
}

int find_par(int u)
{
    if(u!=dset[u].par) dset[u].par=find_par(dset[u].par);
    return dset[u].par;
}

bool union_set(int u,int v)
{
    int up=find_par(u);
    int vp=find_par(v);
    if(up==vp) return false;
    dset[up].member=dset[vp].member=dset[up].member+dset[vp].member;
    if(dset[up].rank_<dset[vp].rank_)
    {
        dset[up].par=dset[vp].par;
    }
    else
    {
        dset[vp].par=dset[up].par;
        if(dset[up].rank_==dset[vp].rank_)
        dset[up].rank_++;
    }
    return true;
}


#define Read freopen("in.txt","r",stdin)
#define Write freopen("in.txt","w",stdout)

int main()
{

    #ifdef MAHDI
//    Read;
    Write;
    #endif // MAHDI
    srand(time(NULL));
//    int test=100;
    int test=1;
    while(test--)
    {
//        int n=rand()%97+331,tn=n;
        int n=100000,tn=n;
//        tn--;
        printf("%d\n",n);
        for(int i=1;i<n/2;i++) printf("%d %d\n",i,2*i);
        for(int i=1;i<n/2;i++) printf("%d %d\n",i,2*i+1);
        printf("50000 100000\n");
//        make_set(n);
//        dset.clear();
//        while(true)
//        {
//            int u,v;
//            u=rand()%n+1;
//            v=rand()%n+1;
//            if(u==v || find_par(u)==find_par(v)) continue;
//            union_set(u,v);
//            tn--;
//            printf("%d %d\n",u,v);
//            if(tn==0) break;
//        }
//        int m=rand()%10007+3331;
        int m=1;
        printf("%d\n",m);
        printf("1 73558\n");
//        while(m--)
//        {
//            int u,v;
//            u=rand()%n+1;
//            v=rand()%n+1;
//            printf("%d %d\n",u,v);
//        }
    }
    return 0;
}

/*
1
8 8
2 3 11
0 1 10
0 2 2
1 3 6
2 7 5
7 4 7
2 5 9
5 6 1
*/









