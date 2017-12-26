#include <tr1/random>
//#include <bits/stdc++.h>
//
//using namespace std;
using namespace std::tr1;
//
//int main()
//{
//    variate_generator<mt19937, normal_distribution<> > r(mt19937(time(0)), normal_distribution<>(0.5, 2.0));
//    mt19937 seeder(time(NULL));
//    variate_generator<mt19937, normal_distribution<> > r1(mt19937(seeder), normal_distribution<>(0.5, 2.0));
//    variate_generator<mt19937, normal_distribution<> > r2(mt19937(seeder), normal_distribution<>(0.5, 2.0));
//    variate_generator<mt19937, uniform_real<> > urng(mt19937(time(NULL)), uniform_real<>());
//    for (int i = 0; i < 5; i++)
//        cout << urng() << endl;
//    return 0;
//}
//
//
//
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
#define Write freopen("in.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

int main()
{
    Write;
    mt19937 seeder(time(NULL));
    variate_generator<mt19937, uniform_real<> > urng(mt19937(time(NULL)), uniform_real<>());
    int n,k;
    int test=1;
    int arr[]={10,9,3,3,10,9,3,10,3,10};
    while(test--)
    {
        k=10;
        n=100000;
        cout<<k<<" "<<n<<endl;
        for(int i=0;i<n;i++)
        {
            random_shuffle(arr,arr+10);
            int val=(int)(urng()*100.0)%10;
            cout<<arr[val]<<" ";
        }
        cout<<endl;
    }
}










