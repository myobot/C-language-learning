#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
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
	puts("�ݰ�");
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




				







	








		



		



	
