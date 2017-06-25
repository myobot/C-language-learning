#include<stdio.h>
#define N 20;
void zhuan(int x,int n);
int main()
{
	int x,i,j,k,p=1;
	printf("ÇëÊäÈëÊı×Ö\n");
	scanf("%d",&x);
	k=x;
	for(i=1;i<20;i++)
	{
		p=p*10;
		if(k==x%p)
		{
			j=i;
			break;
		}	
	}
	zhuan(k,j);
	printf("\n");
	return 0;
}
void zhuan(int x,int j)
{
	int i,k,p;
	i=x%10;
	j--;
	if(j>0)//x>9
		zhuan(x/10,j);
	printf("%c",i+48);
}
