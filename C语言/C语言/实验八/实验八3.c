#include<stdio.h>
#include<stdlib.h>
int jian(int n);
int he(int n);
int main()
{
	int x;
	char ch,c1,*c[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	while(1)
	{
		printf("������һ������λ��\n");
		while(1)
		{
			scanf("%d",&x);
			while((c1=getchar())!='\n')
				continue;
			if(jian(x)==0)
			{
				printf("�����������������һ����λ��\n");
			}
			if(jian(x)==1)
			{
				break;
			}
		}
		printf("%s\n",*(c+he(x)-1));
		system("pause");
		system("cls");
		printf("�Ƿ���������� y ���������� �����ַ� �˳�\n");
		scanf("%c",&ch);
		if(ch!='y')
			break;
		while((c1=getchar())!='\n')
			continue;
	}
	printf("�ݰ�\n");
	return 0;
}
int jian(int n)
{
	if(n>=100&&n<=999)
		return 1;
	else
		return 0;
}
int he(int n)
{
	int i,p,j,k;
	i=n%10;
	j=(n/10)%10;
	k=n/100;
	p=i+j+k;
	return p;
}

	




