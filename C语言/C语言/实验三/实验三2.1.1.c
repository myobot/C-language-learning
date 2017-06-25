#include<stdio.h>

int main()

{
	int ix,ia,ib;

	printf("请输入成绩\n");

	scanf("%d",&ix);

	if(ix<0||ix>100)
	
		printf("输入不合法\n");

	else 
	{
	 	ia = ix%10;

		ib = (ix-ia)/10;

		switch(ib)

		{	
			case 10 :printf("A\n");break;

			case 9 :printf("A\n");break;

			case 8 :printf("B\n");break;

			case 7 :printf("C\n");break;

			case 6 :printf("D\n");break;
			
			default :printf("E\n");

		}
	}

	return 0;

}