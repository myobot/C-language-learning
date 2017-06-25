#include<stdio.h>
int main()
{
	int i,j,k=0,a[13];
	for(i=0;i<13;i++)
		a[i]=0;
	for(i=0;i<13;i++)
	{
		for(j=0;j<i+1;k++)
		{
			if(a[k]==0)
			{
				j++;
				if(j==i+1)
				{
					a[k]=i+1;
					k++;
					break;
				}
			}
			if(k>=13)
				k=k%13;
		}
	}
	for(i=0;i<13;i++)
		printf("%3d",a[i]);
	printf("\n");
	return 0;
}
