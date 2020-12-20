#include"hw0501.h"
int32_t *Sort(int32_t *nums,int32_t numsSize)
{
	int32_t oddSize;
	int32_t evenSize;
	int32_t *odd =malloc(oddSize*sizeof(void));
	int32_t *even =malloc(evenSize*sizeof(void));
	int32_t temp;
	for(int i=0;i<numsSize;i++)
	{
		if(nums[i]%2==1)
		{
			odd[oddSize]=nums[i];
			oddSize++;
		}
		for(int j=0;j<oddSize;j++)
		{
			for(int k=0;k<j;k++)
			{
				if(odd[k]>odd[j])
				{
					temp=odd[k];
					odd[k]=odd[j];
					odd[j]=temp;
				}
			}
		}
		if(nums[i]%2==0)
		{
			even[evenSize]=nums[i];
			evenSize++;
		}
		for(int j=0;j<evenSize;j++)
		{
			for(int k=0;k<j;k++)
			{
				if(even[k]<even[j])
				{
					temp=even[k];
					even[k]=even[j];
					even[j]=temp;
				}
			}
		}
	}
	for(int m=0;m<oddSize;m++)
	{
		printf("%d ",odd[m]);
	}
	for(int n=0;n<oddSize;n++)
	{
		printf("%d ",even[n]);
	}
	free(odd);
	free(even);
	return 0;
}
