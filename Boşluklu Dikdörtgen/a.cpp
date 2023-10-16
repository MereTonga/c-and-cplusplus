#include <stdio.h>

int main()
{
	int x,y,i,j;
	
	scanf("%d %d",&x,&y);
	
	for(i = 1;i <= x;i++)
	{
		for(j = 1;j <= y;j++)
		{
			if(!(i > 1 && j > 1))
				printf("*");
			else if(j == y)
				printf("*");
			else if(i == x)
				printf("*");
			else
				printf(" ");
			
		}
		printf("\n");
	}
}
