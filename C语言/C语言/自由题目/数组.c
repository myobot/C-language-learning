#include<stdio.h>
int main()
{
	float f [10],fsum = 0;
	int ii,iy,p;
	printf("����������\n");
	for(ii=0;ii<10;ii++)
	{
		scanf("%f",&f [ii]);
		//p=scanf("%f",&f [ii]);
		if(f [ii]==0)
		{
			break;
		}
		fsum=fsum+f [ii];
	}
	printf("��Ϊ%.2f\n",fsum);
	return 0;
}
