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

int main()
{
    int arr[11],sz,q,lb,ub,dir[111],fl;
    string s,ts;
    scanf("%d%d ",&sz,&q);
    cin>>s;
    for(int i=0; i<q; i++)
    {
        clr(arr,0);
        cin>>lb>>ub;
        lb--;ub--;
        ts=s.substr(lb,ub-lb+1);
        bool flag=true;
        int pos=0,prvs=-1;
        char prv='p';
//        cout<<"::: "<<ts<<endl;
        while(flag)
        {
//            cout<<"pos:"<<pos<<endl;
            fl=1;
            for(int i=0; i<ts.size(); i++)
            {
                if(ts[i]=='>')
                {
                    fl=1;
                }
                else if(ts[i]=='<')
                {
                    fl=-1;
                }
                dir[i]=fl;
            }
            if(pos<0||pos>=ts.size()) break;
            if(ts[pos]>='1'&&ts[pos]<='9')
            {
                arr[(ts[pos]-48)]++;
                prv=ts[pos];
                ts[pos]=ts[pos]-1;
                pos+=dir[pos];

            }
            else if(ts[pos]=='0')
            {
                arr[0]++;
                prv=ts[pos];
                ts.erase(ts.begin()+pos);

                if(dir[pos]>0)
                {
                    pos+=dir[pos];
                    pos--;
                }
                else pos+=dir[pos];
            }
            else
            {
                if(prv=='>'||prv=='<')
                {
                    prv=ts[pos];
                    ts.erase(ts.begin()+prvs);
                    prvs=pos;
                    if(dir[pos]>0)
                    {
                        pos+=dir[pos];pos--;
                    }
                    else pos+=dir[pos];
                }
                else
                {
                    prv=ts[pos];
                    prvs=pos;
                    pos+=dir[pos];
                }
            }
        }
        for(int i=0;i<10;i++)
        {
            if(i) cout<<" ";
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
