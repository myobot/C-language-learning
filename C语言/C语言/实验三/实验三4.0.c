#include<stdio.h>

int main()

{
	int ix,ia,ib,ic,id,ie;

	printf("������һ����λ��\n");

	scanf("%d",&ix);

	if(ix<10000||ix>99999)

		printf("��������ݴ���\n");

	else
	{
		ia = ix%10;

		ib = (ix%100-ia)/10;

		ic = (ix%1000-10*ib-ia)/100;

		id = (ix%10000-100*ic-10*ib-ia)/1000;

		ie = (ix-1000*id-100*ic-10*ib-ia)/10000;

		if(ia==ie&&ib==id)

			printf("����һ��������\n");

		else
			
			printf("�ⲻ��һ��������\n");
	}
	return 0;

}
