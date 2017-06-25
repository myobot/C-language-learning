#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void menu(void);
void eatline(void);
void chuangjian(FILE *fp);
void chaxun(FILE *fp);
void ghchaxun(FILE *fp);
void xmchaxun(FILE *fp);
void shanchu(FILE *fp);
void xiougai(FILE *fp);
void huizong(FILE *fp);
void xianshi(FILE *fp);
struct gongren
{
	char gongh[11];
	char xingming[10];
	int yfa[3];
	int yko[3];
	int shifa;
};
int main()
{
	int flag=0,flag1=0;
	char xz;
//	char xuanx[9]={'1','2','3','4','5','6','7','8'};
	FILE *fp;
	if((fp=fopen("gongzi.txt","r+b"))==NULL)
	{
		puts("打开文件失败!");
		exit(1);
	}
	while(1)
	{
		menu();
		xz=getchar();
		eatline();
		while(strchr("12345678",xz)==NULL)
		{
			puts("输入错误,请输入正确选项，例如 1、 2、 3");
			xz=getchar();
			eatline();
		}
		switch(xz)
		{
			case '1':system("cls");chuangjian(fp);break;
//			case '2':												不明白添加和创建有什么不同？
			case '3':system("cls");chaxun(fp);break;
			case '4':system("cls");shanchu(fp);break;
			case '5':system("cls");xiougai(fp);break;
			case '6':system("cls");huizong(fp);break;
			case '7':system("cls");xianshi(fp);break;
			case '8':flag++;break;
		}
		fflush(stdin);
		system("pause");
		system("cls");
		if(flag>0)
			break;
	}
	puts("拜拜");
	if(fclose(fp)!=0)
	{
		puts("关闭文件出错!");
	}
	return 0;
}
void menu(void)
{
	printf("%16s\n%20s\n%20s\n%20s\n%20s\n%20s\n%28s\n%20s\n%20s\n%16s\n","职工工资管理系统","1  创建","2  添加","3  查询","4  删除","5  修改","6  汇总实发工资","7  显示","8  退出","请选择:");
}
void eatline(void)
{
	while((getchar())!='\n')
		continue;
}
void chuangjian(FILE *fp)//工号自动生成，应该会跟好一些
{
	int x=0,flag,flag1;
	int i;
	struct gongren gong;
	struct gongren *jianz;
	struct gongren xgong;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	puts("您选择了创建选项");
	puts("现在输入该工人的姓名:");
	while(1)												//姓名查重
	{
		flag=0;
		gets(xgong.xingming);
		for(i=0;i<x;i++)
		{
			if(strcmp(xgong.xingming,jianz[i].xingming)==0)
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
	puts("请输入该工人的工号:");
	while(1)												//工号查重
	{
		flag1=0;
		gets(xgong.gongh);
		for(i=0;i<x;i++)
		{
			if(strcmp(xgong.gongh,jianz[i].gongh)==0)
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
	puts("现在请依次输入该工人的 岗位工资、薪级工资、职务津贴(用空格隔开)");
	while((scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]))!=3)
	{
		fflush(stdin);
		puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
		scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]);
	}
	fflush(stdin);
	puts("现在请依次输入该工人的 工会费、保险费、水电费(用空格隔开)");
	while((scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]))!=3)
	{
		fflush(stdin);
		puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
		scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]);
	}
	fflush(stdin);
	xgong.shifa=xgong.yfa[0]+xgong.yfa[1]+xgong.yfa[2]-xgong.yko[0]-xgong.yko[1]-xgong.yko[2];
	fseek(fp,0L,2);
	fwrite(&xgong,sizeof(struct gongren),1,fp);
	puts("您已成功创建该工人信息");
}
void huizong(FILE *fp)
{
	int x=0,sum=0;
	int i;
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	puts("全部工人实发工资如下:");
	printf("%-16s%-16s%-16s\n","工人工号","工人姓名","实发工资");
	for(i=0;i<x;i++)
	{
		printf("%-16s%-16s%-16d\n",jianz[i].gongh,jianz[i].xingming,jianz[i].shifa);
	}
	for(i=0;i<x;i++)
	{
		sum+=jianz[i].shifa;
	}
	printf("%-s:%-16d\n","总实发工资",sum);
	free(jianz);
}
void chaxun(FILE *fp)
{
	char xz;
	int flag=0;
	while(1)
	{
		printf("选择了工人查询选项\n1)按工号查询\n2)按姓名查询\n0)退出\n请输入您的选择:\n");
		xz=getchar();
		eatline();
		while(strchr("120",xz)==NULL)
		{
			printf("请输入正确的选项，如 1、 2、 0、\n");
			xz=getchar();
			eatline();
		}
		switch(xz)
		{
			case '1':system("cls");ghchaxun(fp);system("pause");break;
			case '2':system("cls");xmchaxun(fp);system("pause");break;
			case '0':flag++;break;
		}
		fflush(stdin);
		system("cls");
		if(flag>0)
			break;
	}
}
void ghchaxun(FILE *fp)
{
	int x=0,flag=0,weizhi;
	int i;
	char gonghao[11];
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	printf("请输入要查询的工人的工号:\n");
	gets(gonghao);
	for(i=0;i<x;i++)
	{
		if(strcmp(gonghao,jianz[i].gongh)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		printf("该工人的信息如下：\n");
		printf("%-8s:%-16s\n%-8s:%-16s\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n","工人姓名",jianz[weizhi].xingming,"工人工号",jianz[weizhi].gongh,"岗位工资",jianz[weizhi].yfa[0],"薪级工资",jianz[weizhi].yfa[1],"职务津贴",jianz[weizhi].yfa[2],"工会费",jianz[weizhi].yko[0],"保险费",jianz[weizhi].yko[1],"水电费",jianz[weizhi].yko[2],"实发工资",jianz[weizhi].shifa);
	}
	else
		puts("没有该工人");
	free(jianz);
}
void xmchaxun(FILE *fp)
{
	int x=0,flag=0,weizhi;
	int i;
	char xingming[10];
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	printf("请输入要查询的工人的姓名:\n");
	gets(xingming);
	for(i=0;i<x;i++)
	{
		if(strcmp(xingming,jianz[i].xingming)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		puts("该工人的信息如下：\n");
		printf("%-8s:%-16s\n%-8s:%-16s\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n","工人姓名",jianz[weizhi].xingming,"工人工号",jianz[weizhi].gongh,"岗位工资",jianz[weizhi].yfa[0],"薪级工资",jianz[weizhi].yfa[1],"职务津贴",jianz[weizhi].yfa[2],"工会费",jianz[weizhi].yko[0],"保险费",jianz[weizhi].yko[1],"水电费",jianz[weizhi].yko[2],"实发工资",jianz[weizhi].shifa);
	}
	else
		puts("没有该工人");
	free(jianz);
}
void shanchu(FILE *fp)//如何将文件内容清除，但不删除原文件?
{
	int x=0,flag=0,weizhi;
	int i;
	char gonghao[11],queren;
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	printf("请输入你要删除的工人的工号\n");
	gets(gonghao);
	for(i=0;i<x;i++)
	{
		if(strcmp(gonghao,jianz[i].gongh)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		puts("该工人的信息如下：");
		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","工人姓名",jianz[weizhi].xingming,"工人工号",jianz[weizhi].gongh,"岗位工资",jianz[weizhi].yfa[0],"薪级工资",jianz[weizhi].yfa[1],"职务津贴",jianz[weizhi].yfa[2],"工会费",jianz[weizhi].yko[0],"保险费",jianz[weizhi].yko[1],"水电费",jianz[weizhi].yko[2],"实发工资",jianz[weizhi].shifa);
		printf("是否删除该工人信息?\n1):删除\n2):取消\n请输入您的选择\n");
		queren=getchar();
		eatline();
		while(strchr("12",queren)==NULL)
		{
			puts("请输入正确选项,如 1、 2");
			system("cls");
			queren=getchar();
			eatline();
		}
		if(queren=='1')
		{
			for(;weizhi<x-1;weizhi++)
			{
				jianz[weizhi]=jianz[weizhi+1];			//依次向前覆盖(删除)
			}
			fclose(fp);                                 //先关闭文件
			if((fp=fopen("gongzi.txt","w+b"))==NULL)	//以 w+b打开，文件被截为零，内容被清空；
			{
				printf("第二次打开文件失败!\n");
				exit(2);
			}
			fseek(fp,0L,0);
			fwrite(&jianz[0],sizeof(struct gongren),x-1,fp);//在写入文件
			puts("您已成功删除该工人");
			fclose(fp);									
			if((fp=fopen("gongzi.txt","r+b"))==NULL)		//从新以 r+b 形式打开
			{
				printf("第三次打开文件失败!\n");
				exit(3);
			}
		}
		if(queren=='0')
		{
			puts("您选择了取消删除");
		}
	}
	else
		puts("没有该工人");
	free(jianz);
}
void xianshi(FILE *fp)
{
	int x=0,flag=0;
	int i,j,k;
	char xuanz;
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	printf("1):按工号升序顺序显示\n2):按姓名升序排序显示\n3):按实发工资升序排序显示\n请选择:\n");
	xuanz=getchar();
	eatline();
	while(strchr("123",xuanz)==NULL)
	{
		puts("请输入正确选项，如 1、 2、 3、");
		xuanz=getchar();
		eatline();
	}
	if(xuanz=='1')
	{
		for(i=0;i<x-1;i++)
		{
			k=i;
			for(j=i;j<x-1;j++)
			{
				if(strcmp(jianz[k].gongh,jianz[j].gongh)>0)
				{
					k=j;
				}
			}
			if(k!=i)
			{
				gong=jianz[i];
				jianz[i]=jianz[k];
				jianz[k]=gong;
			}
		}
		puts("全部工人信息如下:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","工人工号","工人姓名","岗位工资","薪级工资","职务津贴","工会费","保险费","水电费","实发工资");
		for(i=0;i<x;i++)
		{
			printf("%-11s%-10s%-9d%-9d%-9d%-7d%-7d%-7d%-9d\n",jianz[i].gongh,jianz[i].xingming,jianz[i].yfa[0],jianz[i].yfa[1],jianz[i].yfa[2],jianz[i].yko[0],jianz[i].yko[1],jianz[i].yko[2],jianz[i].shifa);
		}

	}
	if(xuanz=='2')
	{
		for(i=0;i<x-1;i++)
		{
			k=i;
			for(j=i+1;j<x;j++)
			{
				if(strcmp(jianz[k].xingming,jianz[j].xingming)>0)
				{
					k=j;
				}
			}
			if(k!=i)
			{
				gong=jianz[i];
				jianz[i]=jianz[k];
				jianz[k]=gong;
			}
		}
		puts("全部工人信息如下:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","工人工号","工人姓名","岗位工资","薪级工资","职务津贴","工会费","保险费","水电费","实发工资");
		for(i=0;i<x;i++)
		{
			printf("%-11s%-10s%-9d%-9d%-9d%-7d%-7d%-7d%-9d\n",jianz[i].gongh,jianz[i].xingming,jianz[i].yfa[0],jianz[i].yfa[1],jianz[i].yfa[2],jianz[i].yko[0],jianz[i].yko[1],jianz[i].yko[2],jianz[i].shifa);
		}
	}
	if(xuanz=='3')
	{
		for(i=0;i<x-1;i++)
		{
			k=i;
			for(j=i+1;j<x;j++)
			{
				if(jianz[k].shifa>jianz[j].shifa)
				{
					k=j;
				}
			}
			if(k!=i)
			{
				gong=jianz[i];
				jianz[i]=jianz[k];
				jianz[k]=gong;
			}
		}
		puts("全部工人信息如下:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","工人工号","工人姓名","岗位工资","薪级工资","职务津贴","工会费","保险费","水电费","实发工资");
		for(i=0;i<x;i++)
		{
			printf("%-11s%-10s%-9d%-9d%-9d%-7d%-7d%-7d%-9d\n",jianz[i].gongh,jianz[i].xingming,jianz[i].yfa[0],jianz[i].yfa[1],jianz[i].yfa[2],jianz[i].yko[0],jianz[i].yko[1],jianz[i].yko[2],jianz[i].shifa);
		}
	}
	free(jianz);
}
void xiougai(FILE *fp)
{
	int x=0,flag=0,weizhi;
	int i,flag1,flag2;
	char xuanz,queren;
	char gonghao[11];
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	printf("请输入你要修改的工人的工号\n");
	gets(gonghao);
	for(i=0;i<x;i++)
	{
		if(strcmp(gonghao,jianz[i].gongh)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		gong=jianz[weizhi];
		puts("该工人的信息如下：");
		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","工人姓名",jianz[weizhi].xingming,"工人工号",jianz[weizhi].gongh,"岗位工资",jianz[weizhi].yfa[0],"薪级工资",jianz[weizhi].yfa[1],"职务津贴",jianz[weizhi].yfa[2],"工会费",jianz[weizhi].yko[0],"保险费",jianz[weizhi].yko[1],"水电费",jianz[weizhi].yko[2],"实发工资",jianz[weizhi].shifa);
		printf("%s\n%s\n%s\n%s\n%s\n%s\n","1):修改该工人的工号","2):修改该工人的姓名","3):修改该工人的 岗位工资、薪级工资、职务津贴","4):修改该工人的 工会费、保险费、水电费","5):全部修改","0):不做修改");
		puts("请选择：");
		xuanz=getchar();
		eatline();
		while(strchr("123450",xuanz)==NULL)
		{
			puts("请输入正确选项，例如 1、 2、 ...");
			xuanz=getchar();
			eatline();
		}
		if(xuanz=='1')
		{
			puts("请输入该工人的工号:");
			while(1)
			{
				flag1=0;
				gets(gong.gongh);
				for(i=0;i<x;i++)
				{
					if(strcmp(gong.gongh,jianz[i].gongh)==0)
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
				gets(gong.xingming);
				for(i=0;i<x;i++)
				{
					if(strcmp(gong.xingming,jianz[i].xingming)==0)
					{
						flag2++;
						break;
					}
				}
				if(flag==0)
					break;
				else
					printf("已存在该工人!\n请从新输入工人姓名\n");
			}
		}
		if(xuanz=='3')
		{
			printf("请依次输入该工人新的 岗位工资、薪级工资、职务津贴(用空格隔开)\n");
			while((scanf("%d %d %d",&gong.yfa[0],&gong.yfa[1],&gong.yfa[2]))!=3)
			{
				fflush(stdin);
				puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
				scanf("%d %d %d",&gong.yfa[0],&gong.yfa[1],&gong.yfa[2]);
			}
			gong.shifa=gong.yfa[0]+gong.yfa[1]+gong.yfa[2]-gong.yko[0]-gong.yko[1]-gong.yko[2];
			fflush(stdin);
		}
		if(xuanz=='4')
		{
			puts("请依次输入该工人新的 工会费、保险费、水电费(用空格隔开)");
			while((scanf("%d %d %d",&gong.yko[0],&gong.yko[1],&gong.yko[2]))!=3)
			{
				fflush(stdin);
				puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
				scanf("%d %d %d",&gong.yko[0],&gong.yko[1],&gong.yko[2]);
			}
			gong.shifa=gong.yfa[0]+gong.yfa[1]+gong.yfa[2]-gong.yko[0]-gong.yko[1]-gong.yko[2];
			fflush(stdin);
		}
		if(xuanz=='5')
		{
			puts("现在输入该工人的姓名:");
			gets(gong.xingming);
			puts("请输入该工人的工号:");
			gets(gong.gongh);
			puts("现在请依次输入该工人的 岗位工资、薪级工资、职务津贴(用空格隔开)");
			while((scanf("%d %d %d",&gong.yfa[0],&gong.yfa[1],&gong.yfa[2]))!=3)
			{
				fflush(stdin);
				puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
				scanf("%d %d %d",&gong.yfa[0],&gong.yfa[1],&gong.yfa[2]);
			}
			fflush(stdin);
			puts("现在请依次输入该工人的 工会费、保险费、水电费(用空格隔开)");
			while((scanf("%d %d %d",&gong.yko[0],&gong.yko[1],&gong.yko[2]))!=3)
			{
				fflush(stdin);
				puts("输入有误，请勿包含除数字外的其他字符,请重新输入正确的工资");
				scanf("%d %d %d",&gong.yko[0],&gong.yko[1],&gong.yko[2]);
			}
			fflush(stdin);
			gong.shifa=gong.yfa[0]+gong.yfa[1]+gong.yfa[2]-gong.yko[0]-gong.yko[1]-gong.yko[2];
		}
		if(xuanz=='0')
		{
			puts("您选择不做修改");
		}
		system("cls");
		printf("最后该工人的信息如下:\n");
		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","工人姓名",gong.xingming,"工人工号",gong.gongh,"岗位工资",gong.yfa[0],"薪级工资",gong.yfa[1],"职务津贴",gong.yfa[2],"工会费",gong.yko[0],"保险费",gong.yko[1],"水电费",gong.yko[2],"实发工资",gong.shifa);
		printf("是否确认修改?\ny):确认\nn):取消\n请选择选项\n");
		queren=getchar();
		eatline();
		while(strchr("yn",queren)==NULL)
		{
			puts("请输入正确选项,  y 、 n");
			queren=getchar();
			eatline();
		}
		if(queren=='y')
		{
			fseek(fp,sizeof(struct gongren)*weizhi,0);
			fwrite(&gong,sizeof(struct gongren),1,fp);
			puts("修改成功");
		}
		if(queren=='n')
		{
			puts("修改已取消");
		}
	}
	else
		puts("没有该工人！");
	free(jianz);
}
	
