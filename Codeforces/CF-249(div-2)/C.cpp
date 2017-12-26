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
#define Write freopen("outM.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const int MAX = 1005;

int sumop[MAX],sumnp[MAX];

int ai[MAX];

char mat[MAX][MAX];

int main()
{
    #ifdef rumman
    Read;
    Write;
    #endif // rumman
    int n;
    while(SF("%d",&n)==1)
    {
        clrall(sumnp,0);
        clrall(sumop,0);
        int t=-1;
        int mn=0,mx=0;
        for(int i=1;i<=n;i++)
        {
            SF("%d",&ai[i]);
            t*=-1;
            sumop[i]=sumop[i-1]+ai[i];
            sumnp[i]=sumnp[i-1]+t*ai[i];
//            cout<<sumop[i]<<" *** "<<sumnp[i]<<endl;
            mn=min(mn,sumnp[i]);
            mx=max(mx,sumnp[i]);
        }
        for(int i=0;i<=n;i++)
        {
            sumnp[i]=1000-(sumnp[i]-mn);
        }
//        cout<<mx<<" :: "<<mn<<endl;
        int r1=1000-(mx-mn),r2=1000;
        for(int i=0;i<=1000;i++)
        {
            for(int j=0;j<=1000;j++)
            {
                mat[i][j]=' ';
            }
            mat[i][sumop[n]]='\0';
        }
        int px=1000+mn,py=0,ny,nx;
        for(int i=1;i<=n;i++)
        {
            nx=sumnp[i];
            ny=sumop[i];
//            cout<<"px : "<<px<<" py : "<<py<<" nx : "<<nx<<" ny : "<<ny<<endl;
            if(nx<px)
            {
//                cout<<"upore : "<<endl;
                for(int i=px,j=py;i>nx;i--,j++)
                {
                    mat[i][j]='/';
//                    cout<<"pos : "<<i<<" "<<j<<endl;
                }
            }
            else
            {
//                cout<<"nice : "<<endl;
                for(int i=px+1,j=py;i<=nx;i++,j++)
                {
                    mat[i][j]='\\';
//                    cout<<"pos : "<<i<<" "<<j<<endl;
                }
            }
            px=nx;
            py=ny;
        }
//        cout<<r1<<" "<<r2<<endl;
        for(int i=r1+1;i<=r2;i++)
        {
            PF("%s\n",mat[i]);
        }
    }
    return 0;
}
/**

     /\
  /\/  \
 /      \
/        \
          \/

/\
  \
   \
    \
     \/
*/

















