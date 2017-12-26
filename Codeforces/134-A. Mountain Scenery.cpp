#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cmath>
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
#include <algorithm>

#define clr(a,x) memset(a,x,sizeof(a));

//reverse(a,a+n);
//binary_search(first,last);
//vector erase v.erase(v.begin(),position);
//map map<int , int > data;

using namespace std;
//bool colour[210][210];
//int rr[]= {-1,-1,0,0,1,1};
//int cc[]= {-1,0,-1,1,0,1};
//int rr[]= {0,0,1,-1};/*4 side move*/
//int cc[]= {-1,1,0,0};/*4 side move*/
//int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

int main(void)
{
    int i,j,it,max,n,k,num;
    vector <int> v,peak;
    while(cin>>n>>k)
    {
        v.clear();
        peak.clear();
        for(i=0; i<(2*n+1); i++)
        {
            cin>>num;
            v.push_back(num);
        }
        it=0;
        if(v.size()==1) v[0]--;
        else
        {
            if(v[0]>v[1])
            {
                if(v[0]-1>v[1]&&it<k)
                {
                    v[0]--;
                    it++;
                }
            }
            for(i=1; i<v.size()-1; i++)
            {
                if(v[i]>v[i-1]&&v[i]>v[i+1])
                {
                    if(v[i]-1>v[i-1]&&v[i]-1>v[i+1]&&it<k)
                    {
                        it++;
                        v[i]--;
                    }
                }
            }
            if(v[i]>v[i-1])
            {
                if(v[i]-1>v[i]&&it<k)
                {
                    v[i]--;
                    it++;
                }
            }
        }
        for(i=0;i<v.size();i++)
        {
            cout<<v[i];
            if(i<v.size()-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
