#include<stdio.h>
#include<string.h>
#define N 100
#define PASS "pass"
int main()
{
	char c[N]=PASS,c1[N];
	int i,j,k,p=0;
	printf("������ָ��:\n");
	for(i=0;i<N;i++)
	{
		if(c[i]=='\0')
			break;
	}
	j=i;
	gets(c1);
/*	i=0;
	while((c1[i]=getchar())!='\n')
		i++; 
*/
	k=strlen(c1);
	if(k==j)
	{
		for(i=0;i<j;i++)
		{
			if(c[i]!=c1[i])
			{
				p++;
				break;
			}
		}
		if(p==0)
			printf("ָ����ȷ\n");
		if(p!=0)
			printf("ָ�����\n");
	}
	else
		printf("ָ�����\n");
	printf("%d\n",j);
	return 0;
}

			

		
