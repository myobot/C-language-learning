#include <stdio.h>

int main()

{
	int ix;
	
	scanf("%d",&ix);

	if(ix>99999)

		printf("你输入的数太大，请重新输入！\n");
	
	else if(ix<10)

		printf("这是一个一位数\n");

	else if(ix>=10&&ix<=99)

		printf("这是一个俩位数\n");

	else if(ix>=100&&ix<=999)

		printf("这是一个三位数\n");

	else if(ix>=1000&&ix<=9999)
		
		printf("这是一个四位数\n");

	else 

		printf("这是一个五位数\n");

	return 0;

}
