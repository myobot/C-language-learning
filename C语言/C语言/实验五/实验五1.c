#include<stdio.h>
int main()
{
	int x [11],ii,isum=0;
	double dfaverage;
	for(ii=1;ii<=10;ii++)
	{
		printf("请输入数数据%d\n",ii);
		scanf("%d",&x [ii]);
		isum=isum+x [ii];
	}
	dfaverage=isum/10.0;
	printf("和为%d 平均值为%.2lf \n",isum,dfaverage);
	return 0;
}