#include <stdio.h>

#define IR 3.14

void main()

{	
	float ix, iy;

	printf("please input a number\n");

	scanf ("%f", &ix);

	iy = IR * ix * ix * ix * 4.0 / 3 ;
	
	printf("iR = %f\n",iy);

}
