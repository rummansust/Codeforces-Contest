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

struct node
{
    int day,mnt,yrr;
};

bool cheak(int i,string &s)
{
    if((s[i-1]>='0'&&s[i-1]<='9')&&(s[i-2]>='0'&&s[i-2]<='9'))
    {
        if((s[i+1]>='0'&&s[i+1]<='9')&&(s[i+2]>='0'&&s[i+2]<='9'))
        {
            if(s[i+3]=='-')
            {
                for(int j=i+4;j<i+8;j++)
                {
                    if(s[j]<'0'||s[i]>'9') return false;
                }
                return true;
            }
        }
    }
    return false;
}

int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool cheak2(int d,int m,int y)
{
    if(m>0&&m<=12)
    {
        if(d>0&&d<=month[m])
        {
            if(y>2012&&y<2016) return true;
        }
    }
    return false;
}

int res[35][13][2020];

int main()
{
    clr(res,0);
    string s;
    int mx=-1;
    cin>>s;
    node tmp,ans;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-')
        {
            if(i-2>-1&&i+7<s.size())
            {
                if(cheak(i,s))
                {
                    tmp.day=((int) (s[i-2]-'0')*10)+(s[i-1]-'0');
                    tmp.mnt=((int) (s[i+1]-'0')*10)+(s[i+2]-'0');
                    tmp.yrr=((int) (s[i+4]-'0')*1000)+((s[i+5]-'0')*100)+((s[i+6]-'0')*10)+((s[i+7]-'0'));
                    if(cheak2(tmp.day,tmp.mnt,tmp.yrr))
                    {
                        int p=res[tmp.day][tmp.mnt][tmp.yrr]++;
                        p++;
                        if(mx<p)
                        {
                            mx=p;
                            ans.day=tmp.day;
                            ans.mnt=tmp.mnt;
                            ans.yrr=tmp.yrr;
                        }
                    }
                }
            }
        }
    }
    printf("%02d-%02d-%04d",ans.day,ans.mnt,ans.yrr);
    return 0;
}
