#include<stdio.h>
int main()
{
	int x [11],ii,isum=0;
	double dfaverage;
	for(ii=1;ii<=10;ii++)
	{
		printf("������������%d\n",ii);
		scanf("%d",&x [ii]);
		isum=isum+x [ii];
	}
	dfaverage=isum/10.0;
	printf("��Ϊ%d ƽ��ֵΪ%.2lf \n",isum,dfaverage);
	return 0;
}