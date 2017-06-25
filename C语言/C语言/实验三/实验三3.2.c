#include <stdio.h>

int main()

{
	int ix,iy,ic,iz,ip;

	scanf("%d",&ix);

	iy = (ix%100)%10;

	ic = (ix%100)/10;

	iz = ix - iy -ic;

	ip = iy*100+ic*10+iz/100;

	printf("%d\n",ip);

}

