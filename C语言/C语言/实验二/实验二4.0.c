#include <stdio.h>

int main()

{
	char c1 = 'D';

	int x=6, z=45678;

	float y=2.5123;

	printf("c1=%c,x=%d,y=%f,z=%d\n",c1,x,y,z);

	printf("c1=%4d,x= %-3d, y=%7.2f, z=%-7d\n",c1,x,y,z-65536);

	printf("%#-5o, %#5x\n",x,x);

	printf("%c  %c  %d\n",c1,c1+32,c1+32);

	return 0;

}