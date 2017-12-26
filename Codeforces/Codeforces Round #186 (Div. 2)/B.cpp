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
#define Assign(name,val) name.assign(val+1,vector<int>())
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
#define maxn 100015

using namespace std;


int x,y;
string s;
int tree[4*maxn];

void build(int cur,int l,int r)
{
    if(l==r)
    {
        tree[cur]=0;
    }
    else
    {
        int mid=(l+r)>>1;
        build(2*cur,l,mid);
        build(2*cur+1,mid+1,r);
        tree[cur]=tree[2*cur]+tree[2*cur+1];
        if(s[mid]==s[mid+1]) tree[cur]++;
    }
    return ;
}

int query(int cur,int l,int r)
{
    if(l>y||r<x) return 0;
//    cout<<x<<" "<<y<<endl;
    if(l>=x&&r<=y) return tree[cur];
//    cout<<"here"<<endl;
    int mid=(l+r)>>1;
    int ret1=query(cur*2,l,mid);
    int ret2=query(cur*2+1,mid+1,r);
//    cout<<ret1<<" "<<ret2<<endl;
    int ret=ret1+ret2;
    if((mid>=x&&mid<=y)&&(mid+1>=x&&mid+1<=y)&&s[mid]==s[mid+1]) ret++;
    return ret;
}

int main()
{
    int Q;
    string p;
    s+='*';
    cin>>p;
    s+=p;
    int n=s.size()-1;
    clr(tree,0);
    build(1,1,n);
//    cout<<tree[3]<<endl;
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        cin>>x>>y;
        cout<<query(1,1,n)<<endl;
    }
    return 0;
}























