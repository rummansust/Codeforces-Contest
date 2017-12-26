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
#define MAX 10

///next_permutation  next_permutation (s.begin(),s.end())
///reverse(a,a+n);
///binary_search(first,last);
///vector erase v.erase(v.begin()+position);
///map map<int , int > data;
///map clear  data.clear();
///map iterator>>>> map <int,vector <int> >::const_iterator it;
///find an element in map (colour.find(nd)==colour.end());//if it return true this
///mean the element is'nt in the map.
///pass a vector to a funtion: funtion (vector <data type> *vector name);

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
    int x,y;
};
data par[MAX][MAX];
int colour[MAX][MAX];
vector <string> v;
string str[]= {"hello","D","RD","R","RU","U","LU","L","LD"};
int bfs_fun(int s1,int s2,int e1,int e2)
{
    int p,q;
    int ts1=s1,ts2=s2;
    bool flag=true;
    queue <int> Q;
    Q.push(s1);
    Q.push(s2);
    colour[s1][s2]=1;
    while(flag)
    {
        s1=Q.front();
        Q.pop();
        s2=Q.front();
        Q.pop();
        for(int i=0; i<8; i++)
        {
            p=s1+rr[i];
            q=s2+cc[i];
            if((p>-1&&p<8)&&(q>-1&&q<8))
            {
                if(colour[p][q]==0)
                {
                    colour[p][q]=i+1;
                    par[p][q].x=s1;
                    par[p][q].y=s2;
                    Q.push(p);
                    Q.push(q);
                    if(e1==p&&e2==q)
                    {
                        flag=false;
                        break;
                    }
                }
            }
        }
    }
    flag=true;
    p=e1;
    q=e2;
    while(flag)
    {
        int col=colour[p][q];
        v.pb(str[col]);
        int t1=par[p][q].x;
        int t2=par[p][q].y;
        p=t1;
        q=t2;
        if(p==ts1&&q==ts2)
        {
            flag=false;
        }
    }
    return 0;
}

int main()
{
    int s1,s2,e1,e2,y;
    char x;
    scanf("%c %d",&x,&y);
    s2=((int) x-'a');
    s1=8-y;
    scanf(" %c %d",&x,&y);
    e2=((int) x-'a');
    e1=8-y;
    v.clear();
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            colour[i][j]=0;
    bool flag=true;
    if(!((s1==e1)&&(s2==e2)))
    {
        flag=false;
        bfs_fun(s1,s2,e1,e2);
    }
    cout<<v.size()<<endl;
    for(int i=v.size()-1;i>-1;i--)
    {
        cout<<v[i]<<endl;
    }
    if(flag) cout<<endl;
    return 0;
}
