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

#define clr(name,val) memset(name,(val),sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 1000000000000
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)

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

ll mat[502][502],build[502][502];

int main()
{
    vector<int> node;
    int n,num;

    for(int i=0;i<502;i++)
    for(int j=0;j<502;j++)
    build[i][j]=oo;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    scanf("%I64d",&mat[i][j]);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&num);
        node.psb(num);
    }
    vector<ll> sumo;
    int data[502];
    clr(data,0);
    ll sum;
    reverse(node.begin(),node.end());
    for(int i=0;i<node.size();i++)
    {
        int u=node[i];
        data[u]++;
        for(int j=1;j<=n;j++)
        {
            if(data[j]==0) continue;
            for(int k=1;k<=n;k++)
            {
                if(j==k) continue;
                if(data[k]==0) continue;
                build[j][k]=min(build[j][k],mat[j][k]);
            }
        }
        for(int l=1;l<=n;l++)
        {
            if(data[l]==0) continue;
            for(int m=1;m<=n;m++)
            {
                if(l==m) continue;
                if(data[m]==0) continue;
                build[m][u]=min(build[m][u],build[m][l]+build[l][u]);
            }
        }
        for(int l=1;l<=n;l++)
        {
            if(data[l]==0) continue;
            for(int m=1;m<=n;m++)
            {
                if(l==m) continue;
                if(data[m]==0) continue;
                build[u][m]=min(build[u][m],build[u][l]+build[l][m]);
            }
        }
        for(int l=1;l<=n;l++)
        {
            if(data[l]==0) continue;
            for(int m=1;m<=n;m++)
            {
                if(l==m) continue;
                if(data[m]==0) continue;
                build[l][m]=min(build[l][m],build[l][u]+build[u][m]);
            }
        }
        sum=0L;
        for(int l=1;l<=n;l++)
        {
            for(int m=1;m<=n;m++)
            {
                if(build[l][m]!=oo&&l!=m) sum+=build[l][m];
            }
        }
        sumo.psb(sum);
    }
    for(int i=sumo.size()-1;i>-1;i--)
    {
        printf("%I64d",sumo[i]);
        if(i) printf(" ");
    }
    puts("");
    return 0;
}
