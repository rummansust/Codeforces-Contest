#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>

#define psb(a) push_back(a)

using namespace std;

int main()
{
    map<string,double> data;
    vector<string> v;
    v.psb("A+");
    v.psb("A");
    v.psb("A-");
    v.psb("B+");
    v.psb("B");
    v.psb("B-");
    v.psb("C+");
    v.psb("C");
    v.psb("C-");
    double k=4.0;
    for(int j=0;j<v.size();k-=.25,j++)
    {
        data[v[j]]=k;
    }
    data["F"]=0.0;
    double crdt[]={3,3,3,1.5,1.5,3.0};
    while(1)
    {
        double sum=0.0;
        for(int i=0;i<6;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++)
            {
                s[j]=(char) toupper(s[j]);
            }
            sum+=(data[s]*crdt[i]);
        }
        printf("CGPA : %lf\n",sum/15.0);
    }
}
