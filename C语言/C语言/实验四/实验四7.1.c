#include<stdio.h>
int main()
{
	int a,i,m,c=0;
	printf("1000���ڵ�����Ϊ:\n");
	for(a=1;a<1000;a++)
	{
		for(m=0,i=1;i<=a/2;i++) 
			if(a%i==0)
				m+=i;
		if(m==a)
		{	
			printf("%4d ",a);
			c++;
			if(c%2==0)
				printf("\n");
		}
	}
}
