#include<stdio.h>
#include<string.h>
#define	N 100
int main()
{
	int i,j,k,p,n=0,t=0;
	char c[N][20],ch[20],c1,c2;
	for(i=0;i<N;i++)
	{
		for(j=0,k=0,p=0;j<20;j++)
		{
			c[i][j]=getchar();
			if(c[i][j]>=32&&c[i][j]<=47)
			{
				c[i][j]='\0';
				k++;
				break;
			}
			if(c[i][j]=='0')
			{
				p++;
				break;
			}
		}
		if(k>0&&p==0)
			continue;
		if(p>0)
		{
			n=i;
			break;
		}
	}
	while((c1=getchar())!='\n')
		continue;
	while(1)
	{
		printf("������Ҫ���ҵĵ���\n");
		gets(ch);
		for(i=0,t=0;i<n;i++)
		{
			if(strcmp(ch,c[i])==0)
			{
				t++;
			}
		}
		if(t==0)
			printf("û�иõ���\n");
		if(t>0)
			printf("�иõ��ʣ���%d��\n",t);
		printf("�Ƿ���������������ʣ�\n���� y ���������� n �˳�\n");
		scanf("%c",&c2);
		if(c2!='y')
			break;
		while((c1=getchar())!='\n')
			continue;
	}
	printf("�ݰ�\n");
	return 0;
}

