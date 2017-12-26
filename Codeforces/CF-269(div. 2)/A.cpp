#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<29)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outE.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

int main()
{
    int val[10];
    int mpp[100];
    clrall(mpp,0);
    for(int i=0;i<6;i++)
    {
        cin>>val[i];
        mpp[val[i]]++;
    }

    for(int i=0;i<6;i++)
    {
        if(mpp[val[i]]==6)
        {
            cout<<"Elephant";
            return 0;
        }
    }
    for(int i=0;i<6;i++)
    {
        if(mpp[val[i]]==5)
        {
        cout<<"Bear";
        return 0;

        }
    }
    sort(val,val+6);
    for(int i=0;i<6;i++)
    {
        if(mpp[val[i]]==4)
        {
            val[i]=100;
        }
    }
    sort(val,val+6);
    if(val[3]!=100)
    {

    cout<<"Alien";
            return 0;
    }
    if(val[0]==val[1])
    {
        cout<<"Elephant";
        return 0;
    }
    if(val[0]<val[1])
    {
        cout<<"Bear";
        return 0;
    }
    cout<<"Alien";
            return 0;
    return 0;
}


















