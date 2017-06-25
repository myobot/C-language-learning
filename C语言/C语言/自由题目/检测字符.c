#include<stdio.h>

int main()

{	
	char cc;int ix=0,iy=0,iz=0,ia=0,ib=1;
	
	printf("请随便输入若干字符\n");

	getchar();

	while((cc=getchar())!='\n')
		{	

			if(cc==32)

				ix++;

			else if(cc>=48&&cc<=57)

				iz++;

			else if(cc>=65&&cc<=90)

				ia++;

			else if(cc>=97&&cc<=122)

				ib++;

			else

				iy++;
		}

	printf("输入了%d个空格\n",ix);
	printf("输入了%d个其他字符\n",iy);
	printf("输入了%d个数字\n",iz);
	printf("输入了%d个大写字母\n",ia);
	printf("输入了%d个小写字母\n",ib);

	return 0;

}




