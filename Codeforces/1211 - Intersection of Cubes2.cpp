#include<stdio.h>

int main()
{
    long long int x1,y1,z1,x2,y2,z2,mx1,my1,mz1,mx2,my2,mz2,l,w,h,vlum;
    int i,j,k,n,test,cas=1;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        scanf("%lld %lld %lld %lld %lld %lld",&x1,&y1,&z1,&x2,&y2,&z2);
        mx1=x1; my1=y1; mz1=z1; mx2=x2; my2=y2; mz2=z2;
        while(--n)
        {
            scanf("%lld %lld %lld %lld %lld %lld",&x1,&y1,&z1,&x2,&y2,&z2);
            if(mx1<x1) mx1=x1;
            if(my1<y1) my1=y1;
            if(mz1<z1) mz1=z1;
            if(mx2>x2) mx2=x2;
            if(my2>y2) my2=y2;
            if(mz2>z2) mz2=z2;
        }
        l=mx2-mx1;
        h=my2-my1;
        w=mz2-mz1;
        if(l<=0||h<=0||w<=0)
        {
            vlum=0;
        }
        else
        {
            vlum=l*h*w;
        }
        printf("Case %d: %lld\n",cas++,vlum);
    }
    return 0;
}
