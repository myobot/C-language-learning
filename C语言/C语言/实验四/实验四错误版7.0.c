#include<stdio.h>

int main()

{
	int ix,iy,iz=0;
	int isum1=0;

	for(ix=6;ix<=1000;ix++)
	{
		for(iy=1,isum1=0;iy<ix;iy++)
			if(ix%iy==0)isum1=isum1+iy;
			if(isum1=ix)
			{
				printf("%4d",ix);
				iz++;
			}
	}
	if(iz%2==0)
		printf("\n");
	
	return 0;
}


