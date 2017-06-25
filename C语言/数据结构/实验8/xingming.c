#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void charu(char data[][20],int n);
void swap1(char data[][20],char swap[][20],int n);
void xier(char data[][20],int n);
void print(char data[][20],int n);
void quick(char data[][20],int i,int j);
void dui(char data[][20],int n);
char zqsr(char *c)
{
	char xz;
	xz=getchar();
	fflush(stdin);
	while(strchr(c,xz)==NULL)
	{
		puts("请重新输入正确选项:");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}
int main()
{
	char xingming[200][20],xz,swap[200][20];
	int i,mark;
	printf("请输入姓名每行一个(输入0,结束输入)\n");
	for(i=0;i<200;i++)
	{
		gets(xingming[i]);
		fflush(stdin);
		if(xingming[i][0]=='0'&&xingming[i][1]=='\0')
		{
			break;
		}
	}
	system("cls");
	for(;;)
	{
		mark=0;
		printf("1)插入排序\n\n2)希尔排序\n\n3)快速排序\n\n4)堆排序\n\n");
		xz=zqsr("1234");
		swap1(xingming,swap,i);
		switch (xz)
		{
			case '1':charu(swap,i);break;
			case '2':xier(swap,i);break;
			case '3':printf("排序前\n");print(swap,i);
					quick(swap,0,i-1);
					printf("排序后\n");print(swap,i);break;
			case '4':dui(swap,i);break;
			case '0':mark=1;break;
		}
		if(mark==1)
			break;
		system("pause");
		system("cls");
	}
	return 0;
}
void swap1(char data[][20],char swap[][20],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		strcpy(swap[i],data[i]);
	}
}

void print(char data[][20],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		puts(data[i]);
	}
}
	
void charu(char data[][20],int n)
{
	int i,j;
	char temp[20];
	printf("排序前:\n");
	print(data,n);
	for(i=0;i<n;i++)
	{
		strcpy(temp,data[i]);
		for(j=i-1;j>=0&&strcmp(temp,data[j])<0;j--)
		{
			
			strcpy(data[j+1],data[j]);
		
		}
		strcpy(data[j+1],temp);
	}
	printf("\n排序后:\n");
	print(data,n);
}
void shellsort(char data[][20],int n,int delta)
{
	char temp[20],swap[20];
	int i,j;
	for(i=delta;i<n;i++)
	{
		strcpy(temp,data[i]);
		for(j=i-delta;j>=0&&strcmp(temp,data[j])<0;j=j-delta)
		{
			strcpy(swap,data[j]);
			strcpy(data[j],data[j+delta]);
			strcpy(data[j+delta],swap);
		}
		strcpy(data[j+delta],temp);
	}
}
void xier(char data[][20],int n)
{
	int j;
	printf("排序前:\n");
	print(data,n);
	j=(int)(log(n+1)/log(2));
	for(;j>0;j--)
		shellsort(data,n,j);
	printf("\n排序后:\n");
	print(data,n);
}

int part(char data[][20],int i,int j)
{
	char temp[20];
	strcpy(temp,data[i]);
	while(i<j)
	{
		while(strcmp(data[j],temp)>0&&i<j)
			j--;
		if(i<j)
		{
			
			strcpy(data[i++],data[j]);
			
		}
		while(strcmp(data[i],temp)<0&&i<j)
			i++;
		if(i<j)
		{
		
			strcpy(data[j--],data[i]);
	
		}	
	}
	strcpy(data[i],temp);
	return i;
}

void quick(char data[][20],int i,int j)
{
	int k;
	if(i<j)
	{
		k=part(data,i,j);
		quick(data,i,k-1);
		quick(data,k+1,j);
	}
}

void builddown(char data[][20],int n,int rootindex)
{
	char root[20];
	int childindex=rootindex*2;
	strcpy(root,data[rootindex]);
	while(childindex<n)
	{
		if(childindex!=n-1&&strcmp(data[childindex+1],data[childindex])>0)
			childindex++;
		if(strcmp(root,data[childindex])<0)
		{
			
			strcpy(data[rootindex],data[childindex]);
		
			rootindex=childindex;
			childindex=rootindex*2;
		}
		else
			break;
	}
	strcpy(data[rootindex],root);
}
void dui(char data[][20],int n)
{
	int i;
	char swap[20];
	int rootindex=(n-2)/2;
	printf("排序前:\n");
	print(data,n);
	for(;rootindex>=0;rootindex--)
		builddown(data,n,rootindex);
	for(i=n-1;i>=0;i--)
	{
		strcpy(swap,data[0]);
		strcpy(data[0],data[i]);
		strcpy(data[i],swap);
		builddown(data,i,0);
	}
	printf("排序后\n");
	print(data,n);
}