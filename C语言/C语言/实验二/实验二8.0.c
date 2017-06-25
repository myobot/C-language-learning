#include <stdio.h>

#include <math.h>

int main()

{
	float fx,fy1,fy2,fy3;

	scanf("%f",&fx);

	fy1 = 2*sqrt(fabs(fx*fx-2))-5;

	fy2 = sin(fx);

	fy3 = fx>10||fx<5;

	printf(" fy1=%f\n fy2=%f\n fy3=%f\n",fy1,fy2,fy3);

	return 0;

}