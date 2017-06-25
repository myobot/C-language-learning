#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include <stddef.h>
char zqsr(char *c);
void cheliangjinru(struct qiche *qqiche,int e);
void chelianglikai(struct qiche *qqiche,int e);
void konglist(struct qiche *qqiche,int e);
void chazhao(struct qiche *qqiche,int e);
void xianshi(struct qiche *qqiche,int e);
void huizong(struct qiche *qqiche,int e,int sum);
void chushihua(struct qiche *qqiche,int e,int sum);
struct qichexinxi
{
	char chepaihao[16];
	time_t jinru;
	char jinrusj[40];
	time_t likai;
	char likaisj[40];
	int jifei;
};
struct qiche
{
	int mark;
	int chewei;
	struct qichexinxi xinxi;
};
int ruzhang=0;
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
int main()
{	
	FILE *fp;
	int flag,sum;
	char xz;
	struct qiche qqiche[20];
	if((fp=fopen("qiche.txt","r+"))==NULL)
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	fseek(fp,0L,0);
	fread(&sum,sizeof(int),1,fp);
	fseek(fp,sizeof(int),0);
	fread(&qqiche[0],sizeof(struct qiche),20,fp);
	while(1)
	{
		flag=0;
		printf("1)车辆进入\n\n2)车辆离开\n\n3)查找空车位并显示车位号\n\n4)查找车辆并显示车辆信息\n\n5)显示所有在位车辆信息\n\n6)显示缴费总金额\n\n7)初始化停车信息\n\n0)退出系统\n\n请选择:\n");
		xz=zqsr("12345670");
		switch(xz)
		{
			case '1':system("cls");
					cheliangjinru(qqiche,20);system("pause");system("cls");break;
			case '2':system("cls");
					chelianglikai(qqiche,20);system("pause");system("cls");break;
			case '3':system("cls");
					konglist(qqiche,20);system("pause");system("cls");break;
			case '4':system("cls");
					chazhao(qqiche,20);system("pause");system("cls");break;
			case '5':system("cls");
					xianshi(qqiche,20);system("pause");system("cls");break;
			case '6':system("cls");
					huizong(qqiche,20,sum);system("pause");system("cls");break;
			case '7':system("cls");
					chushihua(qqiche,20,sum);system("pause");system("cls");break;
			case '0':flag++;break;
		}
		fflush(stdin);
		if(flag>0)
			break;
	}
	sum+=ruzhang;
	fseek(fp,0L,0);
	fwrite(&sum,sizeof(int),1,fp);
	fseek(fp,sizeof(int),0);
	fwrite(&qqiche[0],sizeof(struct qiche),20,fp);
	if(fclose(fp)!=0)
		printf("关闭文件失败!\n");
	printf("拜拜");
	return 0;
}
void konglist(struct qiche *qqiche,int e)
{
	int i,p;
	printf("空位置有:\n");
	for(i=0,p=0;i<e;i++)
	{
		if(qqiche[i].mark==0)
		{
			printf("第%2d位    ",qqiche[i].chewei);
			p++;
			if((p)%5==0)
				printf("\n");
		}
	}
	printf("\n");
}
void cheliangjinru(struct qiche *qqiche,int e)
{	
	char xz,queren;
	int i,weizhi,flag,fkgeshu,fkong[20],j,p,flag1;
	struct tm *tblock;
	for(i=0,j=0;i<e;i++)
	{
		if(qqiche[i].mark==1)
		{
			fkong[j]=qqiche[i].chewei;
			j++;
		}
	}
	fkgeshu=j;
	while(1)
	{
		flag=0;flag1=0;
		printf("现在的空车位有:\n");
		for(i=0,p=0;i<e;i++)
		{
			if(qqiche[i].mark==0)
			{
				printf("第%2d位    ",qqiche[i].chewei);
				p++;
				if(p%5==0)
					printf("\n");
			}
		}
		flag=0;
		printf("\n请选择车位:\n");
		if(scanf("%d",&weizhi)!=1||(weizhi<=0||weizhi>20))
		{
			printf("请输入正确的座位号,请重新输入\n");
			system("pause");system("cls");
			fflush(stdin);
			continue;
		}
		for(i=0;i<fkgeshu;i++)
		{
			if(weizhi==fkong[i])
			{
				printf("该车为已经被占用，请选择上述空座位\n");
				system("pause");system("cls");
				fflush(stdin);
				flag1++;
				break;
			}
		}
		if(flag1>0)
			continue;
		system("cls");
		printf("您选择了第%d号车位，是否确认？\n\n1)确认\n\n2)重新选择\n\n0)取消停车\n\n请选择:\n",weizhi);
		xz=zqsr("120");
		if(xz=='0')
		{
			printf("已取消停车\n");
			break;
		}
		if(xz=='2')
		{
			system("cls");
			continue;
		}
		else
		{
			while(1)
			{
				weizhi=weizhi-1;
				system("cls");
				printf("请输入要停的车牌号:\n");
				gets(qqiche[weizhi].xinxi.chepaihao);
				system("cls");
				printf("输入的车牌号为:%s\n是否确认?\n\n1)确认\n\n0)重新输入\n\n请选择:\n",qqiche[weizhi].xinxi.chepaihao);
				queren=zqsr("10");
				if(queren=='1')
				{
					qqiche[weizhi].xinxi.jinru=time(NULL);
					tblock = localtime(&qqiche[weizhi].xinxi.jinru);
					strcpy(qqiche[weizhi].xinxi.jinrusj,asctime(tblock));
					qqiche[weizhi].xinxi.jifei=0;
					qqiche[weizhi].mark=1;
					printf("车辆成功进入停车场，计费开始\n");
					break;
				}

			}
		}
		break;
	}
}
//wzwzhizuo
void chelianglikai(struct qiche *qqiche,int e)
{
	int i,weizhi,flag=0,shicha,flag1=0,kgeshu,kong[20],j;
	char xz,xz1,chepaihao[16];
	struct tm *tblock;
	for(i=0,j=0;i<e;i++)
	{
		if(qqiche[i].mark==0)
		{
			kong[j]=qqiche[i].chewei;
			j++;
		}
	}
	kgeshu=j;
	printf("1)按车牌号\n\n2)按车位号\n\n0)退回到主菜单\n\n请选择:\n");
	xz=zqsr("120");
	if(xz=='0')
		printf("选择了退回到主菜单\n");
	if(xz=='1')
	{
		system("cls");
		printf("请输入您的车牌号:\n");
		gets(chepaihao);
		for(i=0;i<e;i++)
		{
			if(strcmp(chepaihao,qqiche[i].xinxi.chepaihao)==0)
			{
				weizhi=i;
				flag++;
				break;
			}
		}
		if(flag==0)
			printf("没有该车\n");
		else
		{
			system("cls");
			qqiche[weizhi].xinxi.likai=time(NULL);
			tblock=localtime(&qqiche[weizhi].xinxi.likai);
			strcpy(qqiche[weizhi].xinxi.likaisj,asctime(tblock));
			shicha=(int)difftime(qqiche[weizhi].xinxi.likai,qqiche[weizhi].xinxi.jinru);
			qqiche[weizhi].xinxi.jifei=(shicha/3600+1)*10;
			printf("您的停车信息为;\n");
			printf("%9s:%17s\n%9s:%17s\n%9s:%17s\n%9s:%d元\n","车牌号",qqiche[weizhi].xinxi.chepaihao,"进入时间",qqiche[weizhi].xinxi.jinrusj,"离开时间",qqiche[weizhi].xinxi.likaisj,"计费",qqiche[weizhi].xinxi.jifei);
			printf("是否选择离开?\n1)离开\n0)不离开，退回到主菜单\n");
			xz1=zqsr("10");
			if(xz1=='1')
			{
				ruzhang+=qqiche[weizhi].xinxi.jifei;
				qqiche[weizhi].mark=0;
				printf("您的车已经离开停车场\n");
			}
			if(xz1=='0')
				printf("选择了退出到主菜单\n");
		}
	}
	if(xz=='2')
	{
		system("cls");
		printf("请输入您的车位号:\n");
		while(scanf("%d",&weizhi)!=1||(weizhi<=0||weizhi>20))
		{
			fflush(stdin);
			printf("请输入正确的座位号,请重新输入\n");
//			scanf("%d",&weizhi);
			fflush(stdin);
			system("pause");system("cls");printf("请输入您的车位号:\n");
		}
		for(i=0;i<kgeshu;i++)
		{
			if(weizhi==kong[i])
			{
				flag1++;
				printf("该车为没有车,退回到主菜单\n");
				system("pause");system("cls");
			}
		}
		if(flag1==0)
		{
			system("cls");
			weizhi=weizhi-1;
			qqiche[weizhi].xinxi.likai=time(NULL);
			tblock = localtime(&qqiche[weizhi].xinxi.likai);
			strcpy(qqiche[weizhi].xinxi.likaisj,asctime(tblock));
			shicha=(int)difftime(qqiche[weizhi].xinxi.likai,qqiche[weizhi].xinxi.jinru);
			qqiche[weizhi].xinxi.jifei=(shicha/3600+1)*10;
			printf("您的停车信息为;\n");
			printf("%9s:%17s\n%9s:%17s\n%9s:%17s\n%9s:%d元\n","车牌号",qqiche[weizhi].xinxi.chepaihao,"进入时间",qqiche[weizhi].xinxi.jinrusj,"离开时间",qqiche[weizhi].xinxi.likaisj,"计费",qqiche[weizhi].xinxi.jifei);
			printf("是否选择离开?\n1)离开\n0)不离开，退回到主菜单\n");
			xz1=zqsr("10");
			if(xz1=='1')
			{
				ruzhang+=qqiche[weizhi].xinxi.jifei;
				qqiche[weizhi].mark=0;
			}
			if(xz1=='0')
				printf("选择了退出到主菜单\n");
		}
	}
}
void chazhao(struct qiche *qqiche,int e)
{
	int i,weizhi,flag=0,shicha,flag1=0,j,kong[20],kgeshu=0;
	char xz,chepaihao[16];
	struct tm *tblock;
	for(i=0,j=0;i<e;i++)
	{
		if(qqiche[i].mark==0)
		{
			kong[j]=qqiche[i].chewei;
			j++;
		}
	}
	kgeshu=j;
	while(1)
	{
		flag1=0;flag=0;
		printf("1)按车牌号\n\n2)按车位号\n\n0)退回到主菜单\n\n请选择:\n");
		xz=zqsr("120");
		system("cls");
		if(xz=='0')
		{
			printf("选择了退回到主菜单\n");
			break;
		}
		if(xz=='1')
		{
			printf("请输入您的车牌号:\n");
			gets(chepaihao);
			for(i=0;i<e;i++)
			{
				if(strcmp(chepaihao,qqiche[i].xinxi.chepaihao)==0)
				{
					weizhi=i;
					flag++;
					break;
				}
			}
			if(flag==0)
			{
				printf("没有该车\n");
				system("pause");system("cls");
			}
			else
			{
				system("cls");
				qqiche[weizhi].xinxi.likai=time(NULL);
				tblock = localtime(&qqiche[weizhi].xinxi.likai);
				strcpy(qqiche[weizhi].xinxi.likaisj,asctime(tblock));
				shicha=(int)difftime(qqiche[weizhi].xinxi.likai,qqiche[weizhi].xinxi.jinru);
				qqiche[weizhi].xinxi.jifei=(shicha/3600+1)*10;
				printf("您的停车信息为;\n");
				printf("%9s:%17s\n%9s:%17s\n%9s:%17s\n%9s:%d元\n","车牌号",qqiche[weizhi].xinxi.chepaihao,"进入时间",qqiche[weizhi].xinxi.jinrusj,"当前时间",qqiche[weizhi].xinxi.likaisj,"计费",qqiche[weizhi].xinxi.jifei);
				system("pause");system("cls");
			}
		}
		if(xz=='2')
		{
			printf("请输入您的车位号:\n");
			while(scanf("%d",&weizhi)!=1||(weizhi<=0||weizhi>20))
			{
				fflush(stdin);
				printf("请输入正确的座位号,请重新输入\n");
//				scanf("%d",&weizhi);
				fflush(stdin);
				system("pause");system("cls");
			}
			if(qqiche[weizhi-1].mark==0)
			{
				flag1++;
				printf("该车位没有车\n");
				system("pause");system("cls");
			}
			if(flag1==0)
			{
				weizhi=weizhi-1;
				system("cls");
				qqiche[weizhi].xinxi.likai=time(NULL);
				tblock=localtime(&qqiche[weizhi].xinxi.likai);
				strcpy(qqiche[weizhi].xinxi.likaisj,asctime(tblock));
				shicha=(int)difftime(qqiche[weizhi].xinxi.likai,qqiche[weizhi].xinxi.jinru);
				qqiche[weizhi].xinxi.jifei=(shicha/3600+1)*10;
				printf("您的停车信息为;\n");
				printf("%9s:%17s\n%9s:%17s\n%9s:%17s\n%9s:%d元\n","车牌号",qqiche[weizhi].xinxi.chepaihao,"进入时间",qqiche[weizhi].xinxi.jinrusj,"当前时间",qqiche[weizhi].xinxi.likaisj,"计费",qqiche[weizhi].xinxi.jifei);
				system("pause");system("cls");
			}
		}
		fflush(stdin);
	}
}
void xianshi(struct qiche *qqiche,int e)
{
	int i,j,feikong[20],shicha;
	struct tm *tblock;
	for(i=0,j=0;i<e;i++)
	{
		if(qqiche[i].mark==1)
		{
			feikong[j]=i;
			j++;
		}
	}
	if(j==0)
		printf("所有的车位都没有被占\n");
	else
	{
		printf("共有%d个车位被占\n其停车信息分别为:\n",j);
		for(i=0;i<j;i++)
		{
			printf("第%d位:\n",feikong[i]+1);
			qqiche[feikong[i]].xinxi.likai=time(NULL);
			tblock=localtime(&qqiche[feikong[i]].xinxi.likai);
			strcpy(qqiche[feikong[i]].xinxi.likaisj,asctime(tblock));
			shicha=(int)difftime(qqiche[feikong[i]].xinxi.likai,qqiche[feikong[i]].xinxi.jinru);
			qqiche[feikong[i]].xinxi.jifei=(shicha/3600+1)*10;
			printf("您的停车信息为;\n");
			printf("%9s:%17s\n%9s:%17s\n%9s:%17s\n%9s:%d元\n\n","车牌号",qqiche[feikong[i]].xinxi.chepaihao,"进入时间",qqiche[feikong[i]].xinxi.jinrusj,"当前时间",qqiche[feikong[i]].xinxi.likaisj,"计费",qqiche[feikong[i]].xinxi.jifei);
		}
	}
}
void huizong(struct qiche *qqiche,int e,int sum)
{
	int i,j,feikong[20],shicha,zaiweisum=0;
	for(i=0,j=0;i<e;i++)
	{
		if(qqiche[i].mark==1)
		{
			feikong[j]=i;
			j++;
		}
	}
	for(i=0;i<j;i++)
	{
		qqiche[feikong[i]].xinxi.likai=time(NULL);
		shicha=(int)difftime(qqiche[feikong[i]].xinxi.likai,qqiche[feikong[i]].xinxi.jinru);
		zaiweisum+=(shicha/3600+1)*10;
	}
	printf("不算未离开车辆，总入账金额为:%d\n\n算上未离开车辆，目前总金额为:%d\n",ruzhang+sum,ruzhang+sum+zaiweisum);
}
void chushihua(struct qiche *qqiche,int e,int sum)
{
	
	int i;
	char xz;
	printf("所有信息都将被初始化\n\n是否确认?\n\n1)确认\n\n0)返回主菜单\n\n请选择:\n");
	xz=zqsr("10");
	if(xz=='1')
	{
		for(i=0;i<e;i++)
		{
			qqiche[i].mark=0;
			qqiche[i].chewei=i+1;
			qqiche[i].xinxi.chepaihao[0]='\0';
			qqiche[i].xinxi.jifei=0;
		}
		sum=0;
		ruzhang=0;
		puts("停车信息已初始化!");
	}
	else
		puts("初始化已取消");
}
	




			






