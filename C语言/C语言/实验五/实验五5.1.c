#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char c[N],c1;
	int i,j,k,da=0,xiao=0,shu=0,qi=0;
	printf("�������ַ�\n");
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
	printf("����%d���ַ�\n%d����д��ĸ\n%d��Сд��ĸ\n%d������\n%d�������ַ�\n",j,da,xiao,shu,qi);
	return 0;
}


