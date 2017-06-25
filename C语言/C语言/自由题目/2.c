#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	for(a=1;a<=5;a++)
	{
		for(b=1;b<=5;b++)
		{
			for(c=1;c<=5;c++)
			{
				for(d=1;d<=5;d++)
				{
					for(e=1;e<=5;e++)
					{
						if(c!=1&&e-d==2&&e!=2&&a!=1&&a!=5&&b-c==1)
							printf("A %d  B %d  C %d  D %d  E %d\n",a,b,c,d,e);
					}
				}
			}
		}
	}
	return 0;
}