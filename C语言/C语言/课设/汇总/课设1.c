#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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
struct gongren
{
	char gongh[11];
	char xingming[10];
	int yfa[3];
	int yko[3];
	int shifa;
};
int keshediyi()
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
		system("pause");
		system("cls");
		if(flag>0)
			break;
	}
	puts("�ݰ�");
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
	
