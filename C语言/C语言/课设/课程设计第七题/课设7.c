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
		puts("������������ȷѡ��:");
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
		printf("�ر��ļ�ʧ��!\n");
	printf("�ݰ�");
	return 0;
}
void konglist(struct qiche *qqiche,int e)
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
		printf("\n��ѡ��λ:\n");
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
	printf("1)�����ƺ�\n\n2)����λ��\n\n0)�˻ص����˵�\n\n��ѡ��:\n");
	xz=zqsr("120");
	if(xz=='0')
		printf("ѡ�����˻ص����˵�\n");
	if(xz=='1')
	{
		system("cls");
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
		system("cls");
		printf("���������ĳ�λ��:\n");
		while(scanf("%d",&weizhi)!=1||(weizhi<=0||weizhi>20))
		{
			fflush(stdin);
			printf("��������ȷ����λ��,����������\n");
//			scanf("%d",&weizhi);
			fflush(stdin);
			system("pause");system("cls");printf("���������ĳ�λ��:\n");
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
	printf("����δ�뿪�����������˽��Ϊ:%d\n\n����δ�뿪������Ŀǰ�ܽ��Ϊ:%d\n",ruzhang+sum,ruzhang+sum+zaiweisum);
}
void chushihua(struct qiche *qqiche,int e,int sum)
{
	
	int i;
	char xz;
	printf("������Ϣ��������ʼ��\n\n�Ƿ�ȷ��?\n\n1)ȷ��\n\n0)�������˵�\n\n��ѡ��:\n");
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
		puts("ͣ����Ϣ�ѳ�ʼ��!");
	}
	else
		puts("��ʼ����ȡ��");
}
	




			






