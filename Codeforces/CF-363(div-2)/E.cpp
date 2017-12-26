//#pragma warning (disable: 4786)

#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR         1e-5
#define PRE         1e-8
#define SZ(s)       ((int)s.size())
#define LL          long long
#define csprnt printf("Case %d: ", cas++);
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define REP(i,n)    for(i=0;i<n;i++)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcount(mask)
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<"\t"<<e6<<endl;}
template<class T> void debug(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;} cout<<endl;}
template<class T> void debug(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void debug(T e[110][110],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
//*************************************************My Code Starts Here*********************************************************************************
#define MAX 10010
//normally 1 based index
unsigned int tree[52][MAX][3];
unsigned int last[52][MAX][3];
int MaxVal;//always should be set(size of the set len or len+1)
vector<int>y;

//cumulitive sum
unsigned int query(int idx,int in,int chc){
	unsigned int sum = 0;
	while (idx > 0){
		sum += tree[in][idx][chc];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx,int in,int chc,unsigned int val){
	while (idx <= MaxVal){
		tree[in][idx][chc] += val;
		idx += (idx & -idx);
	}
}

struct cood{
    int srt;
    int rating;
};
vector<cood> arr;

bool comp(cood p,cood q)
{
    return p.srt<q.srt;
}

int bsfind(int st,int end,int tar)
{
    int mid=(st+end)/2;
    if(y[mid]==tar) return mid+1;
    if(y[mid]>tar)  return bsfind(st,mid-1,tar);
    return bsfind(mid+1,end,tar);
}


int main()
{
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
		y.clear();
		arr.clear();
		int i,j,n,k;
		cood tem;
		scanf("%d %d", &n, &k);
		for(i=1;i<=n;i++)
		{
			cin>>tem.srt>>tem.rating;
			arr.pb(tem);
			y.pb(tem.rating);
		}
		sort(y.begin(), y.end());
		y.resize(unique(y.begin(), y.end())-y.begin());
		MaxVal = SZ(y);
		sort(BE(arr),comp);
		unsigned int ans=0,val;
		mem(tree,0);
		mem(last,0);

		for(i=0;i<SZ(arr);i++)
		{
//		    int in=bsfind(0,MaxVal-1,arr[i].rating);
		    int in=lower_bound(y.begin(),y.end(),arr[i].rating)-y.begin();
		    in++;
            update(in,0,2,1-last[0][in][2]);
            last[0][in][2]=1;
            for(j=0;j<k;j++)
		    {
		        val=0;
		        if(j) {
		            val=query(MaxVal,j-1,1);
		            val-=query(in,j-1,1);
                }
                val+=query(MaxVal,j,0)+query(MaxVal,j,2);
		        val-=query(in,j,0)+query(in,j,2);
		        val-=last[j][in][0];
		        last[j][in][0]+=val;
		        update(in,j,0,val);

		        val=0;
		        if(j)
		           val=query(in-1,j-1,0);
                val+=query(in-1,j,1)+query(in-1,j,2);
                val-=last[j][in][1];
		        last[j][in][1]+=val;
		        update(in,j,1,val);
		    }

		    val=0;
		        if(j) {
		            val=query(MaxVal,j-1,1);
		            val-=query(in,j-1,1);
                }
                val+=query(MaxVal,j,0)+query(MaxVal,j,2);
		        val-=query(in,j,0)+query(in,j,2);
		        val-=last[j][in][0];
		        last[j][in][0]+=val;
		        update(in,j,0,val);
		        ans+=val;

		        val=0;
		        if(j)
		           val=query(in-1,j-1,0);
                val+=query(in-1,j,1)+query(in-1,j,2);
                val-=last[j][in][1];
		        last[j][in][1]+=val;
		        update(in,j,1,val);
		        ans+=val;
		    //print1(ans);
		}

		csprnt;
		if(k==0) //per y and nothing will be counted also
            ans+=MaxVal+1;
		print1(ans);
    }
    return 0;
}
/**
1
6 1
1 1
2 2
3 3
4 2
5 3
6 2
*/
