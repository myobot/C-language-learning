#include<stdio.h>

int main()

{
	int ix,ia,ib,ic,id,ie,ij,ih,ii,io,ip,ik,il,iu,is,iz,i2,i3,i4,i5;

	printf("������һ��һ����λ��\n");

	scanf("%d",&ix);

	if(ix<0||ix>99999)

		printf("��������ݲ��Ϸ�\n");

	else if(ix>=0&&ix<=9)

	{	
		iu = ix;

		printf("�����������Ϊ%d\n",iu);

	}

	else if(ix>=10&&ix<=99)

	{	
		is = ix%10;

		iz = (ix-is)/10;

		i2 = is*10+iz;

		printf("�����������Ϊ%d\n",i2);

	}

	else if(ix>=100&&ix<=999)

	{	
		ia = ix%10;

		ib = (ix%100-ia)/10;

		ic = (ix-ia-ib*10)/100;

		i3 = ia*100+ib*10+ic;

		printf("�����������Ϊ%d\n",i3);

	}

	else if(ix>=1000&&ix<=9999)

	{
		id = ix%10;

		ie = (ix%100-id)/10;

		ij = (ix%1000-ie*10-id)/100;

		ih = (ix-100*ij-10*ie-id)/1000;

		i4 = id*1000+ie*100+ij*10+ih;

		printf("�����������Ϊ%d\n",i4);

	}

	else

	{
		ii = ix%10;

		io = (ix%100-ii)/10;

		ip = (ix%1000-io*10-ii)/100;

		ik = (ix%10000-ip*100-io*10-ii)/1000;

		il = (ix-1000*ik-100*ip-10*io-ii)/10000;

		i5 = ii*10000+io*1000+ip*100+ik*10+il;

		printf("�����������Ϊ%d\n",i5);

	}

	return 0;
}


	


