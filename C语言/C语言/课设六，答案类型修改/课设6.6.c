#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
char zqsr(char *c);						//�������ѡ����ȷ���
void wuzhanghao(void);					//���˺�����������
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
	int shuzi[10][3];					//�����������,����÷�.
	double daan[10][2];					//ʹ��������Ĵ𰸣���ȷ��
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
		printf("1)���˺ŵ�½\n\n2)�˺ŵ�½\n\n3)�˺�ע��\n\n4)��������\n\n0)�˳�\n\n��ѡ��:\n");
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
//������ȷѡ���
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
//���˺ŵ�½����
void wuzhanghao(void)
{
	int flag,geshu=0;
	char xz;
	struct jilu *head=NULL;
	struct jilu *creat,*prve,*p;
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
//�˺������½����
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
		flag4=0;flag5=0;
		printf("�������˺�:\n");
		gets(zhanghao);fflush(stdin);
		for(i=0,flag=0,flag1=0,flag2=0,flag3=0,flag6=0;i<x;i++)
		{
			if(strcmp(zhanghao,jianc[i].zhanghao)==0)
			{
				flag6++;
				while(1)
				{
					printf("����������:");
					gets(mima);fflush(stdin);
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
		}
		if(flag6==0)
		{
			printf("û�д��˺�,�Ƿ��������룿\n\n1)���������˺�\n\n0)�˳�\n\n��ѡ��:\n");
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
			strcat(zhwenjian,".txt");					//���˺�������.txt�������ݴ����Ӧ�˺��ļ���
			if((fp2=fopen(zhwenjian,"a+b"))==NULL)		//�򿪶�Ӧ�˺������ļ�
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
					printf("д��ʧ��!\n");
					exit(1);
				}
			}
			if(flagq>0)
			{
				system("cls");
				printf("�Ƿ����������ʷ��¼?\n\n1)���\n\n0)ȡ��\n\n��ѡ��:\n");
				xz3=zqsr("10");
				if(xz3=='1')
				{
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
				else
				{
					printf("��ȡ�����\n");system("pause");system("cls");
				}
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
			//�ͷ������¼
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
	//�ͷ��˺ż�¼
	free(jianc);
}
//ע���˺ź���
void zhuce(void)
{
	FILE *fp4;
	int i,j,x=0,flag,flag1,flag2;
	struct zhanghao jishu,*jianc;
	char *wenti[5]={"�㸸�׵�����?","��ĸ�׵�����?","�������?","�������ܵ����ѵ�����?","���������ʦ������?"};
	char xz,xz1,queren,xz2,xz3;
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
			flag2=0;
			printf("�������˺�;(С�ڵ���15λ�ַ�)\n");
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
			if(flag2==0)
				break;

		}
		if(flag>0)
		{
			break;
		}
		else
		{
			printf("���õ��˺�Ϊ:%-16s\n\n�Ƿ�ȷ�ϣ�\n\ny)ȷ��\n\nn)��������\n\n��ѡ��\n",jishu.zhanghao);
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
					printf("����������:(������С��15�ַ�)\n");
					gets(jishu.mima);fflush(stdin);
					jishu.mima[15]='\0';
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
						printf("%c)%s\n",(char)j+49,wenti[j]);
					printf("��ѡ��:\n");
					xz1=zqsr("12345");system("cls");
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
					printf("%s\n\n��������������Ĵ�:(������15���ַ���7������)\n",jishu.wenti);
					gets(jishu.daan);fflush(stdin);
					jishu.daan[15]='\0';
					printf("\n���õĴ�Ϊ:%s\n\n�Ƿ�ȷ��?\n\ny)ȷ��\n\nn)��������\n\n��ѡ��:\n",jishu.daan);
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
		puts("ѡ���ˣ��˳�����½�˵�!");
	free(jianc);
	if(fclose(fp4)!=0)
	{
		puts("�ر��˺��ļ�ʧ��!");
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
		puts("û�д��˺�!");
	else
	{
		while(1)
		{
			system("cls");
			printf("��������ʱ��ѡ������: %s\n�������:  ",jianc[weizhi].wenti);
			gets(daan);fflush(stdin);
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
				{
					system("cls");continue;
				}
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
void mimaxiougai(struct zhanghao *jianc,int weizhi)
{
	char queren;
	while(1)
	{
		printf("������������,(������15���ַ�)\n");
		gets(jianc[weizhi].mima);fflush(stdin);
		jianc[weizhi].mima[15]='\0';
		printf("������Ϊ:%s\n\n�Ƿ�ȷ��\n\ny)ȷ��\n\nn)��������\n\n��ѡ��;\n",jianc[weizhi].mima);
		queren=zqsr("yn");
		if(queren=='y')
			break;
	}
	printf("�����޸����!\n");
}
void wentixiougai(struct zhanghao *jianc,int weizhi)
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
				printf("%s\n\n��������������Ĵ�:(������15���ַ�����7������)\n",jianc[weizhi].wenti);
				gets(jianc[weizhi].daan);fflush(stdin);
				jianc[weizhi].daan[15]='\0';
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
//λ������
void weishu(struct jilu *xjilu,int x,int y)
{
	int i,ysf,diyi[10],dier[10],zongfen=0,cuowu=0,p,swap;
	double shuru[10];
	double d;
	char yunsuanfu[6]={'+','-','*','/','%'};				//��char�������Ŷ�Ӧ�����
	srand((unsigned)time(0));
	for(i=0;i<10;i++)
	{
		printf("��%d��  ",i+1);
		diyi[i]=rand()%x;				//�������x(10,100,1000)ȡ�࣬�õ�һλ����λ����λ������
		dier[i]=rand()%(x-1)+1;			//��ĸ��Ϊ��
		ysf=rand()%y;										//������ŵ�λ�ö�y(3,4,5)ȡ�࣬�õ���ͬλ����Ӧ�ļ��������
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
					p=(int)(d*100+0.5);									//������λС������������
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
	printf("�÷�Ϊ:%-2d\nһ������%2d����\n",xjilu->defen,cuowu);
	if(xjilu->cuowugeshu!=0)
	{
		printf("�ֱ�Ϊ:\n");
		for(i=0;i<10;i++)
		{
			if(xjilu->daan[i][0]!=xjilu->daan[i][1])
			{
				printf("%-2d%c%2d    �������Ϊ��%4.2lf\n\n%9c��ȷ��ӦΪ��%2.2lf\n\n",xjilu->shuzi[i][0],xjilu->yunsuanfu[i],xjilu->shuzi[i][1],xjilu->daan[i][0],' ',xjilu->daan[i][1]);
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
//�ӷ����㺯��
int jiafa(int diyi,int dier,double *shuru,int i)
{
	double daan;
	printf("�������⣺\n");
	daan=diyi+dier;
	printf("%-2d+%2d = ",diyi,dier);
	while(scanf("%lf",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("��������,������������ȷ������\n");
	}
	fflush(stdin);
	if(daan!=shuru[i])
	{
		printf("�����ˣ�����Ŭ��\n");system("pause");system("cls");printf("���»ش�:\n");
		printf("%-2d+%2d = ",diyi,dier);
		while(scanf("%lf",&shuru[i])!=1)
		{
			fflush(stdin);
			printf("��������,������������ȷ������\n");
		}
		fflush(stdin);
		if(daan!=shuru[i])
		{
			printf("�����ˣ�����Ŭ��!\n");system("pause");system("cls");printf("���»ش�:\n");
			printf("%-2d+%2d = ",diyi,dier);
			while(scanf("%lf",&shuru[i])!=1)
			{
				fflush(stdin);
				printf("��������,������������ȷ������\n");
			}
			fflush(stdin);
			if(daan!=shuru[i])
			{
				printf("�ǳ��ź����ִ���ˣ����������һ�⡣�������ȷ��Ϊ: %.2lf\n",daan);
				return 0;
			}
			else
			{
				printf("����ˣ�ף���㣡��6��\n");
				return 6;
			}
		}
		else
		{
			printf("����ˣ���ܰ�����8��\n");
			return 8;
		}
	}
	else
	{
		printf("��ȫ��ȷ����ǳ���������10��\n");
		return 10;
	}
}
//�������㺯��
int jianfa(int diyi,int dier,double *shuru,int i)
{
	double daan;
	printf("�������⣺\n");
	daan=diyi-dier;
	printf("%-2d-%2d = ",diyi,dier);
	while(scanf("%lf",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("��������,������������ȷ������\n");
	}
	fflush(stdin);
	if(daan!=shuru[i])
	{
		printf("�����ˣ�����Ŭ����\n");system("pause");system("cls");printf("���»ش�:\n");
		printf("%-2d-%2d = ",diyi,dier);
		while(scanf("%lf",&shuru[i])!=1)
		{
			fflush(stdin);
			printf("��������,������������ȷ������\n");
		}
		fflush(stdin);
		if(daan!=shuru[i])
		{
			printf("�����ˣ�����Ŭ��!\n");system("pause");system("cls");printf("���»ش�:\n");
			printf("%-2d-%2d = ",diyi,dier);
			while(scanf("%lf",&shuru[i])!=1)
			{
				fflush(stdin);
				printf("��������,������������ȷ������\n");
			}
			fflush(stdin);
			if(daan!=shuru[i])
			{
				printf("�ǳ��ź����ִ���ˣ����������һ�⡣�������ȷ��Ϊ: %.2lf\n",daan);
				return 0;
			}
			else
			{
				printf("����ˣ�ף���㣡��6��\n");
				return 6;
			}
		}
		else
		{
			printf("����ˣ���ܰ�����8��\n");
			return 8;
		}
	}
	else
	{
		printf("��ȫ��ȷ����ǳ���������10��\n");
		return 10;
	}
}
//�˷����㺯��
int chengfa(int diyi,int dier,double *shuru,int i)
{
	double daan;
	printf("�������⣺\n");
	daan=diyi*dier;
	printf("%-2d��%2d = ",diyi,dier);
	while(scanf("%lf",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("��������,������������ȷ������\n");
	}
	fflush(stdin);
	if(daan!=shuru[i])
	{
		printf("�����ˣ�����Ŭ����\n");system("pause");system("cls");printf("���»ش�:\n");
		printf("%-2d��%2d = ",diyi,dier);
		while(scanf("%lf",&shuru[i])!=1)
		{
			fflush(stdin);
			printf("��������,������������ȷ������\n");
		}
		fflush(stdin);
		if(daan!=shuru[i])
		{
			printf("�����ˣ�����Ŭ����\n");system("pause");system("cls");printf("���»ش�:\n");
			printf("%-2d��%2d = ",diyi,dier);
			while(scanf("%lf",&shuru[i])!=1)
			{
			fflush(stdin);
			printf("��������,������������ȷ������\n");
			}
			fflush(stdin);
			if(daan!=shuru[i])
			{
				printf("�ǳ��ź����ִ���ˣ����������һ�⡣�������ȷ��Ϊ: %.2lf\n",daan);
				return 0;
			}
			else
			{
				printf("����ˣ�ף���㣡��6��\n");
				return 6;
			}
		}
		else
		{
			printf("����ˣ���ܰ�����8��\n");
			return 8;
		}
	}
	else
	{
		printf("��ȫ��ȷ����ǳ���������10��\n");
		return 10;
	}
}
//�������㺯��
int chufa(int diyi,int dier,double *shuru,int i)
{
	double daan,d;
	int p;
	printf("��������(������λС��)��\n");
	d=(double)diyi/(double)dier;
	p=(int)(d*100+0.5);
	daan=p/100.0;
	printf("%-2d��%2d = ",diyi,dier);
	while(scanf("%lf",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("��������,������������ȷ������\n");
	}
	fflush(stdin);
	if(daan!=shuru[i])
	{
		printf("�����ˣ�����Ŭ����\n");system("pause");system("cls");printf("���»ش�:\n");
		printf("%-2d��%2d = ",diyi,dier);
		while(scanf("%lf",&shuru[i])!=1)
		{
			fflush(stdin);
			printf("��������,������������ȷ������\n");
		}
		fflush(stdin);
		if(daan!=shuru[i])
		{
			printf("�����ˣ�����Ŭ����\n");system("pause");system("cls");printf("���»ش�:\n");
			printf("%-2d��%2d = ",diyi,dier);
			while(scanf("%lf",&shuru[i])!=1)
			{
				fflush(stdin);
				printf("��������,������������ȷ������\n");
			}
			fflush(stdin);
			if(daan!=shuru[i])
			{
				printf("�ǳ��ź����ִ���ˣ����������һ�⡣�������ȷ��Ϊ: %.2lf\n",daan);
				return 0;
			}
			else
			{
				printf("����ˣ�ף���㣡��6��\n");
				return 6;
			}
		}
		else
		{
			printf("����ˣ���ܰ�����8��\n");
			return 8;
		}
	}
	else
	{
		printf("��ȫ��ȷ����ǳ���������10��\n");
		return 10;
	}
}
//ȡ�ຯ��
int quyu(int diyi,int dier,double *shuru,int i)
{
	double daan;
	printf("�������⣺\n");
	daan=diyi%dier;
	printf("%-2d%%%2d = ",diyi,dier);
	while(scanf("%lf",&shuru[i])!=1)
	{
		fflush(stdin);
		printf("��������,������������ȷ������\n");
	}
	fflush(stdin);
	if(daan!=shuru[i])
	{
		printf("�����ˣ�����Ŭ����\n");system("pause");system("cls");printf("���»ش�:\n");
		printf("%-2d%%%2d = ",diyi,dier);
		while(scanf("%lf",&shuru[i])!=1)
		{
			fflush(stdin);
			printf("��������,������������ȷ������\n");
		}
		fflush(stdin);
		if(daan!=shuru[i])
		{
			printf("�����ˣ�����Ŭ����\n");system("pause");system("cls");printf("���»ش�:\n");
			printf("%-2d%%%2d = ",diyi,dier);
			while(scanf("%lf",&shuru[i])!=1)
			{
				fflush(stdin);
				printf("��������,������������ȷ������\n");
			}
			fflush(stdin);
			if(daan!=shuru[i])
			{
				printf("�ǳ��ź����ִ���ˣ����������һ�⡣�������ȷ��Ϊ: %.2lf\n",daan);
				return 0;
			}
			else
			{
				printf("����ˣ�ף���㣡��6��\n");
				return 6;
			}
		}
		else
		{
			printf("����ˣ���ܰ�����8��\n");
			return 8;
		}
	}
	else
	{
		printf("��ȫ��ȷ����ǳ���������10��\n");
		return 10;
	}
}
//���˺ŵ�½��ʾ������������ʾ��
void show(struct jilu *head,int e)
{
	int i,j;
	struct jilu *shuchu;
	shuchu=head;
	if(head!=NULL)
	{
		printf("һ������%d����\n�ֱ�Ϊ:\n\n",e);
		for(i=0;i<e;i++)
		{
			printf("��%d�Σ�%cλ������\n",i+1,shuchu->weishu);
			for(j=0;j<10;j++)
			{
				printf("��%d��\n",j+1);
				if(shuchu->daan[j][0]==shuchu->daan[j][1])
				{
					printf("��������� :  %-2d%c%2d = %2.2lf\n",shuchu->shuzi[j][0],shuchu->yunsuanfu[j],shuchu->shuzi[j][1],shuchu->daan[j][1]);
					printf("�÷�Ϊ:  %d\n",shuchu->shuzi[j][2]);
				}
				else
				{
					printf("��������� :  %-2d%c%2d    ������Ĵ�Ϊ: %2.2lf   ��ȷ��Ϊ: %2.2lf\n",shuchu->shuzi[j][0],shuchu->yunsuanfu[j],shuchu->shuzi[j][1],shuchu->daan[j][0],shuchu->daan[j][1]);
					printf("�÷�Ϊ:  %d\n",0);
				}
			}
			printf("������%3d����",shuchu->cuowugeshu);
			printf("\n\n�ܷ�Ϊ:%5d\n\n",shuchu->defen);
			shuchu=shuchu->next;
		}
	}
	else
		printf("����û��������,��ȥ����\n");
}
//�˺ŵ�½��ʾ�������ṹ��������ʾ��
void dlshow(struct jilu *jianz,int e)
{
	int i,j;
	if(e>0)
	{
		printf("һ������%d����\n�ֱ�Ϊ:\n\n",e);
		for(i=0;i<e;i++)
		{
			printf("��%d�Σ�%cλ������\n",i+1,jianz[i].weishu);
			for(j=0;j<10;j++)
			{
				printf("��%d��\n",j+1);
				if(jianz[i].daan[j][0]==jianz[i].daan[j][1])
				{
					printf("��������� :  %-2d%c%2d = %2.2lf\n",jianz[i].shuzi[j][0],jianz[i].yunsuanfu[j],jianz[i].shuzi[j][1],jianz[i].daan[j][1]);
					printf("�÷�Ϊ:  %d\n",jianz[i].shuzi[j][2]);
				}
				else
				{
					printf("��������� :  %-2d%c%2d    ������Ĵ�Ϊ: %2.2lf   ��ȷ��Ϊ: %2.2lf\n",jianz[i].shuzi[j][0],jianz[i].yunsuanfu[j],jianz[i].shuzi[j][1],jianz[i].daan[j][0],jianz[i].daan[j][1]);
					printf("�÷�Ϊ:  %d\n",0);
				}
			}
			printf("������%3d����",jianz[i].cuowugeshu);
			printf("\n\n�ܷ�Ϊ:%5d\n\n",jianz[i].defen);
		}
	}
	else
		printf("����û��������,��ȥ����\n");
}
