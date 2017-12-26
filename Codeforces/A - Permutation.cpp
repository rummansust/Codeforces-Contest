#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SZ 10500

int main()
{
    int i,j,k,l,len1,len2,flag1,flag2,cas=1,flagcas=0;
    char str1[SZ],str2[SZ],temp[SZ];
//    freopen("permutin.txt","r",stdin);
//    freopen("permutout.txt","w",stdout);
    while(gets(str1))
    {
        gets(str2);
        flag1=1;
        flag2=1;
        len1=strlen(str1);
        len2=strlen(str2);
        if(len1!=len2)
        {
            flag1=0;
        }
        else
        {
            for(i=0; i<len1; i++)
            {
                for(j=0; j<len2; j++)
                {
                    if(str1[i]==str2[j])
                    {
                        str2[j]='@';
                        temp[i]=str1[i];
                        flag2=0;
                        break;
                    }
                }
                if(flag2==0) flag2=1;
                else break;
            }
            temp[i]='\0';
            len1=strlen(temp);
            if(len1!=len2)
            {
                flag1=0;
            }
        }
        if(flag1==0)
        {
            printf("Case %d: NOT PERMUTATION\n\n",cas++);
        }
        else
        {
            printf("Case %d: PERMUTATION\n\n",cas++);
        }
    }
    return 0;
}
