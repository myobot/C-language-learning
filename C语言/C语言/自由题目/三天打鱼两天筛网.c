#include<stdio.h>
int 
main()
{
	int ix,iy,ii;
	printf("����������,����0��������\n");
	while(1)
	{
		scanf("%d",&ix);
		if(ix==0)
			break;
		iy=ix%5;
		if(iy>=1&&iy<=3)
		{
			printf("����\n");
		}
		if(iy>3||iy==0)
		{
			printf("ɸ��\n");
		}
	}
	return 0;
}


