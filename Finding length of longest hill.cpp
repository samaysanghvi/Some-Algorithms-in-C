#include<stdio.h>
main()
{
int n,k,i=0,max=0,flag=0,p,start,middle,end,flag1=0;
	scanf("%d",&n);
	int j=0;
	int a[n];
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}i=1;
	while(i<n)
	{  
	if(a[i]==a[i+1])
	{
		i++;
	}
		
	j=i;
		while(a[i]<=a[i+1])
		{
			i++;
			
			
		}p=i;
		while((a[i]>=a[i+1]) && flag==0)
		{
			i++;
			if(i==n)
			{
				flag=1;
			}
		}
		k=i;
		if(k-j+1>=max)
		{
			max=k-j+1;
			middle=p;
			start=j;
			end=k;
		}
		
	}
	 printf("Hill is =%d start=%d middle=%d end=%d\n",max,start,middle,end);
}
