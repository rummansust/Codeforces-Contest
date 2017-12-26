//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#include<iterator>
#include<numeric>
#include<stack>
#include<list>
using namespace std;
#define pi acos(-1)
#define M
#define oo 1<<30
#define ll long long int

struct node{
    int x,y;
    node(){}
    node(int a,int b) : x(a),y(b){}
};

const int MAX=100100;

int W[MAX];
node ara[MAX];

//bool cmp(const node &a, const node &b)
//{
//    return (a.x<=b.x && a.y<=b.y);
//}
bool cmp(const node &a, const node &b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

map<int,queue<int> > mpp;
node res[MAX];

int X[MAX*5];
int Y[MAX*5];

#define mson int nidx=idx<<1,mid=(l+r)>>1;

void update_x(int idx,int l,int r,int p,int v)
{
    if(l==r)
    {
        X[idx]=max(X[idx],v);
        return ;
    }
    mson;
    if(p<=mid) update_x(nidx,l,mid,p,v);
    else update_x(nidx+1,mid+1,r,p,v);
    return ;
}
void update_y(int idx,int l,int r,int p,int v)
{
    if(l==r)
    {
        Y[idx]=max(Y[idx],v);
        return ;
    }
    mson;
    if(p<=mid) update_y(nidx,l,mid,p,v);
    else update_y(nidx+1,mid+1,r,p,v);
    return ;
}

int query_x(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return -1;
    if(b>=i && e<=j) return X[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=query_x(left,b,mid,i,j);
    int p2=query_x(right,mid+1,e,i,j);
    return max(p1,p2);
}
int query_y(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return -1;
    if(b>=i && e<=j) return Y[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=query_y(left,b,mid,i,j);
    int p2=query_y(right,mid+1,e,i,j);
    return max(p1,p2);
}

int main()
{
	int n,x,y,nx,ny;
	while(cin>>n){
        int mx=0,my=0;
        memset(X,-1,sizeof X);
        memset(Y,-1,sizeof Y);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&ara[i].x,&ara[i].y);
            mx=max(mx,ara[i].x);
            my=max(my,ara[i].y);
        }
        for(int i=0;i<n;i++) scanf("%d",&W[i]);
        sort(ara,ara+n,cmp);
        for(int i=0;i<n;i++)
        {
            mpp[ara[i].y-ara[i].x].push(i);
        }
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(!mpp[W[i]].empty())
            {
                res[i]=ara[mpp[W[i]].front()];
                mpp[W[i]].pop();
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            int en=MAX-10;
            for(int i=0;i<n&&flag;i++)
            {
                x=res[i].x;
                y=res[i].y;
                ny=query_x(1,0,en,x,en);
                if(ny>y)
                {
                    flag=false;
                }
                ny=query_x(1,0,en,x+1,en);
                if(ny>=y)
                {
                    flag=false;
                }
                nx=query_y(1,0,en,y,en);
                if(nx>x)
                {
                    flag=false;
                }
                nx=query_y(1,0,en,y+1,en);
                if(nx>=x)
                {
                    flag=false;
                }
                update_x(1,0,en,x,y);
                update_y(1,0,en,y,x);
            }
        }
        if(!flag) printf("NO\n");
        else{
            printf("YES\n");
            for(int i=0;i<n;i++) printf("%d %d\n",res[i].x,res[i].y);
        }
    }
    return 0;
}
/**
10
0 0
1 0
2 0
3 0
4 0
0 1
1 1
2 1
3 1
4 1
0 1 -1 -2 0 -1 -3 -2 -4 -3
*/
/**
3
0 1
1 2
2 1
1 -1 1
*/
/**
2
0 0
1 0
-1 0
*/

/**
15
0 0
1 0
2 0
3 0
4 0
0 1
1 1
2 1
3 1
4 1
0 2
1 2
2 2
3 2
4 2
0 -1 1 0 2 -2 1 -3 -1 -4 0 -2 -1 -3 -2
*/
