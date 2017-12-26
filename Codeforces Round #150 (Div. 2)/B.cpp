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
#define MAX

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

struct data
{
    string s;
    char x,y;
    data(){}
    data(string s,char x,char y):s(s),x(x),y(y){}
};

vector<data> v;
map<int,int> lucky;

void pregen()
{
    for(int i=1;i<10;i++)
    {
        lucky[i]=0;
        string a;
        stringstream ss;
        int n=i;
        ss<<i;
        ss>>a;
        a="0"+a;
        v.psb(data(a,'0',i+48));
    }
    for(int i=10;i<100;i++)
    {
        lucky[i]=0;
        string a;
        stringstream ss;
        ss<<i;
        ss>>a;
        v.psb(data(a,(i%10)+48,(i/10)+48));
    }
}

void precall()
{
    for(int i=0;v[i].s.size()<10;i++)
    {
        int n;
        string a,b,c,d;
        a=v[i].s+v[i].x;
        b=v[i].s+v[i].y;
        c=v[i].x+v[i].s;
        d=v[i].y+v[i].s;
        stringstream ss;
        ss<<a;
        ss>>n;
        if(lucky.find(n)==lucky.end())
        v.psb(data(a,v[i].x,v[i].y)),lucky[n]=0;
        ss.clear();ss<<b;
        ss>>n;
        if(lucky.find(n)==lucky.end())
        v.psb(data(b,v[i].x,v[i].y)),lucky[n]=0;
        ss.clear();ss<<c;
        ss>>n;
        if(lucky.find(n)==lucky.end())
        v.psb(data(c,v[i].x,v[i].y)),lucky[n]=0;
        ss.clear();ss<<d;
        ss>>n;
        if(lucky.find(n)==lucky.end())
        v.psb(data(d,v[i].x,v[i].y)),lucky[n]=0;
    }
}

int main()
{
    pregen();
    precall();
    cout<<lucky.size()<<endl;
    map<int,int> ::const_iterator it;
    int n,p,cnt=0;
    cin>>n;
    for(it=lucky.begin();it!=lucky.end();it++)
    {
        cnt++;
        p=(int) it->first;
       if(p>=n) break;
    }
    if(p==n) cout<<cnt<<endl;
    else cout<<cnt-1<<endl;
    return 0;
}
