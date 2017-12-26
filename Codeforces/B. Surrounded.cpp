#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int r1,r2,x1,y1,x2,y2,temp;
    double c1c2,R;
    while(scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2)==6)
    {
        if(r1>r2)
        {
            temp=r2;
            r2=r1;
            r1=temp;
        }
        c1c2=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
        R=(c1c2-(r1*1.0)-(r2*1.0))/2.0;
        if(R<0)
        {
            if((r1+c1c2)<r2)
            {
                R=((r2*1.0)-(r1*1.0)-c1c2)/2.0;
            }
            else
            {
                R=0;
            }
        }
        printf("%lf\n",R);
    }
    return 0;
}
