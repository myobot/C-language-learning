#include<stdio.h>
#include<stdlib.h>
#define MAX 40
int main()
{
	int x;
	char c[MAX],ch;
	FILE *fp;
	if((fp=fopen("mydata.txt","a+"))==NULL)
	{
		fprintf(stdout,"���ܴ� mydata.txt �ļ�!\n");
		exit(1);
	}
	puts("�������ַ�,������н���");
	while(gets(c)!=NULL&&c[0]!='\0')
		fprintf(fp,"%s",c);
	puts("�ļ����������ַ�");
	rewind(fp);
	while(fgets(c,MAX,fp))
		puts(c);
	printf("\n");
	if(fclose(fp))
		puts("�ļ��ر�ʧ��");
	return 0;
}
