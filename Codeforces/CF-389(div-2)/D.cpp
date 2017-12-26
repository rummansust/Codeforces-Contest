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
#include <utility>
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
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

map<string,vector<int> > mpp;

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    __;
    int n,k,v;
    string s;
    cin>>k>>n;
    for(int i=0;i<k;i++)
    {
        cin>>s>>v;
        mpp[s].psb(v);
    }
    for(auto it:mpp){
        sort(all(mpp[it.fs]));
    }
    string a,b;
    int res=0;
    vector<pair<int,int> > val;
    int tot=0,mx=0;
    for(auto i:mpp){
        a=i.fs;
        b=a;
        reverse(all(b));
        if(a!=b && mpp.count(b)){
            vector<int> &av=mpp[a],&bv=mpp[b];
            for(int x=SZ(av)-1,y=SZ(bv)-1;x>=0&&y>=0;x--,y--){
                if(av[x]+bv[y]>0){
                    res+=av[x]+bv[y];
                    av.ppb();
                    bv.ppb();
                }
            }
        }
        else if(a==b){
            val.psb(mp(0,0));
            int k=SZ(val)-1;
            vector<int> av=mpp[a];
            int sm=0;
            for(int x=SZ(av)-1,y=1;x>=0;x--,y++){
                sm+=av[x];
                if(y&1) val[k].sc=max(sm,val[k].sc);
                else val[k].fs=max(sm,val[k].fs);
            }
            tot+=val[k].fs;
            mx=max(mx,val[k].fs);
            mx=max(mx,val[k].sc);
        }
    }
    for(auto i:val){
        mx=max(mx,tot-i.fs+i.sc);
    }
    mx=max(mx,tot);
    deb(res+mx);
    return 0;
}

/**
7 3
abb 2
aaa -3
bba -1
zyz -4
abb 5
aaa 7
xyx 4
*/
/**
3 1
t -1
t -2
a 2
*/
/**
16 10
abbabbabba -1112
abbabbabba -77
abbabbabba 556
abbabbabba 648
abbabbabba 801
abbabbabba 1292
abbabbabba 3229
abbabbabba 3434
baabaabaab -1107
baabaabaab -353
baabaabaab 3025
baabaabaab 3130
baabaabaab 3313
baabaabaab 3332
baabaabaab 3550
baabaabaab 3681
*/








