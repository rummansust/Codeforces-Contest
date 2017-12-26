#include<bits/stdc++.h>

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
#define oo (1<<28)
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }
ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }
ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

const int MAX = 900000;

vector<int> oddu;
vector<int> oddd;
vector<int> eveu;
vector<int> eved;
int a,b,c,l;

ll res=0;

void calcOdd(int p1,int p2,int s2,int h)
{
    int posuu=(p1-1)/2,posud=0;
    if(s2==1) posud=(p2-1)/2;
    int lb = lower_bound(all(oddu),c)-oddu.begin();
    if(oddu[lb]>c) lb--;
    lb=min(posuu,lb);
    ll x=0;
    x=max(x,(ll)(lb-posud+1));
    res+=x*(ll)(max(h-c+1,0));
    lb = lower_bound(all(oddu),c)-oddu.begin();
    if(oddu[lb]<=c) lb++;
    lb=min(lb,posuu);
    lb=max(lb,posud);
    int t;
    int nlb = lower_bound(all(oddu),h)-oddu.begin();
    if(oddu[nlb]>h) nlb--;
    nlb=min(posuu,nlb);
    x=max(0,nlb-lb+1);
    if(x && oddu[lb]>c && oddu[nlb]>c && nlb>=posud)
    {
        t=oddu[lb];
        res+=x*(ll)(h+1) - (x*x+x*(ll)(t-1));
    }

    if(s2==0)
    {
        posud=(p2-1)/2;
        posud--;
        lb = lower_bound(all(oddd),c)-oddd.begin();
        if(oddd[lb]>c) lb--;
        lb=min(posud,lb);
        x=0;
        x=max(x,(ll)(lb+1));
        res+=x*(ll)(max(h-c+1,0));
        lb = lower_bound(all(oddd),c)-oddd.begin();
        if(oddd[lb]<=c) lb++;

        lb=min(lb,posud);
        nlb = lower_bound(all(oddd),h)-oddd.begin();
        if(oddd[nlb]>h) nlb--;
        nlb=min(posud,nlb);
        x=max(0,nlb-lb+1);
        if(x && oddd[lb]>c && oddd[nlb]>c)
        {
            t=oddd[lb];
            res+=x*(ll)(h+1) - (x*x+x*(ll)(t-1));
        }
    }
    return ;
}

void calcEve(int p1,int p2,int s2,int h)
{
    int posuu=(p1-1)/2,posud=0;
    if(s2==1) posud=(p2-1)/2;
    int lb = lower_bound(all(eveu),c)-eveu.begin();
    if(eveu[lb]>c) lb--;
    lb=min(posuu,lb);
    ll x=0;
    x=max(x,(ll)(lb-posud+1));
    res+=x*(ll)(max(h-c+1,0));
    lb = lower_bound(all(eveu),c)-eveu.begin();
    if(eveu[lb]<=c) lb++;
    lb=min(lb,posuu);
    lb=max(lb,posud);
    int t;
    int nlb = lower_bound(all(eveu),h)-eveu.begin();
    if(eveu[nlb]>h) nlb--;
    nlb=min(posuu,nlb);
    x=max(0,nlb-lb+1);
    if(x && eveu[lb]>c && eveu[nlb]>c && nlb>=posud)
    {
        t=eveu[lb];
        res+=x*(ll)(h+1) - (x*x+x*(ll)(t-1));
    }
    if(s2==0)
    {
        posud=(p2-1)/2;
        lb = lower_bound(all(eved),c)-eved.begin();
        if(eved[lb]>c) lb--;
        lb=min(posud,lb);
        x=0;
        x=max(x,(ll)(lb+1));
        res+=x*(ll)(max(h-c+1,0));
        lb = lower_bound(all(eved),c)-eved.begin();
        if(eved[lb]<=c) lb++;
        lb=min(lb,posud);
        nlb = lower_bound(all(eved),h)-eved.begin();
        if(eved[nlb]>h) nlb--;
        nlb=min(posud,nlb);
        x=max(0,nlb-lb+1);
        if(x && eved[lb]>c && eved[nlb]>c)
        {
            t=eved[lb];
            res+=x*(ll)(h+1) - (x*x+x*(ll)(t-1));
        }
    }
    return ;
}

int main()
{
    for(int i=1;i<MAX;i+=2)
    {
        oddu.psb(i);
    }
    for(int i=3;i<MAX;i+=2)
    {
        oddd.psb(i);
    }
    for(int i=2;i<MAX;i+=2)
    {
        eveu.psb(i);
    }
    for(int i=2;i<MAX;i+=2)
    {
        eved.psb(i);
    }
    SF("%d %d %d %d",&a,&b,&c,&l);
    vector<int> tmp;
    tmp.psb(a);
    tmp.psb(b);
    tmp.psb(c);
    sort(all(tmp));
    b=tmp[2];a=tmp[1];c=tmp[0];
    for(int i=0;i<=l;i++)
    {
        int H = max(0,min((a+b+i-1),(l-i)+c));
        int P1,S2=1,P2;
        P1=(b-a)+i+1;
        P2=(b-a)-i;
        if(P2<0) S2=0,P2=-P2;
        P2++;
        if(P1&1)
        {
            calcOdd(P1,P2,S2,H);
        }
        else
        {
            calcEve(P1,P2,S2,H);
        }
    }
    PF("%I64d\n",res);
    return 0;
}













