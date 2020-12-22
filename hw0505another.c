#include"hw0505.h"
void Printer(char (*visual)[20],int32_t width,int32_t height)
{
	printf("    ");
	for(int i=0;i<width;i++)
	{
		printf("%02d ",i);
	}
	printf("\n");
	for(int j=0;j<width*3+3;j++)
	{
		printf("-");
	}
	printf("\n");
	for(int k=0;k<height;k++)
	{
		printf("%02d| ",k);
		for(int l=0;l<width;l++)
		{
			printf("%2c ",visual[k][l]);
		}
		printf("\n");
	}
	printf("\n");
}
void Flag(char (*visual)[20],int32_t width,int32_t height)
{
	int32_t row,column;
	bool times=0;
	do
	{
		do
		{
			printf("Position (row,column):");
			scanf("%d %d",&row,&column);
			if(row>height || column>width)
			printf("invaild input1!\n");
			else break;
		}while(row>height || column>width);
		if(visual[row][column]=='F')
		{
			visual[row][column]='*';
			times=1;
		}
		else if(visual[row][column]=='*')
		{
			visual[row][column]='F';
			times=1;
		}
		else times=0;
		if(times==0)
		{
			printf("invaild input!\n");
		}
		else break;
	}while(times==0);
}

void Open(char (*visual)[20],char (*ans)[20],char (*ans1)[20],int32_t width,int32_t height,int32_t mine,int32_t row,int32_t column)
{
	bool times=0;
	do
	{
		if(ans1[row][column]=='X')
		{
			printf("\033[31mBomb! You lose!\n\033[0m");
			printf("\033[31mThe answer is:\n\033[0m");
			printf("    ");
			for(int i=0;i<width;i++)
			{
				printf("%02d ",i);
			}
			printf("\n");
			for(int j=0;j<width*3+3;j++)
			{
				printf("-");
			}
			printf("\n");
			for(int k=0;k<height;k++)
			{
				printf("%02d| ",k);
				for(int l=0;l<width;l++)
				{
					printf("\033[31m%2c \033[0m",ans1[k][l]);
				}
				printf("\n");
			}
			printf("\n");
			exit(0);
		}
		else 
		{
			if(visual[row][column]=='*')
			{
				if(ans1[row][column]==' ')
				{
					Open_space(visual,ans,ans1,width,height,mine,row,column);
				}
				else
				visual[row][column]=ans1[row][column];
				times=1;
			}
			else
			times=0;
		}
	}while(times==0);
}

void Open_space(char (*visual)[20],char (*ans)[20],char (*ans1)[20],int32_t width,int32_t height,int32_t mine,int32_t row,int32_t column)
{
	for(int i=row-1;i<=row+1;i++)
	{
		for(int j=column-1;j<=column+1;j++)
		{
			if(ans1[i][j]==' ')
			{
				ans1[i][j]='0';
				Check(visual,ans,ans1,width,height,mine,i,j);
			}
		}
	}
}
void Check(char (*visual)[20],char (*ans)[20],char (*ans1)[20],int32_t width,int32_t height,int32_t mine,int32_t row,int32_t column)
{
	if(ans1[row][column]!=' ')
	Open(visual,ans,ans1,width,height,mine,row,column);
}

//輸贏
void win(char (*visual)[20],int32_t width,int32_t height,int32_t mine)
{
	int test=0;
	int flag=0;
	for(int testX=0;testX<height;testX++)
	{
		for(int testY=0;testY<width;testY++)
		{
			if(visual[testX][testY]=='*')
			test++;
		}
	}
	if(test==mine)
	{
		printf("\033[31mYou win!Congratulation!\n\033[0m");
		exit(0);
	}
}
//炸彈//
void RandomBomb(char (*ans)[20],char (*ans1)[20],int32_t width,int32_t height,int32_t mine)
{
	int i=0;
	int times;
	int sum=width*height;
	bool condition;
	srand(time(NULL));
	while(i<mine)
	{
		int a=(rand()%height)+0;
		int b=(rand()%width)+0;
		if(ans[a][b]==' ')
		{
			ans[a][b]='X';
			i=i+1;
		}
	}
	char temp[9]={' ','1','2','3','4','5','6','7','8'};
	for(int x=0;x<height;x++)
	{
		for(int y=0;y<width;y++)
		{
			if(ans[x][y]=='X')
			ans1[x][y]='0';
			else
			{ 
				condition=1;
				for(int a=-1;a<=1;a++)
				{
					for(int b=-1;b<=1;b++)
					{
						if(ans[x+a][y+b]=='X')
						times++;
					}
				}
			}
			if(condition==1)
			ans1[x][y]=temp[times];
			
			if(ans[x][y]=='X')
			ans1[x][y]='X';	
			times=0;
		}		
	}
}





