#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"hw0504.h"
int main()
{
	int32_t nums;
	double m,constant;
	printf("Please enter the point number:");
	scanf("%d",&nums);
	double *x=malloc(nums*sizeof(double));
	double *y=malloc(nums*sizeof(double));
	for(int i=0;i<nums;i++)
	{
		printf("Please enter Point %d:",i+1);
		scanf("%lf %lf",&x[i],&y[i]);
	}
	double *ans;
	ans=Linear(nums,x,y,&m,&constant);
	printf("Regression Equation: y = %g x  %+g\n",m,constant);
	free(x);
	free(y);
	return 0;
}
