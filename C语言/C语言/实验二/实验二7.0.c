#include <stdio.h>

int main()

{

	int ix, iy, isum, icha, iji;

	float ishang, ip;

	printf("please input two numbers:\n");
	
	scanf("%d %d", &ix, &iy);

	isum = ix + iy;

	icha = ix - iy;

	iji = ix * iy;

	ip = ix;

	ishang = ip / iy;

	printf("%d + %d = %d\n ",ix,iy,isum);
 
	printf("%d - %d = %d\n ",ix,iy,icha);

	printf("%d * %d = %d\n ",ix,iy,iji);

	printf("%d / %d = %f\n ",ix,iy,ishang);
	
	return 0;

}



	