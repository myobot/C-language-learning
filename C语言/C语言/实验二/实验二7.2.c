#include <stdio.h>

int main()

{

	int ix,iy;

	float iz;

	scanf("%d %d",&ix,&iy);

	iz = (float)ix;

	printf("%d+%d=%d\n%d-%d=%d\n%d*%d=%d\n%.1f/%d=%.2f\nำเสýฮช%d\n",ix,iy,ix+iy,ix,iy,ix-iy,ix,iy,ix*iy,iz,iy,iz/iy,ix%iy);

	return 0;

}