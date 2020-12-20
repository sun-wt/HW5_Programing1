#include"hw0504.h"

double *Linear(int32_t nums,double *x,double *y,double *m,double *constant)
{
	double sumX=0,sumY=0;
	double averX,averY;
	double *newX=malloc(nums*sizeof(double));
	double *newY=malloc(nums*sizeof(double));
	double r=0;
	double sumofsquarX,sumofsquarY;
	double sdX,sdY;
	for(int i=0;i<nums;i++)
	{
		sumX+=x[i];
		sumY+=y[i];
	}
	averX=sumX/nums;
	averY=sumY/nums;
	for(int j=0;j<nums;j++)
	{
		newX[j]=x[j]-averX;
		newY[j]=y[j]-averY;
		sumofsquarX+=pow(newX[j],2);
		sumofsquarY+=pow(newY[j],2);
	}
	sdX=sqrt(sumofsquarX/nums);
	sdY=sqrt(sumofsquarY/nums);
	for(int k=0;k<nums;k++)
	{
		r+=(newX[k]*newY[k])/(sqrt(sumofsquarX)*sqrt(sumofsquarY));
	}
	*m=r*(sdY/sdX);
	*constant=(-1)*r*sdY*averX/sdX+averY;
	return 0;
}
