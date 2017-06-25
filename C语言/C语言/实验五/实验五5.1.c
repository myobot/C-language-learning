#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char c[N],c1;
	int i,j,k,da=0,xiao=0,shu=0,qi=0;
	printf("请输入字符\n");
	gets(c);
	for(i=0;i<N;i++)
	{
		if(c[i]=='\0')
			break;
	}
	j=i;
	for(i=0;i<j;i++)
	{
		if(c[i]>='A'&&c[i]<='Z')
			da++;
		else if(c[i]>='a'&&c[i]<='z')
			xiao++;
		else if(c[i]>='0'&&c[i]<='9')
			shu++;
		else
			qi++;
		if(c[i]=='\0')
			break;
	}
	printf("共有%d个字符\n%d个大写字母\n%d个小写字母\n%d个数字\n%d个其他字符\n",j,da,xiao,shu,qi);
	return 0;
}


