#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
char zqsr(char *c);						//检测输入选项正确与否
void wuzhanghao(void);					//无账号输入主函数
void zhanghao(void);
void zhuce(void);
void mimawangji(void);
void mimaxiougai(struct zhanghao *jianc,int weizhi);
void wentixiougai(struct zhanghao *jianc,int weizhi);
void weishu(struct jilu *,int x,int y);
int jiafa(int diyi,int dier,double *shuru,int i);
int jianfa(int diyi,int dier,double *shuru,int i);
int chengfa(int diyi,int dier,double *shuru,int i);
int chufa(int diyi,int dier,double *shuru,int i);
int quyu(int diyi,int dier,double *shuru,int i);
void show(struct jilu *head,int e);
void dlshow(struct jilu *jianz,int e);
struct zhanghao
{
	char zhanghao[16];					//账号
	char mima[16];						//密码
	char wenti[24];						//选择的问题
	char daan[16];						//问题答案
};
struct jilu								//存到对应账号名的文件中
{
	char weishu;						//选择的位数
	int cuowugeshu;						//错误个数
	char yunsuanfu[10];					//每到题的运算符;
	int shuzi[10][3];					//随机的两个数,此题得分.
	double daan[10][2];					//使用者输入的答案，正确答案
	int defen;
	struct jilu *next;
};
int main()
{
	char xz;
	int flag;
	while(1)
	{
		flag=0;
		printf("1)无账号登陆\n\n2)账号登陆\n\n3)账号注册\n\n4)密码忘记\n\n0)退出\n\n请选择:\n");
		xz=zqsr("12340");
		switch(xz)
		{
			case '1':system("cls");
					wuzhanghao();system("pause");system("cls");break;
			case '2':system("cls");
					zhanghao();system("pause");system("cls");break;
			case '3':system("cls");
					zhuce();system("pause");system("cls");break;					
			case '4':system("cls");
					mimawangji();system("pause");system("cls");break;
			case '0':flag++;break;
		}
		fflush(stdin);
		if(flag>0)
			break;
	}
	return 0;
}
//输入正确选项函数
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
//无账号登陆函数
void wuzhanghao(void)
{
	int flag,geshu=0;
	char xz;
	struct jilu *head=NULL;
	struct jilu *creat,*prve,*p;
	while(1)
	{
		flag=0;
		printf("1)一位数\n\n2)两位数\n\n3)三位数\n\n4)查看做题记录\n\n0)退出到账号登陆菜单\n\n请选择:\n");
		xz=zqsr("12340");
		switch(xz)
		{
			case '1':
				{
					system("cls");
					creat=(struct jilu *)malloc(sizeof(struct jilu));
					if(head==NULL)
						head=creat;
					else
						prve->next=creat;
					creat->next=NULL;
					creat->weishu='1';
					weishu(creat,10,3);geshu++;
					prve=creat;
					system("pause");system("cls");break;
				}
			case '2':
				{	
					system("cls");
					creat=(struct jilu *)malloc(sizeof(struct jilu));
					if(head==NULL)
						head=creat;
					else
						prve->next=creat;
					creat->next=NULL;
					creat->weishu='2';
					weishu(creat,100,4);geshu++;
					prve=creat;
					system("pause");system("cls");break;
				}
			case '3':
				{
					system("cls");
					creat=(struct jilu *)malloc(sizeof(struct jilu));
					if(head==NULL)
						head=creat;
					else
						prve->next=creat;
					creat->next=NULL;
					creat->weishu='3';
					weishu(creat,1000,5);geshu++;
					prve=creat;
					system("pause");system("cls");break;
				}
			case '4':system("cls");
					show(head,geshu);
					system("pause");system("cls");break;
			case '0':flag++;break;
		}
		fflush(stdin);
		if(flag>0)
			break;
	}
	prve=head;
	if (head != NULL)
	{
		while (prve->next)
		{
			p = prve;
			prve = prve->next;
			free(p);
		}
	}
}
//账号密码登陆函数
void zhanghao(void)
{
	FILE *fp1,*fp2;
	char xz,zhanghao[16],zhwenjian[21],mima[16],xz1,xz2,xz3;
	int flag,flag1,flag2,flag3,flag4,flag5,flag6,i,cishu=3,flag0,x=0,y=0,flagq,flagp;
	struct zhanghao *jianc;
	struct zhanghao jishu;
	struct jilu jishu2,xjilu,*jianz,*zhuanhuan;
	if((fp1=fopen("zhanghao.txt","r"))==NULL)
	{
		printf("打开账号文件失败!\n");
		exit(1);
	}
	fseek(fp1,0L,0);
	while(fread(&jishu,sizeof(struct zhanghao),1,fp1)==1)
		x++;
	jianc=(struct zhanghao*)malloc(sizeof(struct zhanghao)*x);
	fseek(fp1,0L,0);
	fread(&jianc[0],sizeof(struct zhanghao),x,fp1);
	while(1)
	{
		flag4=0;flag5=0;
		printf("请输入账号:\n");
		gets(zhanghao);fflush(stdin);
		for(i=0,flag=0,flag1=0,flag2=0,flag3=0,flag6=0;i<x;i++)
		{
			if(strcmp(zhanghao,jianc[i].zhanghao)==0)
			{
				flag6++;
				while(1)
				{
					printf("请输入密码:");
					gets(mima);fflush(stdin);
					if(strcmp(mima,jianc[i].mima)==0)
					{
						flag++;
						printf("账号密码输入正确\n");
						break;
					}
					if(strcmp(mima,jianc[i].mima)!=0)
					{
						cishu--;
						if(cishu>0)
							printf("输入错误(您还有%d次机会)\n",cishu);
						if(cishu==0)
						{
							flag3++;
							break;
						}
						printf("是否重新输入\n\n1)重新输入\n\n0)退出到登陆菜单\n\n请选择:\n");
						xz1=zqsr("120");
						if(xz1=='1')
						{
							system("cls");continue;
						}
						if(xz1=='2')
						{
							system("cls");
							flag1++;break;
						}
						if(xz1=='0')
						{
							flag2++;break;
						}
					}
					if(flag1>0)
						break;
					if(flag2>0)
						break;
				}
			}
		}
		if(flag6==0)
		{
			printf("没有此账号,是否重新输入？\n\n1)重新输入账号\n\n0)退出\n\n请选择:\n");
			xz2=zqsr("10");
			if(xz2=='1')
			{
				system("cls");
				flag4++;continue;
			}
			if(xz2=='0')
			{
				flag5++;break;
			}
		}
		if(flag2>0||flag5>0||flag3>0||flag>0)
			break;
	}
	if(flag3>0)
		puts("对不起，三次密码输入错误，退出到登陆菜单");
	if(flag2>0||flag5>0)
		puts("退出到登陆菜单");
	if(flag>0)
	{
		system("cls");
		while(1)
		{
			y=0;
			strcpy(zhwenjian,zhanghao);	
			strcat(zhwenjian,".txt");					//把账号名后复制.txt，将内容存入对应账号文件中
			if((fp2=fopen(zhwenjian,"a+b"))==NULL)		//打开对应账号名的文件
			{
				printf("打开记录文件失败\n");
				exit(1);
			}
			fseek(fp2,0L,0);
			while(fread(&jishu2,sizeof(struct jilu),1,fp2)==1)
				y++;
			jianz=(struct jilu*)malloc(sizeof(struct jilu)*y);
			fseek(fp2,0L,0);
			fread(&jianz[0],sizeof(struct jilu),y,fp2);
			zhuanhuan=&xjilu;
			flag0=0;flagp=0;
			flagq=0;
			printf("1)一位数\n\n2)两位数\n\n3)三位数\n\n4)查看历史做题记录\n\n5)清除历史记录\n\n0)退出到账号登陆菜单\n\n请选择:\n");
			xz=zqsr("123450");
			switch(xz)
			{
				case '1':system("cls");
						zhuanhuan->weishu='1';
						weishu(zhuanhuan,10,3);system("pause");system("cls");break;
				case '2':system("cls");
						zhuanhuan->weishu='2';
						weishu(zhuanhuan,100,4);system("pause");system("cls");break;
				case '3':system("cls");
						zhuanhuan->weishu='3';
						weishu(zhuanhuan,1000,5);system("pause");system("cls");break;
				case '4':system("cls");
						dlshow(jianz,y);system("pause");system("cls");flagp++;break;					
				case '5':flagq++;break;
				case '0':flag0++;break;
			}
			fflush(stdin);
			if(flagq==0&&flagp==0&&flag0==0)
			{
				fseek(fp2,0L,2);
				if(fwrite(&xjilu,sizeof(struct jilu),1,fp2)!=1)
				{
					printf("写入失败!\n");
					exit(1);
				}
			}
			if(flagq>0)
			{
				system("cls");
				printf("是否清空所有历史记录?\n\n1)清空\n\n0)取消\n\n请选择:\n");
				xz3=zqsr("10");
				if(xz3=='1')
				{
					if(fclose(fp2)!=0)
					{
						printf("第二次关闭记录文件失败!");
						exit(1);
					}
					if((fp2=fopen(zhwenjian,"w+b"))==NULL)
					{
						puts("第二次打开记录文件失败!");
						exit(1);
					}
					if(fclose(fp2)!=0)
					{
						printf("第三次关闭记录文件失败!\n");
						exit(4);
					}
					printf("成功清除历史记录!\n");system("pause");system("cls");
				}
				else
				{
					printf("已取消清除\n");system("pause");system("cls");
				}
			}
			if(flagq==0||flag0>0)
			{
				if(fclose(fp2)!=0)
				{
					printf("关闭记录文件失败!\n");
					exit(4);
				}
			}
			fflush(stdin);
			//释放做题记录
			free(jianz);	
			if(flag0>0)
			{
				break;
			}
		}
	}
	if(fclose(fp1)!=0)
	{
		puts("关闭账号文件失败");
		exit(2);
	}
	//释放账号记录
	free(jianc);
}
//注册账号函数
void zhuce(void)
{
	FILE *fp4;
	int i,j,x=0,flag,flag1,flag2;
	struct zhanghao jishu,*jianc;
	char *wenti[5]={"你父亲的名字?","你母亲的名字?","你的名字?","你最亲密的朋友的名字?","你最敬爱的老师的名字?"};
	char xz,xz1,queren,xz2,xz3;
	if((fp4=fopen("zhanghao.txt","r+"))==NULL)
	{
		printf("打开账号文件失败!\n");
		exit(1);
	}
	fseek(fp4,0L,0);
	while(fread(&jishu,sizeof(struct zhanghao),1,fp4)==1)
		x++;
	jianc=(struct zhanghao *)malloc(sizeof(struct zhanghao)*x);
	fseek(fp4,0L,0);
	fread(&jianc[0],sizeof(struct zhanghao),x,fp4);
	while(1)
	{
		flag=0;flag1=0;
		while(1)
		{
			flag2=0;
			printf("请输入账号;(小于等于15位字符)\n");
			gets(jishu.zhanghao);fflush(stdin);
			jishu.zhanghao[15]='\0';
			if(x==0)
			{
				break;
			}
			for(i=0;i<x;i++)
			{
				if(strcmp(jishu.zhanghao,jianc[i].zhanghao)==0)
				{
					flag2++;
					printf("\n已存在相同账号\n\n1)重新输入新账号\n\n0)退出到登陆菜单\n\n请选择:\n");
					xz=zqsr("10");
					if(xz=='0')
					{
						flag++;
					}
					break;
				}
			}
			if(flag>0)
				break;
			else
				system("cls");
			if(flag2==0)
				break;

		}
		if(flag>0)
		{
			break;
		}
		else
		{
			printf("设置的账号为:%-16s\n\n是否确认？\n\ny)确认\n\nn)重新输入\n\n请选择\n",jishu.zhanghao);
			xz3=zqsr("yn");
			if(xz3=='n')
			{
				system("cls");continue;
			}
			else
			{
				system("cls");
				while(1)
				{
					printf("请输入密码:(请输入小于15字符)\n");
					gets(jishu.mima);fflush(stdin);
					jishu.mima[15]='\0';
					printf("\n设置的密码为:%-16s\n\n是否确认？\n\ny)确认\n\nn)重新输入\n\n请选择\n",jishu.mima);
					queren=zqsr("yn");
					if(queren=='y')
						break;
					else
						system("cls");
				}
				system("cls");
				while(1)
				{
					printf("请选择以下一个问题来找回或修改密码:\n");
					for(j=0;j<5;j++)
						printf("%c)%s\n",(char)j+49,wenti[j]);
					printf("请选择:\n");
					xz1=zqsr("12345");system("cls");
					printf("\n选择的是:%s\n\n是否确认?\n\ny)确认\n\nn)重新选择\n\n请选择:\n",wenti[(int)xz1-49]);
					queren=zqsr("yn");
					if(queren=='y')
					{
						strcpy(jishu.wenti,wenti[(int)xz1-49]);
						break;
					}
					else
						system("cls");
				}
				system("cls");
				while(1)
				{
					printf("%s\n\n现在请输入问题的答案:(请少于15个字符或7个汉字)\n",jishu.wenti);
					gets(jishu.daan);fflush(stdin);
					jishu.daan[15]='\0';
					printf("\n设置的答案为:%s\n\n是否确认?\n\ny)确认\n\nn)重新输入\n\n请选择:\n",jishu.daan);
					queren=zqsr("yn");
					if(queren=='y')
						break;
					else
						system("cls");
				}
				system("cls");
				printf("注册完成，以下是您的账号全貌，请记好!\n");
				printf("%s\n%s\n%s\n答案为;%s\n",jishu.zhanghao,jishu.mima,jishu.wenti,jishu.daan);
				printf("\n是否确认注册?\n\n1)确认\n\n2)重新注册\n\n0)取消注册,退回到登陆菜单\n\n请选择:\n");
				xz2=zqsr("120");
				if(xz2=='1')
				{
					printf("恭喜注册成功!\n");
					break;
				}
				if(xz2=='0')
				{
					flag1++;
					break;
				}
				else
					system("cls");continue;
			}
		}
		break;
	}
	if(flag==0&&flag1==0)
	{
		fseek(fp4,0L,2);
		fwrite(&jishu,sizeof(struct zhanghao),1,fp4);
	}
	else
		puts("选择了，退出到登陆菜单!");
	free(jianc);
	if(fclose(fp4)!=0)
	{
		puts("关闭账号文件失败!");
		exit(2);
	}
}
void mimawangji(void)
{
	int i,weizhi,flag=0,flag1=0,flag2=0,flag3=0,x=0;
	char zhanghao[16],xz,daan[16],cishu=3,xz1;
	struct zhanghao jishu,*jianc;
	FILE *fp;
	if((fp=fopen("zhanghao.txt","r+"))==NULL)
	{
		puts("打开账号文件失败!");
		exit(1);
	}
	fseek(fp,0L,0);
	while(fread(&jishu,sizeof(struct zhanghao),1,fp)==1)
		x++;
	jianc=(struct zhanghao*)malloc(sizeof(struct zhanghao)*x);
	fseek(fp,0L,0);
	fread(&jianc[0],sizeof(struct zhanghao),x,fp);
	puts("请输入您的账号:\n");
	gets(zhanghao);fflush(stdin);
	for(i=0;i<x;i++)
	{
		if(strcmp(zhanghao,jianc[i].zhanghao)==0)
		{
			weizhi=i;
			flag++;
			break;
		}
	}
	if(flag==0)
		puts("没有此账号!");
	else
	{
		while(1)
		{
			system("cls");
			printf("这是您当时所选的问题: %s\n请输入答案:  ",jianc[weizhi].wenti);
			gets(daan);fflush(stdin);
			if(strcmp(daan,jianc[weizhi].daan)!=0)
			{
				cishu--;
				if(cishu>0)
					printf("输入错误(您还有%d次机会)\n",cishu);
				if(cishu==0)
				{
					printf("三次机会用尽,您没有机会了\n");
					break;
				}
				printf("是否重新输入\n\n1)重新输入\n\n0)退出到登陆菜单\n\n请选择:\n");
				xz=zqsr("10");
				if(xz=='0')
					break;
				else
				{
					system("cls");continue;
				}
			}
			if(strcmp(daan,jianc[weizhi].daan)==0)
			{
				while(1)
				{
					system("cls");
					printf("1)查看密码\n\n2)修改密码\n\n3)修改问题\n\n0)退出到登陆菜单\n\n请选择:\n");
					xz1=zqsr("1230");
					switch(xz1)
					{
					case '1':system("cls");
							printf("您的密码为:%-16s\n",jianc[weizhi].mima);system("pause");system("cls");break;
					case '2':system("cls");
							mimaxiougai(jianc,weizhi);flag1++;system("pause");system("cls");break;
					case '3':system("cls");
							wentixiougai(jianc,weizhi);flag2++;system("pause");system("cls");break;
					case '0':flag3++;break;
					}
					fflush(stdin);
					if(flag3>0)
						break;
					if(flag1>0||flag2>0)
					{
						fseek(fp,sizeof(struct zhanghao)*weizhi,0);
						if(fwrite(&jianc[weizhi],sizeof(struct zhanghao),1,fp)!=1)
						{
							printf("写入文件失败!\n");
							system("pause");
						}
					}

				}
				if(flag3>0)
					break;
			}
		}
	}
	if(fclose(fp)!=0)
	{
		printf("关闭账号文件失败!");
		exit(1);
	}
	free(jianc);
}
void mimaxiougai(struct zhanghao *jianc,int weizhi)
{
	char queren;
	while(1)
	{
		printf("请输入新密码,(请少于15个字符)\n");
		gets(jianc[weizhi].mima);fflush(stdin);
		jianc[weizhi].mima[15]='\0';
		printf("新密码为:%s\n\n是否确认\n\ny)确认\n\nn)重新输入\n\n请选择;\n",jianc[weizhi].mima);
		queren=zqsr("yn");
		if(queren=='y')
			break;
	}
	printf("密码修改完成!\n");
}
void wentixiougai(struct zhanghao *jianc,int weizhi)
{
	int i;
	char queren,xz;
	char *wenti[5]={"你父亲的名字?","你母亲的名字?","你的名字?","你最亲密的朋友的名字?","你最敬爱的老师的名字?"};
	while(1)
	{
		printf("请选择以下其中的一个问题\n");
		for(i=0;i<5;i++)
			printf("%d):%s\n",i+1,wenti[i]);
		printf("\n请选择:\n");
		xz=zqsr("12345");
		printf("\n选择的是:%s\n\n是否确认?\n\ny)确认\n\nn)重新选择\n\n请选择:\n",wenti[(int)xz-49]);
		queren=zqsr("yn");
		if(queren=='y')
		{
			strcpy(jianc[weizhi].wenti,wenti[(int)xz-49]);
			while(1)
			{
				system("cls");
				printf("%s\n\n现在请输入问题的答案:(请少于15个字符，或7个汉字)\n",jianc[weizhi].wenti);
				gets(jianc[weizhi].daan);fflush(stdin);
				jianc[weizhi].daan[15]='\0';
				printf("\n设置的答案为:%s\n\n是否确认?\n\ny)确认\n\nn)重新选择\n\n请选择:\n",jianc[weizhi].daan);
				queren=zqsr("yn");
				if(queren=='y')
					break;
			}
			break;
		}
		else
			system("cls");
	}
}
//位数函数
void weishu(struct jilu *xjilu,int x,int y)
{
	int i,ysf,diyi[10],dier[10],zongfen=0,cuowu=0,p,swap;
	double shuru[10];
	double d;
	char yunsuanfu[6]={'+','-','*','/','%'};				//用char型数组存放对应运算符
	srand((unsigned)time(0));
	for(i=0;i<10;i++)
	{
		printf("第%d题  ",i+1);
		diyi[i]=rand()%x;				//随机数对x(10,100,1000)取余，得到一位，两位，三位，的数
		dier[i]=rand()%(x-1)+1;			//分母不为零
		ysf=rand()%y;										//运算符号的位置对y(3,4,5)取余，得到不同位数对应的几个运算符
		xjilu->yunsuanfu[i]=yunsuanfu[ysf];
		switch(yunsuanfu[ysf])
		{
			case '+':xjilu->shuzi[i][2]=jiafa(diyi[i],dier[i],shuru,i);
					zongfen+=xjilu->shuzi[i][2];
					xjilu->daan[i][0]=shuru[i];
					xjilu->daan[i][1]=diyi[i]+dier[i];
					system("pause");system("cls");break;
			case '-':if(diyi[i]<dier[i])
					 {
						 swap=diyi[i];
						 diyi[i]=dier[i];
						 dier[i]=swap;
					 }
					xjilu->shuzi[i][2]=jianfa(diyi[i],dier[i],shuru,i);
					zongfen+=xjilu->shuzi[i][2];
					xjilu->daan[i][0]=shuru[i];
					xjilu->daan[i][1]=diyi[i]-dier[i];
					system("pause");system("cls");break;
			case '*':xjilu->shuzi[i][2]=chengfa(diyi[i],dier[i],shuru,i);
					zongfen+=xjilu->shuzi[i][2];
					xjilu->daan[i][0]=shuru[i];
					xjilu->daan[i][1]=diyi[i]*dier[i];
					system("pause");system("cls");break;
			case '/':xjilu->shuzi[i][2]=chufa(diyi[i],dier[i],shuru,i);
					zongfen+=xjilu->shuzi[i][2];				
					xjilu->daan[i][0]=shuru[i];
					d=(double)diyi[i]/dier[i];
					p=(int)(d*100+0.5);									//保留两位小数，四舍五入
					d=p/100.0;
					xjilu->daan[i][1]=d;
					system("pause");system("cls");break;
			case '%':xjilu->shuzi[i][2]=quyu(diyi[i],dier[i],shuru,i);
					zongfen+=xjilu->shuzi[i][2];
					xjilu->daan[i][0]=shuru[i];
					xjilu->daan[i][1]=diyi[i]%dier[i];
					system("pause");system("cls");break;
		}
		xjilu->shuzi[i][0]=diyi[i];
		xjilu->shuzi[i][1]=dier[i];
	}
	xjilu->defen=zongfen;
	for(i=0;i<10;i++)
	{
		if(xjilu->daan[i][0]!=xjilu->daan[i][1])
			cuowu++;
	}
	xjilu->cuowugeshu=cuowu;
	printf("得分为:%-2d\n一共做错%2d道题\n",xjilu->defen,cuowu);
	if(xjilu->cuowugeshu!=0)
	{
		printf("分别为:\n");
		for(i=0;i<10;i++)
		{
			if(xjilu->daan[i][0]!=xjilu->daan[i][1])
			{
				printf("%-2d%c%2d    你输入的为：%4.2lf\n\n%9c正确答案应为：%2.2lf\n\n",xjilu->shuzi[i][0],xjilu->yunsuanfu[i],xjilu->shuzi[i][1],xjilu->daan[i][0],' ',xjilu->daan[i][1]);
			}
		}
	}
	if(xjilu->defen==100)
	{
		puts("\n你真棒，全部答对了!");
	}
	if(xjilu->defen<100&&xjilu->defen>=80)
	{
		puts("\n答的非常好!");
	}
	if(xjilu->defen<80&&xjilu->defen>=60)
	{
		puts("\n答的不错，继续努力");
	}
	if(xjilu->defen<60)
	{
		puts("\n不及格，还得加把劲啊!");
	}
}
//加法计算函数
int jiafa(int diyi,int dier,double *shuru,int i)
{
	double daan;
	printf("请做下题：\n");
	daan=diyi+dier;
	printf("%-2d+%2d = ",diyi,dier);
	while(scanf("%lf",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("输入有误,请重新输入真确的数字\n");
	}
	fflush(stdin);
	if(daan!=shuru[i])
	{
		printf("你答错了，继续努力\n");system("pause");system("cls");printf("重新回答:\n");
		printf("%-2d+%2d = ",diyi,dier);
		while(scanf("%lf",&shuru[i])!=1)
		{
			fflush(stdin);
			printf("输入有误,请重新输入真确的数字\n");
		}
		fflush(stdin);
		if(daan!=shuru[i])
		{
			printf("你答错了，继续努力!\n");system("pause");system("cls");printf("重新回答:\n");
			printf("%-2d+%2d = ",diyi,dier);
			while(scanf("%lf",&shuru[i])!=1)
			{
				fflush(stdin);
				printf("输入有误,请重新输入真确的数字\n");
			}
			fflush(stdin);
			if(daan!=shuru[i])
			{
				printf("非常遗憾你又答错了，请继续做下一题。本题的正确答案为: %.2lf\n",daan);
				return 0;
			}
			else
			{
				printf("答对了，祝贺你！加6分\n");
				return 6;
			}
		}
		else
		{
			printf("答对了，你很棒！加8分\n");
			return 8;
		}
	}
	else
	{
		printf("完全正确，你非常聪明！加10分\n");
		return 10;
	}
}
//减法计算函数
int jianfa(int diyi,int dier,double *shuru,int i)
{
	double daan;
	printf("请做下题：\n");
	daan=diyi-dier;
	printf("%-2d-%2d = ",diyi,dier);
	while(scanf("%lf",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("输入有误,请重新输入正确的数字\n");
	}
	fflush(stdin);
	if(daan!=shuru[i])
	{
		printf("你答错了，继续努力！\n");system("pause");system("cls");printf("重新回答:\n");
		printf("%-2d-%2d = ",diyi,dier);
		while(scanf("%lf",&shuru[i])!=1)
		{
			fflush(stdin);
			printf("输入有误,请重新输入真确的数字\n");
		}
		fflush(stdin);
		if(daan!=shuru[i])
		{
			printf("你答错了，继续努力!\n");system("pause");system("cls");printf("重新回答:\n");
			printf("%-2d-%2d = ",diyi,dier);
			while(scanf("%lf",&shuru[i])!=1)
			{
				fflush(stdin);
				printf("输入有误,请重新输入真确的数字\n");
			}
			fflush(stdin);
			if(daan!=shuru[i])
			{
				printf("非常遗憾你又答错了，请继续做下一题。本题的正确答案为: %.2lf\n",daan);
				return 0;
			}
			else
			{
				printf("答对了，祝贺你！加6分\n");
				return 6;
			}
		}
		else
		{
			printf("答对了，你很棒！加8分\n");
			return 8;
		}
	}
	else
	{
		printf("完全正确，你非常聪明！加10分\n");
		return 10;
	}
}
//乘法计算函数
int chengfa(int diyi,int dier,double *shuru,int i)
{
	double daan;
	printf("请做下题：\n");
	daan=diyi*dier;
	printf("%-2d×%2d = ",diyi,dier);
	while(scanf("%lf",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("输入有误,请重新输入真确的数字\n");
	}
	fflush(stdin);
	if(daan!=shuru[i])
	{
		printf("你答错了，继续努力！\n");system("pause");system("cls");printf("重新回答:\n");
		printf("%-2d×%2d = ",diyi,dier);
		while(scanf("%lf",&shuru[i])!=1)
		{
			fflush(stdin);
			printf("输入有误,请重新输入真确的数字\n");
		}
		fflush(stdin);
		if(daan!=shuru[i])
		{
			printf("你答错了，继续努力！\n");system("pause");system("cls");printf("重新回答:\n");
			printf("%-2d×%2d = ",diyi,dier);
			while(scanf("%lf",&shuru[i])!=1)
			{
			fflush(stdin);
			printf("输入有误,请重新输入真确的数字\n");
			}
			fflush(stdin);
			if(daan!=shuru[i])
			{
				printf("非常遗憾你又答错了，请继续做下一题。本题的正确答案为: %.2lf\n",daan);
				return 0;
			}
			else
			{
				printf("答对了，祝贺你！加6分\n");
				return 6;
			}
		}
		else
		{
			printf("答对了，你很棒！加8分\n");
			return 8;
		}
	}
	else
	{
		printf("完全正确，你非常聪明！加10分\n");
		return 10;
	}
}
//除法计算函数
int chufa(int diyi,int dier,double *shuru,int i)
{
	double daan,d;
	int p;
	printf("请做下题(保留两位小数)：\n");
	d=(double)diyi/(double)dier;
	p=(int)(d*100+0.5);
	daan=p/100.0;
	printf("%-2d÷%2d = ",diyi,dier);
	while(scanf("%lf",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("输入有误,请重新输入真确的数字\n");
	}
	fflush(stdin);
	if(daan!=shuru[i])
	{
		printf("你答错了，继续努力！\n");system("pause");system("cls");printf("重新回答:\n");
		printf("%-2d÷%2d = ",diyi,dier);
		while(scanf("%lf",&shuru[i])!=1)
		{
			fflush(stdin);
			printf("输入有误,请重新输入真确的数字\n");
		}
		fflush(stdin);
		if(daan!=shuru[i])
		{
			printf("你答错了，继续努力！\n");system("pause");system("cls");printf("重新回答:\n");
			printf("%-2d÷%2d = ",diyi,dier);
			while(scanf("%lf",&shuru[i])!=1)
			{
				fflush(stdin);
				printf("输入有误,请重新输入真确的数字\n");
			}
			fflush(stdin);
			if(daan!=shuru[i])
			{
				printf("非常遗憾你又答错了，请继续做下一题。本题的正确答案为: %.2lf\n",daan);
				return 0;
			}
			else
			{
				printf("答对了，祝贺你！加6分\n");
				return 6;
			}
		}
		else
		{
			printf("答对了，你很棒！加8分\n");
			return 8;
		}
	}
	else
	{
		printf("完全正确，你非常聪明！加10分\n");
		return 10;
	}
}
//取余函数
int quyu(int diyi,int dier,double *shuru,int i)
{
	double daan;
	printf("请做下题：\n");
	daan=diyi%dier;
	printf("%-2d%%%2d = ",diyi,dier);
	while(scanf("%lf",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("输入有误,请重新输入真确的数字\n");
	}
	fflush(stdin);
	if(daan!=shuru[i])
	{
		printf("你答错了，继续努力！\n");system("pause");system("cls");printf("重新回答:\n");
		printf("%-2d%%%2d = ",diyi,dier);
		while(scanf("%lf",&shuru[i])!=1)
		{
			fflush(stdin);
			printf("输入有误,请重新输入真确的数字\n");
		}
		fflush(stdin);
		if(daan!=shuru[i])
		{
			printf("你答错了，继续努力！\n");system("pause");system("cls");printf("重新回答:\n");
			printf("%-2d%%%2d = ",diyi,dier);
			while(scanf("%lf",&shuru[i])!=1)
			{
				fflush(stdin);
				printf("输入有误,请重新输入真确的数字\n");
			}
			fflush(stdin);
			if(daan!=shuru[i])
			{
				printf("非常遗憾你又答错了，请继续做下一题。本题的正确答案为: %.2lf\n",daan);
				return 0;
			}
			else
			{
				printf("答对了，祝贺你！加6分\n");
				return 6;
			}
		}
		else
		{
			printf("答对了，你很棒！加8分\n");
			return 8;
		}
	}
	else
	{
		printf("完全正确，你非常聪明！加10分\n");
		return 10;
	}
}
//无账号登陆显示函数（链表显示）
void show(struct jilu *head,int e)
{
	int i,j;
	struct jilu *shuchu;
	shuchu=head;
	if(head!=NULL)
	{
		printf("一共做了%d次题\n分别为:\n\n",e);
		for(i=0;i<e;i++)
		{
			printf("第%d次，%c位数的题\n",i+1,shuchu->weishu);
			for(j=0;j<10;j++)
			{
				printf("第%d题\n",j+1);
				if(shuchu->daan[j][0]==shuchu->daan[j][1])
				{
					printf("这道题答对了 :  %-2d%c%2d = %2.2lf\n",shuchu->shuzi[j][0],shuchu->yunsuanfu[j],shuchu->shuzi[j][1],shuchu->daan[j][1]);
					printf("得分为:  %d\n",shuchu->shuzi[j][2]);
				}
				else
				{
					printf("这道题答错了 :  %-2d%c%2d    你输入的答案为: %2.2lf   正确答案为: %2.2lf\n",shuchu->shuzi[j][0],shuchu->yunsuanfu[j],shuchu->shuzi[j][1],shuchu->daan[j][0],shuchu->daan[j][1]);
					printf("得分为:  %d\n",0);
				}
			}
			printf("共做错%3d道题",shuchu->cuowugeshu);
			printf("\n\n总分为:%5d\n\n",shuchu->defen);
			shuchu=shuchu->next;
		}
	}
	else
		printf("您还没有做题请,先去做题\n");
}
//账号登陆显示函数（结构体数组显示）
void dlshow(struct jilu *jianz,int e)
{
	int i,j;
	if(e>0)
	{
		printf("一共做了%d次题\n分别为:\n\n",e);
		for(i=0;i<e;i++)
		{
			printf("第%d次，%c位数的题\n",i+1,jianz[i].weishu);
			for(j=0;j<10;j++)
			{
				printf("第%d题\n",j+1);
				if(jianz[i].daan[j][0]==jianz[i].daan[j][1])
				{
					printf("这道题答对了 :  %-2d%c%2d = %2.2lf\n",jianz[i].shuzi[j][0],jianz[i].yunsuanfu[j],jianz[i].shuzi[j][1],jianz[i].daan[j][1]);
					printf("得分为:  %d\n",jianz[i].shuzi[j][2]);
				}
				else
				{
					printf("这道题答错了 :  %-2d%c%2d    你输入的答案为: %2.2lf   正确答案为: %2.2lf\n",jianz[i].shuzi[j][0],jianz[i].yunsuanfu[j],jianz[i].shuzi[j][1],jianz[i].daan[j][0],jianz[i].daan[j][1]);
					printf("得分为:  %d\n",0);
				}
			}
			printf("共做错%3d道题",jianz[i].cuowugeshu);
			printf("\n\n总分为:%5d\n\n",jianz[i].defen);
		}
	}
	else
		printf("您还没有做题请,先去做题\n");
}
