#include<stdio.h>

int main()

{	
	char cc;int ix=0,iy=0,iz=0,ia=0,ib=1;
	
	printf("��������������ַ�\n");

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

	printf("������%d���ո�\n",ix);
	printf("������%d�������ַ�\n",iy);
	printf("������%d������\n",iz);
	printf("������%d����д��ĸ\n",ia);
	printf("������%d��Сд��ĸ\n",ib);

	return 0;

}




