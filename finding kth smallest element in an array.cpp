#include<stdio.h>
main()
{
	
	int flag=0,i=0,k,n;
	scanf("%d",&n);int a[n],j=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		
	} printf("Enter kth smallest value finder\n");
	scanf("%d",&k);i=2,j=1;
	while(i<=n && flag==0)
	{
		
		
			if(a[i]==a[i-1])
			{
				a[j]=a[i];
			}
			else 
			{j++;
				a[j]=a[i];
			}
			
			if(k==j)
		{flag=1;
			printf("%d",a[j]);
		}
			
		i++;
	}
	
return(0);
}
