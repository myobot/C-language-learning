#include<stdio.h>
int main()
{
	int x [101],ii,z [101]={0},f [101]={0},a=0,b=0;
	for(ii=1;ii<=100;ii++)
	{
		scanf("%d",&x [ii]);
		if(x[ii]==0)
			break;
		if(x[ii]>0)
		{
			z[ii]=x[ii];
			a++;
		}
		if(x[ii]<0)
		{
			f[ii]=x[ii];
			b++;
		}
	}
	printf("正数分别为:\n");
	for(ii=1;ii<=100;ii++)
	{
		if(z[ii]>0)
			printf("%4d",z[ii]);
	}
	printf("\n负数分别为:\n");
	for(ii=1;ii<=100;ii++)
	{
		if(f[ii]<0)
			printf("%4d",f[ii]);
	}
	printf("\n");
	printf("正数有%d个,负数有%d个\n",a,b);
	return 0;
}


	
	
	