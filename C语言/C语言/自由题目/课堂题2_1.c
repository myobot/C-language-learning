#include<stdio.h>
int isprime(int i);
int main()
{
	int i,j,m,k,a[100];
	printf("������m��ֵ\n");
	while(scanf("%d",&m)!=1||m<0)
	{
		printf("������������������\n");
		fflush(stdin);
	}
	fflush(stdin);
	k=m+1;
	j=0;
	while(1)
	{
		if(isprime(k)==1)
		{
			a[j]=k;
			j++;
			
		}
		k++;
		if(j>=100)
			break;
	}
	for (i=0;i<100;i++)
	{
		printf("%5d",a[i]);
		if((1+i)%10==0)printf("\n");
	}
	return 0;
}
int isprime(int i)
{
	int j;
	for(j=2;j<i;j++)
	{
		if(i%j==0)
		{
			return 0;
		}
	}
	return 1;
}


