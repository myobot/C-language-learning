#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define S 45
char zqsr(char *c);	
struct checi *tianjia(struct checi *);
void lioulan(struct checi *);
int bancishuchu(struct checi *);
void xiougai(struct checi *);
void shijian(struct checi *,int weizhi);
int bancijiancha(struct checi*,int weizhi);
struct checi *shanchu(struct checi *);
void chaxun(struct checi*);
int konglist(struct checi *weizhi);
int alist(struct checi *weizhi);
void yuding(struct checi *weizhi);
void quxiao(struct checi *weizhi);
void paixu(struct checi *head);
void jiaohuan(struct checi *yi,struct checi *er);
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
					head=tianjia(head);system("pause");system("cls");break;
			case '2':system("cls");
					xiougai(head);system("pause");system("cls");break;
			case '3':system("cls");
					head=shanchu(head);system("pause");system("cls");break;
			case '4':system("cls");
					chaxun(head);system("pause");system("cls");break;
			case '5':system("cls");
					lioulan(head);system("pause");system("cls");break;
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
		printf("�ڶ��ιر��ļ�ʧ��\n");
	prve=head;
/*	while(prve!=NULL)
	{
		free(prve);
		prve=prve->next;
	}*/
	printf("�ݰ�");
	return 0;
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
struct checi * tianjia(struct checi *head)
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
void lioulan(struct checi *head)
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
void xiougai(struct checi *head)
{
	int i,k,gewei,shiwei,weizhi,geshu,flag,flag1,m,h;
	struct checi *prve;
	char xz,queren;
	if(head==NULL)
		printf("��û���κγ��Σ�����ȥ���\n");
	else
	{
		while(1)
		{	
			geshu=bancishuchu(head);
			printf("������Ҫ�޸ĵĳ������:\n");
			while(scanf("%d",&weizhi)!=1||(weizhi<=0||weizhi>geshu))
			{
				fflush(stdin);
				printf("��������ȷ�����,����������\n");system("pause");system("cls");bancishuchu(head);printf("������Ҫ�޸ĵĳ������\n");
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
								paixu(head);
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
}
struct checi *shanchu(struct checi *head)
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
void chaxun(struct checi *head)
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
						konglist(prve);system("pause");system("cls");break;
				case '2':system("cls");
						alist(prve);system("pause");system("cls");break;
				case '3':system("cls");
						yuding(prve);system("pause");system("cls");break;
				case '4':system("cls");
						quxiao(prve);system("pause");system("cls");break;
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
int konglist(struct checi *weizhi)
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
int alist(struct checi *weizhi)
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
void yuding(struct checi *weizhi)
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
		y=konglist(weizhi);
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
void quxiao(struct checi *weizhi)
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
void paixu(struct checi *head)
{
	int i=0,j;
	struct checi swap,*prve,*p;
	p=&swap;
	prve=head;
	if(prve->next==NULL)
	{
		prve->next=NULL;
	}
	else
	{
		prve=head;
		while(prve)
		{
			prve=prve->next;i++;
		}
		for(j=0;j<i-1;j++)
		{
			prve=head;
			while(prve->next)
			{
				if((prve->xiaoshi*100+prve->fenzhong)>(prve->next->xiaoshi*100+prve->next->fenzhong))
				{
					jiaohuan(prve,prve->next);
				}
				prve=prve->next;
			}
		}
	}
}
void jiaohuan(struct checi *yi,struct checi *er)				//ֻ���������ṹ�����ֵ�����Ӳ���;
{
	int i;
	struct checi swap;
	swap.xiaoshi=yi->xiaoshi;
	yi->xiaoshi=er->xiaoshi;
	er->xiaoshi=swap.xiaoshi;
	swap.fenzhong=yi->fenzhong;
	yi->fenzhong=er->fenzhong;
	er->fenzhong=swap.fenzhong;
	for(i=0;i<S;i++)
	{
		swap.sseat[i].hao=yi->sseat[i].hao;
		yi->sseat[i].hao=er->sseat[i].hao;
		er->sseat[i].hao=swap.sseat[i].hao;
		strcpy(swap.sseat[i].keren,yi->sseat[i].keren);
		strcpy(yi->sseat[i].keren,er->sseat[i].keren);
		strcpy(er->sseat[i].keren,swap.sseat[i].keren);
		swap.sseat[i].mark=yi->sseat[i].mark;
		yi->sseat[i].mark=er->sseat[i].mark;
		er->sseat[i].mark=swap.sseat[i].mark;
	}
}
				












				
			
			



		








