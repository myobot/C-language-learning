#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
# define PRT printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","工人姓名",xgong.xingming,"工人工号",xgong.gongh,"岗位工资",xgong.yfa[0],"薪级工资",xgong.yfa[1],"职务津贴",xgong.yfa[2],"工会费",xgong.yko[0],"保险费",xgong.yko[1],"水电费",xgong.yko[2],"实发工资",xgong.shifa);
void menu1(void);
void eatline1(void);
struct gongren chuangjian1(struct gongren gong[],int e);
void chaxun1(struct gongren gong[],int e);
void ghchaxun1(struct gongren gong[],int e);
void xmchaxun1(struct gongren gong[],int e);
int shanchu1(struct gongren gong[],int e);
void xiougai1(struct gongren gong[],int e);
void huizong1(struct gongren gong[],int e);
void xianshi1(struct gongren gong[],int e);
void keshediyi(void);
struct gongren
{
	char gongh[11];
	char xingming[10];
	int yfa[3];
	int yko[3];
	int shifa;
};
int keshediyi()
{
	int flag=0,flag1=0,x,q;
	char xz;
	FILE *fp;
	struct gongren gong;
	struct gongren *jianz;
	struct gongren xgong;
	while(1)
	{	
		x=0;
		if((fp=fopen("gongzi.txt","r+b"))==NULL)
		{
			puts("打开文件失败!");
			exit(1);
		}
		fseek(fp,0L,0);
		while(fread(&gong,sizeof(struct gongren),1,fp)==1)
		{
			x++;
		}
		jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
		fseek(fp,0L,0);
/*		for(i=0;i<x;i++)
		{
			fread(&jianz[i],sizeof(struct gongren),1,fp);
		}*/
		fread(&jianz[0],sizeof(struct gongren),x,fp);
		if(fclose(fp)!=0)
		{
			puts("第一次关闭文件失败！");
			exit(2);
		}
		xgong.shifa=-1;
		q=x+1;
		menu1();
		xz=getchar();
		eatline1();
		while(strchr("1234560",xz)==NULL)
		{
			puts("输入错误,请输入正确选项，例如 1、 2、 3");
			xz=getchar();
			eatline1();
		}
		switch(xz)
		{
			case'1':system("cls");
					xgong=chuangjian1(jianz,x);
					break;
			case'2':system("cls");
					chaxun1(jianz,x);
					break;
			case'3':system("cls");
					q=shanchu1(jianz,x);
					break;
			case'4':system("cls");
					xiougai1(jianz,x);
					break;
			case'5':system("cls");
					huizong1(jianz,x);
					break;
			case'6':system("cls");
					xianshi1(jianz,x);
					break;
			case'0':flag++;break;
		}
		fflush(stdin);
//		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","工人姓名",xgong.xingming,"工人工号",xgong.gongh,"岗位工资",xgong.yfa[0],"薪级工资",xgong.yfa[1],"职务津贴",xgong.yfa[2],"工会费",xgong.yko[0],"保险费",xgong.yko[1],"水电费",xgong.yko[2],"实发工资",xgong.shifa);
		if((fp=fopen("gongzi.txt","w+b"))==NULL)
		{
			puts("第二次打开文件失败!");
			exit(3);
		}
		if(xgong.shifa!=-1)
		{
			fseek(fp,0L,0);
			fwrite(&jianz[0],sizeof(struct gongren),x,fp);
			fseek(fp,0L,2);
			fwrite(&xgong,sizeof(struct gongren),1,fp);
		}
		if(q<x)
		{
			fseek(fp,0L,0);
			fwrite(&jianz[0],sizeof(struct gongren),q,fp);
		}
		if(xgong.shifa==-1&&q>=x)
		{
			fseek(fp,0L,0);
			fwrite(&jianz[0],sizeof(struct gongren),x,fp);
		}
		free(jianz);
		if(fclose(fp)!=0)
		{
			puts("第二次关闭文件失败!");
			exit(4);
		}
		system("pause");
		system("cls");
		if(flag>0)
			break;
	}
	puts("拜拜");
}
void menu1(void)
{
	printf("%16s\n%20s\n%20s\n%20s\n%20s\n%28s\n%20s\n%20s\n%16s\n","职工工资管理系统","1  创建","2  查询","3  删除","4  修改","5  汇总实发工资","6  显示","0  退出","请选择:");
}
void eatline1(void)
{
	while((getchar())!='\n')
		continue;
}
struct gongren chuangjian1(struct gongren gong[],int e)//工号自动生成，应该会跟好一些
{
	int flag=0,flag1=0;
	int i;
	struct gongren xgong;
	puts("您选择了创建选项");
	puts("现在输入该工人的姓名:");
	if(e==0)
		gets(xgong.xingming);
	else
	{
		while(1)												//姓名查重
		{
			flag=0;
			gets(xgong.xingming);
			for(i=0;i<e;i++)
			{
				if(strcmp(xgong.xingming,gong[i].xingming)==0)
				{
					flag++;
					break;
				}
			}
			if(flag==0)
				break;
			else
				printf("已存在该工人!\n请从新输入工人姓名\n");
		}
	}
	puts("请输入该工人的工号:");
	if(e==0)
		gets(xgong.gongh);
	else
	{
		while(1)												//工号查重
		{
			flag1=0;
			gets(xgong.gongh);
			for(i=0;i<e;i++)
			{
				if(strcmp(xgong.gongh,gong[i].gongh)==0)
				{
					flag1++;
					break;
				}
			}
			if(flag1==0)
				break;
			else
				printf("该工号已存在\n请输入其他工号\n");
		}
	}
	puts("现在请依次输入该工人的 岗位工资、薪级工资、职务津贴(用空格隔开)");
	while((scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]))!=3)
	{
		fflush(stdin);
		puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
//		scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]);
	}
	fflush(stdin);
	puts("现在请依次输入该工人的 工会费、保险费、水电费(用空格隔开)");
	while((scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]))!=3)
	{
		fflush(stdin);
		puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
//		scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]);
	}
	fflush(stdin);
	xgong.shifa=xgong.yfa[0]+xgong.yfa[1]+xgong.yfa[2]-xgong.yko[0]-xgong.yko[1]-xgong.yko[2];
	puts("您已成功创建该工人信息");
	return xgong;
}
void huizong1(struct gongren gong[],int e)
{
	int x=0,sum=0;
	int i,k,j;
	struct gongren xgong;
	for(i=0;i<e-1;i++)
	{
		k=i;
		for(j=i+1;j<e;j++)
		{
			if(gong[k].shifa>gong[j].shifa)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			xgong=gong[i];
			gong[i]=gong[k];
			gong[k]=xgong;
		}
	}
	puts("全部工人实发工资如下:");
	printf("%-16s%-16s%-16s\n","工人工号","工人姓名","实发工资");
	for(i=0;i<e;i++)
	{
		printf("%-16s%-16s%-16d\n",gong[i].gongh,gong[i].xingming,gong[i].shifa);
	}
	for(i=0;i<e;i++)
	{
		sum+=gong[i].shifa;
	}
	printf("%-s:%-16d\n","总实发工资",sum);
}
void chaxun1(struct gongren gong[],int e)
{
	char xz;
	int flag=0;
	while(1)
	{
		printf("选择了工人查询选项\n1)按工号查询\n2)按姓名查询\n0)退出\n请输入您的选择:\n");
		xz=getchar();
		eatline1();
		while(strchr("120",xz)==NULL)
		{
			printf("请输入正确的选项，如 1、 2、 0、\n");
			xz=getchar();
			eatline1();
		}
		switch(xz)
		{
			case '1':system("cls");
					ghchaxun1(gong,e);
					system("pause");
					break;
			case '2':system("cls");
					xmchaxun1(gong,e);
					system("pause");
					break;
			case '0':flag++;break;
		}
		fflush(stdin);
		system("cls");
		if(flag>0)
			break;
	}
}
void ghchaxun1(struct gongren gong[],int e)
{
	int flag=0,weizhi;
	int i;
	char gonghao[11];
	printf("请输入要查询的工人的工号:\n");
	gets(gonghao);
	for(i=0;i<e;i++)
	{
		if(strcmp(gonghao,gong[i].gongh)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		printf("该工人的信息如下：\n");
		printf("%-8s:%-16s\n%-8s:%-16s\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n","工人姓名",gong[weizhi].xingming,"工人工号",gong[weizhi].gongh,"岗位工资",gong[weizhi].yfa[0],"薪级工资",gong[weizhi].yfa[1],"职务津贴",gong[weizhi].yfa[2],"工会费",gong[weizhi].yko[0],"保险费",gong[weizhi].yko[1],"水电费",gong[weizhi].yko[2],"实发工资",gong[weizhi].shifa);
	}
	else
		puts("没有该工人");
}
void xmchaxun1(struct gongren gong[],int e)
{
	int flag=0,weizhi;
	int i;
	char xingming[10];
	printf("请输入要查询的工人的姓名:\n");
	gets(xingming);
	for(i=0;i<e;i++)
	{
		if(strcmp(xingming,gong[i].xingming)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		puts("该工人的信息如下：\n");
		printf("%-8s:%-16s\n%-8s:%-16s\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n","工人姓名",gong[weizhi].xingming,"工人工号",gong[weizhi].gongh,"岗位工资",gong[weizhi].yfa[0],"薪级工资",gong[weizhi].yfa[1],"职务津贴",gong[weizhi].yfa[2],"工会费",gong[weizhi].yko[0],"保险费",gong[weizhi].yko[1],"水电费",gong[weizhi].yko[2],"实发工资",gong[weizhi].shifa);
	}
	else
		puts("没有该工人");
}
int shanchu1(struct gongren gong[],int e)
{
	int flag=0,weizhi;
	int i;
	char gonghao[11],queren;
	printf("请输入你要删除的工人的工号\n");
	gets(gonghao);
	for(i=0;i<e;i++)
	{
		if(strcmp(gonghao,gong[i].gongh)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		puts("该工人的信息如下：");
		printf("%-8s:%-16s\n%-8s:%-16s\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n","工人姓名",gong[weizhi].xingming,"工人工号",gong[weizhi].gongh,"岗位工资",gong[weizhi].yfa[0],"薪级工资",gong[weizhi].yfa[1],"职务津贴",gong[weizhi].yfa[2],"工会费",gong[weizhi].yko[0],"保险费",gong[weizhi].yko[1],"水电费",gong[weizhi].yko[2],"实发工资",gong[weizhi].shifa);
		printf("是否删除该工人信息?\n1):删除\n2):取消\n请输入您的选择\n");
		queren=getchar();
		eatline1();
		while(strchr("12",queren)==NULL)
		{
			puts("请输入正确选项,如 1、 2");
			system("cls");
			queren=getchar();
			eatline1();
		}
		if(queren=='1')
		{
			for(;weizhi<e-1;weizhi++)
			{
				gong[weizhi]=gong[weizhi+1];			//依次向前覆盖(删除)
			}
			puts("您已成功删除该工人");	
			return e - 1;
		}
		if(queren=='0')
		{
			puts("您选择了取消删除");
		}
	}
	else
		puts("没有该工人");
	return e;
}
void xianshi1(struct gongren gong[],int e)
{
	int flag=0;
	int i,j,k;
	char xuanz;
	struct gongren xgong;
	printf("1):按工号升序顺序显示\n2):按姓名升序排序显示\n3):按实发工资升序排序显示\n请选择:\n");
	xuanz=getchar();
	eatline1();
	while(strchr("123",xuanz)==NULL)
	{
		puts("请输入正确选项，如 1、 2、 3、");
		xuanz=getchar();
		eatline1();
	}
	if(xuanz=='1')
	{
		for(i=0;i<e-1;i++)
		{
			k=i;
			for(j=i+1;j<e;j++)
			{
				if(strcmp(gong[k].gongh,gong[j].gongh)>0)
				{
					k=j;
				}
			}
			if(k!=i)
			{
				xgong=gong[i];
				gong[i]=gong[k];
				gong[k]=xgong;
			}
		}
		puts("全部工人信息如下:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","工人工号","工人姓名","岗位工资","薪级工资","职务津贴","工会费","保险费","水电费","实发工资");
		for(i=0;i<e;i++)
		{
			printf("%-11s%-10s%-9d%-9d%-9d%-7d%-7d%-7d%-9d\n",gong[i].gongh,gong[i].xingming,gong[i].yfa[0],gong[i].yfa[1],gong[i].yfa[2],gong[i].yko[0],gong[i].yko[1],gong[i].yko[2],gong[i].shifa);
		}

	}
	if(xuanz=='2')
	{
		for(i=0;i<e-1;i++)
		{
			k=i;
			for(j=i+1;j<e;j++)
			{
				if(strcmp(gong[k].xingming,gong[j].xingming)>0)
				{
					k=j;
				}
			}
			if(k!=i)
			{
				xgong=gong[i];
				gong[i]=gong[k];
				gong[k]=xgong;
			}
		}
		puts("全部工人信息如下:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","工人工号","工人姓名","岗位工资","薪级工资","职务津贴","工会费","保险费","水电费","实发工资");
		for(i=0;i<e;i++)
		{
			printf("%-11s%-10s%-9d%-9d%-9d%-7d%-7d%-7d%-9d\n",gong[i].gongh,gong[i].xingming,gong[i].yfa[0],gong[i].yfa[1],gong[i].yfa[2],gong[i].yko[0],gong[i].yko[1],gong[i].yko[2],gong[i].shifa);
		}
	}
	if(xuanz=='3')
	{
		for(i=0;i<e-1;i++)
		{
			k=i;
			for(j=i+1;j<e;j++)
			{
				if(gong[k].shifa>gong[j].shifa)
				{
					k=j;
				}
			}
			if(k!=i)
			{
				xgong=gong[i];
				gong[i]=gong[k];
				gong[k]=xgong;
			}
		}
		puts("全部工人信息如下:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","工人工号","工人姓名","岗位工资","薪级工资","职务津贴","工会费","保险费","水电费","实发工资");
		for(i=0;i<e;i++)
		{
			printf("%-11s%-10s%-9d%-9d%-9d%-7d%-7d%-7d%-9d\n",gong[i].gongh,gong[i].xingming,gong[i].yfa[0],gong[i].yfa[1],gong[i].yfa[2],gong[i].yko[0],gong[i].yko[1],gong[i].yko[2],gong[i].shifa);
		}
	}
}
void xiougai1(struct gongren gong[],int e)
{
	int flag=0,weizhi;
	int i,flag1,flag2,flag3;
	char xuanz,queren;
	char gonghao[11];
	struct gongren xgong;
	printf("请输入你要修改的工人的工号\n");
	gets(gonghao);
	for(i=0;i<e;i++)
	{
		if(strcmp(gonghao,gong[i].gongh)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		while(1)
		{
			flag3=0;
			xgong=gong[weizhi];
			puts("该工人的信息如下：");
	//		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","工人姓名",jianz[weizhi].xingming,"工人工号",jianz[weizhi].gongh,"岗位工资",jianz[weizhi].yfa[0],"薪级工资",jianz[weizhi].yfa[1],"职务津贴",jianz[weizhi].yfa[2],"工会费",jianz[weizhi].yko[0],"保险费",jianz[weizhi].yko[1],"水电费",jianz[weizhi].yko[2],"实发工资",jianz[weizhi].shifa);
			PRT;
			printf("%s\n%s\n%s\n%s\n%s\n%s\n","\n1):修改该工人的工号","2):修改该工人的姓名","3):修改该工人的 岗位工资、薪级工资、职务津贴","4):修改该工人的 工会费、保险费、水电费","5):全部修改","0):退出主菜单");
			puts("请选择：");
			xuanz=getchar();
			eatline1();
			while(strchr("123450",xuanz)==NULL)
			{
				puts("请输入正确选项，例如 1、 2、 ...");
				xuanz=getchar();
				eatline1();
			}
			if(xuanz=='1')
			{
				puts("请输入该工人的工号:");
				while(1)
				{
					flag1=0;
					gets(xgong.gongh);
					for(i=0;i<e;i++)
					{
						if(strcmp(xgong.gongh,gong[i].gongh)==0)
						{
							flag1++;
							break;
						}
					}
					if(flag1==0)
						break;
					else
						printf("该工号已存在\n请输入其他工号\n");
				}
			}
			if(xuanz=='2')
			{
				puts("现在输入该工人的姓名:");
				while(1)
				{
					flag2=0;
					gets(xgong.xingming);
					for(i=0;i<e;i++)
					{
						if(strcmp(xgong.xingming,gong[i].xingming)==0)
						{
							flag2++;
							break;
						}
					}
					if(flag2==0)
						break;
					else
						printf("已存在该工人!\n请从新输入工人姓名\n");
				}
			}
			if(xuanz=='3')
			{
				printf("请依次输入该工人新的 岗位工资、薪级工资、职务津贴(用空格隔开)\n");
				while((scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]))!=3)
				{
					fflush(stdin);
					puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
		//			scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]);
				}
				xgong.shifa=xgong.yfa[0]+xgong.yfa[1]+xgong.yfa[2]-xgong.yko[0]-xgong.yko[1]-xgong.yko[2];
				fflush(stdin);
			}
			if(xuanz=='4')
			{
				puts("请依次输入该工人新的 工会费、保险费、水电费(用空格隔开)");
				while((scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]))!=3)
				{
					fflush(stdin);
					puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
		//			scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]);
				}
				xgong.shifa=xgong.yfa[0]+xgong.yfa[1]+xgong.yfa[2]-xgong.yko[0]-xgong.yko[1]-xgong.yko[2];
				fflush(stdin);
			}
			if(xuanz=='5')
			{
				puts("现在输入该工人的姓名:");
				gets(xgong.xingming);
				puts("请输入该工人的工号:");
				gets(xgong.gongh);
				puts("现在请依次输入该工人的 岗位工资、薪级工资、职务津贴(用空格隔开)");
				while((scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]))!=3)
				{
					fflush(stdin);
					puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
//					scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]);
				}
				fflush(stdin);
				puts("现在请依次输入该工人的 工会费、保险费、水电费(用空格隔开)");
				while((scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]))!=3)
				{
					fflush(stdin);
					puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
	//				scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]);
				}
				fflush(stdin);
				xgong.shifa=xgong.yfa[0]+xgong.yfa[1]+xgong.yfa[2]-xgong.yko[0]-xgong.yko[1]-xgong.yko[2];
			}
			if(xuanz=='0')
			{
				flag3=1;
				puts("您选择了退出主菜单");
			}
			system("cls");
			if(flag3==0)
			{
				printf("最后该工人的信息如下:\n");
		//		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","工人姓名",gong.xingming,"工人工号",gong.gongh,"岗位工资",gong.yfa[0],"薪级工资",gong.yfa[1],"职务津贴",gong.yfa[2],"工会费",gong.yko[0],"保险费",gong.yko[1],"水电费",gong.yko[2],"实发工资",gong.shifa);
				PRT;
				printf("是否确认修改?\ny):确认\nn):取消\n请选择选项\n");
				queren=getchar();
				eatline1();
				while(strchr("yn",queren)==NULL)
				{
					puts("请输入正确选项,  y 、 n");
					queren=getchar();
					eatline1();
				}
				if(queren=='y')
				{
					gong[weizhi]=xgong;
					puts("修改成功");
				}
				if(queren=='n')
				{
					puts("修改已取消");
				}
			}
			system("cls");
			if(flag3==1)
				break;
			}
	}
	else
		puts("没有该工人！");
}
	
