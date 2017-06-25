#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include <stddef.h>
#define S 45
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
char zqsr(char *c);						//检测输入选项正确与否
void wuzhanghao6(void);					//无账号输入主函数
void zhanghao6(void);
void zhuce6(void);
void mimawangji6(void);
void mimaxiougai6(struct zhanghao *jianc,int weizhi);
void wentixiougai6(struct zhanghao *jianc,int weizhi);
void weishu6(struct jilu *,int x,int y);
int jiafa6(int diyi,int dier,int *shuru,int i);
int jianfa6(int diyi,int dier,int *shuru,int i);
int chengfa6(int diyi,int dier,int *shuru,int i);
int chufa6(int diyi,int dier,int *shuru,int i);
int quyu6(int diyi,int dier,int *shuru,int i);
void show6(struct jilu *head,int e);
void dlshow6(struct jilu *jianz,int e);
void keshediliou(void);
void cheliangjinru7(struct qiche *qqiche,int e);
void chelianglikai7(struct qiche *qqiche,int e);
void konglist7(struct qiche *qqiche,int e);
void chazhao7(struct qiche *qqiche,int e);
void xianshi7(struct qiche *qqiche,int e);
void huizong7(struct qiche *qqiche,int e,int sum);
void chushihua7(struct qiche *qqiche,int e,int sum);
void keshediqi(void);
void diancai8(char *diancai,int *geshu);
void chakan8(char *diancai,int *geshu);
void tiancai8(char *diancai,int *geshu);
void jiancai8(char *diancai,int *geshu);
void jiesuan8(char *diancai,int *geshu);
void keshediba(void);
struct shebei * luru9(struct shebei *head);
void shuchu9(struct shebei *head,int e);
int lioulan9(struct shebei *head);
void xiougai9(struct shebei *head);
void poyi9(struct shebei *head);
void zonghaofei9(struct shebei *head);
void yisun9(struct shebei *head);
void chaxun9(struct shebei *head);
void keshedijiou(void);
struct checi *tianjia0(struct checi *);
void lioulan0(struct checi *);
int bancishuchu0(struct checi *);
void xiougai0(struct checi *);
void shijian0(struct checi *,int weizhi);
int bancijiancha0(struct checi*,int weizhi);
struct checi *shanchu0(struct checi *);
void chaxun0(struct checi*);
int konglist0(struct checi *weizhi);
int alist0(struct checi *weizhi);
void yuding0(struct checi *weizhi);
void quxiao0(struct checi *weizhi);
void keshedishi(void);
void shuchuqipan(char qipan[][3]);
int duiyizhe(char qipan[][3]);
int diannao(char qipan[][3]);
int diannaojiance(char qipan[][3]);
int jiance10(char qipan[][3]);
int shengfu(char qipan[][3]);
void renxian(void);
void dianxian(void);
void keshefujia(void);
struct gongren
{
	char gongh[11];
	char xingming[10];
	int yfa[3];
	int yko[3];
	int shifa;
};
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
	int shuzi[10][4];					//随机的两个数，使用者输入的答案，正确答案;
	int defen;
	struct jilu *next;
