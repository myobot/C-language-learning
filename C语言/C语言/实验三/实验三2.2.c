#include <stdio.h>

int main()

{
	int ix;

	printf("Input you grade:\n");

	scanf("%d",&ix);

	if(ix>100||ix<0)

		printf("you are input a wrong number!\n");

	else if(ix>=90)

		printf("you got an A!\n");

	else if(ix>=80)

		printf("you got a B.\n");

	else if(ix>=70)

		printf("you got a C!!\n");

	else if(ix>=60)

		printf("you got a D!!!\n");

	else

		printf("you only got a E!,you need work hard!!\n");

	return 0;

}