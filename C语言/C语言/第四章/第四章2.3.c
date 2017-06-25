#include<stdio.h>
int get_int();
int main()
{
	int x[100]={1,10,100,1000,0,0},i,i1,j,k,p,y[96],n,k0,k1,k2,k3,k4;
	char ch;
	for(i=0;i<4;i++)
		printf("%8d",x[i]);
	printf("\n请输入数据\n输入 0 结束输入\n");
	for(i=0;i<96;i++)
	{
		while(scanf("%d",&y[i])!=1)
		{
			while((ch=getchar())!='\n')
				putchar(ch);
			printf("  不合法,请重新输入\n");
		}
		if(y[i]==0)
		{
			n=i;
			break;
		}
	}
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(y[k]>y[j])
				k=j;
		}
		if(k!=i)
		{
			p=y[i];
			y[i]=y[k];
			y[k]=p;
		}
	}
	printf("输入数据排序后为:\n");
	for(i=0;i<n;i++)
		printf("%8d",y[i]);
	printf("\n");
	for(i=1,k0=0,k1=0,k2=0,k3=0,k4=0;i<=n;i++)
	{
		if(y[i-1]<1)
			k0++;
		if(y[i-1]>=1&&y[i-1]<10)
			k1++;
		if(y[i-1]>=10&&y[i-1]<100)
			k2++;
		if(y[i-1]>=100&&y[i-1]<1000)
			k3++;
		if(y[i-1]>=1000)
			k4++;
	}
	for(i=3;i>=0;i--)
	{
		x[i+k0]=x[i];
	}
	for(i=0;i<k0;i++)
	{
		x[i]=y[i];
	}
	for(i=3+k0;i>=1+k0;i--)
	{
		x[i+k1]=x[i];
	}
	for(i=0;i<k1;i++)
	{
		x[i+k0+1]=y[i+k0];
	}
	for(i=3+k0+k1;i>=2+k0+k1;i--)
	{
		x[i+k2]=x[i];
	}
	for(i=0;i<k2;i++)
	{
		x[i+k0+k1+2]=y[i+k0+k1];
	}
	for(i=3+k0+k1+k2;i>=3+k0+k1+k2;i--)
	{
		x[i+k3]=x[i];
	}
	for(i=0;i<k3;i++)
	{
		x[i+k0+k1+k2+3]=y[i+k0+k1+k2];
	}
	for(i=0;i<k4;i++)
	{
		x[i+k0+k1+k2+k3+4]=y[i+k0+k1+k2+k3];
	}
/*	for(i=4;i>=1;i--)
	{
		x[i+k0]=x[i];
	}
	for(i=0;i<k0;i++)
	{
		x[i]=y[i];
	}
	for(i=3+k0;i>=1+k0;i--)//将10 100 1000 向后移动k1+k0 位。
	{
		x[i+k1+k0]=x[i];
	}
	for(i=1;i<=k1;i++)//将数插入。
	{
		x[i+k0]=y[i+k0-1];
	}
	for(i=3+k1+k0;i>=2+k1+k0;i--)// 100 1000 向后移动k1+k2+k0位
	{
		x[i+k2+k0]=x[i];
	}
	for(i1=1,i=2+k1+k0;i1<=k2;i1++,i++)
	{
		x[i]=y[i1+k0+k1-1];
	}
	for(i=3+k1+k2+k0;i>=3+k1+k2+k0;i--)//1000 向后移动k1+k2+k3+k0位
	{
		x[i+k3]=x[i];
	}
	for(i=3+k1+k2+k0,i1=1;i1<=k3;i1++,i++)
	{
		x[i]=y[i1+k0+k1+k2-1];
	}
	for(i=4+k1+k2+k3+k0,i1=1;i1<=k4;i1++,i++)//插入大于1000的数
	{
		x[i]=y[i1+k0+k1+k2+k3-1];
	}*/
	printf("将数插入后的数组为\n");
	for(i=0;i<n+4;i++)
		printf("%8d",x[i]);
	printf("\n");
	return 0;
}
/*int get_int()
{
	int input;
	char ch;
	while(scanf("%d",&input)!=1)
	{
		while((ch=getchar())!='\n')
		{
			putchar(ch);
		}
		printf("  不合法，请重新输入\n");
	}
	return input;
}*/
		






			
			
