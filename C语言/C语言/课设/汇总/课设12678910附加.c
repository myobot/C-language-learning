#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include <stddef.h>
#define S 45
# define PRT printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","��������",xgong.xingming,"���˹���",xgong.gongh,"��λ����",xgong.yfa[0],"н������",xgong.yfa[1],"ְ�����",xgong.yfa[2],"�����",xgong.yko[0],"���շ�",xgong.yko[1],"ˮ���",xgong.yko[2],"ʵ������",xgong.shifa);
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
void xianshi2(struct tongxunlu txl[],int e);		   //��ʾ������
void dangexianshi2(struct tongxunlu txl[],int e);   //��ʾ����
void zhuzhaixianshi2(struct tongxunlu txl[],int e); //��ʾ����
void shoujixianshi2(struct tongxunlu txl[],int e);  //��ʾ����
void quanbuxianshi2(struct tongxunlu txl[],int e);  //��ʾ����
void chaxun2(struct tongxunlu txl[],int e); 
void xiougai2(struct tongxunlu txl[],int e);					 //�޸�������
struct tongxunlu bhxiougai2(struct tongxunlu txl[],int e,int weizhi);    //����޸ĺ���
struct tongxunlu xmxiougai2(struct tongxunlu);		 	 //�����޸ĺ���
struct tongxunlu xnxiougai2(struct tongxunlu);			 //�Ա������޸ĺ���
struct tongxunlu zzxiougai2(struct tongxunlu);			 //סլ�޸ĺ���
struct tongxunlu sjxiougai2(struct tongxunlu);			 //�ֻ��޸ĺ���
struct tongxunlu qbxiougai2(struct tongxunlu txl[],int e,int weizhi);	//ȫ���޸ĺ���
int shanchu2(struct tongxunlu txl[],int e);					//ɾ��������
void zzshanchu2(struct tongxunlu *txl,int weizhi);
void sjshanchu2(struct tongxunlu *txl,int weizhi);
int qbshanchu2(struct tongxunlu *txl,int weizhi,int e);
void keshedier(void);
char zqsr(char *c);						//�������ѡ����ȷ���
void wuzhanghao6(void);					//���˺�����������
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
	char zhanghao[16];					//�˺�
	char mima[16];						//����
	char wenti[24];						//ѡ�������
	char daan[16];						//�����
};
struct jilu								//�浽��Ӧ�˺������ļ���
{
	char weishu;						//ѡ���λ��
	int cuowugeshu;						//�������
	char yunsuanfu[10];					//ÿ����������;
	int shuzi[10][4];					//�������������ʹ��������Ĵ𰸣���ȷ��;
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
		printf("1)�����һ��\n\n2)����ڶ���\n\n3)���������\n\n4)���������\n\n5)����ڰ���\n\n6)����ھ���\n\n7)�����ʮ��\n\n8)���踽��\n\n0)�˳�\n\n��ѡ��;\n");
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
	printf("�ݰ�\n");
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
			puts("���ļ�ʧ��!");
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
			puts("��һ�ιر��ļ�ʧ�ܣ�");
			exit(2);
		}
		xgong.shifa=-1;
		q=x+1;
		menu1();
		xz=getchar();
		eatline1();
		while(strchr("1234560",xz)==NULL)
		{
			puts("�������,��������ȷѡ����� 1�� 2�� 3");
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
//		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","��������",xgong.xingming,"���˹���",xgong.gongh,"��λ����",xgong.yfa[0],"н������",xgong.yfa[1],"ְ�����",xgong.yfa[2],"�����",xgong.yko[0],"���շ�",xgong.yko[1],"ˮ���",xgong.yko[2],"ʵ������",xgong.shifa);
		if((fp=fopen("gongzi.txt","w+b"))==NULL)
		{
			puts("�ڶ��δ��ļ�ʧ��!");
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
			puts("�ڶ��ιر��ļ�ʧ��!");
			exit(4);
		}
		system("cls");
		if(flag>0)
			break;
	}
}
void menu1(void)
{
	printf("%16s\n%20s\n%20s\n%20s\n%20s\n%28s\n%20s\n%20s\n%16s\n","ְ�����ʹ���ϵͳ","1  ����","2  ��ѯ","3  ɾ��","4  �޸�","5  ����ʵ������","6  ��ʾ","0  �˳�","��ѡ��:");
}
void eatline1(void)
{
	while((getchar())!='\n')
		continue;
}
struct gongren chuangjian1(struct gongren gong[],int e)//�����Զ����ɣ�Ӧ�û����һЩ
{
	int flag=0,flag1=0;
	int i;
	struct gongren xgong;
	puts("��ѡ���˴���ѡ��");
	puts("��������ù��˵�����:");
	if(e==0)
		gets(xgong.xingming);
	else
	{
		while(1)												//��������
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
				printf("�Ѵ��ڸù���!\n��������빤������\n");
		}
	}
	puts("������ù��˵Ĺ���:");
	if(e==0)
		gets(xgong.gongh);
	else
	{
		while(1)												//���Ų���
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
				printf("�ù����Ѵ���\n��������������\n");
		}
	}
	puts("��������������ù��˵� ��λ���ʡ�н�����ʡ�ְ�����(�ÿո����)");
	while((scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]))!=3)
	{
		fflush(stdin);
		puts("�����������������������������ַ�,������������ȷ�Ĺ���");
//		scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]);
	}
	fflush(stdin);
	puts("��������������ù��˵� ����ѡ����շѡ�ˮ���(�ÿո����)");
	while((scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]))!=3)
	{
		fflush(stdin);
		puts("�����������������������������ַ�,������������ȷ�Ĺ���");
//		scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]);
	}
	fflush(stdin);
	xgong.shifa=xgong.yfa[0]+xgong.yfa[1]+xgong.yfa[2]-xgong.yko[0]-xgong.yko[1]-xgong.yko[2];
	puts("���ѳɹ������ù�����Ϣ");
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
	puts("ȫ������ʵ����������:");
	printf("%-16s%-16s%-16s\n","���˹���","��������","ʵ������");
	for(i=0;i<e;i++)
	{
		printf("%-16s%-16s%-16d\n",gong[i].gongh,gong[i].xingming,gong[i].shifa);
	}
	for(i=0;i<e;i++)
	{
		sum+=gong[i].shifa;
	}
	printf("%-s:%-16d\n","��ʵ������",sum);
}
void chaxun1(struct gongren gong[],int e)
{
	char xz;
	int flag=0;
	while(1)
	{
		printf("ѡ���˹��˲�ѯѡ��\n1)�����Ų�ѯ\n2)��������ѯ\n0)�˳�\n����������ѡ��:\n");
		xz=getchar();
		eatline1();
		while(strchr("120",xz)==NULL)
		{
			printf("��������ȷ��ѡ��� 1�� 2�� 0��\n");
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
	printf("������Ҫ��ѯ�Ĺ��˵Ĺ���:\n");
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
		printf("�ù��˵���Ϣ���£�\n");
		printf("%-8s:%-16s\n%-8s:%-16s\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n","��������",gong[weizhi].xingming,"���˹���",gong[weizhi].gongh,"��λ����",gong[weizhi].yfa[0],"н������",gong[weizhi].yfa[1],"ְ�����",gong[weizhi].yfa[2],"�����",gong[weizhi].yko[0],"���շ�",gong[weizhi].yko[1],"ˮ���",gong[weizhi].yko[2],"ʵ������",gong[weizhi].shifa);
	}
	else
		puts("û�иù���");
}
void xmchaxun1(struct gongren gong[],int e)
{
	int flag=0,weizhi;
	int i;
	char xingming[10];
	printf("������Ҫ��ѯ�Ĺ��˵�����:\n");
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
		puts("�ù��˵���Ϣ���£�\n");
		printf("%-8s:%-16s\n%-8s:%-16s\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n","��������",gong[weizhi].xingming,"���˹���",gong[weizhi].gongh,"��λ����",gong[weizhi].yfa[0],"н������",gong[weizhi].yfa[1],"ְ�����",gong[weizhi].yfa[2],"�����",gong[weizhi].yko[0],"���շ�",gong[weizhi].yko[1],"ˮ���",gong[weizhi].yko[2],"ʵ������",gong[weizhi].shifa);
	}
	else
		puts("û�иù���");
}
int shanchu1(struct gongren gong[],int e)
{
	int flag=0,weizhi;
	int i;
	char gonghao[11],queren;
	printf("��������Ҫɾ���Ĺ��˵Ĺ���\n");
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
		puts("�ù��˵���Ϣ���£�");
		printf("%-8s:%-16s\n%-8s:%-16s\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n","��������",gong[weizhi].xingming,"���˹���",gong[weizhi].gongh,"��λ����",gong[weizhi].yfa[0],"н������",gong[weizhi].yfa[1],"ְ�����",gong[weizhi].yfa[2],"�����",gong[weizhi].yko[0],"���շ�",gong[weizhi].yko[1],"ˮ���",gong[weizhi].yko[2],"ʵ������",gong[weizhi].shifa);
		printf("�Ƿ�ɾ���ù�����Ϣ?\n1):ɾ��\n2):ȡ��\n����������ѡ��\n");
		queren=getchar();
		eatline1();
		while(strchr("12",queren)==NULL)
		{
			puts("��������ȷѡ��,�� 1�� 2");
			system("cls");
			queren=getchar();
			eatline1();
		}
		if(queren=='1')
		{
			for(;weizhi<e-1;weizhi++)
			{
				gong[weizhi]=gong[weizhi+1];			//������ǰ����(ɾ��)
			}
			puts("���ѳɹ�ɾ���ù���");	
			return e - 1;
		}
		if(queren=='0')
		{
			puts("��ѡ����ȡ��ɾ��");
		}
	}
	else
		puts("û�иù���");
	return e;
}
void xianshi1(struct gongren gong[],int e)
{
	int flag=0;
	int i,j,k;
	char xuanz;
	struct gongren xgong;
	printf("1):����������˳����ʾ\n2):����������������ʾ\n3):��ʵ����������������ʾ\n��ѡ��:\n");
	xuanz=getchar();
	eatline1();
	while(strchr("123",xuanz)==NULL)
	{
		puts("��������ȷѡ��� 1�� 2�� 3��");
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
		puts("ȫ��������Ϣ����:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","���˹���","��������","��λ����","н������","ְ�����","�����","���շ�","ˮ���","ʵ������");
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
		puts("ȫ��������Ϣ����:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","���˹���","��������","��λ����","н������","ְ�����","�����","���շ�","ˮ���","ʵ������");
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
		puts("ȫ��������Ϣ����:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","���˹���","��������","��λ����","н������","ְ�����","�����","���շ�","ˮ���","ʵ������");
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
	printf("��������Ҫ�޸ĵĹ��˵Ĺ���\n");
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
			puts("�ù��˵���Ϣ���£�");
	//		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","��������",jianz[weizhi].xingming,"���˹���",jianz[weizhi].gongh,"��λ����",jianz[weizhi].yfa[0],"н������",jianz[weizhi].yfa[1],"ְ�����",jianz[weizhi].yfa[2],"�����",jianz[weizhi].yko[0],"���շ�",jianz[weizhi].yko[1],"ˮ���",jianz[weizhi].yko[2],"ʵ������",jianz[weizhi].shifa);
			PRT;
			printf("%s\n%s\n%s\n%s\n%s\n%s\n","\n1):�޸ĸù��˵Ĺ���","2):�޸ĸù��˵�����","3):�޸ĸù��˵� ��λ���ʡ�н�����ʡ�ְ�����","4):�޸ĸù��˵� ����ѡ����շѡ�ˮ���","5):ȫ���޸�","0):�˳����˵�");
			puts("��ѡ��");
			xuanz=getchar();
			eatline1();
			while(strchr("123450",xuanz)==NULL)
			{
				puts("��������ȷѡ����� 1�� 2�� ...");
				xuanz=getchar();
				eatline1();
			}
			if(xuanz=='1')
			{
				puts("������ù��˵Ĺ���:");
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
						printf("�ù����Ѵ���\n��������������\n");
				}
			}
			if(xuanz=='2')
			{
				puts("��������ù��˵�����:");
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
						printf("�Ѵ��ڸù���!\n��������빤������\n");
				}
			}
			if(xuanz=='3')
			{
				printf("����������ù����µ� ��λ���ʡ�н�����ʡ�ְ�����(�ÿո����)\n");
				while((scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]))!=3)
				{
					fflush(stdin);
					puts("�����������������������������ַ�,������������ȷ�Ĺ���");
		//			scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]);
				}
				xgong.shifa=xgong.yfa[0]+xgong.yfa[1]+xgong.yfa[2]-xgong.yko[0]-xgong.yko[1]-xgong.yko[2];
				fflush(stdin);
			}
			if(xuanz=='4')
			{
				puts("����������ù����µ� ����ѡ����շѡ�ˮ���(�ÿո����)");
				while((scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]))!=3)
				{
					fflush(stdin);
					puts("�����������������������������ַ�,������������ȷ�Ĺ���");
		//			scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]);
				}
				xgong.shifa=xgong.yfa[0]+xgong.yfa[1]+xgong.yfa[2]-xgong.yko[0]-xgong.yko[1]-xgong.yko[2];
				fflush(stdin);
			}
			if(xuanz=='5')
			{
				puts("��������ù��˵�����:");
				gets(xgong.xingming);
				puts("������ù��˵Ĺ���:");
				gets(xgong.gongh);
				puts("��������������ù��˵� ��λ���ʡ�н�����ʡ�ְ�����(�ÿո����)");
				while((scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]))!=3)
				{
					fflush(stdin);
					puts("�����������������������������ַ�,������������ȷ�Ĺ���");
//					scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]);
				}
				fflush(stdin);
				puts("��������������ù��˵� ����ѡ����շѡ�ˮ���(�ÿո����)");
				while((scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]))!=3)
				{
					fflush(stdin);
					puts("�����������������������������ַ�,������������ȷ�Ĺ���");
	//				scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]);
				}
				fflush(stdin);
				xgong.shifa=xgong.yfa[0]+xgong.yfa[1]+xgong.yfa[2]-xgong.yko[0]-xgong.yko[1]-xgong.yko[2];
			}
			if(xuanz=='0')
			{
				flag3=1;
				puts("��ѡ�����˳����˵�");
			}
			system("cls");
			if(flag3==0)
			{
				printf("���ù��˵���Ϣ����:\n");
		//		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","��������",gong.xingming,"���˹���",gong.gongh,"��λ����",gong.yfa[0],"н������",gong.yfa[1],"ְ�����",gong.yfa[2],"�����",gong.yko[0],"���շ�",gong.yko[1],"ˮ���",gong.yko[2],"ʵ������",gong.shifa);
				PRT;
				printf("�Ƿ�ȷ���޸�?\ny):ȷ��\nn):ȡ��\n��ѡ��ѡ��\n");
				queren=getchar();
				eatline1();
				while(strchr("yn",queren)==NULL)
				{
					puts("��������ȷѡ��,  y �� n");
					queren=getchar();
					eatline1();
				}
				if(queren=='y')
				{
					gong[weizhi]=xgong;
					puts("�޸ĳɹ�");
				}
				if(queren=='n')
				{
					puts("�޸���ȡ��");
				}
			}
			system("cls");
			if(flag3==1)
				break;
			}
	}
	else
		puts("û�иù��ˣ�");
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
			puts("��һ�δ��ļ�ʧ�ܣ�");
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
			puts("��һ�ιر��ļ�ʧ��!");
			exit(2);
		}
		q=x;
		txl.sjgeshu=-1;
		menu2();
		xz=getchar();
		eatline();
		while(strchr("1234560",xz)==NULL)
		{
			puts("��������ȷ��ѡ��!,����1�� 2�� 3��...");
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
			puts("�ڶ��δ��ļ�ʧ�ܣ�");
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
			puts("�ڶ��ιر��ļ�ʧ��!");
			exit(4);
		}
		free(jianc);
		if(flag>0)
			break;
	}
}
void menu2(void)                        //�˵�����
{
	printf("%16s\n%20s\n%20s\n%20s\n%20s\n%20s\n%20s\n%20s\n%16s\n","ͨѶ¼����ϵͳ","1  ����","2  ���","3  ��ѯ","4  �޸�","5  ɾ��","6  ��ʾ","0  �˳�","��ѡ��:");
}
void eatline(void)                      //���к���
{
	while((getchar())!='\n')
	{
		continue;
	}
}
struct tongxunlu chuangjian2(struct tongxunlu txl[],int e)          //��������
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
	printf("ѡ���˴��������ѵ�ͨѶ¼\n���������������ѵı��:\n");
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
					printf("��������Ա������أ�������������\n");
					flag++;
				}
			}
			if(flag==0)
				break;
		}
	}
	printf("��������������ѵ�����\n");
	gets(xtxl.xingming);
	printf("��������������ѵ��Ա�\n");
	gets(xtxl.xingbie);
	puts("��������������ѵ�����");
	while(scanf("%d",&xtxl.nianling)!=1)
	{
		fflush(stdin);
		puts("������������,������������ȷ����");
//		scanf("%d",&xtxl.nianling);
	}
	fflush(stdin);
	printf("�Ƿ��и����ѵ�סլ�绰?\n���� y ��,���� n ��\n");
	zzxz=getchar();
	eatline();
	while(strchr("yn",zzxz)==NULL)
	{
		puts("������������ȷ��ѡ��,�� y �� n");
		zzxz=getchar();
		eatline();
	}
	fflush(stdin);
	if(zzxz=='y')
	{
		puts("��������������ѵ�סլ�绰����");
		gets(xtxl.zhuzhai);
		fflush(stdin);
	}
	printf("�Ƿ��и����ѵ��ֻ�����?\n���� y ��,���� n ��\n");
	sjxz=getchar();
	eatline();
	while(strchr("yn",sjxz)==NULL)
	{
		puts("������������ȷ��ѡ��,�� y �� n");
		sjxz=getchar();
		eatline();
	}
	fflush(stdin);
	if(sjxz=='y')
	{
		
		for(i=0;i<4;i++)
		{
			printf("��������������ѵĵ�%d���ֻ�����:\n",i+1);
			gets(xtxl.shouji[i]);
			xtxl.sjgeshu++;
			if(i!=3)	
			{
				printf("�Ƿ��и����ѵĵ�%d���ֻ�����?\n���� y ��,���� n ��\n",i+2);
				sjxz=getchar();
				fflush(stdin);
				while(strchr("yn",sjxz)==NULL)
				{
					puts("������������ȷ��ѡ��,�� y �� n");
					sjxz=getchar();
					fflush(stdin);
				}
				fflush(stdin);
			}
			if(i==3)
			{
				puts("�ֻ�����洢�����ﵽ����޷��������!");
			}
			if(sjxz=='n')
				break;
		}
	}
	system("pause");
	system("cls");
	printf("�����ѵ�ͨѶ¼��¼�����\n�����Ǹ����ѵ�ͨѶ¼ȫò:\n");
	printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",xtxl.bianhao,"����",xtxl.xingming,"�Ա�",xtxl.xingbie,"����",xtxl.nianling,"סլ�绰",xtxl.zhuzhai);
	for(i=0;i<4;i++)
	{
		if(xtxl.shouji[i][0]=='\0')
			break;
		printf("��%d���ֻ�����:%-17s\n",i+1,xtxl.shouji[i]);
	}
	return xtxl;
}
void tianjia2(struct tongxunlu txl[],int e)//           ��Ӻ���
{
	int i,k=0,flag4=0;
	int weizhi=-1;
	char ren[16],haoma[16],xz,queren;
	printf("ѡ���������Ϣ\n");
	if(e==0)
		printf("ͨѶ¼��Ա��Ϊ0,�޷����(���ȴ���)\n");
	else
	{
		printf("ͨѶ¼�������³�Ա:\n");
		printf("%12s%12s%12s%12\n","���","����","�Ա�","�绰����");
		for(i=0;i<e;i++)
		{
			printf("%12s%12s%12s",txl[i].bianhao,txl[i].xingming,txl[i].xingbie);
			if(txl[i].zhuzhai[0]!='\0')
				k=1;
			printf("%12d\n",k+txl[i].sjgeshu);
		}
		printf("������Ҫ�����Ϣ���˵ı��\n");            //��������(ֻ������һ��!):
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
			printf("���˵���Ϣ����:\n");
			printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi].bianhao,"����",txl[weizhi].xingming,"�Ա�",txl[weizhi].xingbie,"����",txl[weizhi].nianling,"סլ�绰",txl[weizhi].zhuzhai);
			for(i=0;i<4;i++)
			{			
				if(txl[weizhi].shouji[i][0]=='\0')
					break;
				printf("��%d���ֻ�����:%-17s\n",i+1,txl[weizhi].shouji[i]);
			}
			if(txl[weizhi].zhuzhai[0]!='\0'&&txl[weizhi].sjgeshu==4)
			{
				printf("���˵�ͨѶ¼�洢�Ѵ�����!���ܼ�����Ӻ���!\n");
				flag4=1;
			}
			if(txl[weizhi].zhuzhai[0]!='\0'&&txl[weizhi].sjgeshu<4)
			{
				printf("���˵�סլ�绰�Ѵ��ڣ�ֻ��������ֻ�����(����������%d��)\n�������������,�µ��ֻ�����:\n",4-txl[weizhi].sjgeshu);
				while(1)
				{
					while(1)
					{
						gets(haoma);
						printf("Ҫ��ӵ��ֻ���Ϊ: %s\n�Ƿ�ȷ��?\n���� y ȷ�ϣ������� n ��������\n",haoma);
						queren=getchar();
						eatline();
						while(strchr("yn",queren)==NULL)
						{
							printf("ѡ���������,������������ȷѡ����� y �� n\n");
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
							puts("����������ĺ���");
					}
					if(txl[weizhi].sjgeshu==4)
					{
						puts("�ֻ�����洢�����ﵽ����,�޷��������!");
						system("pause");
						break;
					}
					printf("�Ƿ��������ֻ�����?(����������%d��)\ny)����\nn)�������\n",4-txl[weizhi].sjgeshu);
					xz=getchar();
					eatline();
					while(strchr("yn",xz)==NULL)
					{
						printf("ѡ���������,������������ȷѡ����� y �� n\n");
						xz=getchar();
						eatline();
					}
					if(xz=='n')
						break;
					else
						puts("��������һ������");
				}

			}
			if(txl[weizhi].zhuzhai[0]=='\0'&&txl[weizhi].sjgeshu<4)
			{
				while(1)
				{
					if(txl[weizhi].zhuzhai[0]=='\0'&&txl[weizhi].sjgeshu<4)//���������
					{
						printf("\n1)����ֻ�����\n2)���סլ�绰\n0)�������\n��ѡ��:\n");
						xz=getchar();
						eatline();
						while(strchr("120",xz)==NULL)
						{
							printf("ѡ���������,������������ȷѡ����� y �� n\n");
							xz=getchar();
							eatline();
						}
					}
					if(txl[weizhi].zhuzhai[0]!='\0'&&txl[weizhi].sjgeshu<4)//ֻ������ֻ���
					{
						puts("סլ�绰�Ѵ���,ֻ�ܼ�������ֻ�����.");
						printf("1)����ֻ�����\n0)�������\n��ѡ��:\n");
						xz=getchar();
						eatline();
						while(strchr("10",xz)==NULL)
						{
							printf("ѡ���������,������������ȷѡ����� y �� n\n");
							xz=getchar();
							eatline();
						}
					}
					if(txl[weizhi].zhuzhai[0]=='\0'&&txl[weizhi].sjgeshu==4)//ֻ�����סլ��
					{
						puts("�ֻ�����洢�����Ѵ�����,סլ�绰Ϊ�գ�ֻ�ܼ������סլ�绰.");
						printf("1)���סլ�绰\n0)�������\n��ѡ��:\n");
						xz=getchar();
						eatline();
						while(strchr("10",xz)==NULL)
						{
							printf("ѡ���������,������������ȷѡ����� y �� n\n");
							xz=getchar();
							eatline();
						}
					}
					if(txl[weizhi].zhuzhai[0]!='\0'&&txl[weizhi].sjgeshu==4)
					{
						puts("���д洢�Ѵﵽ���ޣ������ټ������!");
						system("pause");
						break;
					}
					system("cls");
					if(xz=='1')
					{
						printf("�������ֻ�����:\n");
						while(1)
						{
							while(1)
							{	
								gets(haoma);
								printf("Ҫ��ӵ��ֻ���Ϊ: %s\n�Ƿ�ȷ��?\n���� y ȷ�ϣ������� n ��������\n",haoma);
								queren=getchar();
								eatline();
								while(strchr("yn",queren)==NULL)
								{
									printf("ѡ���������,������������ȷѡ����� y �� n\n");
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
									puts("����������ĺ���");
							}
							if(txl[weizhi].sjgeshu==4)
							{
								puts("�ֻ�����洢�����ﵽ���ޣ������ټ������!");
								break;
							}
							printf("�Ƿ��������ֻ�����?(����������%d��)\ny)����\nn)�������\n",4-txl[weizhi].sjgeshu);
							xz=getchar();
							eatline();
							while(strchr("yn",xz)==NULL)
							{
								printf("ѡ���������,��������ȷѡ����� y �� n\n");
								xz=getchar();
								eatline();
							}
							if(xz=='n')
								break;
							else
								puts("��������һ������");
						}
					}
					if(xz=='2')
					{
						printf("������Ҫ��ӵ�סլ�绰\n");
						gets(haoma);
						printf("Ҫ��ӵ��ֻ���Ϊ: %s\n�Ƿ�ȷ��?\n���� y ȷ�ϣ������� n ��������\n",haoma);
						while(1)
						{
							queren=getchar();
							eatline();
							while(strchr("yn",queren)==NULL)
							{
								printf("ѡ���������,������������ȷѡ����� y �� n\n");
								queren=getchar();
								eatline();
							}
							if(queren=='y')
							{
								strcpy(txl[weizhi].zhuzhai,haoma);
								break;
							}
							else
								puts("����������ĺ���");
						}
					}
					system("cls");
					if(xz=='0')
						break;
				}
			}
			if(txl[weizhi].zhuzhai[0]!='\0'&&txl[weizhi].sjgeshu<4)
			{
				printf("���˵��ֻ�����洢�Ѵ����ޣ�ֻ�������סլ�绰\n��������סլ�绰:\n");
				gets(haoma);
				printf("Ҫ��ӵ��ֻ���Ϊ: %s\n�Ƿ�ȷ��?\n���� y ȷ�ϣ������� n ��������\n",haoma);
				while(1)
				{
					queren=getchar();
					eatline();
					while(strchr("yn",queren)==NULL)
					{
						printf("ѡ���������,������������ȷѡ����� y �� n\n");
						queren=getchar();
						eatline();
					}
					if(queren=='y')
					{
						strcpy(txl[weizhi].zhuzhai,haoma);
						break;
					}
					else
						puts("����������ĺ���");
				}
			}
			if(flag4==0)
			{
				printf("��Ӻ���˵���Ϣ����:\n");
				printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi].bianhao,"����",txl[weizhi].xingming,"�Ա�",txl[weizhi].xingbie,"����",txl[weizhi].nianling,"סլ�绰",txl[weizhi].zhuzhai);
				for(i=0;i<4;i++)
				{			
					if(txl[weizhi].shouji[i][0]=='\0')
						break;
					printf("��%d���ֻ�����:%-17s\n",i+1,txl[weizhi].shouji[i]);
				}
				printf("��������\n");
			}
		}
		else
			puts("û�д���!");
	}
}
void xianshi2(struct tongxunlu txl[],int e)                //��ʾ������
{
	int i,j,flag=0,k;
	char xz;
	struct tongxunlu swap;
	if(e==0)
		printf("ͨѶ¼��û�г�Ա\n");
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
		printf("1)������ʾ\n2)ֻ��ʾסլ����\n3)ֻ��ʾ�ֻ�����\n4)ȫ����Ϣ��ʾ\n��ѡ��:\n");
		xz=getchar();
		eatline();
		while(strchr("1234",xz)==NULL)
		{
			printf("������������ȷѡ��\n�� 1�� 2��...\n");
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
void dangexianshi2(struct tongxunlu txl[],int e)                //������ʾ����
{
	int i,j;
	char xz;
	char *xuhao;
	xuhao=(char *)malloc(sizeof(char)*e);
	for(i=0;i<e;i++)
	{
		xuhao[i]=i+49;
	}
	printf("    %12s\n","����");
	for(i=0;i<e;i++)
	{
		printf("%-2d: %12s\n",i+1,txl[i].xingming);
	}
	printf("��ѡ������ǰ�����\n");
	xz=getchar();
	eatline();
	while(strchr(xuhao,xz)==NULL)
	{
		printf("������������ȷ���!\n�� 1�� 2��....\n");
		xz=getchar();
		eatline();
	}
	system("cls");
	printf("%s��ȫ����Ϣ����:\n",txl[(int)xz-49].xingming);
	printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[(int)xz-49].bianhao,"����",txl[(int)xz-49].xingming,"�Ա�",txl[(int)xz-49].xingbie,"����",txl[(int)xz-49].nianling,"סլ�绰",txl[(int)xz-49].zhuzhai);
	for(j=0;j<4;j++)
	{
		if(txl[(int)xz-49].shouji[j][0]=='\0')
			break;
		printf("��%d���ֻ�����:%-17s\n",j+1,txl[(int)xz-49].shouji[j]);
	}
	free(xuhao);
}
void zhuzhaixianshi2(struct tongxunlu txl[],int e)                //סլ������ʾ����
{
	int i;
	printf("%12s%12s%12s%12s%16s\n","���","����","�Ա�","����","סլ�绰");
	for(i=0;i<e;i++)
	{
		printf("%12s%12s%12s%12d%16s\n",txl[i].bianhao,txl[i].xingming,txl[i].xingbie,txl[i].nianling,txl[i].zhuzhai);
	}
}
void shoujixianshi2(struct tongxunlu txl[],int e)                //�ֻ�������ʾ����
{
	int i,j;
	for(i=0;i<e;i++)
	{
		printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n","���",txl[i].bianhao,"����",txl[i].xingming,"�Ա�",txl[i].xingbie,"����",txl[i].nianling);
		for(j=0;j<4;j++)
		{
			if(txl[i].shouji[j][0]=='\0')
				break;
			printf("��%d���ֻ�����:%-17s\n",j+1,txl[i].shouji[j]);
		}
	}
}
void quanbuxianshi2(struct tongxunlu txl[],int e)                //ȫ����ʾ����
{
	int i,j;
	for(i=0;i<e;i++)
	{
		printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[i].bianhao,"����",txl[i].xingming,"�Ա�",txl[i].xingbie,"����",txl[i].nianling,"סլ�绰",txl[i].zhuzhai);
		for(j=0;j<4;j++)
		{
			if(txl[i].shouji[j][0]=='\0'||txl[i].shouji[j][0]=='\n')
				break;
			printf("��%d���ֻ�����:%-17s\n",j+1,txl[i].shouji[j]);
		}
		printf("\n\n");
	}
}
void chaxun2(struct tongxunlu txl[],int e)                  //��ѯ����
{
	int i,j,k,weizhi[8];
	char xz;
	char xingming[10],sj[16];
	if(e==0)
		printf("ͨѶ¼��û�г�Ա���޷���ѯ\n");
	else
	{
		while(1)
		{
			for(i=0;i<8;i++)
				weizhi[i]=-1;
			printf("1)������ѯ\n2)�ֻ��Ų�ѯ\n0)�˳���ѯ\n��ѡ��:\n");
			xz=getchar();
			eatline();
			while(strchr("120",xz)==NULL)
			{
				printf("������������ȷ��ѡ��\n�� 1�� 2�� 0\n");
				xz=getchar();
				eatline();
			}
			system("cls");
			if(xz=='1')
			{
				puts("������Ҫ��ѯ�˵�����:");
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
					printf("%s����Ϣ����:\n",xingming);
					printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi[0]].bianhao,"����",txl[weizhi[0]].xingming,"�Ա�",txl[weizhi[0]].xingbie,"����",txl[weizhi[0]].nianling,"סլ�绰",txl[weizhi[0]].zhuzhai);
					for(i=0;i<4;i++)
					{			
						if(txl[weizhi[0]].shouji[i][0]=='\0')
							break;
						printf("��%d���ֻ�����:%-17s\n",i+1,txl[weizhi[0]].shouji[i]);
					}
				}
				if(k>1)
				{
					printf("���ҵ�%d����ͬ��������\n�ֱ�Ϊ:\n",k);
					for(i=0;i<k;i++)
					{
						printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi[i]].bianhao,"����",txl[weizhi[i]].xingming,"�Ա�",txl[weizhi[i]].xingbie,"����",txl[weizhi[i]].nianling,"סլ�绰",txl[weizhi[i]].zhuzhai);
						for(j=0;j<4;j++)
						{			
							if(txl[weizhi[i]].shouji[j][0]=='\0')
								break;
							printf("��%d���ֻ�����:%-17s\n",j+1,txl[weizhi[i]].shouji[j]);
						}
						printf("\n\n");
					}
				}
				if(k==0)
					puts("û�д���!");
				system("pause");
				system("cls");
			}
			if(xz=='2')
			{
				puts("������Ҫ��ѯ�˵�סլ���ֻ�����:");
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
					printf("���˵���Ϣ����:\n");
					printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi[k-1]].bianhao,"����",txl[weizhi[k-1]].xingming,"�Ա�",txl[weizhi[k-1]].xingbie,"����",txl[weizhi[k-1]].nianling,"סլ�绰",txl[weizhi[k-1]].zhuzhai);
					for(i=0;i<4;i++)
					{			
						if(txl[weizhi[k-1]].shouji[i][0]=='\0')
							break;
						printf("��%d���ֻ�����:%-17s\n",i+1,txl[weizhi[k-1]].shouji[i]);
					}
					printf("\n\n");
				}
				if(k>1)
				{
					printf("���ҵ�%d���д˺������\n",k);
					for(k=k-1;k>=0;k--)
					{
						printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi[k]].bianhao,"����",txl[weizhi[k]].xingming,"�Ա�",txl[weizhi[k]].xingbie,"����",txl[weizhi[k]].nianling,"סլ�绰",txl[weizhi[k]].zhuzhai);
						for(i=0;i<4;i++)
						{			
							if(txl[weizhi[k]].shouji[i][0]=='\0')
								break;
							printf("��%d���ֻ�����:%-17s\n",i+1,txl[weizhi[k]].shouji[i]);
						}
						printf("\n\n");
					}
				}
				if(k==0)
				{
					printf("û�д���!");
				}
				system("pause");
				system("cls");
			}
			if(xz=='0')
				break;
		}
	}
}
void xiougai2(struct tongxunlu txl[],int e)				//�޸�������
{
	int i,j,k,weizhi[8];
	char xz,xuanxiang;
	char xingming[10];
	char *xuhao;
	if(e==0)
		puts("ͨѶ¼��û�г�Ա���޷������޸�");
	else
	{
		puts("������Ҫ�޸��˵�����");
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
			printf("1)����޸�\n2)�����޸�\n3)�Ա�������޸�\n4)סլ�绰�޸�\n5)�ֻ������޸�\n6)ȫ���޸�\n��ѡ��:\n");
			xz=getchar();
			eatline();
			while(strchr("123456",xz)==NULL)
			{
				puts("������������ȷѡ��!  �� 1�� 2�� 3��...");
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
			printf("���ҵ�%d������ͬ���ֵ���\n�ֱ�Ϊ:\n",k);
			for(i=0;i<k;i++)
			{
				printf("%d.\n",i+1);
				printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi[i]].bianhao,"����",txl[weizhi[i]].xingming,"�Ա�",txl[weizhi[i]].xingbie,"����",txl[weizhi[i]].nianling,"סլ�绰",txl[weizhi[i]].zhuzhai);
				for(j=0;j<4;j++)
				{			
					if(txl[weizhi[i]].shouji[j][0]=='\0')
						break;
					printf("��%d���ֻ�����:%-17s\n",j+1,txl[weizhi[i]].shouji[j]);
				}
				printf("\n\n");
			}
			printf("������Ҫ�޸�����������\n");
			xz=getchar();
			eatline();
			while(strchr(xuhao,xz)==NULL)
			{
				printf("������������ȷ�����,��1��2��...\n");
				xz=getchar();
				eatline();
			}
			system("cls");
			printf("ѡ���˵�%d���˽����޸�\n����Ϣ����:\n",(int)xz-48);
			printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi[(int)xz-49]].bianhao,"����",txl[weizhi[(int)xz-49]].xingming,"�Ա�",txl[weizhi[(int)xz-49]].xingbie,"����",txl[weizhi[(int)xz-49]].nianling,"סլ�绰",txl[weizhi[(int)xz-49]].zhuzhai);
			for(j=0;j<4;j++)
			{
				if(txl[weizhi[(int)xz-49]].shouji[j][0]=='\0')
					break;
				printf("��%d���ֻ�����:%-17s\n",j+1,txl[weizhi[(int)xz-49]].shouji[j]);
			}
			printf("\n\n1)����޸�\n2)�����޸�\n3)�Ա�������޸�\n4)סլ�绰�޸�\n5)�ֻ������޸�\n6)ȫ���޸�\n��ѡ��:\n");
			xuanxiang=getchar();
			eatline();
			while(strchr("123456",xuanxiang)==NULL)
			{
				puts("������������ȷѡ��!  �� 1�� 2�� 3��...");
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
			puts("û�д���!");
	}
}
struct tongxunlu bhxiougai2(struct tongxunlu txl[],int e,int weizhi)        //����޸ĺ���
{
	int i,flag,flag1;
	char bianhao[11],queren;
	while(1)
	{
		flag1=0;
		printf("�������µı��:\n");
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
						printf("����ظ���������������!\n");
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
		printf("�޸ĺ���˵ı��Ϊ: %13s\n�Ƿ�ȷ���޸ģ�\n1)ȷ��\n2)��������0)ȡ���޸�\n��ѡ��:\n",bianhao);
		queren=getchar();
		eatline();
		while(strchr("120",queren)==NULL)
		{
			puts("�밴��ʾ������ȷѡ��!,����������:");
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
		printf("�޸������!\n");
		return txl[weizhi];
	}
	else
	{
		puts("�޸���ȡ��");
		return txl[weizhi];
	}
}
struct tongxunlu xmxiougai2(struct tongxunlu txl)		 	 //�����޸ĺ���
{
	int flag;
	char xingming[10],queren;
	while(1)
	{
		flag=0;
		printf("�������µ�����:\n");
		gets(xingming);
		printf("�µ�����Ϊ: %11s\n�Ƿ�ȷ���޸ģ�\n1)ȷ��\n2)��������0)ȡ���޸�\n��ѡ��:\n",xingming);
		queren=getchar();
		eatline();
		while(strchr("120",queren)==NULL)
		{
			puts("�밴��ʾ������ȷѡ��!,����������:");
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
		printf("�޸������!\n");
		return txl;
	}
	else
	{
		puts("�޸���ȡ��");
		return txl;
	}
}
struct tongxunlu xnxiougai2(struct tongxunlu txl)			 //�Ա������޸ĺ���
{
	int nianling,flag;
	char xingbie[4],queren;
	while(1)
	{
		flag=0;
		printf("�������µ��Ա�\n");
		gets(xingbie);
		printf("�������µ�����\n");
		while(scanf("%d",&nianling)!=1)
		{
			fflush(stdin);
			puts("������������,������������ȷ����");
//			scanf("%d",nianling);
		}
		fflush(stdin);
		printf("�µ��Ա�Ϊ: %4s���µ�����Ϊ: %4d\n�Ƿ�ȷ���޸ģ�\n1)ȷ��\n2)��������0)ȡ���޸�\n��ѡ��:\n",xingbie,nianling);
		queren=getchar();
		eatline();
		while(strchr("120",queren)==NULL)
		{
			puts("�밴��ʾ������ȷѡ��!,����������:");
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
		puts("������޸�!");
		return txl;
	}
	else
	{
		puts("�޸���ȡ��");
		return txl;
	}
}
struct tongxunlu zzxiougai2(struct tongxunlu txl)			 //סլ�޸ĺ���
{
	int flag;
	char zhuzhai[16],queren;
	if(txl.zhuzhai[0]=='\0')
	{
		puts("��û�д���סլ�绰������ȥ���!");
		return txl;
	}
	else
	{
		while(1)
		{
			flag=0;
			printf("�������µ�סլ�绰:\n");
			gets(zhuzhai);
			printf("�µ�סլ�绰Ϊ: %17s\n�Ƿ�ȷ���޸ģ�\n1)ȷ��\n2)��������0)ȡ���޸�\n��ѡ��:\n",zhuzhai);
			queren=getchar();
			eatline();
			while(strchr("120",queren)==NULL)
			{
				puts("�밴��ʾ������ȷѡ��!,����������:");
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
			printf("�޸������!\n");
			return txl;
		}
		else
		{
			puts("�޸���ȡ��");
			return txl;
		}
	}
}
struct tongxunlu sjxiougai2(struct tongxunlu txl)			 //�ֻ��޸ĺ���
{
	int flag,flag1,i;
	char *xuhao;
	char xz,queren,shouji[16];
	struct tongxunlu mark;
	if(txl.sjgeshu==0)
	{
		printf("��û�д��˵��ֻ����룬����ȥ���!\n");
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
			printf("һ���д��˵�%d���ֻ�����\n�ֱ�Ϊ:\n",txl.sjgeshu);
			for(i=0;i<txl.sjgeshu;i++)
			{
				printf("��%d��: %17s\n",i+1,txl.shouji[i]);
			}
			printf("������Ҫ�޸���һ��:\n");
			flag1=0;
			flag=0;
			xz=getchar();
			eatline();
			while(strchr(xuhao,xz)==NULL)
			{
				puts("��������ȷ�����,��1��...,����������:");
				xz=getchar();
				eatline();
			}
			printf("ѡ�����޸ĵ�%d���ֻ����룬��:%17s\n�Ƿ�ȷ��?\n1)ȷ��\n2)��������\n0)ȡ���޸�\n��ѡ��:\n",(int)xz-48,txl.shouji[(int)xz-49]);
			queren=getchar();
			eatline();
			while(strchr("120",queren)==NULL)
			{
				puts("�밴��ʾ������ȷѡ��!,����������:");
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
				printf("�������µ��ֻ�����:\n");
				gets(shouji);
				printf("�µ��ֻ�����Ϊ: %17s\n�Ƿ�ȷ���޸ģ�\n1)ȷ��\n2)��������\n0)ȡ���޸�\n��ѡ��:\n",shouji);
				queren=getchar();
				eatline();
				while(strchr("120",queren)==NULL)
				{
					puts("�밴��ʾ������ȷѡ��!,����������:");
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
				printf("�޸������!\n");
				free(xuhao);
				return txl;
			}
			if(flag1==1)
			{
				printf("�޸���ȡ��!\n");
				free(xuhao);
				return txl;
			}
		}
		else
		{
			puts("�޸���ȡ��");
			free(xuhao);
			return txl;
		}
	}
	return mark;
}
struct tongxunlu qbxiougai2(struct tongxunlu txl[],int e,int weizhi)			 //ȫ���޸ĺ���
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
		puts("�����������µı��:");
		while(1)
		{
			flag=0;
			gets(xtxl.bianhao);
			for(i=0;i<e;i++)
			{
				if(strcmp(xtxl.bianhao,txl[i].bianhao)==0)
				{
					printf("��������Ա������أ�������������\n");
					flag++;
				}
			}
			if(flag==0)
				break;
		}
		printf("��������������ѵ�����\n");
		gets(xtxl.xingming);
		printf("��������������ѵ��Ա�\n");
		gets(xtxl.xingbie);
		puts("��������������ѵ�����");
		while(scanf("%d",&xtxl.nianling)!=1)
		{
			fflush(stdin);
			puts("������������,������������ȷ����:");
//			scanf("%d",&xtxl.nianling);
		}
		fflush(stdin);
		printf("�Ƿ��и����ѵ�סլ�绰?\n���� y ��,���� n ��\n");
		zzxz=getchar();
		eatline();
		while(strchr("yn",zzxz)==NULL)
		{
			puts("��������ȷ��ѡ��,�� y �� n,����������:");
			zzxz=getchar();
			eatline();
		}
		fflush(stdin);
		if(zzxz=='y')
		{
			puts("��������������ѵ�סլ�绰����");
			gets(xtxl.zhuzhai);
			fflush(stdin);
		}
		printf("�Ƿ��и����ѵ��ֻ�����?\n���� y ��,���� n ��\n");
		sjxz=getchar();
		eatline();
		while(strchr("yn",sjxz)==NULL)
		{
			puts("��������ȷ��ѡ��,�� y �� n,����������:");
			sjxz=getchar();
			eatline();
		}
		fflush(stdin);
		if(sjxz=='y')
		{
			
			for(i=0;i<4;i++)
			{
				printf("��������������ѵĵ�%d���ֻ�����:\n",i+1);
				gets(xtxl.shouji[i]);
				xtxl.sjgeshu++;
				if(i!=3)	
				{
					printf("�Ƿ��и����ѵĵ�%d���ֻ�����?\n���� y ��,���� n ��\n",i+2);
					sjxz=getchar();
					fflush(stdin);
					while(strchr("yn",sjxz)==NULL)
					{
						puts("��������ȷ��ѡ��,�� y �� n,����������:");
						sjxz=getchar();
						fflush(stdin);
					}
					fflush(stdin);
				}
				if(i==3)
				{
					puts("�ֻ�����洢�����ﵽ����޷��������!");
				}
				if(sjxz=='n')
					break;
			}
		}
		system("pause");
		system("cls");
		printf("�����ѵ�ͨѶ¼��¼�����\n�����Ǹ����ѵ�ͨѶ¼ȫò:\n");
		printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",xtxl.bianhao,"����",xtxl.xingming,"�Ա�",xtxl.xingbie,"����",xtxl.nianling,"סլ�绰",xtxl.zhuzhai);
		for(i=0;i<4;i++)
		{
			if(xtxl.shouji[i][0]=='\0')
				break;
			printf("��%d���ֻ�����:%-17s\n",i+1,xtxl.shouji[i]);
		}
		printf("�Ƿ�ȷ���޸ģ�\n1)ȷ��\n2)��������0)ȡ���޸�\n��ѡ��:\n");
		queren=getchar();
		eatline();
		while(strchr("120",queren)==NULL)
		{
			puts("��������ȷѡ��,����������:");
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
		puts("�޸������");
		return xtxl;
	}
	else
	{
		puts("�޸���ȡ��");
		return txl[weizhi];
	}
}
int shanchu2(struct tongxunlu txl[],int e)				//ɾ��������
{
	int i,j,weizhi[8],k,q=e;
	char xz,xingming[10],bianhao[11],xh,*xuhao,xz1;
	while(1)
	{
		for(i=0;i<8;i++)
			weizhi[i]=-1;
		printf("1)����Ų���ɾ������\n2)����������ɾ������\n0)�˳�\n��ѡ��:\n");
		xz1=getchar();
		fflush(stdin);
		while(strchr("120",xz1)==NULL)
		{
			puts("��������ȷѡ��!,����������:");
			xz1=getchar();
			fflush(stdin);
		}
		system("cls");
		if(xz1=='0')
			break;
		if(xz1=='1')
		{
			printf("������Ҫɾ���˵ı��:\n");
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
				puts("û�д���");
			if(weizhi[0]!=-1)
			{
				system("cls");
				printf("���˵���Ϣ����:\n");
				printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi[0]].bianhao,"����",txl[weizhi[0]].xingming,"�Ա�",txl[weizhi[0]].xingbie,"����",txl[weizhi[0]].nianling,"סլ�绰",txl[weizhi[0]].zhuzhai);
				for(j=0;j<4;j++)
				{		
					if(txl[weizhi[0]].shouji[j][0]=='\0')
						break;
					printf("��%d���ֻ�����:%-17s\n",j+1,txl[weizhi[0]].shouji[j]);
				}
				printf("\n\n1)סլ�绰ɾ��\n2)�ֻ�����ɾ��\n3)ȫ��ɾ��\n��ѡ��:\n");
				xz=getchar();
				fflush(stdin);
				while(strchr("123",xz)==NULL)
				{
					puts("��������������������ȷѡ��");
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
			printf("������Ҫɾ���˵�����\n");
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
				puts("û�д���");
			if(k==1)
			{
				system("cls");
				printf("���˵���Ϣ����:\n");
				printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi[0]].bianhao,"����",txl[weizhi[0]].xingming,"�Ա�",txl[weizhi[0]].xingbie,"����",txl[weizhi[0]].nianling,"סլ�绰",txl[weizhi[0]].zhuzhai);
				for(j=0;j<4;j++)
				{		
					if(txl[weizhi[0]].shouji[j][0]=='\0')
						break;
					printf("��%d���ֻ�����:%-17s\n",j+1,txl[weizhi[0]].shouji[j]);
				}
				printf("\n\n1)סլ�绰ɾ��\n2)�ֻ�����ɾ��\n3)ȫ��ɾ��\n��ѡ��:\n");
				xz=getchar();
				fflush(stdin);
				while(strchr("123",xz)==NULL)
				{
					puts("��������������������ȷѡ��");
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
				printf("����%d����������\n�ֱ�Ϊ:\n",k);
				for(i=0;i<k;i++)
				{
					printf("��%d.\n",i+1);
					printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi[i]].bianhao,"����",txl[weizhi[i]].xingming,"�Ա�",txl[weizhi[i]].xingbie,"����",txl[weizhi[i]].nianling,"סլ�绰",txl[weizhi[i]].zhuzhai);
					for(j=0;j<4;j++)
					{			
						if(txl[weizhi[i]].shouji[j][0]=='\0')
							break;
						printf("��%d���ֻ�����:%-17s\n",j+1,txl[weizhi[i]].shouji[j]);
					}
					printf("\n\n");
				}
				printf("������Ҫɾ������������:\n");
				xh=getchar();
				fflush(stdin);
				while(strchr(xuhao,xh)==NULL)
				{
					printf("����������������������ȷ�����\n�� 1��2�� ...\n");
					xh=getchar();
					fflush(stdin);
				}
				system("cls");
				printf("���˵���Ϣ����:\n");
				printf("%-13s:%-12s\n%-13s:%-11s\n%-13s:%-4s\n%-13s:%-4d\n%-13s:%-17s\n","���",txl[weizhi[(int)xh-49]].bianhao,"����",txl[weizhi[(int)xh-49]].xingming,"�Ա�",txl[weizhi[(int)xh-49]].xingbie,"����",txl[weizhi[(int)xh-49]].nianling,"סլ�绰",txl[weizhi[(int)xh-49]].zhuzhai);
				for(j=0;j<4;j++)
				{		
					if(txl[weizhi[(int)xh-49]].shouji[j][0]=='\0')
						break;
					printf("��%d���ֻ�����:%-17s\n",j+1,txl[weizhi[(int)xh-49]].shouji[j]);
				}
				printf("\n\n1)סլ�绰ɾ��\n2)�ֻ�����ɾ��\n3)ȫ��ɾ��\n��ѡ��:\n");
				xz=getchar();
				fflush(stdin);
				free(xuhao);
				while(strchr("123",xz)==NULL)
				{
					puts("��������������������ȷѡ��");
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
void zzshanchu2(struct tongxunlu *txl,int weizhi)				//סլ����ɾ������
{
	char xz;
	if(txl[weizhi].zhuzhai[0]=='\0')
		puts("û�д���סլ�绰,�޷�ɾ��");
	else
	{
		printf("���˵�סլ�绰Ϊ: %17s\n�Ƿ�ɾ��?\ny)ɾ��\nn)ȡ��\n��ѡ��:\n",txl[weizhi].zhuzhai);
		xz=getchar();
		fflush(stdin);
		while(strchr("yn",xz)==NULL)
		{
			puts("��������,������������ȷѡ��:");
			xz=getchar();
			fflush(stdin);
		}
		if(xz=='y')
		{
			txl[weizhi].zhuzhai[0]='\0';
			printf("���ɾ��\n");
		}
		else
			puts("��ȡ��ɾ��");
	}
}
void sjshanchu2(struct tongxunlu *txl,int weizhi)				//�ֻ�����ɾ������
{
	int i,j;
	char *xuhao;
	char xz,queren;
	if(txl[weizhi].sjgeshu==0)
	{
		printf("û�д����ֻ�����,�޷�ɾ��\n");
	}
	else
	{
		xuhao=(char *)malloc(sizeof(char)*txl[weizhi].sjgeshu);
		for(i=0;i<txl[weizhi].sjgeshu;i++)
			xuhao[i]=i+49;
		printf("����%d�����˺���\n�ֱ�Ϊ:\n",txl[weizhi].sjgeshu);
		for(i=0;i<txl[weizhi].sjgeshu;i++)
		{
			printf("��%2d:%17s\n",i+1,txl[weizhi].shouji[i]);
		}
		printf("������Ҫɾ���ڼ�������:\n");
		xz=getchar();
		fflush(stdin);
		while(strchr(xuhao,xz)==NULL)
		{
			puts("����������������ȷ����š��� 1 ");
			xz=getchar();
			fflush(stdin);
		}
		free(xuhao);
		printf("Ҫɾ�����ֻ�����Ϊ: %17s\n�Ƿ�ɾ��?\ny)ɾ��\nn)ȡ��\n��ѡ��:\n",txl[weizhi].shouji[(int)xz-49]);
		queren=getchar();
		fflush(stdin);
		while(strchr("yn",queren)==NULL)
		{
			puts("����������������ȷ��ѡ��");
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
			puts("�����ɾ��");
		}
		if(queren=='n')
			puts("��ȡ��ɾ��");
	}
}
int qbshanchu2(struct tongxunlu *txl,int weizhi,int e)				//ȫ��ɾ������
{
	char xz;
	printf("�Ƿ�ȫ��ɾ��?\ny)ɾ��\nn)ȡ��\n��ѡ��:\n");
	xz=getchar();
	fflush(stdin);
	while(strchr("yn",xz)==NULL)
	{
		puts("��������,������������ȷѡ��:");
		xz=getchar();
		fflush(stdin);
	}
	if(xz=='y')
	{
		for(;weizhi<e-1;weizhi++)
		{
			txl[weizhi]=txl[weizhi+1];
		}
		puts("�����ɾ��");
		return e-1;
	}
	else
	{
		puts("��ȡ��ɾ��");
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
		printf("1)���˺ŵ�½\n\n2)�˺ŵ�½\n\n3)�˺�ע��\n\n4)��������\n\n0)�˳�\n\n��ѡ��:\n");
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
		puts("������������ȷѡ��:");
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
		printf("1)һλ��\n\n2)��λ��\n\n3)��λ��\n\n4)�鿴�����¼\n\n0)�˳����˺ŵ�½�˵�\n\n��ѡ��:\n");
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
		printf("���˺��ļ�ʧ��!\n");
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
		printf("�������˺�:\n");
		gets(zhanghao);
		for(i=0,flag=0,flag1=0,flag2=0,flag3=0;i<x;i++)
		{
			if(strcmp(zhanghao,jianc[i].zhanghao)==0)
			{
				while(1)
				{
					printf("����������:");
					gets(mima);
					if(strcmp(mima,jianc[i].mima)==0)
					{
						flag++;
						printf("�˺�����������ȷ\n");
						break;
					}
					if(strcmp(mima,jianc[i].mima)!=0)
					{
						cishu--;
						if(cishu>0)
							printf("�������(������%d�λ���)\n",cishu);
						if(cishu==0)
						{
							flag3++;
							break;
						}
						printf("�Ƿ���������\n\n1)��������\n\n0)�˳�����½�˵�\n\n��ѡ��:\n");
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
				printf("�˺��������,�Ƿ��������룿\n\n1)���������˺�\n\n0)�˳�\n\n��ѡ��:\n");
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
		puts("�Բ�������������������˳�����½�˵�");
	if(flag2>0||flag5>0)
		puts("�˳�����½�˵�");
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
				printf("�򿪼�¼�ļ�ʧ��\n");
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
			printf("1)һλ��\n\n2)��λ��\n\n3)��λ��\n\n4)�鿴��ʷ�����¼\n\n5)�����ʷ��¼\n\n0)�˳����˺ŵ�½�˵�\n\n��ѡ��:\n");
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
					dlshow6(jianz,y);system("pause");system("cls");flagp++;break;					//��������鿴���˳���¼ʱ��д������.(δ���)
			case '5':flagq++;break;
			case '0':flag0++;break;
			}
			fflush(stdin);
			if(flagq==0&&flagp==0&&flag0==0)
			{
				fseek(fp2,0L,2);
				if(fwrite(&xjilu,sizeof(struct jilu),1,fp2)!=1)
				{
					printf("д��ʧ��!\n");
					system("pause");
				}
			}
			if(flagq>0)
			{
				system("cls");
				if(fclose(fp2)!=0)
				{
					printf("�ڶ��ιرռ�¼�ļ�ʧ��!");
					exit(1);
				}
				if((fp2=fopen(zhwenjian,"w+b"))==NULL)
				{
					puts("�ڶ��δ򿪼�¼�ļ�ʧ��!");
					exit(1);
				}
				if(fclose(fp2)!=0)
				{
					printf("�����ιرռ�¼�ļ�ʧ��!\n");
					exit(4);
				}
				printf("�ɹ������ʷ��¼!\n");system("pause");system("cls");
			}
			if(flagq==0||flag0>0)
			{
				if(fclose(fp2)!=0)
				{
					printf("�رռ�¼�ļ�ʧ��!\n");
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
		puts("�ر��˺��ļ�ʧ��");
		exit(2);
	}
	free(jianc);
}
void zhuce6(void)
{
	FILE *fp4;
	int i,j,x=0,flag,flag1;
	struct zhanghao jishu,*jianc;
	char *wenti[5]={"�㸸�׵�����?","��ĸ�׵�����?","�������?","�������ܵ����ѵ�����?","���������ʦ������?"};
	char xz,xz1,queren,xz2;
	if((fp4=fopen("zhanghao.txt","r+"))==NULL)
	{
		printf("���˺��ļ�ʧ��!\n");
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
			printf("�������˺�;(С�ڵ���15λ�ַ�)\n");
			gets(jishu.zhanghao);
			if(x==0)
			{
				break;
			}
			for(i=0;i<x;i++)
			{
				if(strcmp(jishu.zhanghao,jianc[i].zhanghao)==0)
				{
					printf("\n�Ѵ�����ͬ�˺�\n\n1)�����������˺�\n\n0)�˳�����½�˵�\n\n��ѡ��:\n");
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
				printf("����������:\n");
				gets(jishu.mima);
				printf("\n���õ�����Ϊ:%-16s\n\n�Ƿ�ȷ�ϣ�\n\ny)ȷ��\n\nn)��������\n\n��ѡ��\n",jishu.mima);
				queren=zqsr("yn");
				if(queren=='y')
					break;
				else
					system("cls");
			}
			system("cls");
			while(1)
			{
				printf("��ѡ������һ���������һػ��޸�����:\n");
				for(j=0;j<5;j++)
					printf("%c)%s\n",(char)j+1,wenti[j]);
				printf("��ѡ��:\n");
				xz1=zqsr("12345");
				printf("\nѡ�����:%s\n\n�Ƿ�ȷ��?\n\ny)ȷ��\n\nn)����ѡ��\n\n��ѡ��:\n",wenti[(int)xz1-49]);
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
				printf("%s\n\n��������������Ĵ�:\n",jishu.wenti);
				gets(jishu.daan);
				printf("\n���õĴ�Ϊ:%s\n\n�Ƿ�ȷ��?\n\ny)ȷ��\n\nn)����ѡ��\n\n��ѡ��:\n",jishu.daan);
				queren=zqsr("yn");
				if(queren=='y')
					break;
				else
					system("cls");
			}
			system("cls");
			printf("ע����ɣ������������˺�ȫò����Ǻ�!\n");
			printf("%s\n%s\n%s\n��Ϊ;%s\n",jishu.zhanghao,jishu.mima,jishu.wenti,jishu.daan);
			printf("\n�Ƿ�ȷ��ע��?\n\n1)ȷ��\n\n2)����ע��\n\n0)ȡ��ע��,�˻ص���½�˵�\n\n��ѡ��:\n");
			xz2=zqsr("120");
			if(xz2=='1')
			{
				printf("��ϲע��ɹ�!\n");
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
		puts("ѡ���ˣ��˳�����½�˵�!");
	free(jianc);
	if(fclose(fp4)!=0)
	{
		puts("�ر��˺��ļ�ʧ��!");
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
		puts("���˺��ļ�ʧ��!");
		exit(1);
	}
	fseek(fp,0L,0);
	while(fread(&jishu,sizeof(struct zhanghao),1,fp)==1)
		x++;
	jianc=(struct zhanghao*)malloc(sizeof(struct zhanghao)*x);
	fseek(fp,0L,0);
	fread(&jianc[0],sizeof(struct zhanghao),x,fp);
	puts("�����������˺�:\n");
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
		puts("û�д��˺�!");
	else
	{
		while(1)
		{
			printf("��������ʱ��ѡ������: %s\n�������:  ",jianc[weizhi].wenti);
			gets(daan);
			if(strcmp(daan,jianc[weizhi].daan)!=0)
			{
				cishu--;
				if(cishu>0)
					printf("�������(������%d�λ���)\n",cishu);
				if(cishu==0)
				{
					printf("���λ����þ�,��û�л�����\n");
					break;
				}
				printf("�Ƿ���������\n\n1)��������\n\n0)�˳�����½�˵�\n\n��ѡ��:\n");
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
					printf("1)�鿴����\n\n2)�޸�����\n\n3)�޸�����\n\n0)�˳�����½�˵�\n\n��ѡ��:\n");
					xz1=zqsr("1230");
					switch(xz1)
					{
					case '1':system("cls");
							printf("��������Ϊ:%-16s\n",jianc[weizhi].mima);system("pause");system("cls");break;
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
							printf("д���ļ�ʧ��!\n");
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
		printf("�ر��˺��ļ�ʧ��!");
		exit(1);
	}
	free(jianc);
}
void mimaxiougai6(struct zhanghao *jianc,int weizhi)
{
	char queren;
	while(1)
	{
		printf("������������;\n");
		gets(jianc[weizhi].mima);
		printf("������Ϊ:%s\n\n�Ƿ�ȷ��y)ȷ��\n\nn)��������\n\n��ѡ��;\n",jianc[weizhi].mima);
		queren=zqsr("yn");
		if(queren=='y')
			break;
	}
	printf("�����޸����!\n");
}
void wentixiougai6(struct zhanghao *jianc,int weizhi)
{
	int i;
	char queren,xz;
	char *wenti[5]={"�㸸�׵�����?","��ĸ�׵�����?","�������?","�������ܵ����ѵ�����?","���������ʦ������?"};
	while(1)
	{
		printf("��ѡ���������е�һ������\n");
		for(i=0;i<5;i++)
			printf("%d):%s\n",i+1,wenti[i]);
		printf("\n��ѡ��:\n");
		xz=zqsr("12345");
		printf("\nѡ�����:%s\n\n�Ƿ�ȷ��?\n\ny)ȷ��\n\nn)����ѡ��\n\n��ѡ��:\n",wenti[(int)xz-49]);
		queren=zqsr("yn");
		if(queren=='y')
		{
			strcpy(jianc[weizhi].wenti,wenti[(int)xz-49]);
			while(1)
			{
				system("cls");
				printf("%s\n\n��������������Ĵ�:\n",jianc[weizhi].wenti);
				gets(jianc[weizhi].daan);
				printf("\n���õĴ�Ϊ:%s\n\n�Ƿ�ȷ��?\n\ny)ȷ��\n\nn)����ѡ��\n\n��ѡ��:\n",jianc[weizhi].daan);
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
		xjilu->shuzi[i][1]=dier[i]=rand()%(x-1)+1;			//��ĸ��Ϊ��
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
			case '/':zongfen+=chufa6(diyi[i],dier[i],shuru,i);				//���ڲ���������
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
	printf("�÷�Ϊ:%-2d\nһ������%2d����\n",xjilu->defen,xjilu->cuowugeshu);
	if(xjilu->cuowugeshu!=0)
	{
		printf("�ֱ�Ϊ:\n");
		for(i=0;i<10;i++)
		{
			if(xjilu->shuzi[i][3]!=xjilu->shuzi[i][2])
			{
				printf("%-2d%c%2d    �������Ϊ��%4d\n\n%9c��ȷ��ӦΪ��%2d\n\n",xjilu->shuzi[i][0],xjilu->yunsuanfu[i],xjilu->shuzi[i][1],xjilu->shuzi[i][2],' ',xjilu->shuzi[i][3]);
			}
		}
	}
	if(xjilu->defen==100)
	{
		puts("\n�������ȫ�������!");
	}
	if(xjilu->defen<100&&xjilu->defen>=80)
	{
		puts("\n��ķǳ���!");
	}
	if(xjilu->defen<80&&xjilu->defen>=60)
	{
		puts("\n��Ĳ�������Ŭ��");
	}
	if(xjilu->defen<60)
	{
		puts("\n�����񣬻��üӰѾ���!");
	}
}
int jiafa6(int diyi,int dier,int *shuru,int i)
{
	int daan;
	printf("�������⣺\n");
	daan=diyi+dier;
	printf("%-2d+%2d = ",diyi,dier);
	while(scanf("%d",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("��������,������������ȷ������\n");
//		scanf("%d",&shuru[i]);
		fflush(stdin);
	}
	if(daan!=shuru[i])
	{
		printf("�������ˣ����ӷ�!\n");
		return 0;
	}
	else
	{
		printf("��ϲ�����ˣ���10��!\n");
		return 10;
	}
}
int jianfa6(int diyi,int dier,int *shuru,int i)
{
	int daan;
	printf("�������⣺\n");
	daan=diyi-dier;
	printf("%-2d-%2d = ",diyi,dier);
	while(scanf("%d",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("��������,������������ȷ������\n");
//		scanf("%d",&shuru[i]);
		fflush(stdin);
	}
	if(daan!=shuru[i])
	{
		printf("�������ˣ����ӷ�!\n");
		return 0;
	}
	else
	{
		printf("��ϲ�����ˣ���10��!\n");
		return 10;
	}
}
int chengfa6(int diyi,int dier,int *shuru,int i)
{
	int daan;
	printf("�������⣺\n");
	daan=diyi*dier;
	printf("%-2d��%2d = ",diyi,dier);
	while(scanf("%d",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("��������,������������ȷ������\n");
//		scanf("%d",&shuru[i]);
		fflush(stdin);
	}
	if(daan!=shuru[i])
	{
		printf("�������ˣ����ӷ�!\n");
		return 0;
	}
	else
	{
		printf("��ϲ�����ˣ���10��!\n");
		return 10;
	}
}
int chufa6(int diyi,int dier,int *shuru,int i)
{
	int daan;
	printf("�������⣺\n");
	daan=diyi/dier;
	printf("%-2d��%2d = ",diyi,dier);
	while(scanf("%d",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("��������,������������ȷ������\n");
//		scanf("%d",&shuru[i]);
		fflush(stdin);
	}
	if(daan!=shuru[i])
	{
		printf("�������ˣ����ӷ�!\n");
		return 0;
	}
	else
	{
		printf("��ϲ�����ˣ���10��!\n");
		return 10;
	}
}
int quyu6(int diyi,int dier,int *shuru,int i)
{
	int daan;
	printf("�������⣺\n");
	daan=diyi%dier;
	printf("%-2d%%%2d = ",diyi,dier);
	while(scanf("%d",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("��������,������������ȷ������\n");
//		scanf("%d",&shuru[i]);
		fflush(stdin);
	}
	if(daan!=shuru[i])
	{
		printf("�������ˣ����ӷ�!\n");
		return 0;
	}
	else
	{
		printf("��ϲ�����ˣ���10��!\n");
		return 10;
	}
}
void show6(struct jilu *head,int e)
{
	int i,j;
	struct jilu *shuchu;
	printf("һ������%d����\n�ֱ�Ϊ:\n",e);
	shuchu=head;
	for(i=0;i<e;i++)
	{
		printf("��%d�Σ�%cλ������\n",i+1,shuchu->weishu);
		for(j=0;j<10;j++)
		{
			if(shuchu->shuzi[j][3]==shuchu->shuzi[j][2])
			{
				printf("��������� :  %-2d%c%2d = %2d\n",shuchu->shuzi[j][0],shuchu->yunsuanfu[j],shuchu->shuzi[j][1],shuchu->shuzi[j][3]);
			}
			else
			{
				printf("��������� :  %-2d%c%2d    ������Ĵ�Ϊ: %2d   ��ȷ��Ϊ: %2d\n",shuchu->shuzi[j][0],shuchu->yunsuanfu[j],shuchu->shuzi[j][1],shuchu->shuzi[j][2],shuchu->shuzi[j][3]);
			}
		}
		printf("\n\n�ܷ�Ϊ:%5d\n\n",shuchu->defen);
		shuchu=shuchu->next;
	}
}
void dlshow6(struct jilu *jianz,int e)
{
	int i,j;
	printf("һ������%d����\n�ֱ�Ϊ:\n",e);
	for(i=0;i<e;i++)
	{
		printf("��%d�Σ�%cλ������\n",i+1,jianz[i].weishu);
		for(j=0;j<10;j++)
		{
			if(jianz[i].shuzi[j][3]==jianz[i].shuzi[j][2])
				printf("��������� :  %-2d%c%2d = %2d\n",jianz[i].shuzi[j][0],jianz[i].yunsuanfu[j],jianz[i].shuzi[j][1],jianz[i].shuzi[j][3]);
			else
				printf("��������� :  %-2d%c%2d    ������Ĵ�Ϊ: %2d   ��ȷ��Ϊ: %2d\n",jianz[i].shuzi[j][0],jianz[i].yunsuanfu[j],jianz[i].shuzi[j][1],jianz[i].shuzi[j][2],jianz[i].shuzi[j][3]);
		}
		printf("\n\n�ܷ�Ϊ:%5d\n\n",jianz[i].defen);
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
		printf("���ļ�ʧ��!\n");
		exit(1);
	}
	fseek(fp,0L,0);
	fread(&sum,sizeof(int),1,fp);
	fseek(fp,sizeof(int),0);
	fread(&qqiche[0],sizeof(struct qiche),20,fp);
	while(1)
	{
		flag=0;
		printf("1)��������\n\n2)�����뿪\n\n3)���ҿճ�λ����ʾ��λ��\n\n4)���ҳ�������ʾ������Ϣ\n\n5)��ʾ������λ������Ϣ\n\n6)��ʾ�ɷ��ܽ��\n\n7)��ʼ��ͣ����Ϣ\n\n0)�˳�ϵͳ\n\n��ѡ��:\n");
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
		printf("�ر��ļ�ʧ��!\n");exit(1);
	}
}
void konglist7(struct qiche *qqiche,int e)
{
	int i,p;
	printf("��λ����:\n");
	for(i=0,p=0;i<e;i++)
	{
		if(qqiche[i].mark==0)
		{
			printf("��%2dλ    ",qqiche[i].chewei);
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
		printf("���ڵĿճ�λ��:\n");
		for(i=0,p=0;i<e;i++)
		{
			if(qqiche[i].mark==0)
			{
				printf("��%2dλ    ",qqiche[i].chewei);
				p++;
				if(p%5==0)
					printf("\n");
			}
		}
		flag=0;
		printf("��ѡ��λ:\n");
		if(scanf("%d",&weizhi)!=1||(weizhi<=0||weizhi>20))
		{
			printf("��������ȷ����λ��,����������\n");
			system("pause");system("cls");
			fflush(stdin);
			continue;
		}
		for(i=0;i<fkgeshu;i++)
		{
			if(weizhi==fkong[i])
			{
				printf("�ó�Ϊ�Ѿ���ռ�ã���ѡ����������λ\n");
				system("pause");system("cls");
				fflush(stdin);
				flag1++;
				break;
			}
		}
		if(flag1>0)
			continue;
		system("cls");
		printf("��ѡ���˵�%d�ų�λ���Ƿ�ȷ�ϣ�\n\n1)ȷ��\n\n2)����ѡ��\n\n0)ȡ��ͣ��\n\n��ѡ��:\n",weizhi);
		xz=zqsr("120");
		if(xz=='0')
		{
			printf("��ȡ��ͣ��\n");
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
				printf("������Ҫͣ�ĳ��ƺ�:\n");
				gets(qqiche[weizhi].xinxi.chepaihao);
				system("cls");
				printf("����ĳ��ƺ�Ϊ:%s\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n0)��������\n\n��ѡ��:\n",qqiche[weizhi].xinxi.chepaihao);
				queren=zqsr("10");
				if(queren=='1')
				{
					qqiche[weizhi].xinxi.jinru=time(NULL);
					tblock = localtime(&qqiche[weizhi].xinxi.jinru);
					strcpy(qqiche[weizhi].xinxi.jinrusj,asctime(tblock));
					qqiche[weizhi].xinxi.jifei=0;
					qqiche[weizhi].mark=1;
					printf("�����ɹ�����ͣ�������Ʒѿ�ʼ\n");
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
	printf("1)�����ƺ�\n\n2)����λ��\n\n0)�˻ص����˵�\n\n��ѡ��:\n");
	xz=zqsr("120");
	if(xz=='0')
		printf("ѡ�����˻ص����˵�\n");
	if(xz=='1')
	{
		printf("���������ĳ��ƺ�:\n");
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
			printf("û�иó�\n");
		else
		{
			system("cls");
			qqiche[weizhi].xinxi.likai=time(NULL);
			tblock=localtime(&qqiche[weizhi].xinxi.likai);
			strcpy(qqiche[weizhi].xinxi.likaisj,asctime(tblock));
			shicha=(int)difftime(qqiche[weizhi].xinxi.likai,qqiche[weizhi].xinxi.jinru);
			qqiche[weizhi].xinxi.jifei=(shicha/3600+1)*10;
			printf("����ͣ����ϢΪ;\n");
			printf("%9s:%17s\n%9s:%17s\n%9s:%17s\n%9s:%dԪ\n","���ƺ�",qqiche[weizhi].xinxi.chepaihao,"����ʱ��",qqiche[weizhi].xinxi.jinrusj,"�뿪ʱ��",qqiche[weizhi].xinxi.likaisj,"�Ʒ�",qqiche[weizhi].xinxi.jifei);
			printf("�Ƿ�ѡ���뿪?\n1)�뿪\n0)���뿪���˻ص����˵�\n");
			xz1=zqsr("10");
			if(xz1=='1')
			{
				ruzhang+=qqiche[weizhi].xinxi.jifei;
				qqiche[weizhi].mark=0;
				printf("���ĳ��Ѿ��뿪ͣ����\n");
			}
			if(xz1=='0')
				printf("ѡ�����˳������˵�\n");
		}
	}
	if(xz=='2')
	{
		printf("���������ĳ�λ��:\n");
		while(scanf("%d",&weizhi)!=1||(weizhi<=0||weizhi>20))
		{
			fflush(stdin);
			printf("��������ȷ����λ��,����������\n");
//			scanf("%d",&weizhi);
			fflush(stdin);
			system("pause");system("cls");
		}
		for(i=0;i<kgeshu;i++)
		{
			if(weizhi==kong[i])
			{
				flag1++;
				printf("�ó�Ϊû�г�,�˻ص����˵�\n");
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
			printf("����ͣ����ϢΪ;\n");
			printf("%9s:%17s\n%9s:%17s\n%9s:%17s\n%9s:%dԪ\n","���ƺ�",qqiche[weizhi].xinxi.chepaihao,"����ʱ��",qqiche[weizhi].xinxi.jinrusj,"�뿪ʱ��",qqiche[weizhi].xinxi.likaisj,"�Ʒ�",qqiche[weizhi].xinxi.jifei);
			printf("�Ƿ�ѡ���뿪?\n1)�뿪\n0)���뿪���˻ص����˵�\n");
			xz1=zqsr("10");
			if(xz1=='1')
			{
				ruzhang+=qqiche[weizhi].xinxi.jifei;
				qqiche[weizhi].mark=0;
			}
			if(xz1=='0')
				printf("ѡ�����˳������˵�\n");
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
		printf("1)�����ƺ�\n\n2)����λ��\n\n0)�˻ص����˵�\n\n��ѡ��:\n");
		xz=zqsr("120");
		system("cls");
		if(xz=='0')
		{
			printf("ѡ�����˻ص����˵�\n");
			break;
		}
		if(xz=='1')
		{
			printf("���������ĳ��ƺ�:\n");
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
				printf("û�иó�\n");
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
				printf("����ͣ����ϢΪ;\n");
				printf("%9s:%17s\n%9s:%17s\n%9s:%17s\n%9s:%dԪ\n","���ƺ�",qqiche[weizhi].xinxi.chepaihao,"����ʱ��",qqiche[weizhi].xinxi.jinrusj,"��ǰʱ��",qqiche[weizhi].xinxi.likaisj,"�Ʒ�",qqiche[weizhi].xinxi.jifei);
				system("pause");system("cls");
			}
		}
		if(xz=='2')
		{
			printf("���������ĳ�λ��:\n");
			while(scanf("%d",&weizhi)!=1||(weizhi<=0||weizhi>20))
			{
				fflush(stdin);
				printf("��������ȷ����λ��,����������\n");
//				scanf("%d",&weizhi);
				fflush(stdin);
				system("pause");system("cls");
			}
			if(qqiche[weizhi-1].mark==0)
			{
				flag1++;
				printf("�ó�λû�г�\n");
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
				printf("����ͣ����ϢΪ;\n");
				printf("%9s:%17s\n%9s:%17s\n%9s:%17s\n%9s:%dԪ\n","���ƺ�",qqiche[weizhi].xinxi.chepaihao,"����ʱ��",qqiche[weizhi].xinxi.jinrusj,"��ǰʱ��",qqiche[weizhi].xinxi.likaisj,"�Ʒ�",qqiche[weizhi].xinxi.jifei);
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
		printf("���еĳ�λ��û�б�ռ\n");
	else
	{
		printf("����%d����λ��ռ\n��ͣ����Ϣ�ֱ�Ϊ:\n",j);
		for(i=0;i<j;i++)
		{
			printf("��%dλ:\n",feikong[i]+1);
			qqiche[feikong[i]].xinxi.likai=time(NULL);
			tblock=localtime(&qqiche[feikong[i]].xinxi.likai);
			strcpy(qqiche[feikong[i]].xinxi.likaisj,asctime(tblock));
			shicha=(int)difftime(qqiche[feikong[i]].xinxi.likai,qqiche[feikong[i]].xinxi.jinru);
			qqiche[feikong[i]].xinxi.jifei=(shicha/3600+1)*10;
			printf("����ͣ����ϢΪ;\n");
			printf("%9s:%17s\n%9s:%17s\n%9s:%17s\n%9s:%dԪ\n\n","���ƺ�",qqiche[feikong[i]].xinxi.chepaihao,"����ʱ��",qqiche[feikong[i]].xinxi.jinrusj,"��ǰʱ��",qqiche[feikong[i]].xinxi.likaisj,"�Ʒ�",qqiche[feikong[i]].xinxi.jifei);
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
	printf("����δ�뿪�����������˽��Ϊ:%d\n\n����δ�뿪������Ŀǰ�ܽ��Ϊ:%d\n",ruzhang+sum,ruzhang+sum+zaiweisum);
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
	puts("ͣ����Ϣ�ѳ�ʼ��!");
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
		printf("1)���\n\n2)�鿴�ѵ��Ʒ\n\n3)���\n\n4)����\n\n5)����\n\n0)�˳�\n\n��ѡ��:\n");
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
	char *cai[10]={"�׷�","��������","����ѼƬ","ľ����","������","��˺Բ�ײ�","���Ŷ���","С����Ģ��","ˮ������","Ԫ���ִ���"};
	while(1)
	{
		flag=0;
		printf("������ȫ����Ʒ:\n");
		for(i=0;i<10;i++)
		{
			printf("%d.%-16s%6d\n",i,cai[i],caijia[i]);
		}
		printf("%s\n\n��ѡ��:\n","a.����");
		xz=zqsr("1234567890a");
		if(xz=='a')
		{
			printf("ѡ�����˳�\n");
			break;
		}
		else
		{	
			system("cls");
			printf("ѡ����:%s\n�Ƿ�ȷ�ϣ�\n\n1)ȷ��\n\n0)����ѡ��\n\n��ѡ��\n",cai[(int)xz-48]);
			queren=zqsr("10");
			if(queren=='0')
				continue;
			else
			{
				system("cls");
				printf("������Ҫ�㼸��:\n");
				while(scanf("%d",&dianshu)!=1)
				{
					printf("��������ȷ������,����������\n");
					fflush(stdin);
				}
				diancai[(int)xz-48]='1';
				geshu[(int)xz-48]+=dianshu;
				printf("\n\n�ɹ�����%2d��%-10s\n",dianshu,cai[(int)xz-48]);
			}
		}
		system("pause");system("cls");
		fflush(stdin);
	}
}
void chakan8(char *diancai,int *geshu)
{
	int i,sum=0,j=0;
	char *cai[10]={"�׷�","��������","����ѼƬ","ľ����","������","��˺Բ�ײ�","���Ŷ���","С����Ģ��","ˮ������","Ԫ���ִ���"};
	printf("�������Ѿ���Ĳ�Ʒ:\n");
	for(i=0;i<10;i++)
	{
		if(diancai[i]=='1')
		{
			printf("��%d����:%-12s:%6d��\n\n",j+1,cai[i],geshu[i]);
			j++;
			sum+=geshu[i]*caijia[i];
		}
	}
	printf("����%3dԪ\n",sum);
}
void tiancai8(char *diancai,int *geshu)
{
	int i,flag,dianshu;
	char xz,queren;
	char *cai[10]={"�׷�","��������","����ѼƬ","ľ����","������","��˺Բ�ײ�","���Ŷ���","С����Ģ��","ˮ������","Ԫ���ִ���"};
	chakan8(diancai,geshu);
	while(1)
	{
		flag=0;
		printf("������ȫ����Ʒ:\n");
		for(i=0;i<10;i++)
		{
			printf("%d.%-16s%6d\n",i,cai[i],caijia[i]);
		}
		printf("%s\n\n��ѡ��Ҫ��ӵĲ�Ʒ:\n","a.����");
		xz=zqsr("1234567890a");
		if(xz=='a')
		{
			printf("ѡ�����˳�\n");
			break;
		}
		else
		{	
			system("cls");
			printf("ѡ����:%s\n�Ƿ�ȷ�ϣ�\n\n1)ȷ��\n\n0)����ѡ��\n\n��ѡ��\n",cai[(int)xz-48]);
			queren=zqsr("10");
			if(queren=='0')
				continue;
			else
			{
				system("cls");
				printf("������Ҫ�㼸��:\n");
				while(scanf("%d",&dianshu)!=1)
				{
					printf("��������ȷ������,����������\n");
					fflush(stdin);
				}
				if(diancai[(int)xz-48]=='0')
					diancai[(int)xz-48]='1';
				geshu[(int)xz-48]+=dianshu;
				printf("\n\n�ɹ�����%2d��%-10s\n",dianshu,cai[(int)xz-48]);
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
	char *cai[10]={"�׷�","��������","����ѼƬ","ľ����","������","��˺Բ�ײ�","���Ŷ���","С����Ģ��","ˮ������","Ԫ���ִ���"};
	for(i=0,j=0;i<10;i++)
	{
		if(diancai[i]=='1')
		{
			xuhao1[j]=i;
			j++;
		}
	}
	if(j==0)
		printf("����û�е��κβˣ�����ȥ���!\n");
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
				puts("��Ӧ�������еĲ˶������ˣ��޷���������!");
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
				printf("��ѡ��Ҫ���Ĳ˵����:\n");
				xz=zqsr(xuhao);
				system("cls");
				printf("��Ҫ���Ĳ�Ϊ��%2d��:%-12s\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)����ѡ��Ҫ���Ĳ�\n\n0)�˳������˵�\n\n��ѡ��:\n",(int)xz-48,cai[xuhao1[(int)xz-49]]);
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
					printf("�õ���:%8s ��һ������%d��\n\n������Ҫ���ĸ���:\n",cai[xuhao1[(int)xz-49]],geshu[xuhao1[(int)xz-49]]);
					while(scanf("%d",&jiangeshu)!=1||jiangeshu>geshu[xuhao1[(int)xz-49]])
					{
						fflush(stdin);
						printf("����������������ȷ���֣���ȷ�����Ÿ���С�ڵ������и���\n\n����������:\n");
//						scanf("%d",&jiangeshu);
						fflush(stdin);
					}
					fflush(stdin);
					geshu[xuhao1[(int)xz-49]]-=jiangeshu;
					if(geshu[xuhao1[(int)xz-49]]==0)
						diancai[xuhao1[(int)xz-49]]='0';
					system("cls");
					printf("���ѳɹ�����%d���ò�\n\n�Ƿ�Ҫ��������Ʒ?\n\n1)��������\n\n0)�˳�\n\n��ѡ��:\n",jiangeshu);
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
	printf("�Ƿ�ѡ�����?\n\n1)����\n\n0)�����㣬�������˵�\n\n��ѡ��:\n");
	xz=zqsr("10");
	if(xz=='1')
	{	
		for(i=0;i<10;i++)
		{
			diancai[i]='0';
			geshu[i]=0;
		}
		printf("����ɹ�\n");
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
		printf("���ļ�ʧ��!\n");
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
		printf("1)¼���豸\n\n2)�޸��豸\n\n3)����ķ�,������\n\n4)ͳ��\n\n5)��ѯ\n\n6)���\n\n0)�˳�\n\n��ѡ��:\n");
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
		printf("��һ�ιر��ļ�ʧ��!\n");
		exit(1);
	}
	if((fp=fopen("shebei.txt","w+b"))==NULL)
	{
		printf("�ڶ��δ��ļ�ʧ��!\n");
		exit(2);
	}
	while(prve!=NULL)
	{
		fwrite(&*prve,sizeof(struct shebei),1,fp);
		prve=prve->next;
	}
	if(fclose(fp)!=0)
	{
		printf("�ڶ��ιر��ļ�ʧ��\n");exit(1);
	}
}
void shuchu(struct shebei *head,int e)
{
	int i;
	struct shebei *prve;
	prve=head;
	for(i=0;i<e;i++)
	{
		printf("%12s%12s\n%12s%12s\n%12s%12s\n%12s%12d\n%12s%12s\n%12s","���: ",prve->bianhao,"�豸����: ",prve->mingcheng,"�豸����: ",prve->zhonglei,"����۸�: ",prve->jiage,"��������: ",prve->riqi,"�Ƿ񱨷�: ");
		if(prve->mark=='1')
		{
			printf("%12s\n%12s%12s\n\n","��","��������: ",prve->briqi);
		}
		if(prve->mark=='0')
			printf("%12s\n\n\n","��");
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
		printf("������Ҫ¼����豸�ı��:\n");
		gets(creat->bianhao);
		prve=head;
		while(prve==NULL)
		{
			if(strcmp(prve->bianhao,creat->bianhao)==0)
			{	
				flag2++;
				printf("�����б���ظ���������������\n");
				break;
			}
			prve=prve->next;
		}
		if(flag2>0)
		{
			system("cls");continue;
		}
		printf("����ı��Ϊ:%s\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)��������\n\n0)�˳������˵�\n\n��ѡ��:\n",creat->bianhao);
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
				printf("������������豸������;\n");
				gets(creat->mingcheng);
				printf("���������Ϊ:%s\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n0)��������\n\n\n\n��ѡ��:\n",creat->mingcheng);
				xz1=zqsr("10");
				if(xz1=='0')
				{
					system("cls");continue;
				}
				else
				{
					system("cls");
					printf("������������豸������:\n");
					gets(creat->zhonglei);
					printf("�����������Ϊ:%s\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n0)��������\n\n\n\n��ѡ��:\n",creat->zhonglei);	
					xz2=zqsr("10");
					if(xz2=='0')
					{
						system("cls");continue;
					}
					else
					{
						system("cls");
						printf("������������豸�ļ۸�:\n");
						while(scanf("%d",&creat->jiage)!=1||(creat->jiage<0))
						{
							fflush(stdin);
							printf("��������,��������ȷ�ļ۸�!\n");
							fflush(stdin);
						}
						fflush(stdin);
						system("cls");
						printf("������������豸�Ĺ�������:\n");
						gets(creat->riqi);
						system("cls");
						printf("���豸�Ƿ񱨷�?\n\n1)�ѱ���\n\n2)δ����\n\n��ѡ��:\n");
						xz3=zqsr("12");
						if(xz3=='1')
						{
							printf("��������豸�ı�������:\n");
							gets(creat->briqi);
							creat->mark='1';
						}
						if(xz3=='2')
							creat->mark='0';
						system("cls");
						printf("¼����豸��Ϣ����:\n\n");
						shuchu(creat,1);
						printf("�Ƿ�ȷ��?\n\n1)ȷ��\n\n0)����¼��\n\n��ѡ��:\n");
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
							printf("¼�������!\n");
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
		printf("%d.\n%12s%12s\n%12s%12s\n%12s%12s\n%12s%12d\n%12s%12s\n%12s",i+1,"���: ",prve->bianhao,"�豸����: ",prve->mingcheng,"�豸����: ",prve->zhonglei,"����۸�: ",prve->jiage,"��������: ",prve->riqi,"�Ƿ񱨷�: ");
		if(prve->mark=='1')
		{
			printf("%12s\n%12s%12s\n\n","��","��������: ",prve->briqi);
		}
		if(prve->mark=='0')
			printf("%12s\n\n\n","��");
		i++;
		prve=prve->next;
	}
	printf("����%3d���豸\n",i);
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
			printf("��%d���豸:\n%s\n\n",i+1,prve->mingcheng);
			i++;
			prve=prve->next;
		}
		if(i==0)
		{
			printf("��û���κ��豸!,����ȥ¼��!\n");
			break;
		}
		printf("������Ҫ�޸ĵ��豸�����:\n");
		while(scanf("%d",&weizhi)!=1||weizhi<0||weizhi>i)
		{
			fflush(stdin);printf("��������ȷ�����,����������\n");
		}
		prve=head;
		for(i=0;i<weizhi-1;i++)
			prve=prve->next;
		fflush(stdin);
		system("cls");
		printf("ѡ����ǵ�%d���豸,��%s\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)����ѡ��\n\n0)�˻ص����˵�\n\n��ѡ��:\n",weizhi,prve->mingcheng);
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
				printf("������������豸�ı��;\n");
				gets(genggai.bianhao);
				printf("������������豸������:\n");
				gets(genggai.mingcheng);
				printf("������������豸������:\n");
				gets(genggai.zhonglei);
				printf("������������豸�ļ۸�\n");
				while(scanf("%d",&genggai.jiage)!=1||genggai.jiage<0)
				{
					printf("��������,��������ȷ������,����������\n");
					fflush(stdin);
				}
				fflush(stdin);
				printf("������������豸�Ĺ�������\n");
				gets(genggai.riqi);
				printf("���豸�Ƿ񱨷�?\n\n1)�ѱ���\n\n2)δ����\n\n��ѡ��:\n");
				xz3=zqsr("12");
				if(xz3=='1')
				{
					printf("��������豸�ı�������:\n");
					gets(genggai.briqi);
					genggai.mark='1';
				}
				if(xz3=='2')
					genggai.mark='0';
				system("cls");
				printf("¼����豸��Ϣ����:\n\n");
				shuchu(&genggai,1);
				printf("�Ƿ�ȷ��?\n\n1)ȷ��\n\n0)����¼��\n\n��ѡ��:\n");
				xz2=zqsr("10");
				if(xz2=='0')
					continue;
				if(xz2=='1')
				{
					genggai.next=prve->next;
					*prve=genggai;
					printf("���������\n");
					break;
				}
			}
		}
		system("cls");
		printf("�Ƿ�Ҫ���������豸?\n\n1)���������豸\n\n0)�˳������˵�\n\n��ѡ��:\n");
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
		printf("1)�鿴�ܺķ�\n\n2)������\n\n0)�˳������˵�\n\n��ѡ��:\n");
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
			printf("��%d�������豸 : %s\n\n",j+1,prve->mingcheng);
			j++;
		}
		i++;
		prve=prve->next;
	}
	printf("����%d�������豸\n",j);
}
void yisun9(struct shebei *head)
{
	int i=0,weizhi,j;
	char xz;
	struct shebei *prve,*qianyige;
	while(1)
	{
		j=lioulan9(head);
		printf("������Ҫ�Ƴ����豸�����\n");
		while(scanf("%d",&weizhi)!=1||weizhi<0||weizhi>j)
		{
			printf("��������ȷ�����,����������\n");
			fflush(stdin);
		}
		fflush(stdin);
		prve=head;
		for(i=0;i<weizhi-1;i++)
			prve=prve->next;
		system("cls");
		printf("ѡ���Ƴ����ǵ�%d���豸,����Ϊ: %s\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)����ѡ��\n\n0)�˳�����һ��˵�\n\n��ѡ��:\n",weizhi,prve->mingcheng);
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
				printf("�Ƴ��ɹ�\n");
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
		printf("��%d���豸: %s\n",i+1,prve->mingcheng);
		i++;
		prve=prve->next;
	}
	printf("������Ҫ���ҵ��豸�����:\n");
	while(scanf("%d",&weizhi)!=1||weizhi<0||weizhi>i)
	{
		printf("��������������������ȷ�����\n");
		fflush(stdin);
	}
	fflush(stdin);
	system("cls");
	printf("���豸����Ϣ����:\n");
	prve=head;
	for(i=0;i<weizhi-1;i++)
		prve=prve->next;
	printf("%12s%12s\n%12s%12s\n%12s%12s\n%12s%12d\n%12s%12s\n%12s","���: ",prve->bianhao,"�豸����: ",prve->mingcheng,"�豸����: ",prve->zhonglei,"����۸�: ",prve->jiage,"��������: ",prve->riqi,"�Ƿ񱨷�: ");
	if(prve->mark=='1')
	{
		printf("%12s\n%12s%12s\n\n","��","��������: ",prve->briqi);
	}
	if(prve->mark=='0')
		printf("%12s\n\n\n","��");
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
		printf("���ļ�ʧ��!\n");
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
		printf("1)��ӳ���\n\n2)�޸ķ���ʱ��\n\n3)ɾ������\n\n4)��ѯ����\n\n5)���\n\n0)�˳�\n\n��ѡ��:\n");
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
		printf("��һ�ιر��ļ�ʧ��!\n");
		exit(1);
	}
	if((fp=fopen("daba.txt","w+b"))==NULL)
	{
		printf("�ڶ��δ��ļ�ʧ��!\n");
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
		printf("�ڶ��ιر��ļ�ʧ��\n");exit(1);
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
		printf("��%d�೵: %2d:%c%c\n",i+1,prve->xiaoshi,shiwei+48,gewei+48);
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
		printf("Ŀǰ��û�г�\n������Ҫ��ӵĳ��ε�ʱ��(�м�����ð�Ÿ���,�� 8:30 )\n");
		while(1)
		{
			while(scanf("%d:%d",&h,&m)!=2||(h<0||h>24||m<0||m>=60))
			{
				fflush(stdin);
				printf("��������ȷ��ʱ��\n����ð�Ÿ���,�� 8:30 ��\n������������0:00 ~ 24:00֮���ʱ��:\n");
				fflush(stdin);
			}
			fflush(stdin);
			system("cls");
			gewei=m%10;	
			shiwei=m/10;
			printf("Ҫ��ӵ�ʱ��Ϊ: %2d:%c%c\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)��������\n\n0)�˳������˵�\n\n��ѡ��:\n",h,shiwei+48,gewei+48);
			queren=zqsr("120");
			if(queren=='0')
				break;
			if(queren=='2')
			{
				system("cls");
				printf("����������ʱ��\n");
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
				printf("�µĳ����ѽ���!\n");
				break;
			}
		}
	}
	else
	{
		printf("Ŀǰ�ĳ�������:\n");
		i=0;	
		prve=head;
		while(1)
		{	
			bancishuchu(head);
			printf("������Ҫ��ӵĳ��ε�ʱ��(�м�����ð�Ÿ���,�� 8:30 )\n");
			flag=0;flag1=0;
			fflush(stdin);
			while(scanf("%d:%d",&h,&m)!=2||(h<0||h>24||m<0||m>60))
			{
				fflush(stdin);
				printf("��������ȷ��ʱ��\n����ð�Ÿ���,�� 8:30 ��\n������������0:00 ~ 24:00֮���ʱ��:\n");
				fflush(stdin);
			}
			fflush(stdin);
			prve=head;
			while(prve!=NULL)
			{
				if(prve->fenzhong==m&&prve->xiaoshi==h)
				{
					printf("�����иó���!���Ƿ���������?\n\n1)��������\n\n0)�˻����˵�\n\n��ѡ��\n");
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
				printf("��������ʱ��\n");system("cls");continue;
			}
			if(flag==2)
				break;
			if(flag==0)
			{
				system("cls");
				gewei=m%10;	
				shiwei=m/10;
				printf("Ҫ��ӵ�ʱ��Ϊ: %2d:%c%c\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)��������\n\n0)�˳������˵�\n\n��ѡ��:\n",h,shiwei+48,gewei+48);
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
								printf("�µĳ����ѽ���!\n");
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
							printf("�µĳ����ѽ���!\n");
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
		printf("û���κγ���!\n");
	else
	{
		i=0;
		while(prve!=NULL)
		{
			gewei=prve->fenzhong%10;	shiwei=prve->fenzhong/10;
			printf("��%d�೵: %2d:%c%c\n",i+1,prve->xiaoshi,shiwei+48,gewei+48);
			i++;
			for(j=0,k=0;j<S;j++)
			{
				if(prve->sseat[j].mark=='1')
				{
					printf("��%2d��λ: %s  \n",prve->sseat[j].hao,prve->sseat[j].keren);
					k++;
				}	
			}
			printf("\n\n����%d���˿�\n\n",k);
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
		printf("������Ҫ�޸ĵĳ������:\n");
		while(scanf("%d",&weizhi)!=1||(weizhi<0||weizhi>geshu))
		{
			fflush(stdin);
			printf("��������ȷ�����,����������\n");system("cls");
			fflush(stdin);
		}
		fflush(stdin);
		k=bancijiancha(head,weizhi);
		if(k==1)
		{
			printf("�ð�γ��Ѿ���Ʊ��Ԥ�������ܱ��޸�!\n\n1)����ѡ��\n\n0)�˳������˵�\n\n��ѡ��:\n");
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
			printf("��ѡ����ǵ�%d��γ�,����ʱ��Ϊ: ",weizhi);
			shijian(head,weizhi);
			printf("\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)����ѡ��\n\n0)�˳������˵�\n\n��ѡ��:\n");
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
					printf("������Ҫ�޸ĵĳ��ε�ʱ��(�м�����ð�Ÿ���,�� 8:30 )\n");
					flag=0;flag1=0;
					fflush(stdin);
					while(scanf("%d:%d",&h,&m)!=2||(h<0||h>24||m<0||m>60))
					{
						fflush(stdin);
						printf("��������ȷ��ʱ��\n����ð�Ÿ���,�� 8:30 ��\n������������0:00 ~ 24:00֮���ʱ��:\n");
						fflush(stdin);
					}
					fflush(stdin);
					prve=head;
					while(prve!=NULL)
					{
						if(prve->fenzhong==m&&prve->xiaoshi==h)
						{
							printf("�����иó���!���Ƿ���������?\n\n1)��������\n\n0)�˻����˵�\n\n��ѡ��\n");
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
						printf("��������ʱ��\n");system("cls");continue;
					}
					if(flag==2)
						break;
					if(flag==0)
					{
						system("cls");
						gewei=m%10;	
						shiwei=m/10;
						printf("Ҫ��ӵ�ʱ��Ϊ: %d:%c%c\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)��������\n\n0)�˳������˵�\n\n��ѡ��:\n",h,shiwei+48,gewei+48);
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
							printf("�޸ĳɹ�\n");
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
		printf("���������еİ��:\n");
		geshu=bancishuchu(head);
		printf("\n\n��ѡ��Ҫɾ���İ��:\n");
		while(scanf("%d",&weizhi)!=1||(weizhi<0||weizhi>geshu))
		{
			fflush(stdin);
			printf("��������ȷ�����,����������\n");system("cls");
			fflush(stdin);
		}
		fflush(stdin);
		k=bancijiancha(head,weizhi);
		if(k==1)
		{
			printf("�ð�γ��Ѿ���Ʊ��Ԥ�������ܱ��޸�!\n\n1)����ѡ��\n\n0)�˳������˵�\n\n��ѡ��:\n");
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
			printf("��ѡ����ǵ�%d��γ�,����ʱ��Ϊ: ",weizhi);
			shijian(head,weizhi);
			printf("\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)����ѡ��\n\n0)�˳������˵�\n\n��ѡ��:\n");
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
					printf("ɾ���ɹ�\n");
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
					printf("ɾ���ɹ�\n");
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
		printf("���������еİ��:\n");
		geshu=bancishuchu(head);
		printf("\n\n��ѡ��Ҫ��ѯ�İ��:\n");
		while(scanf("%d",&weizhi)!=1||(weizhi<0||weizhi>geshu))
		{
			fflush(stdin);
			printf("��������ȷ�����,����������\n");system("cls");
			fflush(stdin);
		}
		fflush(stdin);
		printf("��ѡ����ǵ�%d��γ�,����ʱ��Ϊ: ",weizhi);
		shijian(head,weizhi);
		printf("\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)����ѡ��\n\n0)�˳������˵�\n\n��ѡ��:\n");
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
				printf("1)����λ�б�\n\n2)��Ԥ����λ�б�\n\n3)Ԥ����λ\n\n4)ȡ��Ԥ��\n\n0)�˳�\n\n��ѡ��;\n");
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
		printf("�Ƿ��ѯ��������?\n\n1)��ѯ��������\n\n0)�˳������˵�\n\n��ѡ��:\n");
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
			printf("��%2dλ    ",i+1);
			geshu++;
			if(geshu%5==0)
				printf("\n");
		}
	}
	if(geshu==0)
		printf("\n���е���λ����Ԥ����!\n");
	else
		printf("\n����λ����%d��\n",geshu);
	return geshu;
}
int alist0(struct checi *weizhi)
{
	int i,geshu=0;
	for(i=0;i<S;i++)
	{
		if(weizhi->sseat[i].mark=='1')
		{
			printf("��%2dλ: ����Ϊ: %s\n",weizhi->sseat[i].hao,weizhi->sseat[i].keren);
			geshu++;
		}
	}
	if(geshu==0)
		printf("\n���е���λ��û�б�Ԥ����!\n");
	else
		printf("\n��Ԥ����λ����%d��\n",geshu);
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
		printf("��������ҪԤ������λ��:\n");
		while(scanf("%d",&x)!=1||(x<0||x>S))
		{
			fflush(stdin);
			printf("��������,��������ȷ����λ��\n����������:\n");
			fflush(stdin);
		}
		xz='2';
		for(i=0;i<y;i++)
		{
			if((x-1)==p[i])
			{
				printf("��λ���Ѿ���Ԥ����!\n\n1)����ѡ��\n\n0)�˳�Ԥ��\n\n��ѡ��:\n");
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
				printf("��ҪԤ������λΪ:��%dλ\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)����ѡ��\n\n0)�˳�Ԥ��\n\n��ѡ��:\n",x);
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
						printf("��������������:\n");
						gets(weizhi->sseat[x-1].keren);
						printf("�����������Ϊ:%s\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)��������\n\n��ѡ��;\n",weizhi->sseat[x-1].keren);
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
					printf("���ѳɹ�Ԥ���˴�ͳ�,ʱ��Ϊ:");shijian(weizhi,0);
					printf("  �ĵ�%d����λ\n\n",x);
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
		printf("��������������:\n");
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
			printf("�����������Ϊ: %s\n��û��Ԥ����λ\n\n1)������������\n\n0)�˳�ȡ��Ԥ��\n\n��ѡ��:\n",xingming);
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
			printf("��Ԥ������λΪ:��%cλ\n\n�Ƿ�ȷ��ȡ��Ԥ��?\n\n1)ȷ��\n\n0)�˻���һ���˵�\n\n��ѡ��:\n",weizhi->sseat[x].hao);
			xz1=zqsr("10");
			if(xz1=='0')
				break;
			else
			{
				weizhi->sseat[x].mark='0';
				printf("���ѳɹ�ȡ��Ԥ��\n");
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
		printf("1)���˶���������\n\n2)���˵�������\n\n0)�˳�\n\n��ѡ��\n");
		xz=getchar();
		fflush(stdin);
		while(strchr("120",xz)==NULL)
		{
			printf("��������ȷѡ��,����������\n");
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
	printf("�ݰ�\n");
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
			printf("ƽ��\n");
			break;
		}		
		if((k=diannao(qipan))!=0)
			break;
		shengyu=jiance10(qipan);
		if(shengyu==0)
		{
			printf("ƽ��\n");
			break;
		}
		if(shengyu!=0)
		{
			printf("������\n");system("pause");system("cls");
		}
		if((k=duiyizhe(qipan))!=0)
			break;	
		else
		{
			printf("�������ǵ�������\n");system("pause");
		}
	}
	if(k==1)
		puts("��Ӯ��!\1");
	if(k==2)
		puts("������!");
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
			printf("ƽ��\n");
			break;
		}
		if((k=duiyizhe(qipan))!=0)
			break;
		shengyu=jiance10(qipan);
		if(shengyu==0)
		{
			printf("ƽ��\n");
			break;
		}
		else
		{
			printf("�������ǵ�������\n");system("pause");fflush(stdin);
		}
		if((k=diannao(qipan))!=0)
			break;	
		else
		{
			printf("������\n");system("pause");	system("cls");fflush(stdin);
		}
	}
	if(k==1)
		puts("��Ӯ��!\1");
	if(k==2)
		puts("������!");
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
	printf("\n\n������Ҫ�����ӷ���ĵ�λ��(�� 1,2 ,�ö��Ÿ���):\n");
	while(1)
	{
		while((scanf("%d,%d",&yi,&er)!=2)||(yi<0||yi>3||er<0||er>3))
		{
			fflush(stdin);
			system("cls");shuchuqipan(qipan);
			printf("��������ȷ��λ��!���Ͻ�Ϊ 1,1 ���½�Ϊ 3,3 \n�벻ҪԽ�磬����������\n");
		}
		fflush(stdin);
		if(qipan[yi-1][er-1]=='X'||qipan[yi-1][er-1]=='O')
		{
			printf("��λ���Ѿ�������!\n����������λ��\n");system("pause");
			system("cls");shuchuqipan(qipan);printf("���������룬Ҫ�����λ��\n");
			continue;
		}
		printf("�����λ��Ϊ(%d,%d)\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n2)��������\n\n��ѡ��:\n",yi,er);
		queren=getchar();
		fflush(stdin);
		while(strchr("12",queren)==NULL)
		{
			printf("��������,������������ȷ��ѡ�� y��n\n");
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
			system("cls");shuchuqipan(qipan);printf("���������룬Ҫ�����λ��\n");
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
						if(j+p<3)								//��ֹԽ��
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
								if(k7==2&&i==j)					//�²�- -
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
							if(j+p<3)								//��ֹԽ��
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





