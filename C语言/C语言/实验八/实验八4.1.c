#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char c[N],c1[N-10],*c2,cc;
	int i,j,m;
	c2=c;
	for(i=0;i<10;i++)
	{
		*c2++=i+48;
		printf("%c",c[i]);
	}
	for(i=10;i<N;i++)
		*c2++=' ';
	printf("\nÇëÊäÈëÄãÒªÌæ»»µÄÎ»ÖÃm\n");
	scanf("%d",&m);
	while((cc=getchar())!='\n')
		continue;
	printf("ÇëÊäÈëÄãÒªÌæ»»µÄ×Ö·û´®\n");
	gets(c1);
	j=strlen(c1);
	for(i=0;i<10-m;i++)
		c[m+i]=' ';
	c2=&c[m];
	for(i=0;i<j;i++)
	{
		*c2++=c1[i];
	}
	for(i=0;i<j+m;i++)
		printf("%c",c[i]);
	printf("\n");
	return 0;
}