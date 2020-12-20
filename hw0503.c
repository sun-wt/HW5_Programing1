#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include"hw0503.h"
int main()
{
	int32_t degree1,degree2;
	int32_t plus,minus;
	int32_t times;
	printf("Please enter p1 degree:");
	scanf("%d",&degree1);
	if(degree1<0)
	{
		printf("invaild input\n");
		return 0;
	}
	printf("Please enter p1 coefficients:");
	int32_t coefficients1[degree1+1];
	for(int i=0;i<degree1+1;i++)
	{
		scanf("%d",&coefficients1[i]);
	}
	printf("Please enter p2 degree:");
	scanf("%d",&degree2);
	if(degree2<0)
	{
		printf("invaild input\n");
		return 0;
	}
	printf("Please enter p2 coefficients:");
	int32_t coefficients2[degree2+1];
	for(int i=0;i<degree2+1;i++)
	{
		scanf("%d",&coefficients2[i]);
	}
	printf("p1: ");
	device(degree1,coefficients1);
	printf("p2: ");
	device(degree2,coefficients2);
	printf("p1 + p2: ");
	Plus(degree1,degree2,coefficients1,coefficients2,&plus);
	printf("p1 - p2: ");
	Minus(degree1,degree2,coefficients1,coefficients2,&minus);
	printf("p1 * p2: ");
	Mul(degree1,degree2,coefficients1,coefficients2);
	return 0;
}














