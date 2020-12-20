#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<memory.h>
#include"hw0501.h"
#include"test.h"
int main()
{
	int32_t array_size=100;
	int32_t *array =malloc(array_size*sizeof(int));
	array_size=0;
	memset(array, 0, array_size);
	printf("Before:");
	while(1){
		scanf("%d",&array[array_size]);
		array_size++;
		if(array[array_size]<0)
		{
			printf("invaild input\n");
			break;
		}
		if(getchar()=='\n')
		{
			break;
		}
	}
	printf("After:");
	int32_t *ans;
	ans=Sort(array,array_size);
	free(array);
	printf("\n");	
	return 0;
}
