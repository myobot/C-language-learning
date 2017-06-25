#include<stdio.h>

int main()

{
	int ix,iy=1;
	float isum=0;

	scanf("%d",&ix);

	while(iy<=2*ix-1)
	{
		
		isum=isum+1.0/iy;

		iy=iy+2;
	}
	printf("%f\n",isum);

return 0;
}