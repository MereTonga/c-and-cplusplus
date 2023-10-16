#include <stdio.h>

int main()
{
	int x,i,j;
	scanf("%d",&x);
	int k = x-1;
	
	for(i = 1;i <= x;i++)
	{
		for(j = i; j < x;j++)
			printf(" ");
		
		for(j = 1;j <= (2*i)-1;j++)
			printf("*");
		
		printf("\n");
	}
	
	for(i = 1;i <= x-1;i++)
	{
		for(j = 1; j <= i;j++)
			printf(" ");
		
		for(j = 1;j <= (2*k)-1;j++)
			printf("*");
		
		k--;
		
		printf("\n");
	}
}
