#include"hw0503.h"
void Plus(int32_t degree1,int32_t degree2,int32_t *coefficients1,int32_t *coefficients2,int32_t *plus)
{
	int32_t times;
	if(degree1>degree2)
	{
		times=degree1;
		for(int i=times;i>=0;i--)
		{
			if(degree2>=0)
			{
				plus[i]=coefficients1[i]+coefficients2[degree2];
				degree2--;
			}
			else plus[i]=coefficients1[i];
		}
	}
	else 
	{
		times=degree2;
		for(int i=times;i>=0;i--)
		{
			if(degree1>=0)
			{
				plus[i]=coefficients1[degree1]+coefficients2[i];
				degree1--;
			}
			else plus[i]=coefficients2[i];
		}
	}
	
	for(int j=0;j<=times;j++)
	{
		if(j!=times)
		{
			if(j==0) printf("%dx^%d ",plus[j],times-j);
			else printf("%+dx^%d ",plus[j],times-j);
		}
		else printf("%+d\n",plus[j]);
	}
	
}

void Minus(int32_t degree1,int32_t degree2,int32_t *coefficients1,int32_t *coefficients2,int32_t *minus)
{
	int32_t times;
	if(degree1>degree2)
	{
		times=degree1;
		for(int i=times;i>=0;i--)
		{
			if(degree2>=0)
			{
				minus[i]=coefficients1[i]-coefficients2[degree2];
				degree2--;
			}
			else minus[i]=-coefficients1[i];
		}
	}
	else 
	{
		times=degree2;
		for(int i=times;i>=0;i--)
		{
			if(degree1>=0)
			{
				minus[i]=coefficients1[degree1]-coefficients2[i];
				degree1--;
			}
			else minus[i]=-coefficients2[i];
		}
	}
	
	for(int j=0;j<=times;j++)
	{
		if(j!=times)
		{
			if(j==0) printf("%dx^%d ",minus[j],times-j);
			else printf("%+dx^%d ",minus[j],times-j);
		}
		else printf("%+d\n",minus[j]);
	}
	
}

void Mul(int32_t degree1,int32_t degree2,int32_t *coefficients1,int32_t *coefficients2)
{
	int32_t times=degree1+degree2+1;
	int32_t mul[times];
	int32_t sum=0;
	memset(mul,0,times);
	int32_t arraymul[degree2+1][times];
	for(int f=0;f<degree2+1;f++)
	{
		for(int g=0;g<times;g++)
		{
			arraymul[f][g]=0;
		}
	}
	for(int h=0;h<degree2+1;h++)
	{
		for(int i=0;i<degree2+1;i++)
		{
			if(i>=h && i<degree1+1)
			{
       				for(int j=0;j<degree1+1;j++)
				{
					arraymul[h][j+i]=coefficients1[j]*coefficients2[h];
				}
				i=degree2+1;
   			}
		}
	}
	for(int k=0;k<times;k++)
	{
		sum=0;
		for(int l=0;l<degree2+1;l++)
		{
			sum=sum+arraymul[l][k];
		}
		mul[k]=sum;
	}
	for(int m=0;m<times;m++)
	{
		if(m!=times-1)
		{
			if(m==0) printf("%dx^%d ",mul[m],times-m-1);
			else printf("%+dx^%d ",mul[m],times-m-1);
		}
		else printf("%+d\n",mul[m]);
	}	
}

char device(int32_t degree,int32_t *coefficients)
{
	for(int i=0;i<=degree;i++)
	{
		if(i!=degree)
		{
			if(i==0) printf("%dx^%d ",coefficients[i],degree-i);
			else printf("%+dx^%d ",coefficients[i],degree-i);
		}
		else printf("%+d\n",coefficients[i]);
	}
	return 0;
}
		
	
