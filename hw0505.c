#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include"hw0505.h"

char visual[20][20];
char ans[20][20];
char ans1[20][20];

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
	int32_t row,column;
	RandomBomb(ans,ans1,width,height,mine);
	Printer(ans,width,height);
	Printer(ans1,width,height);
	while(1)
	{
		do
		{
			Printer(visual,width,height);
			printf("Your Option (1:Open , 2:Flag):");
			scanf("%d",&option);
			if(option==1)
			{	
				do
				{
					printf("Position (row,column):");
					scanf("%d %d",&row,&column);
					if(row>height || column>width)
					{
						printf("%d>%d||%d>%d\n",row,height,column,width);
						printf("invaild input!\n");
					}
					else break;
				}while(row>height || column>width);
				Open(visual,ans,ans1,width,height,mine,row,column);
				//Check(visual,ans,ans1,width,height,mine,row,column);
				win(visual,width,height,mine); 
			}
			else if(option==2)
			{
				Flag(visual,width,height);
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



