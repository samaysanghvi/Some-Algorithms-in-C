#include <stdio.h>
#include <string.h>
 int checkpalin(char a[100],int s,int e)
 {
     int flag=0,i,j,res;
     res=0;
     i=s;
     j=e;
     while(i<=j && flag==0)
     {
         if(a[i]==a[j])
         {
             i++;
             j--;
         }
         else
         {
             flag=1;
         }
     }
     if(flag==1)
     {
         res=0;
     }
     else
     {
         res=e-s+1;
     }
     return res;
 }
int main()
{
    char s[100];
    scanf("%s",s);
    int i,j,len,res;
    res=0,i=0;
    len=strlen(s);
    j=len-1;
    while(i<len)
    {
        if(s[i]==s[j])
        {
            if(j-i+1>res)
            {
                res=checkpalin(s,i,j);
            }
        }
        j--;
        if(j<0)
        {
            i++;
            j=len-1;
        }
    }
    printf("%d\n",res);
    return 0;
}

