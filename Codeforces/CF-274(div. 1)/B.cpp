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

const int MAX = 110000;

set<int> mark,add;

vector<int> A;
vector<int> B;


int main()
{
    int val,n,l,x,y;
    SF("%d",&n);
    SF("%d",&l);
    SF("%d",&x);
    SF("%d",&y);
    for(int i=0;i<n;i++)
    {
        SF("%d",&val);
        mark.insert(val);
    }
    int a=-1,b=-1;
    int fa=false,fb=false;
    for(set<int> :: iterator it = mark.begin();it!=mark.end();it++)
    {
        int val=(*it);
        int d=(val-x);
        if(d>=0)
        {
            if(mark.find(d)!=mark.end())
            {
                fa=true;
                break;
            }
            else
            {
                A.psb(d);
            }
        }
//        else
//        {
            d=val+x;
            if(d>l) continue;
            if(mark.find(d)!=mark.end())
            {
                fa=true;
                break;
            }
            else
            {
                A.psb(d);
            }
//        }
    }
    for(set<int> :: iterator it = mark.begin();it!=mark.end();it++)
    {
        int val=(*it);
        int d=(val-y);
        if(d>=0)
        {
            if(mark.find(d)!=mark.end())
            {
                fb=true;
                break;
            }
            else
            {
                B.psb(d);
            }
        }
//        else
//        {
            d=val+y;
            if(d>l) continue;
            if(mark.find(d)!=mark.end())
            {
                fb=true;
                break;
            }
            else
            {
                B.psb(d);
            }
//        }
    }
    if(fa&&fb)
    {
        cout<<0<<endl;
    }
    else if(fa&&!fb)
    {
        cout<<1<<endl;
        cout<<B[0]<<endl;
    }
    else if(!fa&&fb)
    {
        cout<<1<<endl;
        cout<<A[0]<<endl;
    }
    else
    {
        sort(A.begin(),A.end());
        cout<<endl;
        for(int i=0;i<SZ(B);i++)
        {
            if(binary_search(A.begin(),A.end(),B[i]))
            {
                cout<<1<<endl;
                cout<<B[i]<<endl;
                return 0;
            }
        }
        cout<<2<<endl;
        if(A[0]>B[0]) swap(A[0],B[0]);
        cout<<A[0]<<" "<<B[0]<<endl;
    }
    return 0;
}

/**
3 300 130 180
0 50 300


3 1000000000 999999 1000005
0 99999 1000000000
*/
















