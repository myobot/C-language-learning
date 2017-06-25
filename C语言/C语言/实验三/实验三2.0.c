#include <stdio.h>

int main()

{
	int ix;

	printf("Input you grade:\n");

	scanf("%d",&ix);

	if(ix>=90)

		printf("you got an A!\n");

	else if(ix>=80)

		printf("you got a B.\n");

	else if(ix>=70)

		printf("you got a C!!!\n");

	else 

		printf("you only got a D,you need work hard!!\n");

	return 0;

}

