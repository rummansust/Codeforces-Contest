#include <bits/stdc++.h>
using namespace std;typedef long long ll;ll T=1e18;ll T1=1e17;int main(){ll A,P=1;cin>>A;for(int i=0;i<810;i++){P+=T1;P%=A;}ll K=(P==0?0:(A-P));cout<<1+K<<" "<<T+K<<"\n";return 0;}
