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
//map clear  data.clear();
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

int main(void)
{
    int i,j,k,nst,len;
    char s[1020];
    string ans,ts;
    map <char,int> track;
    bool flag;
    scanf("%d ",&k);
//        s.clear();
    ans.clear();
    ts.clear();
    scanf("%s",&s);
    track.clear();
    len=strlen(s);
    for(i=0; i<len; i++)
    {
        track[s[i]]++;
    }
    map<char,int>::const_iterator it;
    flag=true;
    for(it=track.begin(); it!=track.end(); ++it)
    {
        nst=track[it->first];
//            cout<<nst<<endl;
        if(nst%k!=0)
        {
            flag=false;
            break;
        }
//            cout<<it->first<<" "<<it->second<<endl;
    }
    if(flag)
    {
        for(it=track.begin(); it!=track.end(); ++it)
        {
            for(i=0; i<((int) it->second)/k; i++)
            {
                ts+=(char) it->first;
            }
        }
        for(i=0; i<k; i++) ans+=ts;
    }
    else ans="-1";
    cout<<ans<<endl;
    return 0;
}
