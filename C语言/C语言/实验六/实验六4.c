#include<stdio.h>
int isprime(int n);
int main()
{
	int m,n,i=0,j;
	printf("ÇëÊäÈë·¶Î§ m n\n");
	scanf("%d %d",&m,&n);
	if(m>n)
	{
		j=m;
		m=n;
		n=j;
	}
	printf("ËØÊıÎª:\n");
	for(;m<=n;m++)
	{
		if(isprime(m)==1)
		{
			printf("%4d",m);
			i++;
			if(i%5==0)
				printf("\n");
		}
	}
	return 0;
}
int isprime(int n)
{
	int i,j;
	for(i=2,j=0;i<n;i++)      // for(i=2;i<n;i++)
	{						  //{	
		if(n%i==0)			  //	if(n%i==0)	
		{					  //	{
			j++;			  //		return 0;
			return 0;		  //	}	
		}					  //}
	}						  //return 1;	
	if(j==0)
		return 1;
}