#include<stdio.h>

int main()

{
	int x,m,y=1,ii=1;

	printf("��������������\n");

	scanf("%d %d",&x,&m);

	while(ii<=m)
	{
		y=y*x;
		ii++;
	}
	printf("%d\n",y);
	return 0;

}

