#include <stdio.h>
#include <math.h>
int main()
{
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    int bitnum,res1,res2,res;
    scanf("%d",&bitnum);
    res1=n1/pow(2,bitnum-1);
    res1=res1%2;
    res2=n2/pow(2,bitnum-1);
    res2=res2%2;
    res=res1+res2;
    if(res==2 || res==0)
    {
    	printf("0\n");
	}
	else
	{
		printf("1\n");
	}
    return 0;
}

