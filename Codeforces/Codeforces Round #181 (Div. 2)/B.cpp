#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <sstream>

#define clr(name,val) memset(name,val,sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back(b)
#define ppb() pop_back()
#define oo 100000000000000000LL
#define swap(x,y) {int t;t=x;x=y;y=t;}
#define for_i(s,n) for(int i=s;i<n;i++)
#define for_j(s,n) for(int j=s;j<n;j++)
#define for_k(s,n) for(int k=s;k<n;k++)
#define MAX 55

///next_permutation  next_permutation (s.begin(),s.end())
///reverse(a,a+n);
///binary_search(first,last);
///vector erase v.erase(v.begin()+position);
///map map<int , int > data;
///map clear  data.clear();
///map iterator>>>> map <int,vector <int> >::const_iterator it;
///find an element in map (colour.find(nd)==colour.end());//if it return true this
///mean the element is'nt in the map.
///pass a vector to a funtion: funtion (vector <data type> &vector name);
///make_pair  point=make_pair(i,j);
///access pair value point.first;point.second;

using namespace std;

///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

struct edge
{
    int parent,rank,member;
};

vector<edge> dset(MAX);

void makeset(int i)
{
    dset[i].parent=i;
    dset[i].rank=0;
    dset[i].member=1;
    return;
}

int findset(int u)
{
    if(dset[u].parent==u) return u;
    dset[u].parent=findset(dset[u].parent);
}

void unionset(int u,int v)
{
    int up=findset(u);
    int vp=findset(v);
    if(dset[up].parent==dset[vp].parent) return;
    if(dset[up].rank<dset[vp].rank)
    {
        dset[up].parent=dset[vp].parent;
        dset[up].member=dset[vp].member=dset[up].member+dset[vp].member;
    }
    else
    {
        dset[vp].parent=dset[up].parent;
        dset[up].member=dset[vp].member=dset[up].member+dset[vp].member;
        if(dset[up].rank==dset[vp].rank)
        dset[up].rank=dset[up].rank+1;
    }
    return;
}

int main()
{
    int n,m,u,v;
    map<int,vector<int> > data;
    map<int,int> data2;
    vector<int> vtr[30];
    cin>>n>>m;
    for_i(0,n+1)
    makeset(i);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        unionset(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        if(dset[findset(i)].member!=1)
        data[findset(i)].psb(i);
    }
    map<int,vector<int> > :: const_iterator it;
    for(it=data.begin();it!=data.end();it++)
    {
        if((it->second).size()>3)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    int k=0;
    for(it=data.begin();it!=data.end();it++)
    {
        for(int i=0;i<(it->second).size();i++)
        {
            vtr[k].psb((it->second)[i]);
            data2[(it->second)[i]]++;
        }
        k++;
    }
    queue<int> Q;
    for(int i=1;i<=n;i++)
    {
        if(data2.find(i)==data2.end()) Q.push(i);
    }
    for(int i=0;i<(n/3);i++)
    {
        if(vtr[i].size()<3);
        {
            for(int j=vtr[i].size();j<3;j++)
            {
                if(!Q.empty()) vtr[i].psb(Q.front()),Q.pop();
                else break;
            }
        }
    }
    for(int i=0;i<(n/3);i++)
    {
        if(vtr[i].size()!=3)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0;i<(n/3);i++)
    {
        for(int j=0;j<vtr[i].size();j++)
        {
            if(j) cout<<" ";
            cout<<vtr[i][j];
        }
        cout<<endl;
    }

    return 0;
}
