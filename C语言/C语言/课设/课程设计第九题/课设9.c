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
		puts("������������ȷѡ��:");
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
		printf("�ڶ��ιر��ļ�ʧ��\n");
	printf("�ݰ�\n");
	return 0;
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
struct shebei * luru(struct shebei *head)
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
int lioulan(struct shebei *head)
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
void poyi(struct shebei *head)
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
			printf("��%d�������豸 : %s\n\n",j+1,prve->mingcheng);
			j++;
		}
		i++;
		prve=prve->next;
	}
	printf("����%d�������豸\n",j);
}
void yisun(struct shebei *head)
{
	int i=0,weizhi,j;
	char xz;
	struct shebei *prve,*qianyige;
	while(1)
	{
		j=lioulan(head);
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
void chaxun(struct shebei *head)
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
	
		
			


	







