#include<stdio.h>
int 
main()
{
	int ix,iy,ii;
	printf("请输入天数,输入0结束程序\n");
	while(1)
	{
		scanf("%d",&ix);
		if(ix==0)
			break;
		iy=ix%5;
		if(iy>=1&&iy<=3)
		{
			printf("打鱼\n");
		}
		if(iy>3||iy==0)
		{
			printf("筛网\n");
		}
	}
	return 0;
}


