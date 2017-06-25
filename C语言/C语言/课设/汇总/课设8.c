#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char zqsr(char *c);
void diancai8(char *diancai,int *geshu);
void chakan8(char *diancai,int *geshu);
void tiancai8(char *diancai,int *geshu);
void jiancai8(char *diancai,int *geshu);
void jiesuan8(char *diancai,int *geshu);
void keshediba(void);
char zqsr(char *c)
{
	char xz;
	xz=getchar();
	fflush(stdin);
	while(strchr(c,xz)==NULL)
	{
		puts("请重新输入正确选项:");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}
const int caijia[10]={3,10,18,15,88,12,8,48,58,25};
void keshediba()
{
	int geshu_[10];
	char diancai_[10],xz;
	int i,flag;
	for(i=0;i<10;i++)
	{
		diancai_[i]='0';
		geshu_[i]=0;
	}
	while(1)
	{
		flag=0;
		printf("1)点菜\n\n2)查看已点菜品\n\n3)添菜\n\n4)减菜\n\n5)结算\n\n0)退出\n\n请选择:\n");
		xz=zqsr("123450");
		switch (xz)
		{
		case '1':system("cls");
				diancai8(diancai_,geshu_);system("pause");system("cls");break;
		case '2':system("cls");
				chakan8(diancai_,geshu_);system("pause");system("cls");break;
		case '3':system("cls");
				tiancai8(diancai_,geshu_);system("pause");system("cls");break;
		case '4':system("cls");
				jiancai8(diancai_,geshu_);system("pause");system("cls");break;
		case '5':system("cls");
				jiesuan8(diancai_,geshu_);system("pause");system("cls");break;
		case '0':flag++;break;
		}
		fflush(stdin);
		if(flag>0)
			break;
	}
	printf("拜拜\n");
}
void diancai8(char *diancai,int *geshu)
{
	int i,flag,dianshu;
	char xz,queren;
	char *cai[10]={"米饭","宫保鸡丁","酱爆鸭片","木须肉","沸腾鱼","手撕圆白菜","麻婆豆腐","小鸡炖蘑菇","水晶肘子","元香酥带鱼"};
	while(1)
	{
		flag=0;
		printf("以下是全部菜品:\n");
		for(i=0;i<10;i++)
		{
			printf("%d.%-16s%6d\n",i,cai[i],caijia[i]);
		}
		printf("%s\n\n请选择:\n","a.返回");
		xz=zqsr("1234567890a");
		if(xz=='a')
		{
			printf("选择了退出\n");
			break;
		}
		else
		{	
			system("cls");
			printf("选择了:%s\n是否确认？\n\n1)确认\n\n0)重新选择\n\n请选择\n",cai[(int)xz-48]);
			queren=zqsr("10");
			if(queren=='0')
				continue;
			else
			{
				system("cls");
				printf("请输入要点几个:\n");
				while(scanf("%d",&dianshu)!=1)
				{
					printf("请输入正确的数字,请重新输入\n");
					fflush(stdin);
				}
				diancai[(int)xz-48]='1';
				geshu[(int)xz-48]+=dianshu;
				printf("\n\n成功点了%2d个%-10s\n",dianshu,cai[(int)xz-48]);
			}
		}
		system("pause");system("cls");
		fflush(stdin);
	}
}
void chakan8(char *diancai,int *geshu)
{
	int i,sum=0,j=0;
	char *cai[10]={"米饭","宫保鸡丁","酱爆鸭片","木须肉","沸腾鱼","手撕圆白菜","麻婆豆腐","小鸡炖蘑菇","水晶肘子","元香酥带鱼"};
	printf("以下是已经点的菜品:\n");
	for(i=0;i<10;i++)
	{
		if(diancai[i]=='1')
		{
			printf("第%d道菜:%-12s:%6d个\n\n",j+1,cai[i],geshu[i]);
			j++;
			sum+=geshu[i]*caijia[i];
		}
	}
	printf("共计%3d元\n",sum);
}
void tiancai8(char *diancai,int *geshu)
{
	int i,flag,dianshu;
	char xz,queren;
	char *cai[10]={"米饭","宫保鸡丁","酱爆鸭片","木须肉","沸腾鱼","手撕圆白菜","麻婆豆腐","小鸡炖蘑菇","水晶肘子","元香酥带鱼"};
	chakan8(diancai,geshu);
	while(1)
	{
		flag=0;
		printf("以下是全部菜品:\n");
		for(i=0;i<10;i++)
		{
			printf("%d.%-16s%6d\n",i,cai[i],caijia[i]);
		}
		printf("%s\n\n请选择要添加的菜品:\n","a.返回");
		xz=zqsr("1234567890a");
		if(xz=='a')
		{
			printf("选择了退出\n");
			break;
		}
		else
		{	
			system("cls");
			printf("选择了:%s\n是否确认？\n\n1)确认\n\n0)重新选择\n\n请选择\n",cai[(int)xz-48]);
			queren=zqsr("10");
			if(queren=='0')
				continue;
			else
			{
				system("cls");
				printf("请输入要点几个:\n");
				while(scanf("%d",&dianshu)!=1)
				{
					printf("请输入正确的数字,请重新输入\n");
					fflush(stdin);
				}
				if(diancai[(int)xz-48]=='0')
					diancai[(int)xz-48]='1';
				geshu[(int)xz-48]+=dianshu;
				printf("\n\n成功点了%2d个%-10s\n",dianshu,cai[(int)xz-48]);
			}
		}
		system("pause");system("cls");
		fflush(stdin);
	}
}
void jiancai8(char *diancai,int *geshu)
{
	int i,j,flag,jiangeshu,xuhao1[10];
	char xz,queren,xz1,*xuhao;
	char *cai[10]={"米饭","宫保鸡丁","酱爆鸭片","木须肉","沸腾鱼","手撕圆白菜","麻婆豆腐","小鸡炖蘑菇","水晶肘子","元香酥带鱼"};
	for(i=0,j=0;i<10;i++)
	{
		if(diancai[i]=='1')
		{
			xuhao1[j]=i;
			j++;
		}
	}
	if(j==0)
		printf("您还没有点任何菜，请先去点菜!\n");
	else
	{
		while(1)
		{
			flag=0;
			for(i=0,j=0;i<10;i++)
			{
				if(diancai[i]=='1')
				{
					xuhao1[j]=i;
					j++;
				}
			}
			if(j==0)
			{
				puts("您应经把所有的菜都减完了，无法继续减菜!");
				break;
			}
			else
			{
				xuhao=(char *)malloc(sizeof(char)*j);
				for(i=0;i<j;i++)
				{
					xuhao[i]=i+49;
				}
				chakan8(diancai,geshu);
				printf("请选择要减的菜的序号:\n");
				xz=zqsr(xuhao);
				system("cls");
				printf("您要减的菜为第%2d道:%-12s\n\n是否确认?\n\n1)确认\n\n2)重新选择要减的菜\n\n0)退出到主菜单\n\n请选择:\n",(int)xz-48,cai[xuhao1[(int)xz-49]]);
				xz1=zqsr("120");
				if(xz1=='2')
				{
					system("cls");
					continue;
				}
				if(xz1=='0')
					break;
				if(xz1=='1')
				{
					system("cls");
					printf("该道菜:%8s 您一共点了%d个\n\n请输入要减的个数:\n",cai[xuhao1[(int)xz-49]],geshu[xuhao1[(int)xz-49]]);
					while(scanf("%d",&jiangeshu)!=1||jiangeshu>geshu[xuhao1[(int)xz-49]])
					{
						fflush(stdin);
						printf("输入有误，请输入正确数字，并确保减才个数小于等于已有个数\n\n请重新输入:\n");
//						scanf("%d",&jiangeshu);
						fflush(stdin);
					}
					fflush(stdin);
					geshu[xuhao1[(int)xz-49]]-=jiangeshu;
					if(geshu[xuhao1[(int)xz-49]]==0)
						diancai[xuhao1[(int)xz-49]]='0';
					system("cls");
					printf("您已成功减了%d个该菜\n\n是否还要减其他菜品?\n\n1)继续减菜\n\n0)退出\n\n请选择:\n",jiangeshu);
					queren=zqsr("10");
					if(queren=='0')
						break;
					else
						system("cls");
				}
				fflush(stdin);
			}
		}
	}
}
void jiesuan8(char *diancai,int *geshu)
{
	int i;
	char xz;
	chakan8(diancai,geshu);
	printf("是否选择结算?\n\n1)结算\n\n0)不结算，返回主菜单\n\n请选择:\n");
	xz=zqsr("10");
	if(xz=='1')
	{	
		for(i=0;i<10;i++)
		{
			diancai[i]='0';
			geshu[i]=0;
		}
		printf("结算成功\n");
	}
}


				






