#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000
int main()
{
	int i=0,j,k,p,i1;
	char x[N],c[20]={'\0'},c1[20],ch,n,ch1;
	FILE *fp;
	printf("���������\n");
	for(i=0;i<N;i++)
	{	
		x[i]=getchar();
		if(x[i]=='0')
		{
			k=i;
			break;
		}
	}
	while((ch=getchar())!='\n')
		continue;
	while(1)
	{
		printf("\n������Ҫ���ҵĵ���:\n");
		gets(c1);
		for(i=0,j=0,p=0;i<=k;i++,j++)
		{
			c[j]=x[i];
			if(x[i]>=32&&x[i]<=47||x[i]=='?'||x[i]=='0')
			{
				c[j]='\0';
				if(strcmp(c1,c)==0)
				{
					p++;
				}
				for(i1=0;i1<j;i1++)
				{
					c[i1]='\0';
				}
				j=-1;
			}
		}
		if(p==0)
			printf("û�д˵���\n");
		if(p>0)
			printf("�д˵��ʣ���%d��\n",p);
		printf("�Ƿ�������������ʣ����� y ����������� y �������ַ�(�����)����\n");
		scanf("%c",&n);
		while((ch=getchar())!='\n')
			continue;
		if(n!='y')
			break;
		system("pause");
		system("cls");
		for(i=0;i<k;i++)
			printf("%c",x[i]);
		printf("\n");
	}
	printf("�ݰ�\n");
	return 0;
}