#include<stdio.h>
#include<stdint.h>
#include"hw0502.h"
#include"test2.h"
int main()
{
	int32_t matrix[4][4];
	printf("The Matrix is\n");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	int32_t ans=Matrix(matrix);
	return 0;
}
			

