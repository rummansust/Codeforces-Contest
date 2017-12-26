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

const int MAX = 1005;

int up[5][MAX][MAX];
int mat[5][MAX][MAX];
int Lpos[MAX],Rpos[MAX];
int his[MAX];

///up = 1, down = 2, left = 3, right = 4;

pair<int,int> upPos(int i,int j,int n,int m)
{
    return mp(i,j);
}

pair<int,int> downPos(int i,int j,int n,int m)
{
    return mp(n-i+1,j);
}

pair<int,int> leftPos(int i,int j,int n,int m)
{
    return mp(j,i);
}

pair<int,int> rightPos(int i,int j,int n,int m)
{
    return mp(m-j+1,i);
}

void printMat(int indx,int n,int m)
{
    puts("::::::::::::::::::::::::::::");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i) PF(" ");
            PF("%d",mat[indx][i][j]);
        }
        puts("");
    }
    puts("::::::::::::::::::::::::::::");
    return ;
}
void printUp(int indx,int n,int m)
{
    puts("::::::::::::::::::::::::::::");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i) PF(" ");
            PF("%d",up[indx][i][j]);
        }
        puts("");
    }
    puts("::::::::::::::::::::::::::::");
    return ;
}

void makeUp(int n,int m)
{
    int height;

    ///up
    for(int j=1;j<=m;j++)
    {
        height=0;
        for(int i=1;i<=n;i++)
        {
            if(!mat[1][i][j]) height=0;
            else height++;
            up[1][i][j]=height;
        }
    }

    ///down
    for(int j=1;j<=m;j++)
    {
        height=0;
        for(int i=1;i<=n;i++)
        {
            if(!mat[2][i][j]) height=0;
            else height++;
            up[2][i][j]=height;
        }
    }

    ///left
    for(int j=1;j<=n;j++)
    {
        height=0;
        for(int i=1;i<=m;i++)
        {
            if(!mat[3][i][j]) height=0;
            else height++;
            up[3][i][j]=height;
        }
    }

    ///right
    for(int j=1;j<=n;j++)
    {
        height=0;
        for(int i=1;i<=m;i++)
        {
            if(!mat[4][i][j]) height=0;
            else height++;
            up[4][i][j]=height;
        }
    }
    return ;
}

void update(int x,int y,int n,int m)
{
    int nx,ny;
    pair<int,int> ret;

    ret=upPos(x,y,n,m);
    nx=ret.fs,ny=ret.sc;
    mat[1][nx][ny]=!mat[1][nx][ny];
    int height=0;
    for(int i=1;i<=n;i++)
    {
        if(!mat[1][i][ny]) height=0;
        else height++;
        up[1][i][ny]=height;
    }

    ret=downPos(x,y,n,m);
    nx=ret.fs,ny=ret.sc;
    mat[2][nx][ny]=!mat[2][nx][ny];
    height=0;
    for(int i=1;i<=n;i++)
    {
        if(!mat[2][i][ny]) height=0;
        else height++;
        up[2][i][ny]=height;
    }

    ret=leftPos(x,y,n,m);
    nx=ret.fs,ny=ret.sc;
    mat[3][nx][ny]=!mat[3][nx][ny];
    height=0;
    for(int i=1;i<=m;i++)
    {
        if(!mat[3][i][ny]) height=0;
        else height++;
        up[3][i][ny]=height;
    }

    ret=rightPos(x,y,n,m);
    nx=ret.fs,ny=ret.sc;
    mat[4][nx][ny]=!mat[4][nx][ny];
    height=0;
    for(int i=1;i<=m;i++)
    {
        if(!mat[4][i][ny]) height=0;
        else height++;
        up[4][i][ny]=height;
    }

    return ;
}

int process(int pos,int n)
{
    for(int i=1;i<=n;i++) Lpos[i]=Rpos[i]=i;
    for(int i=1;i<=n;i++)
    {
        while(Lpos[i]>1 && his[i]<=his[ Lpos[i] - 1 ])
        {
            Lpos[i]=Lpos[ Lpos[i] - 1 ];
        }
    }
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
        while(Rpos[i]<n && his[i]<=his[ Rpos[i] + 1 ])
        {
            Rpos[i]=Rpos[ Rpos[i] + 1 ];
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(pos>=Lpos[i] && pos<=Rpos[i])
        {
            res=max(res,his[i]*(Rpos[i]-Lpos[i]+1));
        }
    }
    return res;
}

int getSol(int x,int y,int n,int m)
{
    int res=0;

    ///up
    int row,col;
    pair<int,int> ret;
    ret = upPos(x,y,n,m);
    row=ret.fs;
    col=ret.sc;
    for(int i=1;i<=m;i++) his[i]=up[1][row][i];
    res=max(res,process(col,m));

    ///down
    ret = downPos(x,y,n,m);
    row=ret.fs;
    col=ret.sc;
    for(int i=1;i<=m;i++) his[i]=up[2][row][i];
    res=max(res,process(col,m));

    ///left
    ret = leftPos(x,y,n,m);
    row=ret.fs;
    col=ret.sc;
    for(int i=1;i<=n;i++) his[i]=up[3][row][i];
    res=max(res,process(col,n));

    ///right
    ret = rightPos(x,y,n,m);
    row=ret.fs;
    col=ret.sc;
    for(int i=1;i<=n;i++) his[i]=up[4][row][i];
    res=max(res,process(col,n));

    return res;
}

int main()
{
    #ifdef rumman
    Read;
    Write;
    #endif // rumman
    int n,m,q;
    SF("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            SF("%d",&mat[1][i][j]);
            mat[2][n-i+1][j]=mat[3][j][i]=mat[4][m-j+1][i]=mat[1][i][j];
        }
    }
    makeUp(n,m);
    int x,y,typ;
    while(q--)
    {
        SF("%d %d %d",&typ,&x,&y);
        if(typ==1)
        {
            update(x,y,n,m);
        }
        else
        {
            PF("%d\n",getSol(x,y,n,m));
        }
    }

    return 0;
}

/**

3 4 5
0 1 1 0
1 0 0 1
0 1 1 0
1 2 2
1 2 3
2 2 2

*/















