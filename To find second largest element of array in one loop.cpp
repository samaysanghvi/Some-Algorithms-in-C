#include<stdio.h>
main()
{
	int n,i=0;
	scanf("%d",&n);
	int a[n],m1,m2;
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i==1)
		{
			m1=m2=a[i];
		}
		if(a[i]>m1)
		{
			m2=m1;
			m1=a[i];
		}
		else if(a[i]>m2 && a[i]!=m1)
		{
			m2=a[i];
		}
	}
	printf("%d\n%d",m1,m2);
	return(0);
}