//	char c;
};
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
const int caijia[10]={3,10,18,15,88,12,8,48,58,25};
int ruzhang=0;
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
struct seat
{
	int hao;
	char mark;
	char keren[16];
};
struct checi
{
	int xiaoshi;
	int fenzhong;
	struct seat sseat[S];
	struct checi *next;
};
int main()
{
	int flag=0;
	char xz;
	while(1)
	{
		printf("1)课设第一题\n\n2)课设第二题\n\n3)课设第六题\n\n4)课设第七题\n\n5)课设第八题\n\n6)课设第九题\n\n7)课设第十题\n\n8)课设附加\n\n0)退出\n\n请选择;\n");
		xz=zqsr("123456780");
		switch(xz)
		{
		case '1':system("cls");
				keshediyi();system("pause");system("cls");break;
		case '2':system("cls");
				keshedier();system("pause");system("cls");break;
		case '3':system("cls");
				keshediliou();system("pause");system("cls");break;
		case '4':system("cls");
				keshediqi();system("pause");system("cls");break;
		case '5':system("cls");
				keshediba();system("pause");system("cls");break;
		case '6':system("cls");
				keshedijiou();system("pause");system("cls");break;
		case '7':system("cls");
				keshedishi();system("pause");system("cls");break;
		case '8':system("cls");
				keshefujia();system("pause");system("cls");break;
		case '0':flag++;break;
		}
		if(flag>0)
			break;
	}
	printf("拜拜\n");
	return 0;
}
void keshediyi()
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
		system("cls");
		if(flag>0)
			break;
	}
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
void keshedier()
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
void keshediliou()
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
					wuzhanghao6();system("pause");system("cls");break;
			case '2':system("cls");
					zhanghao6();system("pause");system("cls");break;
			case '3':system("cls");
					zhuce6();system("pause");system("cls");break;					
			case '4':system("cls");
					mimawangji6();system("pause");system("cls");break;
			case '0':flag++;break;
		}
		fflush(stdin);
		if(flag>0)
			break;
	}
}
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
void wuzhanghao6(void)
{
	int flag,geshu=0;
	char xz;
	struct jilu *head=NULL;
	struct jilu *creat,*prve;
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
				weishu6(creat,10,3);geshu++;
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
				weishu6(creat,100,4);geshu++;
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
				weishu6(creat,1000,5);geshu++;
				prve=creat;
				system("pause");system("cls");break;
			}
		case '4':system("cls");
				show6(head,geshu);
				system("pause");system("cls");break;
		case '0':flag++;break;
		}
		fflush(stdin);
		if(flag>0)
			break;
	}
}
void zhanghao6(void)
{
	FILE *fp1,*fp2;
	char xz,zhanghao[16],zhwenjian[21],mima[16],xz1,xz2;
	int flag,flag1,flag2,flag3,flag4,flag5,i,cishu=3,flag0,x=0,y=0,flagq,flagp;
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
		printf("请输入账号:\n");
		gets(zhanghao);
		for(i=0,flag=0,flag1=0,flag2=0,flag3=0;i<x;i++)
		{
			if(strcmp(zhanghao,jianc[i].zhanghao)==0)
			{
				while(1)
				{
					printf("请输入密码:");
					gets(mima);
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
			else
			{
				printf("账号输入错误,是否重新输入？\n\n1)重新输入账号\n\n0)退出\n\n请选择:\n");
				xz2=zqsr("10");
				if(xz2=='1')
				{
					system("cls");
					flag4++;break;
				}
				if(xz2=='0')
				{
					flag5++;break;
				}
			}
			if(flag2>0||flag5>0||flag3>0||flag>0)
				break;
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
			strcat(zhwenjian,".txt");
			if((fp2=fopen(zhwenjian,"r+b"))==NULL)
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
					weishu6(zhuanhuan,10,3);system("pause");system("cls");break;
			case '2':system("cls");
					zhuanhuan->weishu='2';
					weishu6(zhuanhuan,100,4);system("pause");system("cls");break;
			case '3':system("cls");
					zhuanhuan->weishu='3';
					weishu6(zhuanhuan,1000,5);system("pause");system("cls");break;
			case '4':system("cls");
					dlshow6(jianz,y);system("pause");system("cls");flagp++;break;					//先用链表查看，退出登录时，写入链表.(未完成)
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
					system("pause");
				}
			}
			if(flagq>0)
			{
				system("cls");
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
			if(flagq==0||flag0>0)
			{
				if(fclose(fp2)!=0)
				{
					printf("关闭记录文件失败!\n");
					exit(4);
				}
			}
			fflush(stdin);
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
	free(jianc);
}
void zhuce6(void)
{
	FILE *fp4;
	int i,j,x=0,flag,flag1;
	struct zhanghao jishu,*jianc;
	char *wenti[5]={"你父亲的名字?","你母亲的名字?","你的名字?","你最亲密的朋友的名字?","你最敬爱的老师的名字?"};
	char xz,xz1,queren,xz2;
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
			printf("请输入账号;(小于等于15位字符)\n");
			gets(jishu.zhanghao);
			if(x==0)
			{
				break;
			}
			for(i=0;i<x;i++)
			{
				if(strcmp(jishu.zhanghao,jianc[i].zhanghao)==0)
				{
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
		}
		if(flag>0)
		{
			break;
		}
		else
		{
			system("cls");
			while(1)
			{
				printf("请输入密码:\n");
				gets(jishu.mima);
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
					printf("%c)%s\n",(char)j+1,wenti[j]);
				printf("请选择:\n");
				xz1=zqsr("12345");
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
				printf("%s\n\n现在请输入问题的答案:\n",jishu.wenti);
				gets(jishu.daan);
				printf("\n设置的答案为:%s\n\n是否确认?\n\ny)确认\n\nn)重新选择\n\n请选择:\n",jishu.daan);
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
				system("cls");
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
void mimawangji6(void)
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
	gets(zhanghao);
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
			printf("这是您当时所选的问题: %s\n请输入答案:  ",jianc[weizhi].wenti);
			gets(daan);
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
					system("cls");
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
							mimaxiougai6(jianc,weizhi);flag1++;system("pause");system("cls");break;
					case '3':system("cls");
							wentixiougai6(jianc,weizhi);flag2++;system("pause");system("cls");break;
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
void mimaxiougai6(struct zhanghao *jianc,int weizhi)
{
	char queren;
	while(1)
	{
		printf("请输入新密码;\n");
		gets(jianc[weizhi].mima);
		printf("新密码为:%s\n\n是否确认y)确认\n\nn)重新输入\n\n请选择;\n",jianc[weizhi].mima);
		queren=zqsr("yn");
		if(queren=='y')
			break;
	}
	printf("密码修改完成!\n");
}
void wentixiougai6(struct zhanghao *jianc,int weizhi)
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
				printf("%s\n\n现在请输入问题的答案:\n",jianc[weizhi].wenti);
				gets(jianc[weizhi].daan);
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
void weishu6(struct jilu *xjilu,int x,int y)
{
	int i,ysf,diyi[10],dier[10],zongfen=0;
	int shuru[10];
	char yunsuanfu[6]={'+','-','*','/','%'};
	srand((unsigned)time(0));
	for(i=0;i<10;i++)
	{
		xjilu->shuzi[i][0]=diyi[i]=rand()%x;
		xjilu->shuzi[i][1]=dier[i]=rand()%(x-1)+1;			//分母不为零
		ysf=rand()%y;
		xjilu->yunsuanfu[i]=yunsuanfu[ysf];
		switch(yunsuanfu[ysf])
		{
			case '+':zongfen+=jiafa6(diyi[i],dier[i],shuru,i);
					xjilu->shuzi[i][2]=shuru[i];
					xjilu->shuzi[i][3]=diyi[i]+dier[i];
					system("pause");system("cls");break;
			case '-':zongfen+=jianfa6(diyi[i],dier[i],shuru,i);
					xjilu->shuzi[i][2]=shuru[i];
					xjilu->shuzi[i][3]=diyi[i]-dier[i];
					system("pause");system("cls");break;
			case '*':zongfen+=chengfa6(diyi[i],dier[i],shuru,i);
					xjilu->shuzi[i][2]=shuru[i];
					xjilu->shuzi[i][3]=diyi[i]*dier[i];
					system("pause");system("cls");break;
			case '/':zongfen+=chufa6(diyi[i],dier[i],shuru,i);				//存在不整除问题
					xjilu->shuzi[i][2]=shuru[i];
					xjilu->shuzi[i][3]=diyi[i]/dier[i];
					system("pause");system("cls");break;
			case '%':zongfen+=quyu6(diyi[i],dier[i],shuru,i);
					xjilu->shuzi[i][2]=shuru[i];
					xjilu->shuzi[i][3]=diyi[i]%dier[i];
					system("pause");system("cls");break;
		}
	}
	xjilu->defen=zongfen;
	xjilu->cuowugeshu=10-zongfen/10;
	printf("得分为:%-2d\n一共做错%2d道题\n",xjilu->defen,xjilu->cuowugeshu);
	if(xjilu->cuowugeshu!=0)
	{
		printf("分别为:\n");
		for(i=0;i<10;i++)
		{
			if(xjilu->shuzi[i][3]!=xjilu->shuzi[i][2])
			{
				printf("%-2d%c%2d    你输入的为：%4d\n\n%9c正确答案应为：%2d\n\n",xjilu->shuzi[i][0],xjilu->yunsuanfu[i],xjilu->shuzi[i][1],xjilu->shuzi[i][2],' ',xjilu->shuzi[i][3]);
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
int jiafa6(int diyi,int dier,int *shuru,int i)
{
	int daan;
	printf("请做下题：\n");
	daan=diyi+dier;
	printf("%-2d+%2d = ",diyi,dier);
	while(scanf("%d",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("输入有误,请重新输入真确的数字\n");
//		scanf("%d",&shuru[i]);
		fflush(stdin);
	}
	if(daan!=shuru[i])
	{
		printf("你做错了，不加分!\n");
		return 0;
	}
	else
	{
		printf("恭喜你答对了，加10分!\n");
		return 10;
	}
}
int jianfa6(int diyi,int dier,int *shuru,int i)
{
	int daan;
	printf("请做下题：\n");
	daan=diyi-dier;
	printf("%-2d-%2d = ",diyi,dier);
	while(scanf("%d",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("输入有误,请重新输入正确的数字\n");
//		scanf("%d",&shuru[i]);
		fflush(stdin);
	}
	if(daan!=shuru[i])
	{
		printf("你做错了，不加分!\n");
		return 0;
	}
	else
	{
		printf("恭喜你答对了，加10分!\n");
		return 10;
	}
}
int chengfa6(int diyi,int dier,int *shuru,int i)
{
	int daan;
	printf("请做下题：\n");
	daan=diyi*dier;
	printf("%-2d×%2d = ",diyi,dier);
	while(scanf("%d",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("输入有误,请重新输入真确的数字\n");
//		scanf("%d",&shuru[i]);
		fflush(stdin);
	}
	if(daan!=shuru[i])
	{
		printf("你做错了，不加分!\n");
		return 0;
	}
	else
	{
		printf("恭喜你答对了，加10分!\n");
		return 10;
	}
}
int chufa6(int diyi,int dier,int *shuru,int i)
{
	int daan;
	printf("请做下题：\n");
	daan=diyi/dier;
	printf("%-2d÷%2d = ",diyi,dier);
	while(scanf("%d",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("输入有误,请重新输入真确的数字\n");
//		scanf("%d",&shuru[i]);
		fflush(stdin);
	}
	if(daan!=shuru[i])
	{
		printf("你做错了，不加分!\n");
		return 0;
	}
	else
	{
		printf("恭喜你答对了，加10分!\n");
		return 10;
	}
}
int quyu6(int diyi,int dier,int *shuru,int i)
{
	int daan;
	printf("请做下题：\n");
	daan=diyi%dier;
	printf("%-2d%%%2d = ",diyi,dier);
	while(scanf("%d",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("输入有误,请重新输入真确的数字\n");
//		scanf("%d",&shuru[i]);
		fflush(stdin);
	}
	if(daan!=shuru[i])
	{
		printf("你做错了，不加分!\n");
		return 0;
	}
	else
	{
		printf("恭喜你答对了，加10分!\n");
		return 10;
	}
}
void show6(struct jilu *head,int e)
{
	int i,j;
	struct jilu *shuchu;
	printf("一共做了%d次题\n分别为:\n",e);
	shuchu=head;
	for(i=0;i<e;i++)
	{
		printf("第%d次，%c位数的题\n",i+1,shuchu->weishu);
		for(j=0;j<10;j++)
		{
			if(shuchu->shuzi[j][3]==shuchu->shuzi[j][2])
			{
				printf("这道题答对了 :  %-2d%c%2d = %2d\n",shuchu->shuzi[j][0],shuchu->yunsuanfu[j],shuchu->shuzi[j][1],shuchu->shuzi[j][3]);
			}
			else
			{
				printf("这道题答错了 :  %-2d%c%2d    你输入的答案为: %2d   正确答案为: %2d\n",shuchu->shuzi[j][0],shuchu->yunsuanfu[j],shuchu->shuzi[j][1],shuchu->shuzi[j][2],shuchu->shuzi[j][3]);
			}
		}
		printf("\n\n总分为:%5d\n\n",shuchu->defen);
		shuchu=shuchu->next;
	}
}
void dlshow6(struct jilu *jianz,int e)
{
	int i,j;
	printf("一共做了%d次题\n分别为:\n",e);
	for(i=0;i<e;i++)
	{
		printf("第%d次，%c位数的题\n",i+1,jianz[i].weishu);
		for(j=0;j<10;j++)
		{
			if(jianz[i].shuzi[j][3]==jianz[i].shuzi[j][2])
				printf("这道题答对了 :  %-2d%c%2d = %2d\n",jianz[i].shuzi[j][0],jianz[i].yunsuanfu[j],jianz[i].shuzi[j][1],jianz[i].shuzi[j][3]);
			else
				printf("这道题答错了 :  %-2d%c%2d    你输入的答案为: %2d   正确答案为: %2d\n",jianz[i].shuzi[j][0],jianz[i].yunsuanfu[j],jianz[i].shuzi[j][1],jianz[i].shuzi[j][2],jianz[i].shuzi[j][3]);
		}
		printf("\n\n总分为:%5d\n\n",jianz[i].defen);
	}

}
void keshediqi()
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
					cheliangjinru7(qqiche,20);system("pause");system("cls");break;
			case '2':system("cls");
					chelianglikai7(qqiche,20);system("pause");system("cls");break;
			case '3':system("cls");
					konglist7(qqiche,20);system("pause");system("cls");break;
			case '4':system("cls");
					chazhao7(qqiche,20);system("pause");system("cls");break;
			case '5':system("cls");
					xianshi7(qqiche,20);system("pause");system("cls");break;
			case '6':system("cls");
					huizong7(qqiche,20,sum);system("pause");system("cls");break;
			case '7':system("cls");
					chushihua7(qqiche,20,sum);system("pause");system("cls");break;
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
	{
		printf("关闭文件失败!\n");exit(1);
	}
}
void konglist7(struct qiche *qqiche,int e)
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
void cheliangjinru7(struct qiche *qqiche,int e)
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
		printf("请选择车位:\n");
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
void chelianglikai7(struct qiche *qqiche,int e)
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
		printf("请输入您的车位号:\n");
		while(scanf("%d",&weizhi)!=1||(weizhi<=0||weizhi>20))
		{
			fflush(stdin);
			printf("请输入正确的座位号,请重新输入\n");
//			scanf("%d",&weizhi);
			fflush(stdin);
			system("pause");system("cls");
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
void chazhao7(struct qiche *qqiche,int e)
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
void xianshi7(struct qiche *qqiche,int e)
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
void huizong7(struct qiche *qqiche,int e,int sum)
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
void chushihua7(struct qiche *qqiche,int e,int sum)
{
	int i;
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
void keshedijiou()
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
				head=luru9(head);system("pause");system("cls");break;
		case '2':system("cls");
				xiougai9(head);system("pause");system("cls");break;
		case '3':system("cls");
				poyi9(head);system("pause");system("cls");break;
//		case '4':
		case '5':system("cls");
				chaxun9(head);system("pause");system("cls");break;
		case '6':system("cls");
				lioulan9(head);system("pause");system("cls");break;
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
	{
		printf("第二次关闭文件失败\n");exit(1);
	}
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
struct shebei * luru9(struct shebei *head)
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
int lioulan9(struct shebei *head)
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
void xiougai9(struct shebei *head)
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
void poyi9(struct shebei *head)
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
				zonghaofei9(head);system("pause");system("cls");break;
		case '2':system("cls");
				yisun9(head);system("pause");system("cls");break;
		case '0':flag++;break;
		}
		if(flag>0)
			break;
	}
}
void zonghaofei9(struct shebei *head)
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
void yisun9(struct shebei *head)
{
	int i=0,weizhi,j;
	char xz;
	struct shebei *prve,*qianyige;
	while(1)
	{
		j=lioulan9(head);
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
void chaxun9(struct shebei *head)
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
void keshedishi()
{
	int x,flag;
	char xz;
	FILE *fp;
	struct checi jishu;
	struct checi *head=NULL;
	struct checi *prve,*creat;
	if((fp=fopen("daba.txt","r+b"))==NULL)
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	fseek(fp,0L,0);
	x=0;
	while(fread(&jishu,sizeof(struct checi),1,fp)==1)
	{
		x++;
		creat=(struct checi*)malloc(sizeof(struct checi));
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
		printf("1)添加车次\n\n2)修改发车时间\n\n3)删除车次\n\n4)查询车次\n\n5)浏览\n\n0)退出\n\n请选择:\n");
		xz=zqsr("123450");
		switch(xz)
		{
			case '1':system("cls");
					head=tianjia0(head);system("pause");system("cls");break;
			case '2':system("cls");
					xiougai0(head);system("pause");system("cls");break;
			case '3':system("cls");
					head=shanchu0(head);system("pause");system("cls");break;
			case '4':system("cls");
					chaxun0(head);system("pause");system("cls");break;
			case '5':system("cls");
					lioulan0(head);system("pause");system("cls");break;
			case '0':flag++;break;
		}
		if(flag>0)
			break;
	}
	if(fclose(fp)!=0)
	{
		printf("第一次关闭文件失败!\n");
		exit(1);
	}
	if((fp=fopen("daba.txt","w+b"))==NULL)
	{
		printf("第二次打开文件失败!\n");
		exit(2);
	}
	prve=head;
	fseek(fp,0L,0);
	while(prve!=NULL)
	{
		fwrite(&*prve,sizeof(struct checi),1,fp);
		prve=prve->next;
	}
	if(fclose(fp)!=0)
	{
		printf("第二次关闭文件失败\n");exit(1);
	}
}
int bancijiancha(struct checi *head,int weizhi)
{
	int i;
	struct checi *prve;
	prve=head;
	for(i=0;i<weizhi-1;i++)
	{
		prve=prve->next;
	}
	for(i=0;i<S;i++)
	{
		if(prve->sseat[i].mark=='1')
			return 1;
	}
	return 0;
}
void shijian(struct checi *head,int weizhi)
{
	int i,gewei,shiwei;
	struct checi *prve;
	prve=head;
	for(i=0;i<weizhi-1;i++)
	{
		prve=prve->next;
	}
	gewei=prve->fenzhong%10;shiwei=prve->fenzhong/10;
	printf("%2d:%c%c",prve->xiaoshi,shiwei+48,gewei+48);
}
int bancishuchu(struct checi *head)
{
	int i,gewei,shiwei;
	struct checi *prve;
	prve=head;
	i=0;
	while(prve!=NULL)
	{
		gewei=prve->fenzhong%10;shiwei=prve->fenzhong/10;
		printf("第%d班车: %2d:%c%c\n",i+1,prve->xiaoshi,shiwei+48,gewei+48);
		i++;
		prve=prve->next;
	}
	return i;
}
struct checi * tianjia0(struct checi *head)
{
	char queren,xz;
	int h,m,i,flag,flag1,shiwei,gewei;
	struct checi *creat,*prve;
	if(head==NULL)
	{
		printf("目前还没有车\n请输入要添加的车次的时间(中间请用冒号隔开,如 8:30 )\n");
		while(1)
		{
			while(scanf("%d:%d",&h,&m)!=2||(h<0||h>24||m<0||m>=60))
			{
				fflush(stdin);
				printf("请输入正确的时间\n请用冒号隔开,如 8:30 。\n请重新输入在0:00 ~ 24:00之间的时间:\n");
				fflush(stdin);
			}
			fflush(stdin);
			system("cls");
			gewei=m%10;	
			shiwei=m/10;
			printf("要添加的时间为: %2d:%c%c\n是否确认?\n\n1)确认\n\n2)重新输入\n\n0)退出到主菜单\n\n请选择:\n",h,shiwei+48,gewei+48);
			queren=zqsr("120");
			if(queren=='0')
				break;
			if(queren=='2')
			{
				system("cls");
				printf("请重新输入时间\n");
				continue;
			}
			if(queren=='1')
			{
				creat=(struct checi*)malloc(sizeof(struct checi));
				head=creat;
				creat->xiaoshi=h;
				creat->fenzhong=m;
				for(i=0;i<S;i++)
				{
					creat->sseat[i].hao=i+1;
					creat->sseat[i].mark='0';
					creat->sseat[i].keren[0]='\0';
				}
				creat->next=NULL;
				printf("新的车次已建成!\n");
				break;
			}
		}
	}
	else
	{
		printf("目前的车次如下:\n");
		i=0;	
		prve=head;
		while(1)
		{	
			bancishuchu(head);
			printf("请输入要添加的车次的时间(中间请用冒号隔开,如 8:30 )\n");
			flag=0;flag1=0;
			fflush(stdin);
			while(scanf("%d:%d",&h,&m)!=2||(h<0||h>24||m<0||m>60))
			{
				fflush(stdin);
				printf("请输入正确的时间\n请用冒号隔开,如 8:30 。\n请重新输入在0:00 ~ 24:00之间的时间:\n");
				fflush(stdin);
			}
			fflush(stdin);
			prve=head;
			while(prve!=NULL)
			{
				if(prve->fenzhong==m&&prve->xiaoshi==h)
				{
					printf("该已有该车次!，是否重新输入?\n\n1)重新输入\n\n0)退回主菜单\n\n请选择\n");
					xz=zqsr("10");
					if(xz=='1')
						flag=1;
					if(xz=='0')
						flag=2;
					break;
				}
				prve=prve->next;
			}
			if(flag==1)
			{
				printf("重新输入时间\n");system("cls");continue;
			}
			if(flag==2)
				break;
			if(flag==0)
			{
				system("cls");
				gewei=m%10;	
				shiwei=m/10;
				printf("要添加的时间为: %2d:%c%c\n是否确认?\n\n1)确认\n\n2)重新输入\n\n0)退出到主菜单\n\n请选择:\n",h,shiwei+48,gewei+48);
				queren=zqsr("120");
				if(queren=='0')
					break;
				if(queren=='2')
				{
					system("cls");
					continue;
				}
				if(queren=='1')
				{
					creat=(struct checi*)malloc(sizeof(struct checi));
					prve=head;
					while(prve!=NULL)
					{
						if(prve->next!=NULL)
						{
							if((h*100+m)>(prve->xiaoshi*100+prve->fenzhong)&&(h*100+m)<(prve->next->xiaoshi*100+prve->next->fenzhong))
							{
								creat->xiaoshi=h;
								creat->fenzhong=m;
								for(i=0;i<S;i++)
								{
									creat->sseat[i].hao=i+1;
									creat->sseat[i].mark='0';
									creat->sseat[i].keren[0]='\0';
								}
								creat->next=prve->next;
								prve->next=creat;
								printf("新的车次已建成!\n");
								flag1++;
								break;
							}
						}
						else
						{
							creat->xiaoshi=h;
							creat->fenzhong=m;
							for(i=0;i<S;i++)
							{
								creat->sseat[i].hao=i+1;
								creat->sseat[i].mark='0';
								creat->sseat[i].keren[0]='\0';
							}
							creat->next=NULL;
							prve->next=creat;
							printf("新的车次已建成!\n");
							flag1++;
							break;
						}
						prve=prve->next;
					}
				}
				if(flag1>0)
					break;
			}
		}
	}
	return (head);
}
void lioulan0(struct checi *head)
{
	int i,j,k,gewei,shiwei;
	struct checi *prve;
	prve=head;
	if(head==NULL)
		printf("没有任何车次!\n");
	else
	{
		i=0;
		while(prve!=NULL)
		{
			gewei=prve->fenzhong%10;	shiwei=prve->fenzhong/10;
			printf("第%d班车: %2d:%c%c\n",i+1,prve->xiaoshi,shiwei+48,gewei+48);
			i++;
			for(j=0,k=0;j<S;j++)
			{
				if(prve->sseat[j].mark=='1')
				{
					printf("第%2d座位: %s  \n",prve->sseat[j].hao,prve->sseat[j].keren);
					k++;
				}	
			}
			printf("\n\n共计%d名乘客\n\n",k);
			prve=prve->next;
		}
	}
}
void xiougai0(struct checi *head)
{
	int i,k,gewei,shiwei,weizhi,geshu,flag,flag1,m,h;
	struct checi *prve;
	char xz,queren;
	while(1)
	{	
		geshu=bancishuchu(head);
		printf("请输入要修改的车次序号:\n");
		while(scanf("%d",&weizhi)!=1||(weizhi<0||weizhi>geshu))
		{
			fflush(stdin);
			printf("请输入正确的序号,请重新输入\n");system("cls");
			fflush(stdin);
		}
		fflush(stdin);
		k=bancijiancha(head,weizhi);
		if(k==1)
		{
			printf("该班次车已经有票被预订，不能被修改!\n\n1)重新选择\n\n0)退出到主菜单\n\n请选择:\n");
			xz=zqsr("10");
			if(xz=='1')
			{
				system("cls");
				continue;
			}
			else
				break;
		}
		if(k==0)
		{
			printf("您选择的是第%d班次车,出发时间为: ",weizhi);
			shijian(head,weizhi);
			printf("\n\n是否确认?\n\n1)确认\n\n2)重新选择\n\n0)退出到主菜单\n\n请选择:\n");
			queren=zqsr("120");
			if(queren=='0')
				break;
			if(queren=='2')
			{	
				system("cls");continue;
			}
			else
			{
				while(1)
				{
					system("cls");
					bancishuchu(head);
					printf("请输入要修改的车次的时间(中间请用冒号隔开,如 8:30 )\n");
					flag=0;flag1=0;
					fflush(stdin);
					while(scanf("%d:%d",&h,&m)!=2||(h<0||h>24||m<0||m>60))
					{
						fflush(stdin);
						printf("请输入正确的时间\n请用冒号隔开,如 8:30 。\n请重新输入在0:00 ~ 24:00之间的时间:\n");
						fflush(stdin);
					}
					fflush(stdin);
					prve=head;
					while(prve!=NULL)
					{
						if(prve->fenzhong==m&&prve->xiaoshi==h)
						{
							printf("该已有该车次!，是否重新输入?\n\n1)重新输入\n\n0)退回主菜单\n\n请选择\n");
							xz=zqsr("10");
							if(xz=='1')
								flag=1;
							if(xz=='0')
								flag=2;
							break;
						}
						prve=prve->next;
					}
					if(flag==1)
					{
						printf("重新输入时间\n");system("cls");continue;
					}
					if(flag==2)
						break;
					if(flag==0)
					{
						system("cls");
						gewei=m%10;	
						shiwei=m/10;
						printf("要添加的时间为: %d:%c%c\n是否确认?\n\n1)确认\n\n2)重新输入\n\n0)退出到主菜单\n\n请选择:\n",h,shiwei+48,gewei+48);
						queren=zqsr("120");
						if(queren=='0')
							break;
						if(queren=='2')
						{
							system("cls");
							continue;
						}
						if(queren=='1')
						{
							prve=head;
							for(i=0;i<weizhi-1;i++)
							{
								prve=prve->next;
							}
							prve->fenzhong=m;
							prve->xiaoshi=h;
							flag1++;
							printf("修改成功\n");
							break;
						}
					}
					if(flag1>0)
						break;
				}
			}
		}
		break;
	}
}
struct checi *shanchu0(struct checi *head)
{
	int i,weizhi,flag,geshu,k;
	char xz,queren;
	struct checi *prve,*qianyige;
	while(1)
	{
		flag=0;
		printf("以下是已有的班次:\n");
		geshu=bancishuchu(head);
		printf("\n\n请选择要删除的班次:\n");
		while(scanf("%d",&weizhi)!=1||(weizhi<0||weizhi>geshu))
		{
			fflush(stdin);
			printf("请输入正确的序号,请重新输入\n");system("cls");
			fflush(stdin);
		}
		fflush(stdin);
		k=bancijiancha(head,weizhi);
		if(k==1)
		{
			printf("该班次车已经有票被预订，不能被修改!\n\n1)重新选择\n\n0)退出到主菜单\n\n请选择:\n");
			xz=zqsr("10");
			if(xz=='1')
			{
				system("cls");continue;
			}
			else
				break;
		}
		if(k==0)
		{
			printf("您选择的是第%d班次车,出发时间为: ",weizhi);
			shijian(head,weizhi);
			printf("\n\n是否确认?\n\n1)确认\n\n2)重新选择\n\n0)退出到主菜单\n\n请选择:\n");
			queren=zqsr("120");
			if(queren=='0')
				break;
			if(queren=='2')
			{	
				system("cls");continue;
			}
			else
			{
				prve=head;
				if(weizhi==1)
				{
					head=prve->next;
					free(prve);
					printf("删除成功\n");
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
					printf("删除成功\n");
				}
			}	
		}
		break;
	}
	return (head);
}
void chaxun0(struct checi *head)
{
	int i,weizhi,flag,geshu;
	char queren,xz,xz1;
	struct checi *prve;
	while(1)
	{
		printf("以下是已有的班次:\n");
		geshu=bancishuchu(head);
		printf("\n\n请选择要查询的班次:\n");
		while(scanf("%d",&weizhi)!=1||(weizhi<0||weizhi>geshu))
		{
			fflush(stdin);
			printf("请输入正确的序号,请重新输入\n");system("cls");
			fflush(stdin);
		}
		fflush(stdin);
		printf("您选择的是第%d班次车,出发时间为: ",weizhi);
		shijian(head,weizhi);
		printf("\n\n是否确认?\n\n1)确认\n\n2)重新选择\n\n0)退出到主菜单\n\n请选择:\n");
		queren=zqsr("120");
		if(queren=='0')
			break;
		if(queren=='2')
		{	
			system("cls");continue;
		}
		else
		{	
			prve=head;
			for(i=0;i<weizhi-1;i++)
				prve=prve->next;
			while(1)
			{
				system("cls");flag=0;
				printf("1)空座位列表\n\n2)已预订座位列表\n\n3)预定座位\n\n4)取消预定\n\n0)退出\n\n请选择;\n");
				xz=zqsr("12340");
				switch(xz)
				{
				case '1':system("cls");
						konglist0(prve);system("pause");system("cls");break;
				case '2':system("cls");
						alist0(prve);system("pause");system("cls");break;
				case '3':system("cls");
						yuding0(prve);system("pause");system("cls");break;
				case '4':system("cls");
						quxiao0(prve);system("pause");system("cls");break;
				case '0':flag++;break;
				}
				if(flag>0)
					break;
			}
		}
		system("cls");
		printf("是否查询其他车次?\n\n1)查询其他车次\n\n0)退出到主菜单\n\n请选择:\n");
		xz1=zqsr("10");
		if(xz1=='1')
		{
			system("cls");continue;
		}
		else
			break;
	}
}
int konglist0(struct checi *weizhi)
{
	int i,geshu=0;
	for(i=0;i<S;i++)
	{
		if(weizhi->sseat[i].mark=='0')
		{
			printf("第%2d位    ",i+1);
			geshu++;
			if(geshu%5==0)
				printf("\n");
		}
	}
	if(geshu==0)
		printf("\n所有的座位都被预订了!\n");
	else
		printf("\n空座位共计%d个\n",geshu);
	return geshu;
}
int alist0(struct checi *weizhi)
{
	int i,geshu=0;
	for(i=0;i<S;i++)
	{
		if(weizhi->sseat[i].mark=='1')
		{
			printf("第%2d位: 客人为: %s\n",weizhi->sseat[i].hao,weizhi->sseat[i].keren);
			geshu++;
		}
	}
	if(geshu==0)
		printf("\n所有的座位都没有被预订了!\n");
	else
		printf("\n已预订座位共计%d个\n",geshu);
	return geshu;
}
void yuding0(struct checi *weizhi)
{
	int x,p[S],y,i,flag1=0,j=0,flag2;
	char queren,xz,xz1;
	for(i=0;i<S;i++)
	{
		if(weizhi->sseat[i].mark=='1')
		{
			p[j]=i;
			j++;
		}
	}
	while(1)
	{	
		flag2=0;
		y=konglist0(weizhi);
		printf("请输入您要预定的座位号:\n");
		while(scanf("%d",&x)!=1||(x<0||x>S))
		{
			fflush(stdin);
			printf("输入有误,请输入正确的座位号\n请重新输入:\n");
			fflush(stdin);
		}
		xz='2';
		for(i=0;i<y;i++)
		{
			if((x-1)==p[i])
			{
				printf("该位置已经被预定了!\n\n1)重新选择\n\n0)退出预定\n\n请选择:\n");
				xz=zqsr("10");
				break;
			}
		}
		if(xz=='1')
		{		
			system("cls");continue;
		}
		if(xz=='0')
			break;
		else
		{
			while(1)
			{
				system("cls");
				printf("您要预定的座位为:第%d位\n\n是否确认?\n\n1)确认\n\n2)重新选择\n\n0)退出预定\n\n请选择:\n",x);
				queren=zqsr("120");
				if(queren=='0')
					break;
				if(queren=='2')
				{
					system("cls");flag2++;break;
				}
				else
				{
					while(1)
					{
						system("cls");
						printf("请输入您的姓名:\n");
						gets(weizhi->sseat[x-1].keren);
						printf("您输入的姓名为:%s\n\n是否确认?\n\n1)确认\n\n2)重新输入\n\n请选择;\n",weizhi->sseat[x-1].keren);
						xz1=zqsr("12");
						if(xz1=='1')
						{
							weizhi->sseat[x-1].mark='1';
							break;
						}
						else
						{
							system("cls");continue;
						}
					}
					printf("您已成功预定了大巴车,时间为:");shijian(weizhi,0);
					printf("  的第%d号座位\n\n",x);
				}
				break;
			}
		}
		if(flag2>0)
			continue;
		break;
	}
}
void quxiao0(struct checi *weizhi)
{
	int i,flag,x;
	char xingming[16],xz,xz1;
	while(1)
	{
		printf("请输入您的姓名:\n");
		gets(xingming);
		for(i=0,flag=0;i<S;i++)
		{
			if(strcmp(weizhi->sseat[i].keren,xingming)==0)
			{
				flag++;
				x=i;
				break;
			}
		}
		if(flag==0)
		{
			printf("您输入的姓名为: %s\n您没有预定座位\n\n1)重新输入姓名\n\n0)退出取消预订\n\n请选择:\n",xingming);
			xz=zqsr("10");
			if(xz=='0')
				break;
			else
			{
				system("cls");continue;
			}
		}
		else
		{
			printf("您预定的座位为:第%c位\n\n是否确认取消预定?\n\n1)确认\n\n0)退回上一级菜单\n\n请选择:\n",weizhi->sseat[x].hao);
			xz1=zqsr("10");
			if(xz1=='0')
				break;
			else
			{
				weizhi->sseat[x].mark='0';
				printf("您已成功取消预定\n");
				break;
			}
		}
	}
}
void keshefujia()
{
	int flag;
	char xz;
	while(1)
	{
		flag=0;
		printf("1)单人对弈者先下\n\n2)单人电脑先下\n\n0)退出\n\n请选择\n");
		xz=getchar();
		fflush(stdin);
		while(strchr("120",xz)==NULL)
		{
			printf("请输入正确选项,请重新输入\n");
			xz=getchar();
			fflush(stdin);
		}
		switch(xz)
		{
		case '1':system("cls");
				renxian();system("pause");system("cls");break;
		case '2':system("cls");
				dianxian();system("pause");system("cls");break;
		case '0':flag++;break;
		}
		fflush(stdin);
		if(flag>0)
			break;
	}
	system("cls");
	printf("拜拜\n");
}
void dianxian(void)
{
		int i,j,shengyu,k;
	char qipan[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			qipan[i][j]=' ';
	}
	while(1)
	{
		shengyu=jiance10(qipan);
		if(shengyu==0)
		{
			printf("平局\n");
			break;
		}		
		if((k=diannao(qipan))!=0)
			break;
		shengyu=jiance10(qipan);
		if(shengyu==0)
		{
			printf("平局\n");
			break;
		}
		if(shengyu!=0)
		{
			printf("该你了\n");system("pause");system("cls");
		}
		if((k=duiyizhe(qipan))!=0)
			break;	
		else
		{
			printf("接下来是电脑下子\n");system("pause");
		}
	}
	if(k==1)
		puts("你赢了!\1");
	if(k==2)
		puts("你输了!");
}
void renxian(void)
{
	int i,j,shengyu,k;
	char qipan[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			qipan[i][j]=' ';
	}
	while(1)
	{
		shengyu=jiance10(qipan);
		if(shengyu==0)
		{
			printf("平局\n");
			break;
		}
		if((k=duiyizhe(qipan))!=0)
			break;
		shengyu=jiance10(qipan);
		if(shengyu==0)
		{
			printf("平局\n");
			break;
		}
		else
		{
			printf("接下来是电脑下子\n");system("pause");fflush(stdin);
		}
		if((k=diannao(qipan))!=0)
			break;	
		else
		{
			printf("该你了\n");system("pause");	system("cls");fflush(stdin);
		}
	}
	if(k==1)
		puts("你赢了!\1");
	if(k==2)
		puts("你输了!");
}


void shuchuqipan(char qipan[][3])
{
	int i,j;
	printf("----------\n");
	for(i=0;i<3;i++)
	{
		printf("|");
		for(j=0;j<3;j++)
			printf("%2c|",qipan[i][j]);
		printf("\n----------\n");
	}
}
int duiyizhe(char qipan[][3])
{
	int yi,er;
	char queren;
	shuchuqipan(qipan);
	printf("\n\n请输入要将棋子放入的的位置(如 1,2 ,用逗号隔开):\n");
	while(1)
	{
		while((scanf("%d,%d",&yi,&er)!=2)||(yi<0||yi>3||er<0||er>3))
		{
			fflush(stdin);
			system("cls");shuchuqipan(qipan);
			printf("请输入正确的位置!左上角为 1,1 右下角为 3,3 \n请不要越界，请重新输入\n");
		}
		fflush(stdin);
		if(qipan[yi-1][er-1]=='X'||qipan[yi-1][er-1]=='O')
		{
			printf("该位置已经有棋子!\n请重新输入位置\n");system("pause");
			system("cls");shuchuqipan(qipan);printf("请重新输入，要放入的位置\n");
			continue;
		}
		printf("输入的位置为(%d,%d)\n\n是否确认?\n\n1)确认\n\n2)重新输入\n\n请选择:\n",yi,er);
		queren=getchar();
		fflush(stdin);
		while(strchr("12",queren)==NULL)
		{
			printf("输入有误,请重新输入正确的选项 y或n\n");
			queren=getchar();
			fflush(stdin);
		}
		if(queren=='1')
		{
			system("cls");
			qipan[yi-1][er-1]='X';
			shuchuqipan(qipan);
			if(shengfu(qipan)==1)
				return 1;
			else
			{
				return 0;
			}
		}
		else
		{
			system("cls");shuchuqipan(qipan);printf("请重新输入，要放入的位置\n");
			continue;
		}
	}
}
int diannao(char qipan[][3])
{
	
	int kongwei[9][2];
	int i,j,k,weizhi,flag,flag1;
	int k1,k2,k3,k4,p,e;
	int k5,k6,k7,k8;
	for(i=0,k=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(qipan[i][j]==' ')
			{
				kongwei[k][0]=i;
				kongwei[k][1]=j;
				k++;
			}
		}
	}
	flag=0;
	system("cls");
	if(k==9)
	{
		qipan[1][1]='O';
		shuchuqipan(qipan);
	}
	else
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(qipan[i][j]=='O')
				{
					k1=0;k2=0;k3=0;k4=0;flag=0;k5=0;k6=0;k7=0;k8=0;
					for(p=0;p<3;p++)
					{
						if(j+p<3)								//防止越界
						{
							if(qipan[i][j+p]=='O')
							{
								k5++;
								if(k5==2)
									break;
							}
						}
						if(i+p<3)
						{
							if(qipan[i+p][j]=='O')
							{
								k6++;
								if(k6==2)
									break;
							}
						}
						if(i+p<3&&j+p<3)
						{
							if(qipan[i+p][j+p]=='O')
							{
								k7++;
								if(k7==2&&i==j)					//下策- -
									break;
							}
						}
						if(i+p<3&&j-p>=0)
						{
							if(qipan[i+p][j-p]=='O')
							{
								k8++;
								if(k8==2)
									break;
							}
						}
					}
					if(k5==2)
					{
						for(e=0;e<3;e++)
						{
							if(qipan[i][e]==' ')
							{
								qipan[i][e]='O';
								flag++;
								break;
							}
						}
					}
					if(k6==2)
					{
						for(e=0;e<3;e++)
						{
							if(qipan[e][j]==' ')
							{							
								qipan[e][j]='O';
								flag++;
								break;
							}
						}
					}
					if(k7==2&&i==j)
					{
						for(e=0;e<3;e++)
						{
							if(qipan[e][e]==' ')
							{
								qipan[e][e]='O';
								flag++;
								break;
							}
						}
					}
					if(k8==2)
					{
						for(e=-2;e<3;e++)
						{
							if(i+e<3&&i+e>=0&&j-e>=0&&j-e<3)
							{
								if(qipan[i+e][j-e]==' ')
								{
									qipan[i+e][j-e]='O';
									flag++;
									break;
								}
							}
						}
					}
				}
				if(flag>0)
					break;
			}
			if(flag>0)
			{
				shuchuqipan(qipan);
				break;
			}
		}
		flag1=0;
		if(flag==0)
		{
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					if(qipan[i][j]=='X')
					{
						k1=0;k2=0;k3=0;k4=0;k5=0;k6=0;k7=0;k8=0;
						for(p=0;p<3;p++)
						{
							if(j+p<3)								//防止越界
							{
								if(qipan[i][j+p]=='X')
								{
									k1++;
									if(k1==2)
										break;
								}
							}
							if(i+p<3)
							{
								if(qipan[i+p][j]=='X')
								{
									k2++;
									if(k2==2)
										break;
								}
							}
							if(i+p<3&&j+p<3)
							{
								if(qipan[i+p][j+p]=='X')								//if(qipan[i+p][j+p]=='X')
								{
									k3++;
									if(k3==2)
										break;
								}
							}
							if(i+p<3&&j-p>=0)
							{
								if(qipan[i+p][j-p]=='X')
								{
									k4++;
									if(k4==2)
										break;
								}
							}
						}
						if(k1==2)
						{
							for(e=0;e<3;e++)
							{
								if(qipan[i][e]==' ')
								{
									qipan[i][e]='O';
									flag1++;
									break;
								}
							}
						}
						if(k2==2)			//&&k3<2&&k4<2&&k1<2
						{
							for(e=0;e<3;e++)
							{
								if(qipan[e][j]==' ')
								{
									qipan[e][j]='O';
									flag1++;
									break;
								}
							}
						}
						if(k3==2)			//&&k4<2&&k1<2&&k2<2
						{
							for(e=0;e<3;e++)
							{
								if(qipan[e][e]==' ')
								{
									qipan[e][e]='O';
									flag1++;
									break;
								}
							}
						}
						if(k4==2)			//&&k1<2&&k2<2&&k3<2
						{
							for(e=-2;e<3;e++)
							{
								if(i+e<3&&i+e>=0&&j-e>=0&&j-e<3)
								{
									if(qipan[i+e][j-e]==' ')
									{
										qipan[i+e][j-e]='O';
										flag1++;
										break;
									}
								}
							}
						}
					}
					if(flag1>0)
						break;
				}
				if(flag1>0)
				{
					shuchuqipan(qipan);
					break;
				}
			}
		}
		if(flag==0&&flag1==0)
		{
			srand((unsigned)time(0));
			weizhi=rand()%k;
			qipan[kongwei[weizhi][0]][kongwei[weizhi][1]]='O';
			shuchuqipan(qipan);
		}
	}
	if(shengfu(qipan)==2)
		return 2;
	else
	{
		return 0;
	}
}
int jiance10(char qipan[][3])
{
	int i,j,k;
	for(i=0,k=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(qipan[i][j]==' ')
				k++;
		}
	}
	return k;
}
int shengfu(char qipan[][3])
{
	int i;
	int j,k11,k12,k13,k14,k21,k22,k23,k24,p;
/*	for(i=0;i<3;i++)
	{
		if(qipan[i][0]==qipan[i][1]&&qipan[i][0]==qipan[i][2]&&qipan[i][1]==qipan[i][2]&&qipan[i][0]=='X')
			return 1;
		if(qipan[i][0]==qipan[i][1]&&qipan[i][0]==qipan[i][2]&&qipan[i][1]==qipan[i][2]&&qipan[i][0]=='X')
			return 2;
		if(qipan[0][i]==qipan[1][i]&&qipan[0][i]==qipan[2][i]&&qipan[1][i]==qipan[2][i]&&qipan[0][i]=='X')
			return 1;
		if(qipan[0][i]==qipan[1][i]&&qipan[0][i]==qipan[2][i]&&qipan[1][i]==qipan[2][i]&&qipan[0][i]=='X')
			return 2;
	}
	if(qipan[0][0]==qipan[1][1]&&qipan[0][0]==qipan[2][2]&&qipan[1][1]==qipan[2][2]&&qipan[0][0]=='X')
		return 1;
	if(qipan[0][0]==qipan[1][1]&&qipan[0][0]==qipan[2][2]&&qipan[1][1]==qipan[2][2]&&qipan[0][0]=='X')
		return 2;
	if(qipan[0][2]==qipan[1][1]&&qipan[0][2]==qipan[2][0]&&qipan[1][1]==qipan[2][0]&&qipan[1][1]=='X')
		return 1;
	if(qipan[0][2]==qipan[1][1]&&qipan[0][2]==qipan[2][0]&&qipan[1][1]==qipan[2][0]&&qipan[1][1]=='X')
		return 1;*/
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(qipan[i][j]!=' ')
			{
				k11=0;k12=0;k13=0;k14=0;k21=0;k22=0;k23=0;k24=0;
				for(p=0;p<3;p++)
				{
					if(j+p<3)
					{
						if(qipan[i][j+p]=='X')
							k11++;
						if(qipan[i][j+p]=='O')
							k21++;
					}
					if(i+p<3)
					{
						if(qipan[i+p][j]=='X')
							k12++;
						if(qipan[i+p][j]=='O')
							k22++;
					}
					if(i+p<3&&j+p<3)
					{
						if(qipan[i+p][j+p]=='X')
							k13++;
						if(qipan[i+p][j+p]=='O')
							k23++;
					}
					if(i+p<3&&j-p>=0)
					{
						if(qipan[i+p][j-p]=='X')
							k14++;
						if(qipan[i+p][j-p]=='O')
							k24++;
					}
				}
				if(k11==3||k12==3||k13==3||k14==3)
					return 1;
				if(k21==3||k22==3||k23==3||k24==3)
					return 2;
			}
		}
	}
	return 0;
}





