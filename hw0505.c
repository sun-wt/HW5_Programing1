#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include"hw0505.h"

char **visual;
char **ans;
char **ans1;

int main() 
{
	int32_t width,height,mine;
	int32_t option=0;
  do
	{
		printf("Please enter the width       (10-16):");
	  	scanf("%d",&width);
		if(width<10||width>16)
		{
			printf("invaid input for width\n");
		}
  	}while(width<10||width>16);
	do
	{
		printf("Please enter the height      (10-16):");
		scanf("%d",&height);
		if(height<10||height>16)
		{
			printf("invaid input for height\n");
		}
	}while(height<10||height>16);
	do
	{
		printf("Please enter the mine number (30-90):");
		scanf("%d",&mine);
		if(mine<30||mine>90)
		{
			printf("invaid input for mine\n");
		}
	}while(mine<30||mine>90);
	char visual[height][width];
	char ans[height][width];
	char ans1[height][width];
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			visual[i][j]='*';
			ans[i][j]=' ';
			ans1[i][j]=' ';
		}
	}
	bool winorlose=1;
	RandomBomb(*ans,*ans1,width,height,mine);
	Printer(&ans[0][0],width,height);
	Printer(&ans1[0][0],width,height);
	while(1)
	{
		do
		{
			Printer(&visual[0][0],width,height);
			printf("Your Option (1:Open , 2:Flag):");
			scanf("%d",&option);
			if(option==1)
			{
				Open(&visual[0][0],&ans[0][0],&ans1[0][0],width,height,mine);
				win(&visual[0][0],width,height,mine); 
			}
			else if(option==2)
			{
				Flag(&visual[0][0],width,height);
			}
			if(option==1||option==2)
			continue;
			else
			printf("invaild input!\n");
			printf("\n");
		}while(option!=1||option!=2); 
	}
	return 0;	
}



