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
		fprintf(stdout,"不能打开 mydata.txt 文件!\n");
		exit(1);
	}
	puts("请输入字符,输入空行结束");
	while(gets(c)!=NULL&&c[0]!='\0')
		fprintf(fp,"%s",c);
	puts("文件里有如下字符");
	rewind(fp);
	while(fgets(c,MAX,fp))
		puts(c);
	printf("\n");
	if(fclose(fp))
		puts("文件关闭失败");
	return 0;
}
