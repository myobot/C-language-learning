# include <stdio.h>
int max(int ix,int iy,int iz);

int main()

{
	int ia,ib,ic,imax;

	printf("please input three numbers:\n");

	scanf("%d %d %d", &ia,&ib,&ic);

	imax = max(ia,ib,ic);
	
	printf("This is the answer.\n");

	printf("Max=%d\n",imax);

}

int max(int ix,int iy,int iz)

{
	int imax2;

	if(ix>iy&&ix>iz)

		imax2 = ix;

	if(iy>ix&&iy>iz)

		imax2 = iy;

	if(iz>ix&&iz>iy)

		imax2 = iz;
	
	return imax2;
}





