#include<stdio.h>

int main()

{
	int ix,iy,iz,ic=0;
	
	printf("«Î ‰»Î∑∂Œß\n");

	scanf("%d %d",&ix,&iy);

	for(ix;ix<=iy;ix++)
	{
		for(iz=2;iz<=ix;iz++)

		{
			if(ix%iz==0)
				break;
		}
			if(iz==ix)
			{
				printf("%4d",ix);
				ic++;
			}
	}
	if (ic % 10 = 0)
		printf("\n");
	printf("\n");
	return 0;

}

