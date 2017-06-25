#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char zqsr(char *c);
struct shebei * luru(struct shebei *head);
void shuchu(struct shebei *head,int e);
int lioulan(struct shebei *head);
void xiougai(struct shebei *head);
void poyi(struct shebei *head);
void zonghaofei(struct shebei *head);
void yisun(struct shebei *head);
void chaxun(struct shebei *head);
struct shebei
{
	char bianhao[10];
	char zhonglei[16];
	char mingcheng[16];
	int jiage;
	char riqi[16];
	char mark;
	char briqi[16];
	struct shebei *next;
};
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
	int i,flag;
	char xz;
	struct shebei *head=NULL;
	struct shebei *prve,*creat,jishu;
	FILE *fp;
	if((fp=fopen("shebei.txt","r+b"))==NULL)
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	i=0;
	while(fread(&jishu,sizeof(struct shebei),1,fp)==1)
	{
		i++;
		creat=(struct shebei *)malloc(sizeof(struct shebei));
		if(head==NULL)
			head=creat;
		else
			prve->next=creat;
		*creat=jishu;
		creat->next=NULL;
		prve=creat;
	}
	while(1)
	{
		flag=0;
		printf("1)录入设备\n\n2)修改设备\n\n3)破损耗费,遗损处理\n\n4)统计\n\n5)查询\n\n6)浏览\n\n0)退出\n\n请选择:\n");
		xz=zqsr("1234560");
		switch(xz)
		{
		case '1':system("cls");
				head=luru(head);system("pause");system("cls");break;
		case '2':system("cls");
				xiougai(head);system("pause");system("cls");break;
		case '3':system("cls");
				poyi(head);system("pause");system("cls");break;
//		case '4':
		case '5':system("cls");
				chaxun(head);system("pause");system("cls");break;
		case '6':system("cls");
				lioulan(head);system("pause");system("cls");break;
		case '0':flag++;break;
		}
		fflush(stdin);
		if(flag>0)
			break;
	}
	prve=head;
	if(fclose(fp)!=0)
	{
		printf("第一次关闭文件失败!\n");
		exit(1);
	}
	if((fp=fopen("shebei.txt","w+b"))==NULL)
	{
		printf("第二次打开文件失败!\n");
		exit(2);
	}
	while(prve!=NULL)
	{
		fwrite(&*prve,sizeof(struct shebei),1,fp);
		prve=prve->next;
	}
	if(fclose(fp)!=0)
		printf("第二次关闭文件失败\n");
	printf("拜拜\n");
	return 0;
}
void shuchu(struct shebei *head,int e)
{
	int i;
	struct shebei *prve;
	prve=head;
	for(i=0;i<e;i++)
	{
		printf("%12s%12s\n%12s%12s\n%12s%12s\n%12s%12d\n%12s%12s\n%12s","编号: ",prve->bianhao,"设备名称: ",prve->mingcheng,"设备种类: ",prve->zhonglei,"购入价格: ",prve->jiage,"购入日期: ",prve->riqi,"是否报废: ");
		if(prve->mark=='1')
		{
			printf("%12s\n%12s%12s\n\n","是","报废日期: ",prve->briqi);
		}
		if(prve->mark=='0')
			printf("%12s\n\n\n","否");
		prve=prve->next;
	}
}
struct shebei * luru(struct shebei *head)
{
	int flag,flag1,flag2;
	struct shebei *prve,*creat;
	char xz,xz1,xz2,xz3,xz4;
	while(1)
	{
		flag=0;flag1=0;flag2=0;
		creat=(struct shebei *)malloc(sizeof(struct shebei));
		printf("请输入要录入的设备的编号:\n");
		gets(creat->bianhao);
		prve=head;
		while(prve==NULL)
		{
			if(strcmp(prve->bianhao,creat->bianhao)==0)
			{	
				flag2++;
				printf("与已有编号重复，请重新输入编号\n");
				break;
			}
			prve=prve->next;
		}
		if(flag2>0)
		{
			system("cls");continue;
		}
		printf("输入的编号为:%s\n\n是否确认?\n\n1)确认\n\n2)重新输入\n\n0)退出到主菜单\n\n请选择:\n",creat->bianhao);
		xz=zqsr("120");
		if(xz=='0')
		{
			free(creat);break;
		}
		if(xz=='2')
		{
			system("cls");continue;
		}
		else
		{
			while(1)
			{
				system("cls");
				printf("现在请输入该设备的名称;\n");
				gets(creat->mingcheng);
				printf("输入的名称为:%s\n\n是否确认?\n\n1)确认\n\n0)重新输入\n\n\n\n请选择:\n",creat->mingcheng);
				xz1=zqsr("10");
				if(xz1=='0')
				{
					system("cls");continue;
				}
				else
				{
					system("cls");
					printf("现在请输入该设备的种类:\n");
					gets(creat->zhonglei);
					printf("输入的种类名为:%s\n\n是否确认?\n\n1)确认\n\n0)重新输入\n\n\n\n请选择:\n",creat->zhonglei);	
					xz2=zqsr("10");
					if(xz2=='0')
					{
						system("cls");continue;
					}
					else
					{
						system("cls");
						printf("现在请输入该设备的价格:\n");
						while(scanf("%d",&creat->jiage)!=1||(creat->jiage<0))
						{
							fflush(stdin);
							printf("输入有误,请输入正确的价格!\n");
							fflush(stdin);
						}
						fflush(stdin);
						system("cls");
						printf("现在请输入该设备的购入日期:\n");
						gets(creat->riqi);
						system("cls");
						printf("该设备是否报废?\n\n1)已报废\n\n2)未报废\n\n请选择:\n");
						xz3=zqsr("12");
						if(xz3=='1')
						{
							printf("请输入该设备的报废日期:\n");
							gets(creat->briqi);
							creat->mark='1';
						}
						if(xz3=='2')
							creat->mark='0';
						system("cls");
						printf("录入的设备信息如下:\n\n");
						shuchu(creat,1);
						printf("是否确认?\n\n1)确认\n\n0)重新录入\n\n请选择:\n");
						xz4=zqsr("10");
						if(xz4=='0')
						{	
							system("cls");flag1++;break;
						}
						if(xz4=='1')
						{
							if(head==NULL)
							{	
								head=creat;
								creat->next=NULL;
							}
							else
							{
								prve=head;
								while(prve->next!=NULL)
								{	
									prve=prve->next;
								}
								creat->next=NULL;
								prve->next=creat;
							}
							printf("录入已完成!\n");
							break;
												
						}
					}
				}
				break;
			}
		}
		if(flag1>0)
				continue;
		break;
	}
	return (head);
}
int lioulan(struct shebei *head)
{
	int i=0;
	struct shebei *prve;
	prve=head;
	while(prve!=NULL)
	{
		printf("%d.\n%12s%12s\n%12s%12s\n%12s%12s\n%12s%12d\n%12s%12s\n%12s",i+1,"编号: ",prve->bianhao,"设备名称: ",prve->mingcheng,"设备种类: ",prve->zhonglei,"购入价格: ",prve->jiage,"购入日期: ",prve->riqi,"是否报废: ");
		if(prve->mark=='1')
		{
			printf("%12s\n%12s%12s\n\n","是","报废日期: ",prve->briqi);
		}
		if(prve->mark=='0')
			printf("%12s\n\n\n","否");
		i++;
		prve=prve->next;
	}
	printf("共计%3d个设备\n",i);
	return i;
}
void xiougai(struct shebei *head)
{
	int weizhi,i;
	char xz,xz1,xz2,xz3;
	struct shebei *prve;
	struct shebei genggai;
	while(1)
	{
		i=0;
		prve=head;
		while(prve!=NULL)
		{
			printf("第%d个设备:\n%s\n\n",i+1,prve->mingcheng);
			i++;
			prve=prve->next;
		}
		if(i==0)
		{
			printf("还没有任何设备!,请先去录入!\n");
			break;
		}
		printf("请输入要修改的设备的序号:\n");
		while(scanf("%d",&weizhi)!=1||weizhi<0||weizhi>i)
		{
			fflush(stdin);printf("请输入正确的序号,请重新输入\n");
		}
		prve=head;
		for(i=0;i<weizhi-1;i++)
			prve=prve->next;
		fflush(stdin);
		system("cls");
		printf("选择的是第%d个设备,即%s\n\n是否确认?\n\n1)确认\n\n2)重新选择\n\n0)退回到主菜单\n\n请选择:\n",weizhi,prve->mingcheng);
		xz=zqsr("120");
		if(xz=='0')
			break;
		if(xz=='2')
		{
			system("cls");continue;
		}
		if(xz=='1')
		{
			while(1)
			{
				system("cls");
				printf("现在请输入该设备的编号;\n");
				gets(genggai.bianhao);
				printf("现在请输入该设备的名称:\n");
				gets(genggai.mingcheng);
				printf("现在请输入该设备的种类:\n");
				gets(genggai.zhonglei);
				printf("现在请输入该设备的价格\n");
				while(scanf("%d",&genggai.jiage)!=1||genggai.jiage<0)
				{
					printf("输入有误,请输入正确的数字,请重新输入\n");
					fflush(stdin);
				}
				fflush(stdin);
				printf("现在请输入该设备的购入日期\n");
				gets(genggai.riqi);
				printf("该设备是否报废?\n\n1)已报废\n\n2)未报废\n\n请选择:\n");
				xz3=zqsr("12");
				if(xz3=='1')
				{
					printf("请输入该设备的报废日期:\n");
					gets(genggai.briqi);
					genggai.mark='1';
				}
				if(xz3=='2')
					genggai.mark='0';
				system("cls");
				printf("录入的设备信息如下:\n\n");
				shuchu(&genggai,1);
				printf("是否确认?\n\n1)确认\n\n0)重新录入\n\n请选择:\n");
				xz2=zqsr("10");
				if(xz2=='0')
					continue;
				if(xz2=='1')
				{
					genggai.next=prve->next;
					*prve=genggai;
					printf("更改已完成\n");
					break;
				}
			}
		}
		system("cls");
		printf("是否还要更改其他设备?\n\n1)更改其他设备\n\n0)退出到主菜单\n\n请选择:\n");
		xz1=zqsr("10");
		if(xz1=='1')
		{
			system("cls");continue;
		}
		else
			break;
	}
}
void poyi(struct shebei *head)
{
	char xz;
	int flag=0;
	while(1)
	{
		printf("1)查看总耗费\n\n2)遗损处理\n\n0)退出到主菜单\n\n请选择:\n");
		xz=zqsr("120");
		switch(xz)
		{
		case '1':system("cls");
				zonghaofei(head);system("pause");system("cls");break;
		case '2':system("cls");
				yisun(head);system("pause");system("cls");break;
		case '0':flag++;break;
		}
		if(flag>0)
			break;
	}
}
void zonghaofei(struct shebei *head)
{
	int i=0,sum=0,j=0;
	struct shebei *prve;
	prve=head;
	while(prve!=NULL)
	{
		if(prve->mark=='1')
		{
			printf("第%d个报废设备 : %s\n\n",j+1,prve->mingcheng);
			j++;
		}
		i++;
		prve=prve->next;
	}
	printf("共计%d个报废设备\n",j);
}
void yisun(struct shebei *head)
{
	int i=0,weizhi,j;
	char xz;
	struct shebei *prve,*qianyige;
	while(1)
	{
		j=lioulan(head);
		printf("请输入要移除的设备的序号\n");
		while(scanf("%d",&weizhi)!=1||weizhi<0||weizhi>j)
		{
			printf("请输入正确的序号,请重新输入\n");
			fflush(stdin);
		}
		fflush(stdin);
		prve=head;
		for(i=0;i<weizhi-1;i++)
			prve=prve->next;
		system("cls");
		printf("选择移除的是第%d个设备,名称为: %s\n\n是否确认?\n\n1)确认\n\n2)重新选择\n\n0)退出到上一层菜单\n\n请选择:\n",weizhi,prve->mingcheng);
		xz=zqsr("120");
		if(xz=='0')
			break;
		if(xz=='2')
		{
			system("cls");continue;
		}
		if(xz=='1')
		{
			prve=head;
			if(weizhi==1)
			{
				head=NULL;
				free(prve);
			}
			else
			{
				for(i=0;i<weizhi-2;i++)
				{
					prve=prve->next;
				}
				qianyige=prve;
				prve=prve->next;
				qianyige->next=prve->next;
				free(prve);
				printf("移除成功\n");
				break;
			}
		}
	}
}
void chaxun(struct shebei *head)
{
	int i=0,j=0,weizhi;
	struct shebei *prve;
	prve=head;
	while(prve!=NULL)
	{
		printf("第%d个设备: %s\n",i+1,prve->mingcheng);
		i++;
		prve=prve->next;
	}
	printf("请输入要查找的设备的序号:\n");
	while(scanf("%d",&weizhi)!=1||weizhi<0||weizhi>i)
	{
		printf("输入有误，请重新输入正确的序号\n");
		fflush(stdin);
	}
	fflush(stdin);
	system("cls");
	printf("该设备的信息如下:\n");
	prve=head;
	for(i=0;i<weizhi-1;i++)
		prve=prve->next;
	printf("%12s%12s\n%12s%12s\n%12s%12s\n%12s%12d\n%12s%12s\n%12s","编号: ",prve->bianhao,"设备名称: ",prve->mingcheng,"设备种类: ",prve->zhonglei,"购入价格: ",prve->jiage,"购入日期: ",prve->riqi,"是否报废: ");
	if(prve->mark=='1')
	{
		printf("%12s\n%12s%12s\n\n","是","报废日期: ",prve->briqi);
	}
	if(prve->mark=='0')
		printf("%12s\n\n\n","否");
}
	
		
			


	







