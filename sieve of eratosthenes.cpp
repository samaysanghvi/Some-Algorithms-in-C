#include<stdio.h>
#include<math.h>
 int main()
 {
 	int a[20]={0};int i=0;
 	
 	int j=0;
 	i=2;
 	while(i<sqrt(20))
 	{
	 j=2;
 		while((i*j)<20)
 		{
 			if(a[i*j]==0)
 			{
 				a[i*j]=1;
			 }
			 j++;
		 }i++;
	 }
	 for(i=2;i<=19;i++)
	 {
	 	if(a[i]!=1)
	 	{
	 		printf("%d\n",i);
		 }
	 }
	 return 0;
 }
