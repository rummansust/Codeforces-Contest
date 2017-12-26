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
#define Write freopen("outDs.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const int MAX = 405;

int mat[MAX][MAX];
int tmp[MAX][MAX];
int rowSum[MAX][MAX],colSum[MAX][MAX],digSum1[MAX][MAX],digSum2[MAX][MAX];

void printGrid(int n,int m)
{
    puts("::::::::::::::::::::::");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            PF("%d",mat[i][j]);
        }
        puts("");
    }
    puts("::::::::::::::::::::::");
    return ;
}

void rotateGrid(int &n,int &m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            tmp[m-j+1][i]=mat[i][j];
        }
    }
    swap(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            mat[i][j]=tmp[i][j];
        }
    }
    return ;
}

void makeSum(int n,int m)
{
    clrall(rowSum,0);
    clrall(colSum,0);
    clrall(digSum1,0);
    clrall(digSum2,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            rowSum[i][j]=rowSum[i][j-1]+mat[i][j];
            colSum[i][j]=colSum[i-1][j]+mat[i][j];
            digSum1[i][j]=digSum1[i-1][j-1]+mat[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>0;j--)
        {
            digSum2[i][j]=digSum2[i-1][j+1]+mat[i][j];
        }
    }
}

int getNRRightAngle(int n,int m)
{
    int ret=0;
    int t=min(n,m);
    int i2,j2,i3,j3,s1,s2,s3,c1,c2,c3;
    ///row,col,dig1;
    for(int i1=1;i1<=n;i1++)
    {
        for(int j1=1;j1<=m;j1++)
        {
            for(int k=1;k<=t;k++)
            {
                i3=i1+k;
                j3=j1+k;
                i2=i3;
                j2=j1;
                if((i2>0&&i2<=n) && (i3>0&&i3<=n) && (j2>0&&j2<=m) && (j3>0&&j3<=m))
                {
                    c1=j3-j2+1;
                    c2=i2-i1+1;
                    c3=k+1;
                    s1=rowSum[i3][j3]-rowSum[i2][j2-1];
                    s2=colSum[i2][j2]-colSum[i1-1][j1];
                    s3=digSum1[i3][j3]-digSum1[i1-1][j1-1];
                    if(c1==s1 && c2==s2 && c3==s3) ret++;
                }
                else break;
            }
        }
    }
    return ret;
}

int getRRightAngle(int n,int m)
{
    int ret=0;
    int t=min(n,m);
    int i2,j2,i3,j3,s1,s2,s3,c1,c2,c3;
    ///col,dig2,dig1;
    for(int i1=1;i1<=n;i1++)
    {
        for(int j1=1;j1<=m;j1++)
        {
            for(int k=1;k<=t;k++)
            {
                i2=i1+2*k;
                j2=j1;
                i3=i1+k;
                j3=j1+k;
                if((i2>0&&i2<=n) && (i3>0&&i3<=n) && (j2>0&&j2<=m) && (j3>0&&j3<=m))
                {
                    c1=i2-i1+1;
                    c2=k+1;
                    c3=k+1;
                    s1=colSum[i2][j2]-colSum[i1-1][j1];
                    s2=digSum2[i2][j2]-digSum2[i3-1][j3+1];
                    s3=digSum1[i3][j3]-digSum1[i1-1][j1-1];
                    if(c1==s1 && c2==s2 && c3==s3) ret++;
                }
                else break;
            }
        }
    }
    return ret;
}

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    int n,m,res=0;
    char ch;
    SF("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            SF(" %c",&ch);
            mat[i][j]=(ch=='0');
        }
    }
    makeSum(n,m);
    res+=getNRRightAngle(n,m);
    res+=getRRightAngle(n,m);

    rotateGrid(n,m);
    makeSum(n,m);
    res+=getNRRightAngle(n,m);
    res+=getRRightAngle(n,m);

    rotateGrid(n,m);
    makeSum(n,m);
    res+=getNRRightAngle(n,m);
    res+=getRRightAngle(n,m);

    rotateGrid(n,m);
    makeSum(n,m);
    res+=getNRRightAngle(n,m);
    res+=getRRightAngle(n,m);

    PF("%d\n",res);
    return 0;
}












