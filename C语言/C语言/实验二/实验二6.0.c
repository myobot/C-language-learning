#include <stdio.h>

#define PI 3.14159

int main()

{
	int ix;

	double ic, is;

	scanf("%d",&ix);

	ic = ix * 2 * PI;

	is = 4.0 / 3 * ix * ix * ix * PI ;

	printf("�ܳ�Ϊ%.2f ���Ϊ%.2f\n", ic, is);

	return 0;

}

