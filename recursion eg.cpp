#include<stdio.h>
int func(int x);
main()
{int i;
	i=func(78);
	printf("%d",i);
}

int func(int x)
{
	int retval;
	if(x>101)
	{
		retval=x-11;
	}
	else
	{
		retval=func(func(x+12));
	}
	return retval;
}
