#include <stdio.h>

int main()

{
	int ix;
	
	scanf("%d",&ix);

	if(ix>99999)

		printf("���������̫�����������룡\n");
	
	else if(ix<10)

		printf("����һ��һλ��\n");

	else if(ix>=10&&ix<=99)

		printf("����һ����λ��\n");

	else if(ix>=100&&ix<=999)

		printf("����һ����λ��\n");

	else if(ix>=1000&&ix<=9999)
		
		printf("����һ����λ��\n");

	else 

		printf("����һ����λ��\n");

	return 0;

}
