#include<stdio.h>
int 
main()
{
	int ix[5][3],isum[5]={0},ii,ij,isum2[3]={0};
	double daverage[5],daverage2[3];
	for(ii=0;ii<5;ii++)
	{	
		printf("清输入第%d个同学的三科成绩\n",ii+1);
		for(ij=0;ij<3;ij++)
		{
			scanf("%d",&ix[ii][ij]);
			isum[ii]=isum[ii]+ix[ii][ij];
		}
		daverage[ii]=isum[ii]/3.0;
	}
	for(ii=0;ii<3;ii++)
	{
		for(ij=0;ij<5;ij++)
		{
			isum2[ii]=isum2[ii]+ix[ij][ii];
		}
		daverage2[ii]=isum2[ii]/5.0;
	}
	printf("              语文     数学   外语   总成绩   平均成绩 \n");
	for(ii=0;ii<5;ii++)
	{
		printf("第%d个同学",ii+1);
		for(ij=0;ij<3;ij++)
		{
			printf("%8d",ix[ii][ij]);
		}
		printf("%8d  %8.1lf\n",isum[ii],daverage[ii]);
	}
	printf("各科总成绩");
	for(ii=0;ii<3;ii++)
	{
		printf("%8d",isum2[ii]);
	}
	printf("\n各科平均分");
	for(ii=0;ii<3;ii++)
	{
		printf("%8.1lf",daverage2[ii]);
	}
	printf("\n");
	return 0;
}

		
			
