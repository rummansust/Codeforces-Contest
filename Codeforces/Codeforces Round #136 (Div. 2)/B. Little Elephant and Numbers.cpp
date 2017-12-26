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

#define clr(a,x) memset(a,x,sizeof(a));
#define ll long long
#define pb(b) push_back(a)
#define oo 100000000000000000LL
#define SZ 32000

//reverse(a,a+n);
//binary_search(first,last);
//vector erase v.erase(v.begin(),position);
//map map<int , int > data;
//map clear  data.clear();

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

ll divisor[SZ];

int main()
{
    ll num,sl,it,cnt;
    string s,n;
    stringstream ss;
    double sq;
    bool flag,pice;
    while(cin>>num)
    {
        if(num==2) cnt=1;
        else
        {
            n.clear();
            ss<<num;
            ss>>n;
            ss.clear();
            cnt=0;
            sq=sqrt(num);
            sl=(ll) ceil(sq);
            if(sl*sl==num) flag=false;
            else flag=true;
            it=0;
            for(ll i=1; i<=sl; i++)
            {
                if(num%i==0)
                {
                    divisor[it++]=i;
                    ss<<i;
                    ss>>s;
//                    cout<<".."<<s<<endl;
                    ss.clear();
                    pice=false;
                    for(ll j=0; j<s.size(); j++)
                    {
                        for(int k=0; k<n.size(); k++)
                        {
                            if(s[j]==n[k])
                            {
                                pice=true;
                                cnt++;
                                break;
                            }
                        }
                        if(pice) break;
                    }
                    s.clear();
                    if(flag||i!=sl)
                    {
                        divisor[it++]=(num/i);
                        ss<<(num/i);
                        ss>>s;
//                        cout<<".."<<s<<endl;
                        ss.clear();
                        pice=false;
                        for(ll j=0; j<s.size(); j++)
                        {
                            for(int k=0; k<n.size(); k++)
                            {
                                if(s[j]==n[k])
                                {
                                    pice=true;
                                    cnt++;
                                    break;
                                }
                            }
                            if(pice) break;
                        }
                    }
                    s.clear();
//                cout<<i<<endl;cout<<num/i<<endl;
                }
            }

        }
        cout<<cnt<<endl;
    }
    return 0;
}
