#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i1[4],i2[4],i3[4],i4[4],i5[4],ii,isum[6]={0};
	double daverage[6];
	printf("请输入第一个同学的各科成绩\n");
	for(ii=1;ii<=3;ii++)
	{
		scanf_s("%d",&i1[ii]);
		isum[1]=isum[1]+i1[ii];
	}
	printf("请输入第二个同学的各科成绩\n");
	for(ii=1;ii<=3;ii++)
	{
		scanf_s("%d",&i2[ii]);
		isum[2]=isum[2]+i2[ii];
	}
	printf("请输入第三个同学的各科成绩\n");
	for(ii=1;ii<=3;ii++)
	{
		scanf_s("%d",&i3[ii]);
		isum[3]=isum[3]+i3[ii];
	}
	printf("请输入第四个同学的各科成绩\n");
	for(ii=1;ii<=3;ii++)
	{
		scanf_s("%d",&i4[ii]);
		isum[4]=isum[4]+i4[ii];
	}
	printf("请输入第五个同学的各科成绩\n");
	for(ii=1;ii<=3;ii++)
	{
		scanf_s("%d",&i5[ii]);
		isum[5]=isum[5]+i5[ii];
	}
	for(ii=1;ii<=5;ii++)
	{
		daverage[ii]=isum[ii]/3.0;
	} 
	printf("      同学一   同学二   同学三   同学四   同学五\n");
	printf("语文   %-9d%-9d%-9d%-9d%-9d\n",i1[1],i2[1],i3[1],i4[1],i5[1]);
	printf("数学   %-9d%-9d%-9d%-9d%-9d\n",i1[2],i2[2],i3[2],i4[2],i5[2]);
	printf("英语   %-9d%-9d%-9d%-9d%-9d\n",i1[3],i2[3],i3[3],i4[3],i5[3]);
	printf("总成绩 %-9d%-9d%-9d%-9d%-9d\n",isum[1],isum[2],isum[3],isum[4],isum[5]);
	printf("平均分 %-9.1lf%-9.1lf%-9.1lf%-9.1lf%-9.1lf\n",daverage[1],daverage[2],daverage[3],daverage[4],daverage[5]);
	system("pause");
	return 0;
}

