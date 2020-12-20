#include"hw0502.h"
int32_t Matrix(int32_t matrix[4][4])
{
	int32_t ans1=0,ans2=0,ans3=0,ans4=0,ans=0;
	int32_t j,k;
	for(int i=1;i<4;i++)
	{
		if(i==1) j=2,k=3;
		else if(i==2) j=1,k=3;
		else j=1,k=2;
		ans1+=matrix[1][i]*(matrix[2][j]*matrix[3][k]-matrix[2][k]*matrix[3][j]);
	}
	ans1*=matrix[0][0];
	for(int i=0;i<4;i++)
	{
		if(i!=1)
		{
			if(i==0) j=2,k=3;
			else if(i==2) j=0,k=3;
			else j=0,k=2;
			ans2+=matrix[1][i]*(matrix[2][j]*matrix[3][k]-matrix[2][k]*matrix[3][j]);
		}
	}
	ans2*=matrix[0][1];
	for(int i=0;i<4;i++)
	{
		if(i!=2)
		{
			if(i==0) j=1,k=3;
			else if(i==1) j=0,k=3;
			else j=0,k=1;
			ans3+=matrix[1][i]*(matrix[2][j]*matrix[3][k]-matrix[2][k]*matrix[3][j]);
		}
	}
	ans3*=matrix[0][2];
	for(int i=0;i<3;i++)
	{
		if(i==0) j=1,k=2;
		else if(i==1) j=0,k=2;
		else j=0,k=1;
		ans4+=matrix[1][i]*(matrix[2][j]*matrix[3][k]-matrix[2][k]*matrix[3][j]);
	}
	ans4*=matrix[0][3];
	ans=ans1+ans2+ans3+ans4;
	printf("The determinant is %d.\n",ans);
	return 0;
}

