#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int suiji(int pai[52])
{
	int i,s,mark,number=0,pai1[52];
	for(i=0;i<52;i++)
	{	
		if(pai[i]!=0)
		{
			pai1[number]=i;
			number++;
		}
	}
	s=rand()%number;
	mark=pai[pai1[s]];
	pai[pai1[s]]=0;
	return mark;

}
int bijiao(int shu[4])
{
	int i,max=0,max1=shu[0];
	for(i=1;i<=3;i++)
	{
		if(max1<shu[i])
		{
			max=i;
			max1=shu[i];
		}
			
	}
	return max;
}
		
int main()
{
	int fen[4][13],i,j,pai[52];
	int a,b,ms[13][2],max,lun[4],sum[4];
	srand((unsigned int)time(0));
	for(i=0;i<52;i++)
		pai[i]=i+1;
	for(i=0;i<4;i++)
	{
		sum[i]=0;
		for(j=0;j<13;j++)
		{
			fen[i][j]=suiji(pai);
		}
		
	}
	
/*	for(i=0;i<4;i++)
	{
		printf("\n第%d人:\n",i+1);
		for(j=0;j<13;j++)
		{

			a=fen[i][j]%13;
			b=fen[i][j]/13;

			if(a==0)
				printf("大小：%-2d ",13);
			else
				printf("大小：%-2d ",a);
			printf("花色：");
			switch(b)
			{
				case 0:printf("黑桃\n");break;
				case 1:printf("红心\n");break;
				case 2:printf("方片\n");break;
				case 3:printf("梅花\n");break;
				case 4:printf("梅花\n");break;
			}
		}
	}*/
	for(j=0;j<13;j++)
	{
		ms[j][0]=0;
		ms[j][1]=0;
		printf("第%d轮：\n",j+1);
	
		for(i=0;i<4;i++)
		{
			
			printf("第%d人：",i+1);
			a=fen[i][j]%13;
			b=fen[i][j]/13;

			if(a==0)
			{
				printf("大小：%-2d ",13);
				lun[i]=13;
			}
			else
			{
				printf("大小：%-2d ",a);
				lun[i]=a;
			}
			printf("花色：");
			switch(b)
			{
				case 0:printf("黑桃\n");break;
				case 1:printf("红心\n");break;
				case 2:printf("方片\n");break;
				case 3:printf("梅花\n");break;
				case 4:printf("梅花\n");break;
			}
		}

		max=bijiao(lun);
		ms[j][0]=max;
		b=fen[max][j]/13;
		switch (b)
		{
			case 0:ms[j][1]=15;break;
			case 1:ms[j][1]=10;break;
			case 2:ms[j][1]=5;break;
			case 3:ms[j][1]=1;break;
			case 4:ms[j][1]=1;break;
		}

		printf("第 %d 轮 第 %d 人 获胜。得分：%d \n",j+1,max+1,ms[j][1]);
		system("pause");
	}
	for(i=0;i<13;i++)
	{
		switch (ms[i][0])
		{
			case 0:sum[0]+=ms[i][1];break;
			case 1:sum[1]+=ms[i][1];break;
			case 2:sum[2]+=ms[i][1];break;
			case 3:sum[3]+=ms[i][1];break;
		}
	}
	for(i=0;i<4;i++)
	{
		printf("第%d人总得分：%d\n",i+1,sum[i]);
	}
	max=bijiao(sum);
	printf("最终第%d人获胜，得分%d\n",max+1,sum[max]);


	return 0;
}
				
