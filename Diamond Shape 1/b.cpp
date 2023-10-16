#include <stdio.h>

int main()
{
	
  int x;
  printf("Bir sayý giriniz : ");
  scanf("%d",&x);
  
  for(int i = 1;i <= x+x;i++)
  {
  	if(i <= x)
  	{
  		for(int j = x;j >= i;j--)
  			printf("*");
	
		for(int j = 2;i > 1 && j <= i;j++)
			printf("  ");
	
		for(int j = x;j >= i;j--)
  			printf("*");
	}
	else
	{
		for(int j = 1;j <= i-x;j++)
			printf("*");
		
		for(int j = ((i-x)*2)-2; j < (x*2)-2;j++)
			printf(" ");
		
		for(int j = 1;j <= i-x;j++)
			printf("*");
	}
	
  	printf("\n");
  }
  
}
