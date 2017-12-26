#include<bits/stdc++.h> //srand(time(NULL))

using namespace std;

#define REP(i,n)     for(i=0;i<(n);i++)
#define REPI(x,a,b)  for(x=(a);x<=(b);x++)

#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)//reverse_iterator
#define mem(a,b)    memset(a,b,sizeof(a))
#define pii         pair < int , int >
#define BE(a)       a.begin(),a.end()
#define EQ(a,b)     (fabs(a-b)<ERR)
#define SZ(a)       (int)a.size()
#define vi          vector<int>
#define ll          long long
#define mp          make_pair
#define pb          push_back
#define sc          second
#define fs          first

#define deb(a...)          {cerr<<"#"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

//bool operator()(const int &p,const int &q){return p<q;}//for map,set sort declare it in a struct
//bool operator<(const data &p)const{return p.w<w;}

#define oo          (1<<30)
#define MAX         200009 // (int)1e5 + 9
//loop | binary search | priority queue | backtracking map<int , bool> | disjoin set |
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out2.txt","w",stdout)
vector<int>vec;
int n;
int main()
{
#ifdef rumman
    Read;
    Write;
#endif // rumman
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,j,k;
    cin>>n;
    REP(i,n)
    {
        int v;
        cin>>v;
        vec.pb(v);
    }
    sort(BE(vec));
    vec.resize( distance( vec.begin() , unique(BE(vec)) ) );
    int ans = 0;

    for(i=0; i<SZ(vec); i++)
    {
        for(j=vec[i]*2; j<=vec.back()+vec[i]; j+=vec[i])
        {
            int ind = lower_bound(BE(vec),j)-vec.begin();
            ind--;
            if( 0<=ind && ind<SZ(vec) && vec[ind]>=vec[i]) ans = max( ans , vec[ind]%vec[i] );
        }
    }
    cout<<ans<<endl;
}
