#include<stdio.h>

int main()

{
	char ca=0,cb=0,cc,cd=0;int ix=0,iy=0,iz=0,ia=0,ib=0;

	printf("�����������ַ�\n");

	getchar();

	while((cc=getchar())!='\n')

		{	
			if(cc==' ')

			{
				ix++;

			}

			else if(cc>='A'&&cc<='Z')

			{
				iy++;

				ca=cc;
			}

			else if(cc>='a'&&cc<='z')

			{
				iz++;

				cb=cc;
		
			}
	
			else if(cc>='0'&&cc<='9')

			{
				ia++;

				cd=cc;
	
			}

			else 
			
				ib++;

	}

	printf("����%d���ո�\n",ix);

	printf("����%d����д��ĸ���ֱ�Ϊ%s\n",iy,ca);

	printf("����%d��Сд��ĸ���ֱ�Ϊ%s\n",iz,cb);

	printf("����%d�����֣��ֱ�Ϊ%s\n",ia,cd);

	printf("����%d�������ַ�\n");

	return 0;
}