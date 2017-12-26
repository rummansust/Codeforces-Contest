///for testing purpose
/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


pair < LL, LL > pp[2][100001];
vector < pair < LL, LL > > vc;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL h, q; cin >> h >> q;
    int c1 = 0, c2 = 0;

    while(q--){
        LL lvl, l, r, ans;
        cin >> lvl >> l >> r >> ans;
        for(int j = lvl + 1; j <= h; j++){
            l *= 2ll;
            r = (r * 2ll + 1ll);
        }
        if(ans == 0){
            pp[ans][c1++] = mp(l, r);
        } else {
            pp[ans][c2++] = mp(l, r);
        }
    }

    LL l = 1, r = 1, mx, mn;
    for(int i = 2; i <= h; i++){
        l *= 2ll;
        r = (r * 2ll + 1ll);
    }
    mx = r; mn = l;

    REP(i, c2){
        if(pp[1][i].xx > r || pp[1][i].yy < l){
            cout << "Game cheated!" << endl;
            return 0;
        }
        l = max(l, pp[1][i].xx);
        r = min(r, pp[1][i].yy);
    }

    sort(pp[0], pp[0] + c1);

    LL rgt = mn - 1;
    LL nl,nr;
    REP(i, c1){
        if(pp[0][i].yy <= rgt) continue;
        if(pp[0][i].xx > rgt+1){
            nl=max(l,rgt + 1);
            nr=min(r,pp[0][i].xx - 1);
            if(nl<=nr) vc.pb(mp(nl,nr));
        }
        rgt = max(rgt, pp[0][i].yy);
    }
    if(rgt < mx)
    {
        nl=max(l,rgt + 1);
        nr=min(r,mx);
        if(nl<=nr) vc.pb(mp(nl,nr));
    }

    vc.resize(distance(vc.begin(),unique(vc.begin(),vc.end())));
    int s=vc.size();
    if(s==0){
        cout << "Game cheated!" << endl;
        return 0;
    }
    if(s==1 && vc[0].xx==vc[0].yy){
        cout << vc[0].xx << endl;
    } else {
        cout << "Data not sufficient!" << endl;
    }
}
