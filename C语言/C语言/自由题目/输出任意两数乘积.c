# include<stdio.h>
int add(int ia,int ib);
void main()
{
		int ix,iy,isum;

		printf("Please input two integers:\n 001");

		scanf_s("%d %d",&ix,&iy);

		isum=add(ix,iy);

		printf("sum=%d\n",isum);

}

int add(int ia,int ib)

{
		int ic;

		ic=ia*ib;

		return ic;
}
