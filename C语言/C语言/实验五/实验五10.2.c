#include<stdio.h>
int main()
{
	int x[10]={1,2,3,4,5,6,7,8,9,10},i,j,k,m;
	for(i=0;i<10;i++)
		printf("%3d",x[i]);
	printf("\n������Ҫ�ƶ���λ��\n");
	scanf("%d",&m);
	if(m>10)
	{
		m=m%10;
	}
	for(i=0;i<m;i++)
	{
		k=x[9];
		for(j=9;j>=0;j--)
		{
			x[j]=x[j-1];
		}
		x[0]=k;
	}
	printf("�ƶ��������Ϊ\n");
	for(i=0;i<10;i++)
		printf("%3d",x[i]);
	printf("\n");
	return 0;
}



