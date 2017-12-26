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
#define pb(b) push_back(b)
#define oo 100000000000000000LL
#define swap(x,y) {int t;t=x;x=y;y=t;}
#define for_i(s,n) for(int i=s;i<n;i++)
#define for_j(s,n) for(int j=s;j<n;j++)
#define for_k(s,n) for(int k=s;k<n;k++)
#define MAX 6

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
    string name;
    int cost;
};

int md(int x,int a,int b,int c)
{
    return ((x*a+b)%c);
}

bool comp(data a,data b)
{
    return a.cost>b.cost;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    data tmp;
    vector<data> vt;
    vector<string> v[MAX];
    int x,a,b,c,team,m,gpos;
    char grp;
    while(scanf("%d",&team)==1)
    {
        vt.clear();
        for(int i=0;i<MAX;i++) v[i].clear();
        scanf("%d %d %d %d ",&x,&a,&b,&c);
        for(int i=0;i<team;i++)
        {
            cin>>tmp.name>>tmp.cost;
            vt.pb(tmp);
        }
        sort(vt.begin(),vt.end(),comp);
        for(int i=0,l=0;i<team;l++)
        {
            for(int j=0;j<team/4;j++,i++)
            {
                v[l].pb(vt[i].name);
            }
        }
//        cout<<":::::::::::::"<<endl;
//        for(int i=0;i<4;i++)
//        {
//            for(int j=0;j<v[i].size();j++)
//            {
//                cout<<v[i][j]<<endl;
//            }
//            cout<<":::::::::::::"<<endl;
//        }
        m=team/4;
        grp='A';
        for(int i=0;i<m-1;i++)
        {
            cout<<"Group "<<grp<<":"<<endl;
            for(int j=0;j<4;j++)
            {
                int s=v[j].size();
                x=md(x,a,b,c);
                gpos=x%s;
                cout<<v[j][gpos]<<endl;
                v[j].erase(v[j].begin()+gpos);
            }
            grp++;
        }
        cout<<"Group "<<grp<<":"<<endl;
        for(int i=0;i<4;i++)
        {
            cout<<v[i][0]<<endl;
        }
    }
    return 0;
}
