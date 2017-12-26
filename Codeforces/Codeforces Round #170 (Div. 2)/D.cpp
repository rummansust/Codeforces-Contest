#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(m==3&&n>4)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        cout<<-i<<" "<<(n-i)*(n-i)<<endl;
    }
    for(int i=0;i<n-m;i++)
    {
        cout<<i<<" "<<-(n-i)*(n-i)<<endl;
    }
    return 0;
}
