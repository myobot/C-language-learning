#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	int i,j,k=0;
	char c[N],c1,ch,cc;
	printf("������һ���ַ���\n");
	gets(c);
	for(i=0;i<N;i++)
	{
		if(c[i]=='\0')
			break;
	}
	j=i;printf("����%d���ַ�\n",j);
	printf("��������Ҫ���ҵ��ַ�\n");
	scanf("%c",&c1);
	while(1)
	{
		for(i=0;i<j;i++)
		{
			if(c1==c[i])
			{
				k++;
			}
		}
		if(k>0)
			printf("(YES!)�и��ַ�����%d��.\n",k);
		if(k==0)
			printf("(Not Found!)û�и��ַ�\n");
		printf("�Ƿ�Ҫ���ұ���ַ�������y����������n����\n");
		while((cc=getchar())!='\n')
			continue;
		scanf("%c",&ch);
		while((cc=getchar())!='\n')
			continue;
		if(ch!='y')
			break;
		printf("������Ҫ���ҵ��ַ�\n");
		scanf("%c",&c1);
	}
	printf("�ݰ�\n");
	return 0;
}



