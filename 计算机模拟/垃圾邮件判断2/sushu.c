#include<stdio.h>
int main()
{
	int i,j,k=0,mark;
	for(i=1100;;i++)
	{
		mark=0;
		for(j=2;j<i/2;j++)
		{
			if(i%j==0)
			{
				mark=1;
				break;
			}
		}
		if(mark==0)
		{
			printf("%d\n",i);
			k++;
			if(k>10)
				break;
		}
	}
	return 0;
}