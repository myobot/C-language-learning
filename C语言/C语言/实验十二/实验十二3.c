#include<stdio.h>
#include<stdlib.h>
#define N 100
int main()
{
	int i,k;
	char c[N],ch,file1[20],file2[20],x[N];
	FILE *fp1,*fp2;
	printf("������Դ�ļ�����\n");
	gets(file1);
	printf("������Ҫ���Ƶ����ļ���:\n");
	gets(file2);
	if((fp1=fopen(file1,"r"))==NULL||(fp2=fopen(file2,"a"))==NULL)
		printf("���ļ�ʧ��!\n");
	puts("Դ�ļ���������:");
	for(i=0;i<N;i++)
	{
		if((fscanf(fp1,"%c",&c[i]))==1)
		{
			printf("%c",c[i]);
			k=i;
		}
		else
			break;
	}
	for(i=0;i<=k;i++)
	{
		if((fprintf(fp2,"%c",c[i]))!=1)
			break;
	}
	printf("\n���Ƶ����ļ���������:\n");
/*	fseek(fp2,0L,SEEK_SET);
	while((fscanf(fp2,"%c",&x[i]))==1)
		printf("%c",x[i]);*/
	if(fclose(fp1)!=0||fclose(fp2)!=0)
		puts("�ر��ļ�ʧ��");
	if((fp2=fopen(file2,"a"))==NULL)
		printf("���ļ�ʧ��!\n");
	for(i=0;i<=k;i++)
	{
		if((fscanf(fp1,"%c",&c[i]))==1)
		{
			printf("%c",c[i]);
		}
		else
			break;
	}
	if(fclose(fp2)!=0)
		puts("�ر��ļ�ʧ��");
	return 0;
}
