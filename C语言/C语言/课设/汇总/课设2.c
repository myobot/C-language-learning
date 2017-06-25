#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void menu2(void);
void eatline(void);
struct tongxunlu chuangjian2(struct tongxunlu txl[],int e);
void tianjia2(struct tongxunlu txl[],int e);
void xianshi2(struct tongxunlu txl[],int e);		   //显示主函数
void dangexianshi2(struct tongxunlu txl[],int e);   //显示函数
void zhuzhaixianshi2(struct tongxunlu txl[],int e); //显示函数
void shoujixianshi2(struct tongxunlu txl[],int e);  //显示函数
void quanbuxianshi2(struct tongxunlu txl[],int e);  //显示函数
void chaxun2(struct tongxunlu txl[],int e); 
void xiougai2(struct tongxunlu txl[],int e);					 //修改主函数
struct tongxunlu bhxiougai2(struct tongxunlu txl[],int e,int weizhi);    //编号修改函数
struct tongxunlu xmxiougai2(struct tongxunlu);		 	 //姓名修改函数
struct tongxunlu xnxiougai2(struct tongxunlu);			 //性别年龄修改函数
struct tongxunlu zzxiougai2(struct tongxunlu);			 //住宅修改函数
struct tongxunlu sjxiougai2(struct tongxunlu);			 //手机修改函数
struct tongxunlu qbxiougai2(struct tongxunlu txl[],int e,int weizhi);	//全部修改函数
int shanchu2(struct tongxunlu txl[],int e);					//删除主函数
void zzshanchu2(struct tongxunlu *txl,int weizhi);
void sjshanchu2(struct tongxunlu *txl,int weizhi);
int qbshanchu2(struct tongxunlu *txl,int weizhi,int e);
void keshedier(void);
struct tongxunlu
{
	char bianhao[11];
	char xingming[10];
	char xingbie[5];
	int nianling;
	char zhuzhai[16];
	int sjgeshu;
	char shouji[4][16];
};
void keshedier();
{
	int x,flag,q;
	char xz;
	FILE *fp;
	struct tongxunlu txl;
	struct tongxunlu *jianc;
	while(1)
	{
		flag=0;
		x=0;	
		if((fp=fopen("tongxunlu.txt","r"))==NULL)
		{
			puts("第一次打开文件失败！");
			exit(1);
		}
		fseek(fp,0L,0);
		while(fread(&txl,sizeof(struct tongxunlu),1,fp)==1)
		{	
			x++;
		}
		jianc=(struct tongxunlu *)malloc(x*(sizeof(struct tongxunlu)));
		fseek(fp,0L,0);
		fread(&jianc[0],sizeof(struct tongxunlu),x,fp);
		if(fclose(fp)!=0)
		{
			puts("第一次关闭文件失败!");
			exit(2);
		}
		q=x;
		txl.sjgeshu=-1;
		menu2();
		xz=getchar();
		eatline();
		while(strchr("1234560",xz)==NULL)
		{
			puts("请输入正确的选项!,例如1、 2、 3、...");
			xz=getchar();
			eatline();
		}
		switch (xz)
		{
			case '1':system("cls");
					txl=chuangjian2(jianc,x);
					system("pause");system("cls");	break;
			case '2':system("cls");
					tianjia2(jianc,x);
					system("pause");system("cls");break;
			case '3':system("cls");
					chaxun2(jianc,x);
					system("pause");system("cls");break;
			case '4':system("cls");
					xiougai2(jianc,x);
					system("pause");system("cls");	break;
			case '5':system("cls");
					q=shanchu2(jianc,x);
					system("pause");system("cls");break;
			case '6':system("cls");
					xianshi2(jianc,x);
					system("pause");system("cls");break;
			case '0':flag++;system("cls");break;
		}
		fflush(stdin);
		if((fp=fopen("tongxunlu.txt","w"))==NULL)
		{
			puts("第二次打开文件失败！");
			exit(3);
		}
		if(txl.sjgeshu!=-1)
		{
			fseek(fp,0L,0);
			fwrite(&jianc[0],sizeof(struct tongxunlu),x,fp);
			fseek(fp,0L,2);
			fwrite(&txl,sizeof(struct tongxunlu),1,fp);
		}
		if(txl.sjgeshu==-1&&q==x)
		{
			fseek(fp,0L,0);
			fwrite(&jianc[0],sizeof(struct tongxunlu),x,fp);
		}
		if(q<x)
		{
			fseek(fp,0L,0);
			fwrite(&jianc[0],sizeof(struct tongxunlu),q,fp);
		}
		if(fclose(fp)!=0)
		{
			puts("第二次关闭文件失败!");
			exit(4);
		}
		free(jianc);
		if(flag>0)
			break;
	}
	puts("拜拜");
}
void menu2(void)                        //菜单函数
{
	printf("%16s\n%20s\n%20s\n%20s\n%20s\n%20s\n%20s\n%20s\n%16s\n","通讯录管理系统","1  创建","2  添加","3  查询","4  修改","5  删除","6  显示","0  退出","请选择:");
}
void eatline(void)                      //清行函数
{
	while((getchar())!='\n')
	{
		continue;
	}
}
struct tongxunlu chuangjian2(struct tongxunlu txl[],int e)          //创建函数
{
	int i,flag;
	char zzxz,sjxz;
	struct tongxunlu xtxl;
	xtxl.sjgeshu=0;
	xtxl.zhuzhai[0]='\0';
	for(i=0;i<4;i++)
	{
		xtxl.shouji[i][0]='\0';
	}
	printf("选择了创建新朋友的通讯录\n现在请输入新朋友的编号:\n");
	if(e==0)
	{
		gets(xtxl.bianhao);
	}
	else
	{
		while(1)
		{
			flag=0;
			gets(xtxl.bianhao);
			for(i=0;i<e;i++)
			{
				if(strcmp(xtxl.bianhao,txl[i].bianhao)==0)
				{
					printf("与现有人员编号相重，请重新输入编号\n");
					flag++;
				}
			}
			if(flag==0)
				break;
		}
	}
	printf("现在请输入该朋友的姓名\n");
	gets(xtxl.xingming);
	printf("现在请输入该朋友的性别\n");
	gets(xtxl.xingbie);
	puts("现在请输入该朋友的年龄");
	while(scanf("%d",&xtxl.nianling)!=1)
	{
		fflush(stdin);
		puts("输入年龄有误,请重新输入正确数字");
//		scanf("%d",&xtxl.nianling);
	}
	fflush(stdin);
	printf("是否有该朋友的住宅电话?\n输入 y 有,输入 n 无\n");
	zzxz=getchar();
	eatline();
	while(strchr("yn",zzxz)==NULL)
	{
		puts("请重新输入正确的选项,如 y 、 n");
		zzxz=getchar();
		eatline();
	}
	fflush(stdin);
	if(zzxz=='y')
	{
		puts("现在请输入该朋友的住宅电话号码");
		gets(xtxl.zhuzhai);
		fflush(stdin);
	}
	printf("是否有该朋友的手机号码?\n输入 y 有,输入 n 无\n");
	sjxz=getchar();
	eatline();
	while(strchr("yn",sjxz)==NULL)
	{
		puts("请重新输入正确的选项,如 y 、 n");
		sjxz=getchar();
		eatline();
	}
	fflush(stdin);
	if(sjxz=='y')
	{
		
		for(i=0;i<4;i++)
		{
			printf("现在请输入该朋友的第%d个手机号码:\n",i+1);
			gets(xtxl.shouji[i]);
			xtxl.sjgeshu++;
			if(i!=3)	
			{
				printf("是否有该朋友的第%d个手机号码?\n输入 y 有,输入 n 无\n",i+2);
				sjxz=getchar();
				fflush(stdin);
				while(strchr("yn",sjxz)==NULL)
				{
					puts("请重新输入正确的选项,如 y 、 n");
					sjxz=getchar();
					fflush(stdin);
				}
				fflush(stdin);
			}
			if(i==3)
			{
				puts("手机号码存储个数达到最大，无法继续添加!");
			}
			if(sjxz=='n')
				break;
		}
	}
	system("pause");
	system("cls");
	printf("该朋友的通讯录，录入完毕\n以下是该朋友的通讯录全貌:\n");
	printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",xtxl.bianhao,"姓名",xtxl.xingming,"性别",xtxl.xingbie,"年龄",xtxl.nianling,"住宅电话",xtxl.zhuzhai);
	for(i=0;i<4;i++)
	{
		if(xtxl.shouji[i][0]=='\0')
			break;
		printf("第%d个手机号码:%-17s\n",i+1,xtxl.shouji[i]);
	}
	return xtxl;
}
void tianjia2(struct tongxunlu txl[],int e)//           添加函数
{
	int i,k=0,flag4=0;
	int weizhi=-1;
	char ren[16],haoma[16],xz,queren;
	printf("选择了添加信息\n");
	if(e==0)
		printf("通讯录成员数为0,无法添加(请先创建)\n");
	else
	{
		printf("通讯录中有如下成员:\n");
		printf("%12s%12s%12s%12\n","编号","姓名","性别","电话个数");
		for(i=0;i<e;i++)
		{
			printf("%12s%12s%12s",txl[i].bianhao,txl[i].xingming,txl[i].xingbie);
			if(txl[i].zhuzhai[0]!='\0')
				k=1;
			printf("%12d\n",k+txl[i].sjgeshu);
		}
		printf("请输入要添加信息的人的编号\n");            //或者姓名(只数其中一种!):
		gets(ren);
		for(i=0;i<e;i++)
		{
			if(strcmp(ren,txl[i].bianhao)==0)
			{
				weizhi=i;
				break;
			}
		}
/*		if(weizhi==-1)
		{
			for(i=0;i<e;i++)
			{
				if(strcmp(ren,txl[i].xingming)==0)
				{
					weizhi=i;
					break;
				}
			}
		}*/
		system("cls");
		if(weizhi!=-1)
		{
			printf("此人的信息如下:\n");
			printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi].bianhao,"姓名",txl[weizhi].xingming,"性别",txl[weizhi].xingbie,"年龄",txl[weizhi].nianling,"住宅电话",txl[weizhi].zhuzhai);
			for(i=0;i<4;i++)
			{			
				if(txl[weizhi].shouji[i][0]=='\0')
					break;
				printf("第%d个手机号码:%-17s\n",i+1,txl[weizhi].shouji[i]);
			}
			if(txl[weizhi].zhuzhai[0]!='\0'&&txl[weizhi].sjgeshu==4)
			{
				printf("此人的通讯录存储已达上限!不能继续添加号码!\n");
				flag4=1;
			}
			if(txl[weizhi].zhuzhai[0]!='\0'&&txl[weizhi].sjgeshu<4)
			{
				printf("此人的住宅电话已存在，只能添加其手机号码(最多能在添加%d个)\n现在请输入此人,新的手机号码:\n",4-txl[weizhi].sjgeshu);
				while(1)
				{
					while(1)
					{
						gets(haoma);
						printf("要添加的手机号为: %s\n是否确认?\n输入 y 确认，请输入 n 重新输入\n",haoma);
						queren=getchar();
						eatline();
						while(strchr("yn",queren)==NULL)
						{
							printf("选项输入错误,请重新输入正确选项，例如 y 、 n\n");
							queren=getchar();
							eatline();
						}
						if(queren=='y')
						{
							strcpy(txl[weizhi].shouji[txl[weizhi].sjgeshu],haoma);
							txl[weizhi].sjgeshu++;
							break;
						}
						else
							puts("请重新输入的号码");
					}
					if(txl[weizhi].sjgeshu==4)
					{
						puts("手机号码存储个数达到上限,无法继续添加!");
						system("pause");
						break;
					}
					printf("是否继续添加手机号码?(现在最多添加%d个)\ny)继续\nn)不再添加\n",4-txl[weizhi].sjgeshu);
					xz=getchar();
					eatline();
					while(strchr("yn",xz)==NULL)
					{
						printf("选项输入错误,请重新输入正确选项，例如 y 、 n\n");
						xz=getchar();
						eatline();
					}
					if(xz=='n')
						break;
					else
						puts("请输入下一个号码");
				}

			}
			if(txl[weizhi].zhuzhai[0]=='\0'&&txl[weizhi].sjgeshu<4)
			{
				while(1)
				{
					if(txl[weizhi].zhuzhai[0]=='\0'&&txl[weizhi].sjgeshu<4)//能添加两种
					{
						printf("\n1)添加手机号码\n2)添加住宅电话\n0)不再添加\n请选择:\n");
						xz=getchar();
						eatline();
						while(strchr("120",xz)==NULL)
						{
							printf("选项输入错误,请重新输入正确选项，例如 y 、 n\n");
							xz=getchar();
							eatline();
						}
					}
					if(txl[weizhi].zhuzhai[0]!='\0'&&txl[weizhi].sjgeshu<4)//只能添加手机号
					{
						puts("住宅电话已存在,只能继续添加手机号码.");
						printf("1)添加手机号码\n0)不再添加\n请选择:\n");
						xz=getchar();
						eatline();
						while(strchr("10",xz)==NULL)
						{
							printf("选项输入错误,请重新输入正确选项，例如 y 、 n\n");
							xz=getchar();
							eatline();
						}
					}
					if(txl[weizhi].zhuzhai[0]=='\0'&&txl[weizhi].sjgeshu==4)//只能添加住宅号
					{
						puts("手机号码存储数量已达上限,住宅电话为空，只能继续添加住宅电话.");
						printf("1)添加住宅电话\n0)不再添加\n请选择:\n");
						xz=getchar();
						eatline();
						while(strchr("10",xz)==NULL)
						{
							printf("选项输入错误,请重新输入正确选项，例如 y 、 n\n");
							xz=getchar();
							eatline();
						}
					}
					if(txl[weizhi].zhuzhai[0]!='\0'&&txl[weizhi].sjgeshu==4)
					{
						puts("所有存储已达到上限，不能再继续添加!");
						system("pause");
						break;
					}
					system("cls");
					if(xz=='1')
					{
						printf("请输入手机号码:\n");
						while(1)
						{
							while(1)
							{	
								gets(haoma);
								printf("要添加的手机号为: %s\n是否确认?\n输入 y 确认，请输入 n 重新输入\n",haoma);
								queren=getchar();
								eatline();
								while(strchr("yn",queren)==NULL)
								{
									printf("选项输入错误,请重新输入正确选项，例如 y 、 n\n");
									queren=getchar();
									eatline();
								}
								if(queren=='y')
								{
									strcpy(txl[weizhi].shouji[txl[weizhi].sjgeshu],haoma);
									txl[weizhi].sjgeshu++;
									break;
								}
								else
									puts("请重新输入的号码");
							}
							if(txl[weizhi].sjgeshu==4)
							{
								puts("手机号码存储个数达到上限，不能再继续添加!");
								break;
							}
							printf("是否继续添加手机号码?(现在最多添加%d个)\ny)继续\nn)不再添加\n",4-txl[weizhi].sjgeshu);
							xz=getchar();
							eatline();
							while(strchr("yn",xz)==NULL)
							{
								printf("选项输入错误,请输入正确选项，例如 y 、 n\n");
								xz=getchar();
								eatline();
							}
							if(xz=='n')
								break;
							else
								puts("请输入下一个号码");
						}
					}
					if(xz=='2')
					{
						printf("请输入要添加的住宅电话\n");
						gets(haoma);
						printf("要添加的手机号为: %s\n是否确认?\n输入 y 确认，请输入 n 重新输入\n",haoma);
						while(1)
						{
							queren=getchar();
							eatline();
							while(strchr("yn",queren)==NULL)
							{
								printf("选项输入错误,请重新输入正确选项，例如 y 、 n\n");
								queren=getchar();
								eatline();
							}
							if(queren=='y')
							{
								strcpy(txl[weizhi].zhuzhai,haoma);
								break;
							}
							else
								puts("请重新输入的号码");
						}
					}
					system("cls");
					if(xz=='0')
						break;
				}
			}
			if(txl[weizhi].zhuzhai[0]!='\0'&&txl[weizhi].sjgeshu<4)
			{
				printf("此人的手机号码存储已达上限，只能添加其住宅电话\n请输入其住宅电话:\n");
				gets(haoma);
				printf("要添加的手机号为: %s\n是否确认?\n输入 y 确认，请输入 n 重新输入\n",haoma);
				while(1)
				{
					queren=getchar();
					eatline();
					while(strchr("yn",queren)==NULL)
					{
						printf("选项输入错误,请重新输入正确选项，例如 y 、 n\n");
						queren=getchar();
						eatline();
					}
					if(queren=='y')
					{
						strcpy(txl[weizhi].zhuzhai,haoma);
						break;
					}
					else
						puts("请重新输入的号码");
				}
			}
			if(flag4==0)
			{
				printf("添加后此人的信息如下:\n");
				printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi].bianhao,"姓名",txl[weizhi].xingming,"性别",txl[weizhi].xingbie,"年龄",txl[weizhi].nianling,"住宅电话",txl[weizhi].zhuzhai);
				for(i=0;i<4;i++)
				{			
					if(txl[weizhi].shouji[i][0]=='\0')
						break;
					printf("第%d个手机号码:%-17s\n",i+1,txl[weizhi].shouji[i]);
				}
				printf("已完成添加\n");
			}
		}
		else
			puts("没有此人!");
	}
}
void xianshi2(struct tongxunlu txl[],int e)                //显示主函数
{
	int i,j,flag=0,k;
	char xz;
	struct tongxunlu swap;
	if(e==0)
		printf("通讯录中没有成员\n");
	else
	{
		for(i=0;i<e-1;i++)
		{
			k=i;
			for(j=i+1;j<e;j++)
			{
				if(strcmp(txl[k].xingming,txl[j].xingming)>0)
				{
					k=j;
				}
			}
			if(k!=i)
			{
				swap=txl[i];
				txl[i]=txl[k];
				txl[k]=swap;
			}
		}
		printf("1)单个显示\n2)只显示住宅号码\n3)只显示手机号码\n4)全部信息显示\n请选择:\n");
		xz=getchar();
		eatline();
		while(strchr("1234",xz)==NULL)
		{
			printf("请重新输入正确选项\n如 1、 2、...\n");
			xz=getchar();
			eatline();
		}
		switch (xz)
		{
			case '1':system("cls");
					dangexianshi2(txl,e);
					break;
			case '2':system("cls");
					zhuzhaixianshi2(txl,e);
					break;
			case '3':system("cls");
					shoujixianshi2(txl,e);
					break;
			case '4':system("cls");
					quanbuxianshi2(txl,e);
					break;
		}
	}
}
void dangexianshi2(struct tongxunlu txl[],int e)                //单个显示函数
{
	int i,j;
	char xz;
	char *xuhao;
	xuhao=(char *)malloc(sizeof(char)*e);
	for(i=0;i<e;i++)
	{
		xuhao[i]=i+49;
	}
	printf("    %12s\n","姓名");
	for(i=0;i<e;i++)
	{
		printf("%-2d: %12s\n",i+1,txl[i].xingming);
	}
	printf("请选择姓名前的序号\n");
	xz=getchar();
	eatline();
	while(strchr(xuhao,xz)==NULL)
	{
		printf("请重新输入正确序号!\n如 1、 2、....\n");
		xz=getchar();
		eatline();
	}
	system("cls");
	printf("%s的全部信息如下:\n",txl[(int)xz-49].xingming);
	printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[(int)xz-49].bianhao,"姓名",txl[(int)xz-49].xingming,"性别",txl[(int)xz-49].xingbie,"年龄",txl[(int)xz-49].nianling,"住宅电话",txl[(int)xz-49].zhuzhai);
	for(j=0;j<4;j++)
	{
		if(txl[(int)xz-49].shouji[j][0]=='\0')
			break;
		printf("第%d个手机号码:%-17s\n",j+1,txl[(int)xz-49].shouji[j]);
	}
	free(xuhao);
}
void zhuzhaixianshi2(struct tongxunlu txl[],int e)                //住宅号码显示函数
{
	int i;
	printf("%12s%12s%12s%12s%16s\n","编号","姓名","性别","年龄","住宅电话");
	for(i=0;i<e;i++)
	{
		printf("%12s%12s%12s%12d%16s\n",txl[i].bianhao,txl[i].xingming,txl[i].xingbie,txl[i].nianling,txl[i].zhuzhai);
	}
}
void shoujixianshi2(struct tongxunlu txl[],int e)                //手机号码显示函数
{
	int i,j;
	for(i=0;i<e;i++)
	{
		printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n","编号",txl[i].bianhao,"姓名",txl[i].xingming,"性别",txl[i].xingbie,"年龄",txl[i].nianling);
		for(j=0;j<4;j++)
		{
			if(txl[i].shouji[j][0]=='\0')
				break;
			printf("第%d个手机号码:%-17s\n",j+1,txl[i].shouji[j]);
		}
	}
}
void quanbuxianshi2(struct tongxunlu txl[],int e)                //全部显示函数
{
	int i,j;
	for(i=0;i<e;i++)
	{
		printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[i].bianhao,"姓名",txl[i].xingming,"性别",txl[i].xingbie,"年龄",txl[i].nianling,"住宅电话",txl[i].zhuzhai);
		for(j=0;j<4;j++)
		{
			if(txl[i].shouji[j][0]=='\0'||txl[i].shouji[j][0]=='\n')
				break;
			printf("第%d个手机号码:%-17s\n",j+1,txl[i].shouji[j]);
		}
		printf("\n\n");
	}
}
void chaxun2(struct tongxunlu txl[],int e)                  //查询函数
{
	int i,j,k,weizhi[8];
	char xz;
	char xingming[10],sj[16];
	if(e==0)
		printf("通讯录中没有成员，无法查询\n");
	else
	{
		while(1)
		{
			for(i=0;i<8;i++)
				weizhi[i]=-1;
			printf("1)姓名查询\n2)手机号查询\n0)退出查询\n请选择:\n");
			xz=getchar();
			eatline();
			while(strchr("120",xz)==NULL)
			{
				printf("请重新输入正确的选项\n如 1、 2、 0\n");
				xz=getchar();
				eatline();
			}
			system("cls");
			if(xz=='1')
			{
				puts("请输入要查询人的姓名:");
				gets(xingming);
				for(i=0,k=0;i<e;i++)
				{
					if(strcmp(xingming,txl[i].xingming)==0)
					{
						weizhi[k]=i;
						k++;
					}
				}
				if(k==1)
				{
					printf("%s的信息如下:\n",xingming);
					printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi[0]].bianhao,"姓名",txl[weizhi[0]].xingming,"性别",txl[weizhi[0]].xingbie,"年龄",txl[weizhi[0]].nianling,"住宅电话",txl[weizhi[0]].zhuzhai);
					for(i=0;i<4;i++)
					{			
						if(txl[weizhi[0]].shouji[i][0]=='\0')
							break;
						printf("第%d个手机号码:%-17s\n",i+1,txl[weizhi[0]].shouji[i]);
					}
				}
				if(k>1)
				{
					printf("共找到%d个相同姓名的人\n分别为:\n",k);
					for(i=0;i<k;i++)
					{
						printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi[i]].bianhao,"姓名",txl[weizhi[i]].xingming,"性别",txl[weizhi[i]].xingbie,"年龄",txl[weizhi[i]].nianling,"住宅电话",txl[weizhi[i]].zhuzhai);
						for(j=0;j<4;j++)
						{			
							if(txl[weizhi[i]].shouji[j][0]=='\0')
								break;
							printf("第%d个手机号码:%-17s\n",j+1,txl[weizhi[i]].shouji[j]);
						}
						printf("\n\n");
					}
				}
				if(k==0)
					puts("没有此人!");
				system("pause");
				system("cls");
			}
			if(xz=='2')
			{
				puts("请输入要查询人的住宅或手机号码:");
				gets(sj);
				for(i=0,k=0;i<e;i++)
				{
					if(strcmp(sj,txl[i].zhuzhai)==0)
					{
						weizhi[k]=i;
						k++;
						continue;
					}
					for(j=0;j<4;j++)
					{
						if(strcmp(sj,txl[i].shouji[j])==0)
						{
							weizhi[k]=i;
							k++;
							continue;
						}
					}
				}
				if(k==1)
				{
					printf("此人的信息如下:\n");
					printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi[k-1]].bianhao,"姓名",txl[weizhi[k-1]].xingming,"性别",txl[weizhi[k-1]].xingbie,"年龄",txl[weizhi[k-1]].nianling,"住宅电话",txl[weizhi[k-1]].zhuzhai);
					for(i=0;i<4;i++)
					{			
						if(txl[weizhi[k-1]].shouji[i][0]=='\0')
							break;
						printf("第%d个手机号码:%-17s\n",i+1,txl[weizhi[k-1]].shouji[i]);
					}
					printf("\n\n");
				}
				if(k>1)
				{
					printf("共找到%d个有此号码的人\n",k);
					for(k=k-1;k>=0;k--)
					{
						printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi[k]].bianhao,"姓名",txl[weizhi[k]].xingming,"性别",txl[weizhi[k]].xingbie,"年龄",txl[weizhi[k]].nianling,"住宅电话",txl[weizhi[k]].zhuzhai);
						for(i=0;i<4;i++)
						{			
							if(txl[weizhi[k]].shouji[i][0]=='\0')
								break;
							printf("第%d个手机号码:%-17s\n",i+1,txl[weizhi[k]].shouji[i]);
						}
						printf("\n\n");
					}
				}
				if(k==0)
				{
					printf("没有此人!");
				}
				system("pause");
				system("cls");
			}
			if(xz=='0')
				break;
		}
	}
}
void xiougai2(struct tongxunlu txl[],int e)				//修改主函数
{
	int i,j,k,weizhi[8];
	char xz,xuanxiang;
	char xingming[10];
	char *xuhao;
	if(e==0)
		puts("通讯录中没有成员，无法进行修改");
	else
	{
		puts("请输入要修改人的姓名");
		gets(xingming);
		for(i=0,k=0;i<e;i++)
		{
			if(strcmp(xingming,txl[i].xingming)==0)
			{
				weizhi[k]=i;
				k++;
			}
		}
		if(k==1)
		{
			printf("1)编号修改\n2)姓名修改\n3)性别和年龄修改\n4)住宅电话修改\n5)手机号码修改\n6)全部修改\n请选择:\n");
			xz=getchar();
			eatline();
			while(strchr("123456",xz)==NULL)
			{
				puts("请重新输入真确选项!  如 1、 2、 3、...");
				xz=getchar();
				eatline();
			}
			switch (xz)
			{
				case '1':system("cls");
						txl[weizhi[0]]=bhxiougai2(txl,e,weizhi[(int)xz-49]);
						break;
				case '2':system("cls");
						txl[weizhi[0]]=xmxiougai2(txl[weizhi[0]]);
						break;
				case '3':system("cls");
						txl[weizhi[0]]=xnxiougai2(txl[weizhi[0]]);
						break;
				case '4':system("cls");
						txl[weizhi[0]]=zzxiougai2(txl[weizhi[0]]);
						break;
				case '5':system("cls");
						txl[weizhi[0]]=sjxiougai2(txl[weizhi[0]]);
						break;
				case '6':system("cls");
						txl[weizhi[0]]=qbxiougai2(txl,e,weizhi[(int)xz-49]);
						break;
			}
		}
		if(k>1)
		{
			xuhao=(char *)malloc(sizeof(char)*k);
			for(i=0;i<k;i++)
				xuhao[i]=i+49;
			printf("共找到%d个有相同名字的人\n分别为:\n",k);
			for(i=0;i<k;i++)
			{
				printf("%d.\n",i+1);
				printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi[i]].bianhao,"姓名",txl[weizhi[i]].xingming,"性别",txl[weizhi[i]].xingbie,"年龄",txl[weizhi[i]].nianling,"住宅电话",txl[weizhi[i]].zhuzhai);
				for(j=0;j<4;j++)
				{			
					if(txl[weizhi[i]].shouji[j][0]=='\0')
						break;
					printf("第%d个手机号码:%-17s\n",j+1,txl[weizhi[i]].shouji[j]);
				}
				printf("\n\n");
			}
			printf("请输入要修改人上面的序号\n");
			xz=getchar();
			eatline();
			while(strchr(xuhao,xz)==NULL)
			{
				printf("请重新输入正确的序号,如1、2、...\n");
				xz=getchar();
				eatline();
			}
			system("cls");
			printf("选择了第%d个人进行修改\n其信息如下:\n",(int)xz-48);
			printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi[(int)xz-49]].bianhao,"姓名",txl[weizhi[(int)xz-49]].xingming,"性别",txl[weizhi[(int)xz-49]].xingbie,"年龄",txl[weizhi[(int)xz-49]].nianling,"住宅电话",txl[weizhi[(int)xz-49]].zhuzhai);
			for(j=0;j<4;j++)
			{
				if(txl[weizhi[(int)xz-49]].shouji[j][0]=='\0')
					break;
				printf("第%d个手机号码:%-17s\n",j+1,txl[weizhi[(int)xz-49]].shouji[j]);
			}
			printf("\n\n1)编号修改\n2)姓名修改\n3)性别和年龄修改\n4)住宅电话修改\n5)手机号码修改\n6)全部修改\n请选择:\n");
			xuanxiang=getchar();
			eatline();
			while(strchr("123456",xuanxiang)==NULL)
			{
				puts("请重新输入真确选项!  如 1、 2、 3、...");
				xuanxiang=getchar();
				eatline();
			}
			switch (xuanxiang)
			{
				case '1':system("cls");
						txl[weizhi[(int)xz-49]]=bhxiougai2(txl,e,weizhi[(int)xz-49]);
						break;
				case '2':system("cls");
						txl[weizhi[(int)xz-49]]=xmxiougai2(txl[weizhi[(int)xz-49]]);
						break;
				case '3':system("cls");
						txl[weizhi[(int)xz-49]]=xnxiougai2(txl[weizhi[(int)xz-49]]);
						break;
				case '4':system("cls");
						txl[weizhi[(int)xz-49]]=zzxiougai2(txl[weizhi[(int)xz-49]]);
						break;
				case '5':system("cls");
						txl[weizhi[(int)xz-49]]=sjxiougai2(txl[weizhi[(int)xz-49]]);
						break;
				case '6':system("cls");
						txl[weizhi[(int)xz-49]]=qbxiougai2(txl,e,weizhi[(int)xz-49]);
						break;
			}
			free(xuhao);
		}
		if(k==0)
			puts("没有此人!");
	}
}
struct tongxunlu bhxiougai2(struct tongxunlu txl[],int e,int weizhi)        //编号修改函数
{
	int i,flag,flag1;
	char bianhao[11],queren;
	while(1)
	{
		flag1=0;
		printf("请输入新的编号:\n");
		while(1)
		{
			flag=0;
			gets(bianhao);
			if(strcmp(bianhao,txl[weizhi].bianhao)!=0)
			{
				for(i=0;i<e;i++)
				{
					if(strcmp(bianhao,txl[i].bianhao)==0)
					{
						printf("编号重复，请重新输入编号!\n");
						flag++;
						break;
					}
				}
			}
			else
				break;
			if(flag==0)
				break;
		}
		printf("修改后此人的编号为: %13s\n是否确认修改？\n1)确认\n2)重新输入0)取消修改\n请选择:\n",bianhao);
		queren=getchar();
		eatline();
		while(strchr("120",queren)==NULL)
		{
			puts("请按提示输入正确选项!,请重新输入:");
			queren=getchar();
			eatline();
		}
		if(queren=='1')
			break;
		if(queren=='0')
		{
			flag1=1;
			break;
		}

	}
	if(flag1==0)
	{
		strcpy(txl[weizhi].bianhao,bianhao);
		printf("修改已完成!\n");
		return txl[weizhi];
	}
	else
	{
		puts("修改已取消");
		return txl[weizhi];
	}
}
struct tongxunlu xmxiougai2(struct tongxunlu txl)		 	 //姓名修改函数
{
	int flag;
	char xingming[10],queren;
	while(1)
	{
		flag=0;
		printf("请输入新的姓名:\n");
		gets(xingming);
		printf("新的姓名为: %11s\n是否确认修改？\n1)确认\n2)重新输入0)取消修改\n请选择:\n",xingming);
		queren=getchar();
		eatline();
		while(strchr("120",queren)==NULL)
		{
			puts("请按提示输入正确选项!,请重新输入:");
			queren=getchar();
			eatline();
		}
		if(queren=='1')
			break;
		if(queren=='0')
		{
			flag=1;
			break;
		}

	}
	if(flag==0)
	{
		strcpy(txl.xingming,xingming);
		printf("修改已完成!\n");
		return txl;
	}
	else
	{
		puts("修改已取消");
		return txl;
	}
}
struct tongxunlu xnxiougai2(struct tongxunlu txl)			 //性别年龄修改函数
{
	int nianling,flag;
	char xingbie[4],queren;
	while(1)
	{
		flag=0;
		printf("请输入新的性别\n");
		gets(xingbie);
		printf("请输入新的年龄\n");
		while(scanf("%d",&nianling)!=1)
		{
			fflush(stdin);
			puts("输入年龄有误,请重新输入正确数字");
//			scanf("%d",nianling);
		}
		fflush(stdin);
		printf("新的性别为: %4s，新的年龄为: %4d\n是否确认修改？\n1)确认\n2)重新输入0)取消修改\n请选择:\n",xingbie,nianling);
		queren=getchar();
		eatline();
		while(strchr("120",queren)==NULL)
		{
			puts("请按提示输入正确选项!,请重新输入:");
			queren=getchar();
			eatline();
		}
		if(queren=='1')
			break;
		if(queren=='0')
		{
			flag=1;
			break;
		}

	}
	if(flag==0)
	{	
		strcpy(txl.xingbie,xingbie);
		txl.nianling=nianling;
		puts("已完成修改!");
		return txl;
	}
	else
	{
		puts("修改已取消");
		return txl;
	}
}
struct tongxunlu zzxiougai2(struct tongxunlu txl)			 //住宅修改函数
{
	int flag;
	char zhuzhai[16],queren;
	if(txl.zhuzhai[0]=='\0')
	{
		puts("还没有此人住宅电话，请先去添加!");
		return txl;
	}
	else
	{
		while(1)
		{
			flag=0;
			printf("请输入新的住宅电话:\n");
			gets(zhuzhai);
			printf("新的住宅电话为: %17s\n是否确认修改？\n1)确认\n2)重新输入0)取消修改\n请选择:\n",zhuzhai);
			queren=getchar();
			eatline();
			while(strchr("120",queren)==NULL)
			{
				puts("请按提示输入正确选项!,请重新输入:");
				queren=getchar();
				eatline();
			}
			if(queren=='1')
				break;
			if(queren=='0')
			{
				flag=1;
				break;
			}

		}
		if(flag==0)
		{
			strcpy(txl.zhuzhai,zhuzhai);
			printf("修改已完成!\n");
			return txl;
		}
		else
		{
			puts("修改已取消");
			return txl;
		}
	}
}
struct tongxunlu sjxiougai2(struct tongxunlu txl)			 //手机修改函数
{
	int flag,flag1,i;
	char *xuhao;
	char xz,queren,shouji[16];
	struct tongxunlu mark;
	if(txl.sjgeshu==0)
	{
		printf("还没有此人的手机号码，请先去添加!\n");
		return txl;
	}
	else
	{
		mark=txl;
		xuhao=(char *)malloc(sizeof(char)*txl.sjgeshu);
		for(i=0;i<txl.sjgeshu;i++)
			xuhao[i]=i+49;
		while(1)
		{
			printf("一共有此人的%d个手机号码\n分别为:\n",txl.sjgeshu);
			for(i=0;i<txl.sjgeshu;i++)
			{
				printf("第%d个: %17s\n",i+1,txl.shouji[i]);
			}
			printf("请输入要修改哪一个:\n");
			flag1=0;
			flag=0;
			xz=getchar();
			eatline();
			while(strchr(xuhao,xz)==NULL)
			{
				puts("请输入正确的序号,如1、...,请重新输入:");
				xz=getchar();
				eatline();
			}
			printf("选择了修改第%d个手机号码，即:%17s\n是否确认?\n1)确认\n2)重新输入\n0)取消修改\n请选择:\n",(int)xz-48,txl.shouji[(int)xz-49]);
			queren=getchar();
			eatline();
			while(strchr("120",queren)==NULL)
			{
				puts("请按提示输入正确选项!,请重新输入:");
				queren=getchar();
				eatline();
			}
			if(queren=='2')
				system("cls");
			if(queren=='1')
				break;
			if(queren=='0')
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			while(1)
			{
				flag1=0;
				printf("请输入新的手机号码:\n");
				gets(shouji);
				printf("新的手机号码为: %17s\n是否确认修改？\n1)确认\n2)重新输入\n0)取消修改\n请选择:\n",shouji);
				queren=getchar();
				eatline();
				while(strchr("120",queren)==NULL)
				{
					puts("请按提示输入正确选项!,请重新输入:");
					queren=getchar();
					eatline();
				}
				if(queren=='1')
					break;
				if(queren=='0')
				{
					flag1=1;
					break;
				}

			}
			if(flag1==0)
			{
				strcpy(txl.shouji[(int)xz-49],shouji);
				printf("修改已完成!\n");
				free(xuhao);
				return txl;
			}
			if(flag1==1)
			{
				printf("修改已取消!\n");
				free(xuhao);
				return txl;
			}
		}
		else
		{
			puts("修改已取消");
			free(xuhao);
			return txl;
		}
	}
	return mark;
}
struct tongxunlu qbxiougai2(struct tongxunlu txl[],int e,int weizhi)			 //全部修改函数
{
	int i,flag,flag2;
	char zzxz,sjxz,queren;
	struct tongxunlu xtxl;
	xtxl.sjgeshu=0;
	xtxl.zhuzhai[0]='\0';
	for(i=0;i<4;i++)
	{
		xtxl.shouji[i][0]='\0';
	}
	while(1)
	{
		flag2=0;
		puts("现在请输入新的编号:");
		while(1)
		{
			flag=0;
			gets(xtxl.bianhao);
			for(i=0;i<e;i++)
			{
				if(strcmp(xtxl.bianhao,txl[i].bianhao)==0)
				{
					printf("与现有人员编号相重，请重新输入编号\n");
					flag++;
				}
			}
			if(flag==0)
				break;
		}
		printf("现在请输入该朋友的姓名\n");
		gets(xtxl.xingming);
		printf("现在请输入该朋友的性别\n");
		gets(xtxl.xingbie);
		puts("现在请输入该朋友的年龄");
		while(scanf("%d",&xtxl.nianling)!=1)
		{
			fflush(stdin);
			puts("输入年龄有误,请重新输入正确数字:");
//			scanf("%d",&xtxl.nianling);
		}
		fflush(stdin);
		printf("是否有该朋友的住宅电话?\n输入 y 有,输入 n 无\n");
		zzxz=getchar();
		eatline();
		while(strchr("yn",zzxz)==NULL)
		{
			puts("请输入正确的选项,如 y 、 n,请重新输入:");
			zzxz=getchar();
			eatline();
		}
		fflush(stdin);
		if(zzxz=='y')
		{
			puts("现在请输入该朋友的住宅电话号码");
			gets(xtxl.zhuzhai);
			fflush(stdin);
		}
		printf("是否有该朋友的手机号码?\n输入 y 有,输入 n 无\n");
		sjxz=getchar();
		eatline();
		while(strchr("yn",sjxz)==NULL)
		{
			puts("请输入正确的选项,如 y 、 n,请重新输入:");
			sjxz=getchar();
			eatline();
		}
		fflush(stdin);
		if(sjxz=='y')
		{
			
			for(i=0;i<4;i++)
			{
				printf("现在请输入该朋友的第%d个手机号码:\n",i+1);
				gets(xtxl.shouji[i]);
				xtxl.sjgeshu++;
				if(i!=3)	
				{
					printf("是否有该朋友的第%d个手机号码?\n输入 y 有,输入 n 无\n",i+2);
					sjxz=getchar();
					fflush(stdin);
					while(strchr("yn",sjxz)==NULL)
					{
						puts("请输入正确的选项,如 y 、 n,请重新输入:");
						sjxz=getchar();
						fflush(stdin);
					}
					fflush(stdin);
				}
				if(i==3)
				{
					puts("手机号码存储个数达到最大，无法继续添加!");
				}
				if(sjxz=='n')
					break;
			}
		}
		system("pause");
		system("cls");
		printf("该朋友的通讯录，录入完毕\n以下是该朋友的通讯录全貌:\n");
		printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",xtxl.bianhao,"姓名",xtxl.xingming,"性别",xtxl.xingbie,"年龄",xtxl.nianling,"住宅电话",xtxl.zhuzhai);
		for(i=0;i<4;i++)
		{
			if(xtxl.shouji[i][0]=='\0')
				break;
			printf("第%d个手机号码:%-17s\n",i+1,xtxl.shouji[i]);
		}
		printf("是否确认修改？\n1)确认\n2)重新输入0)取消修改\n请选择:\n");
		queren=getchar();
		eatline();
		while(strchr("120",queren)==NULL)
		{
			puts("请输入正确选项,请重新输入:");
			queren=getchar();
			eatline();
		}
		if(queren=='1')
			break;
		if(queren=='0')
		{
			flag2=1;
			break;
		}
	}
	if(flag2==0)
	{
		puts("修改已完成");
		return xtxl;
	}
	else
	{
		puts("修改已取消");
		return txl[weizhi];
	}
}
int shanchu2(struct tongxunlu txl[],int e)				//删除主函数
{
	int i,j,weizhi[8],k,q=e;
	char xz,xingming[10],bianhao[11],xh,*xuhao,xz1;
	while(1)
	{
		for(i=0;i<8;i++)
			weizhi[i]=-1;
		printf("1)按编号查找删除对象\n2)按姓名查找删除对象\n0)退出\n请选择:\n");
		xz1=getchar();
		fflush(stdin);
		while(strchr("120",xz1)==NULL)
		{
			puts("请输入正确选项!,请重新输入:");
			xz1=getchar();
			fflush(stdin);
		}
		system("cls");
		if(xz1=='0')
			break;
		if(xz1=='1')
		{
			printf("请输入要删除人的编号:\n");
			gets(bianhao);
			for(i=0;i<e;i++)
			{
				if(strcmp(bianhao,txl[i].bianhao)==0)
				{
					weizhi[0]=i;
					break;
				}
			}
			if(weizhi[0]==-1)
				puts("没有此人");
			if(weizhi[0]!=-1)
			{
				system("cls");
				printf("此人的信息如下:\n");
				printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi[0]].bianhao,"姓名",txl[weizhi[0]].xingming,"性别",txl[weizhi[0]].xingbie,"年龄",txl[weizhi[0]].nianling,"住宅电话",txl[weizhi[0]].zhuzhai);
				for(j=0;j<4;j++)
				{		
					if(txl[weizhi[0]].shouji[j][0]=='\0')
						break;
					printf("第%d个手机号码:%-17s\n",j+1,txl[weizhi[0]].shouji[j]);
				}
				printf("\n\n1)住宅电话删除\n2)手机号码删除\n3)全部删除\n请选择:\n");
				xz=getchar();
				fflush(stdin);
				while(strchr("123",xz)==NULL)
				{
					puts("输入有误，请重新输入正确选项");
					xz=getchar();
					fflush(stdin);
				}
				switch(xz)
				{
					case '1':system("cls");
							zzshanchu2(txl,weizhi[0]);system("pause");system("cls");break;
					case '2':system("cls");
							sjshanchu2(txl,weizhi[0]);system("pause");system("cls");break;
					case '3':system("cls");
							q=qbshanchu2(txl,weizhi[0],e);system("pause");system("cls");break;
				}
			}
		}
		if(xz1=='2')
		{
			printf("请输入要删除人的姓名\n");
			gets(xingming);
			for(i=0,k=0;i<e;i++)
			{
				if(strcmp(xingming,txl[i].xingming)==0)
				{
					weizhi[k]=i;
					k++;
				}
			}
			if(k==0)
				puts("没有此人");
			if(k==1)
			{
				system("cls");
				printf("此人的信息如下:\n");
				printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi[0]].bianhao,"姓名",txl[weizhi[0]].xingming,"性别",txl[weizhi[0]].xingbie,"年龄",txl[weizhi[0]].nianling,"住宅电话",txl[weizhi[0]].zhuzhai);
				for(j=0;j<4;j++)
				{		
					if(txl[weizhi[0]].shouji[j][0]=='\0')
						break;
					printf("第%d个手机号码:%-17s\n",j+1,txl[weizhi[0]].shouji[j]);
				}
				printf("\n\n1)住宅电话删除\n2)手机号码删除\n3)全部删除\n请选择:\n");
				xz=getchar();
				fflush(stdin);
				while(strchr("123",xz)==NULL)
				{
					puts("输入有误，请重新输入正确选项");
					xz=getchar();
					fflush(stdin);
				}
				switch(xz)
				{
				case '1':system("cls");
						zzshanchu2(txl,weizhi[0]);system("pause");system("cls");break;
				case '2':system("cls");
						sjshanchu2(txl,weizhi[0]);system("pause");system("cls");break;
				case '3':system("cls");
						q=qbshanchu2(txl,weizhi[0],e);system("pause");system("cls");break;
				}
			}
			if(k>1)
			{
				xuhao=(char *)malloc(sizeof(char)*k);
				for(i=0;i<k;i++)
					xuhao[i]=i+49;
				printf("共有%d个重名的人\n分别为:\n",k);
				for(i=0;i<k;i++)
				{
					printf("第%d.\n",i+1);
					printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi[i]].bianhao,"姓名",txl[weizhi[i]].xingming,"性别",txl[weizhi[i]].xingbie,"年龄",txl[weizhi[i]].nianling,"住宅电话",txl[weizhi[i]].zhuzhai);
					for(j=0;j<4;j++)
					{			
						if(txl[weizhi[i]].shouji[j][0]=='\0')
							break;
						printf("第%d个手机号码:%-17s\n",j+1,txl[weizhi[i]].shouji[j]);
					}
					printf("\n\n");
				}
				printf("请输入要删除人上面的序号:\n");
				xh=getchar();
				fflush(stdin);
				while(strchr(xuhao,xh)==NULL)
				{
					printf("输入有误，请重新上输入正确的序号\n如 1、2、 ...\n");
					xh=getchar();
					fflush(stdin);
				}
				system("cls");
				printf("此人的信息如下:\n");
				printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","编号",txl[weizhi[(int)xh-49]].bianhao,"姓名",txl[weizhi[(int)xh-49]].xingming,"性别",txl[weizhi[(int)xh-49]].xingbie,"年龄",txl[weizhi[(int)xh-49]].nianling,"住宅电话",txl[weizhi[(int)xh-49]].zhuzhai);
				for(j=0;j<4;j++)
				{		
					if(txl[weizhi[(int)xh-49]].shouji[j][0]=='\0')
						break;
					printf("第%d个手机号码:%-17s\n",j+1,txl[weizhi[(int)xh-49]].shouji[j]);
				}
				printf("\n\n1)住宅电话删除\n2)手机号码删除\n3)全部删除\n请选择:\n");
				xz=getchar();
				fflush(stdin);
				free(xuhao);
				while(strchr("123",xz)==NULL)
				{
					puts("输入有误，请重新输入正确选项");
					xz=getchar();
					fflush(stdin);
				}
				switch(xz)
				{
				case '1':system("cls");
						zzshanchu2(txl,weizhi[(int)xh-49]);system("pause");system("cls");
						break;
				case '2':system("cls");
						sjshanchu2(txl,weizhi[(int)xh-49]);system("pause");system("cls");
						break;
				case '3':system("cls");
						q=qbshanchu2(txl,weizhi[(int)xh-49],e);system("pause");system("cls");break;
				}
			}
		}
	}
	return q;
}
void zzshanchu2(struct tongxunlu *txl,int weizhi)				//住宅号码删除函数
{
	char xz;
	if(txl[weizhi].zhuzhai[0]=='\0')
		puts("没有此人住宅电话,无法删除");
	else
	{
		printf("此人的住宅电话为: %17s\n是否删除?\ny)删除\nn)取消\n请选择:\n",txl[weizhi].zhuzhai);
		xz=getchar();
		fflush(stdin);
		while(strchr("yn",xz)==NULL)
		{
			puts("输入有误,请重新输入正确选项:");
			xz=getchar();
			fflush(stdin);
		}
		if(xz=='y')
		{
			txl[weizhi].zhuzhai[0]='\0';
			printf("完成删除\n");
		}
		else
			puts("已取消删除");
	}
}
void sjshanchu2(struct tongxunlu *txl,int weizhi)				//手机号码删除函数
{
	int i,j;
	char *xuhao;
	char xz,queren;
	if(txl[weizhi].sjgeshu==0)
	{
		printf("没有此人手机号码,无法删除\n");
	}
	else
	{
		xuhao=(char *)malloc(sizeof(char)*txl[weizhi].sjgeshu);
		for(i=0;i<txl[weizhi].sjgeshu;i++)
			xuhao[i]=i+49;
		printf("共有%d个此人号码\n分别为:\n",txl[weizhi].sjgeshu);
		for(i=0;i<txl[weizhi].sjgeshu;i++)
		{
			printf("第%2d:%17s\n",i+1,txl[weizhi].shouji[i]);
		}
		printf("请输入要删除第几个号码:\n");
		xz=getchar();
		fflush(stdin);
		while(strchr(xuhao,xz)==NULL)
		{
			puts("输入有误，请输入正确的序号。如 1 ");
			xz=getchar();
			fflush(stdin);
		}
		free(xuhao);
		printf("要删除的手机号码为: %17s\n是否删除?\ny)删除\nn)取消\n请选择:\n",txl[weizhi].shouji[(int)xz-49]);
		queren=getchar();
		fflush(stdin);
		while(strchr("yn",queren)==NULL)
		{
			puts("输入有误，请输入正确的选项");
			queren=getchar();
			fflush(stdin);
		}
		if(queren=='y')
		{
			txl[weizhi].shouji[(int)xz-49][0]='\0';
			txl[weizhi].sjgeshu--;
			for(i=0,j=(int)xz-49;i<(txl[weizhi].sjgeshu-((int)xz-48));i++)
			{
				strcpy(txl[weizhi].shouji[i],txl[weizhi].shouji[i+1]);
			}
			puts("已完成删除");
		}
		if(queren=='n')
			puts("已取消删除");
	}
}
int qbshanchu2(struct tongxunlu *txl,int weizhi,int e)				//全部删除函数
{
	char xz;
	printf("是否全部删除?\ny)删除\nn)取消\n请选择:\n");
	xz=getchar();
	fflush(stdin);
	while(strchr("yn",xz)==NULL)
	{
		puts("输入有误,请重新输入正确选项:");
		xz=getchar();
		fflush(stdin);
	}
	if(xz=='y')
	{
		for(;weizhi<e-1;weizhi++)
		{
			txl[weizhi]=txl[weizhi+1];
		}
		puts("已完成删除");
		return e-1;
	}
	else
	{
		puts("已取消删除");
		return e;
	}
}




				







	








		



		



	
