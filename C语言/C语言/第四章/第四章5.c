#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char c[N];
	int i,j;
	printf("�������ַ���\n");
	gets(c);
/*	for(i=0;i<N;i++)
	{
		if(c[i]=='\0')
			break;
	} */
	
	i=0;
	while(c[i]!='\0')
	{
		i++;
	}
	
	j=i;
	printf("һ����%d���ַ�\n",j);
	return 0;
}