#include<stdio.h>

int main()

{
	char ca=0,cb=0,cc,cd=0;int ix=0,iy=0,iz=0,ia=0,ib=0;

	printf("请输入若干字符\n");

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

	printf("共有%d个空格\n",ix);

	printf("共有%d个大写字母，分别为%s\n",iy,ca);

	printf("共有%d个小写字母，分别为%s\n",iz,cb);

	printf("共有%d个数字，分别为%s\n",ia,cd);

	printf("共有%d个其他字符\n");

	return 0;
}