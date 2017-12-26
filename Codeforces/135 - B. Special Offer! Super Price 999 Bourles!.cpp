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
#define LL long long

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

int main()
{
    LL num,red,rnum,nine,tnine,mx,i,j,it,k,nn,n;
    bool flag;
    string s,a;
    stringstream ss;
    while(cin>>s>>red)
    {
        ss.clear();
        ss<<s;
        ss>>num;
        tnine=num;
        rnum=num-red;
        nine=0;
        for(k=s.size()-1,nn=0; k>-1; k--)
        {
            if(s[k]!='9') break;
            nn++;
        }
        n=nn;
        for(i=s.size()-1,j=0; i>-1; i--,j++)
        {
            if(s[i]!='9')
            it=((int) (s[i]-'0')+1)*ceil(pow(10,j));
            else continue;
            tnine-=it;
//            cout<<tnine<<endl;
            ss.clear();
            s.clear();
            ss<<tnine;
            ss>>s;
            for(k=s.size()-1,nn=0; k>-1; k--)
            {
                if(s[k]!='9') break;
                nn++;
            }
            if(tnine>=rnum&&nn>n)
            {
                nine=tnine;
                n=nn;
            }
            else break;
        }
        if(nine==0) nine=num;
        cout<<nine<<endl;
    }
    return 0;
}
