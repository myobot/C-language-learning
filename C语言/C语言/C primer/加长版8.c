#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void hbmenu(void);
void cdmenu(void);
void eatline(void);
void member(FILE *fp,int x);
void elist(FILE *fp,int x,int p[],int y[]);
void alist(FILE *fp,int x);
void assign(FILE *fp,int weizhi);
void Delete(FILE *fp,int weizhi);
struct seat
{
	char hao;
	char biao;
	char keren[20];
};
struct hangban
{
	char hhao[4];
	struct seat seats[12];
};
int main()
{
	int flag=0,flag1,flag2=0;
	int hbwz;
	int p[12],y[1];
	FILE *fp;
	char hbxz,cdxz;
	char hb[4][4]={{"102"},{"311"},{"444"},{"519"}};
	if((fp=fopen("seat2.txt","r+"))==NULL)
	{
		puts("打开文件失败!");
		exit(1);
	}
	while(1)
	{
		hbmenu();
		puts("请输入要选择的航班对应序号");
		hbxz=getchar();
		eatline();
		while(strchr("12340",hbxz)==NULL)
		{
			puts("输入有误，请输入正确选项，例如 1 , 2 , 3 , 4 , 0");
			hbxz=getchar();
			eatline();
		}
		if(hbxz=='0')
		{
			break;
		}
		else
		{
			hbwz=(int)hbxz-49;
			system("pause");
			system("cls");
			while(1)
			{
				flag1=0;flag2=0;
				printf("欢迎登陆巨人航空公司售票系统\n您选择了第 %s 航班\n",hb[hbwz]);
				cdmenu();
				puts("请输入选项");
				cdxz=tolower(getchar());
				eatline();
				while(strchr("abcdefg",cdxz)==NULL)
				{
					puts("输入有误，请输入正确选项，例如 a , b , c , d , e , f, g");
					cdxz=tolower(getchar());
					eatline();
				}
				switch(cdxz)
				{
					case 'a':member(fp,hbwz);break;
					case 'b':elist(fp,hbwz,p,y);break;
					case 'c':alist(fp,hbwz);break;
					case 'd':assign(fp,hbwz);break;
					case 'e':Delete(fp,hbwz);break;
					case 'f':flag1++;break;//退出到航班选择
					case 'g':flag2++;break;//退出程序
				}
				fflush(stdin);
				system("pause");
				system("cls");
				if(flag1>0)
					break;
				if(flag2>0)
					break;
			}
		}
		if(flag2>0)
			break;
	}
	puts("再见");
	if(fclose(fp)!=0)
	{
		printf("关闭文件失败\n");
	}
	return 0;
}
void hbmenu(void)
{
	char hb[4][4]={{"102"},{"311"},{"444"},{"519"}};
	int i;
	for(i=0;i<4;i++)
	{
		printf("%d>: %s 航班\n",i+1,hb[i]);
	}
	printf("0>: 退出程序\n");
}
void cdmenu(void)
{
	printf("a)空座位数\nb)空座位列表\nc)已预订座位列表\nd)预定座位\ne)取消预定\nf)退出到航班选择菜单\ng)退出程序\n");
}
void eatline(void)
{
	while(getchar()!='\n')
		continue;
}
void member(FILE *fp,int x)
{
	struct hangban hhangban;
	int i,j=0;
	rewind(fp);
	fseek(fp,sizeof(struct hangban)*x,0);
	fread(&hhangban,sizeof(struct hangban),1,fp);
	for(i=0;i<12;i++)
	{
		if(hhangban.seats[i].biao=='0')
			j++;
	}
	printf("一共有%d个空座位\n",j);
}
void elist(FILE *fp,int x,int p[],int y[])
{
	struct hangban hhangban;
	int i,j=0,flag=0;
	rewind(fp);
	fseek(fp,sizeof(struct hangban)*x,0);
	fread(&hhangban,sizeof(struct hangban),1,fp);
	printf("目前空位子有:\n");
	for(i=0;i<12;i++)
	{
		if(hhangban.seats[i].biao=='0')
		{
			p[j]=i;
			j++;
			y[0]=j;
			printf("第%2d位   ",i+1);
		//	flag++;
			if(++flag%6==0)
				printf("\n");
		}
	}
}
void alist(FILE *fp,int x)
{
	struct hangban hhangban;
	int i,as[12],j=0;
	char ke[12][10];
	rewind(fp);
	fseek(fp,sizeof(struct hangban)*x,0);
	fread(&hhangban,sizeof(struct hangban),1,fp);
	for(i=0;i<12;i++)
	{
		if(hhangban.seats[i].biao=='1')
		{
			as[j]=i;
			strcpy(ke[j],hhangban.seats[i].keren);
			j++;
		}
	}
	if(j==0)
	{
		printf("所有座位都还没有被预定!\n");
	}
	else
	{
		printf("已经预定的座位有:\n");
		for(i=0;i<j;i++)
		{
			printf("第%d位  %s \n",as[i]+1,ke[i]);
		}
	}
}
void assign(FILE *fp,int weizhi)
{
	struct hangban hhangban;
	struct seat sseat;
	int x,p[12],y[1],i,flag,flag1=0,j=0;
	char queren,xingming[20];
	char hb[4][4]={{"102"},{"311"},{"444"},{"519"}};
	elist(fp,weizhi,p,y);
	rewind(fp);
	fseek(fp,sizeof(struct hangban)*weizhi,0);
	fread(&hhangban,sizeof(struct hangban),1,fp);
	printf("\n请输入您要预定的座位号\n");
	while(1)
	{
		flag=0;
		if(scanf("%d",&x)!=1||(x<=0||x>12))
		{
			printf("请输入正确的座位号,请重新输入\n");
			continue;
		}
		for(i=0;i<=y[0];i++)
		{
			if((x-1)==p[i])
			{
				flag++;
				break;
			}
		}
		if(flag>0)
		{
			printf("您要预定的座位号为%d\n是否确认？，确认请输入 y ，取消预定输入 n \n",x);
			eatline();
			while(1)
			{
				queren=getchar();
				eatline();
				if(queren=='y')
				{
					printf("现在请输入您的身份信息\n请输入您的姓名:\n");
					gets(xingming);
					for(i=0;i<12;i++)
					{
						if(strcmp(xingming,hhangban.seats[i].keren)==0)
						{
							flag1=1;
							break;
						}
					}
					if(1==flag1)
					{
						printf("您已经预订座位了，请不要重复预定!\n");
						break;
					}
					if(0==flag1)
					{
						strcpy(sseat.keren,xingming);
						sseat.biao='1';
						fseek(fp,sizeof(struct hangban)*weizhi+sizeof(char)*4+sizeof(struct seat)*(x-1),0);
						fwrite(&sseat,sizeof(struct seat),1,fp);
						printf("您已成功预定了 %s 航班的第 %d 座位！\n",hb[weizhi],x);
						break;
					}
				}
				if(queren=='n')
				{
					printf("您取消了预定\n");
					break;
				}
				else
					puts("请输入 y 或 n ,确认或取消预定");
			}
			break;
		}
		if(flag==0)
			printf("该座位已经被预定，请预定上述空座位\n");
	}
}
void Delete(FILE *fp,int weizhi)
{
	struct hangban hhangban;
	int x=0;
	int i;
	char xingming[20];
	char ch,biao='0';
	rewind(fp);
	fseek(fp,sizeof(struct hangban)*weizhi,0);
	fread(&hhangban,sizeof(struct hangban),1,fp);
	puts("请输入您的姓名");
	gets(xingming);
	for(i=0;i<12;i++)
	{
		if(strcmp(xingming,hhangban.seats[i].keren)==0)
		{
			x=i+1;
			break;
		}
	}
	if(x==0)
		puts("您没有预订座位");
	else
	{
		printf("您预定的是第 %d 位\n您是否想要取消预定？ 输入 y 取消预定，输入 n 不取消预定\n",x);
		while(1)
		{
			ch=getchar();
			eatline();
			if(ch=='y')
			{
				fseek(fp,sizeof(struct hangban)*weizhi+sizeof(char)*4+sizeof(struct seat)*(x-1)+sizeof(char),0);
				fwrite(&biao,sizeof(char),1,fp);
				puts("您已成功取消预定!");
				break;
			}
			if(ch=='n')
			{
				puts("感谢您选择我们！");
				break;
			}
			else
				puts("请输入 y 或 n");
		}
	}
}





				

