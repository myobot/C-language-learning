#include<stdio.h>
#include<stdlib.h>
int he(int *i,int n);
void huan(int *i,int n);
int main()
{
	int *i,j;
	char c,cc;
	i=(int *)malloc(2*sizeof(int));
	while(1)
	{
		printf("������������\n");
		for(j=0;j<2;j++)
		{
			while(scanf("%d",&i[j])!=1)
			{
				while((c=getchar())!='\n')
					continue;
				printf("�����������������\n");
			}
		}
		huan(i,2);
		printf("��Ϊ:%d\n������Ϊ:%d %d\n",he(i,2),i[0],i[1]);
		printf("�Ƿ������\n����y ���� �����������ַ��˳����� n ��\n");
		while((c=getchar())!='\n')
			continue;
		cc=getchar();
		while((c=getchar())!='\n')
			continue;
		if(cc!='y')
			break;
	}
	pritnf("�ݰ�\n");
	free(i);
	return 0;
}
int he(int *i,int n)
{
	int j,sum=0;
	for(j=0;j<n;j++)
		sum+=i[j];
	return sum;
}
void huan(int *i,int n)
{
	int swap,j;
	for(j=0;j<n-1;j++)
	{
		swap=i[j];
		i[j]=i[j+1];
		i[j+1]=swap;
	}
}
		
	
		