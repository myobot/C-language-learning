#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void menu(void);
void eatline(void);
void chuangjian(FILE *fp);
void chaxun(FILE *fp);
void ghchaxun(FILE *fp);
void xmchaxun(FILE *fp);
void shanchu(FILE *fp);
void xiougai(FILE *fp);
void huizong(FILE *fp);
void xianshi(FILE *fp);
struct gongren
{
	char gongh[11];
	char xingming[10];
	int yfa[3];
	int yko[3];
	int shifa;
};
int main()
{
	int flag=0,flag1=0;
	char xz;
//	char xuanx[9]={'1','2','3','4','5','6','7','8'};
	FILE *fp;
	if((fp=fopen("gongzi.txt","r+b"))==NULL)
	{
		puts("���ļ�ʧ��!");
		exit(1);
	}
	while(1)
	{
		menu();
		xz=getchar();
		eatline();
		while(strchr("12345678",xz)==NULL)
		{
			puts("�������,��������ȷѡ����� 1�� 2�� 3");
			xz=getchar();
			eatline();
		}
		switch(xz)
		{
			case '1':system("cls");chuangjian(fp);break;
//			case '2':												��������Ӻʹ�����ʲô��ͬ��
			case '3':system("cls");chaxun(fp);break;
			case '4':system("cls");shanchu(fp);break;
			case '5':system("cls");xiougai(fp);break;
			case '6':system("cls");huizong(fp);break;
			case '7':system("cls");xianshi(fp);break;
			case '8':flag++;break;
		}
		fflush(stdin);
		system("pause");
		system("cls");
		if(flag>0)
			break;
	}
	puts("�ݰ�");
	if(fclose(fp)!=0)
	{
		puts("�ر��ļ�����!");
	}
	return 0;
}
void menu(void)
{
	printf("%16s\n%20s\n%20s\n%20s\n%20s\n%20s\n%28s\n%20s\n%20s\n%16s\n","ְ�����ʹ���ϵͳ","1  ����","2  ���","3  ��ѯ","4  ɾ��","5  �޸�","6  ����ʵ������","7  ��ʾ","8  �˳�","��ѡ��:");
}
void eatline(void)
{
	while((getchar())!='\n')
		continue;
}
void chuangjian(FILE *fp)//�����Զ����ɣ�Ӧ�û����һЩ
{
	int x=0,flag,flag1;
	int i;
	struct gongren gong;
	struct gongren *jianz;
	struct gongren xgong;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	puts("��ѡ���˴���ѡ��");
	puts("��������ù��˵�����:");
	while(1)												//��������
	{
		flag=0;
		gets(xgong.xingming);
		for(i=0;i<x;i++)
		{
			if(strcmp(xgong.xingming,jianz[i].xingming)==0)
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
	puts("������ù��˵Ĺ���:");
	while(1)												//���Ų���
	{
		flag1=0;
		gets(xgong.gongh);
		for(i=0;i<x;i++)
		{
			if(strcmp(xgong.gongh,jianz[i].gongh)==0)
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
	puts("��������������ù��˵� ��λ���ʡ�н�����ʡ�ְ�����(�ÿո����)");
	while((scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]))!=3)
	{
		fflush(stdin);
		puts("�����������������������������ַ�,������������ȷ�Ĺ���");
		scanf("%d %d %d",&xgong.yfa[0],&xgong.yfa[1],&xgong.yfa[2]);
	}
	fflush(stdin);
	puts("��������������ù��˵� ����ѡ����շѡ�ˮ���(�ÿո����)");
	while((scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]))!=3)
	{
		fflush(stdin);
		puts("�����������������������������ַ�,������������ȷ�Ĺ���");
		scanf("%d %d %d",&xgong.yko[0],&xgong.yko[1],&xgong.yko[2]);
	}
	fflush(stdin);
	xgong.shifa=xgong.yfa[0]+xgong.yfa[1]+xgong.yfa[2]-xgong.yko[0]-xgong.yko[1]-xgong.yko[2];
	fseek(fp,0L,2);
	fwrite(&xgong,sizeof(struct gongren),1,fp);
	puts("���ѳɹ������ù�����Ϣ");
}
void huizong(FILE *fp)
{
	int x=0,sum=0;
	int i;
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	puts("ȫ������ʵ����������:");
	printf("%-16s%-16s%-16s\n","���˹���","��������","ʵ������");
	for(i=0;i<x;i++)
	{
		printf("%-16s%-16s%-16d\n",jianz[i].gongh,jianz[i].xingming,jianz[i].shifa);
	}
	for(i=0;i<x;i++)
	{
		sum+=jianz[i].shifa;
	}
	printf("%-s:%-16d\n","��ʵ������",sum);
	free(jianz);
}
void chaxun(FILE *fp)
{
	char xz;
	int flag=0;
	while(1)
	{
		printf("ѡ���˹��˲�ѯѡ��\n1)�����Ų�ѯ\n2)��������ѯ\n0)�˳�\n����������ѡ��:\n");
		xz=getchar();
		eatline();
		while(strchr("120",xz)==NULL)
		{
			printf("��������ȷ��ѡ��� 1�� 2�� 0��\n");
			xz=getchar();
			eatline();
		}
		switch(xz)
		{
			case '1':system("cls");ghchaxun(fp);system("pause");break;
			case '2':system("cls");xmchaxun(fp);system("pause");break;
			case '0':flag++;break;
		}
		fflush(stdin);
		system("cls");
		if(flag>0)
			break;
	}
}
void ghchaxun(FILE *fp)
{
	int x=0,flag=0,weizhi;
	int i;
	char gonghao[11];
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	printf("������Ҫ��ѯ�Ĺ��˵Ĺ���:\n");
	gets(gonghao);
	for(i=0;i<x;i++)
	{
		if(strcmp(gonghao,jianz[i].gongh)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		printf("�ù��˵���Ϣ���£�\n");
		printf("%-8s:%-16s\n%-8s:%-16s\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n","��������",jianz[weizhi].xingming,"���˹���",jianz[weizhi].gongh,"��λ����",jianz[weizhi].yfa[0],"н������",jianz[weizhi].yfa[1],"ְ�����",jianz[weizhi].yfa[2],"�����",jianz[weizhi].yko[0],"���շ�",jianz[weizhi].yko[1],"ˮ���",jianz[weizhi].yko[2],"ʵ������",jianz[weizhi].shifa);
	}
	else
		puts("û�иù���");
	free(jianz);
}
void xmchaxun(FILE *fp)
{
	int x=0,flag=0,weizhi;
	int i;
	char xingming[10];
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	printf("������Ҫ��ѯ�Ĺ��˵�����:\n");
	gets(xingming);
	for(i=0;i<x;i++)
	{
		if(strcmp(xingming,jianz[i].xingming)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		puts("�ù��˵���Ϣ���£�\n");
		printf("%-8s:%-16s\n%-8s:%-16s\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n%-8s:%-16d\n","��������",jianz[weizhi].xingming,"���˹���",jianz[weizhi].gongh,"��λ����",jianz[weizhi].yfa[0],"н������",jianz[weizhi].yfa[1],"ְ�����",jianz[weizhi].yfa[2],"�����",jianz[weizhi].yko[0],"���շ�",jianz[weizhi].yko[1],"ˮ���",jianz[weizhi].yko[2],"ʵ������",jianz[weizhi].shifa);
	}
	else
		puts("û�иù���");
	free(jianz);
}
void shanchu(FILE *fp)//��ν��ļ��������������ɾ��ԭ�ļ�?
{
	int x=0,flag=0,weizhi;
	int i;
	char gonghao[11],queren;
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	printf("��������Ҫɾ���Ĺ��˵Ĺ���\n");
	gets(gonghao);
	for(i=0;i<x;i++)
	{
		if(strcmp(gonghao,jianz[i].gongh)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		puts("�ù��˵���Ϣ���£�");
		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","��������",jianz[weizhi].xingming,"���˹���",jianz[weizhi].gongh,"��λ����",jianz[weizhi].yfa[0],"н������",jianz[weizhi].yfa[1],"ְ�����",jianz[weizhi].yfa[2],"�����",jianz[weizhi].yko[0],"���շ�",jianz[weizhi].yko[1],"ˮ���",jianz[weizhi].yko[2],"ʵ������",jianz[weizhi].shifa);
		printf("�Ƿ�ɾ���ù�����Ϣ?\n1):ɾ��\n2):ȡ��\n����������ѡ��\n");
		queren=getchar();
		eatline();
		while(strchr("12",queren)==NULL)
		{
			puts("��������ȷѡ��,�� 1�� 2");
			system("cls");
			queren=getchar();
			eatline();
		}
		if(queren=='1')
		{
			for(;weizhi<x-1;weizhi++)
			{
				jianz[weizhi]=jianz[weizhi+1];			//������ǰ����(ɾ��)
			}
			fclose(fp);                                 //�ȹر��ļ�
			if((fp=fopen("gongzi.txt","w+b"))==NULL)	//�� w+b�򿪣��ļ�����Ϊ�㣬���ݱ���գ�
			{
				printf("�ڶ��δ��ļ�ʧ��!\n");
				exit(2);
			}
			fseek(fp,0L,0);
			fwrite(&jianz[0],sizeof(struct gongren),x-1,fp);//��д���ļ�
			puts("���ѳɹ�ɾ���ù���");
			fclose(fp);									
			if((fp=fopen("gongzi.txt","r+b"))==NULL)		//������ r+b ��ʽ��
			{
				printf("�����δ��ļ�ʧ��!\n");
				exit(3);
			}
		}
		if(queren=='0')
		{
			puts("��ѡ����ȡ��ɾ��");
		}
	}
	else
		puts("û�иù���");
	free(jianz);
}
void xianshi(FILE *fp)
{
	int x=0,flag=0;
	int i,j,k;
	char xuanz;
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	printf("1):����������˳����ʾ\n2):����������������ʾ\n3):��ʵ����������������ʾ\n��ѡ��:\n");
	xuanz=getchar();
	eatline();
	while(strchr("123",xuanz)==NULL)
	{
		puts("��������ȷѡ��� 1�� 2�� 3��");
		xuanz=getchar();
		eatline();
	}
	if(xuanz=='1')
	{
		for(i=0;i<x-1;i++)
		{
			k=i;
			for(j=i;j<x-1;j++)
			{
				if(strcmp(jianz[k].gongh,jianz[j].gongh)>0)
				{
					k=j;
				}
			}
			if(k!=i)
			{
				gong=jianz[i];
				jianz[i]=jianz[k];
				jianz[k]=gong;
			}
		}
		puts("ȫ��������Ϣ����:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","���˹���","��������","��λ����","н������","ְ�����","�����","���շ�","ˮ���","ʵ������");
		for(i=0;i<x;i++)
		{
			printf("%-11s%-10s%-9d%-9d%-9d%-7d%-7d%-7d%-9d\n",jianz[i].gongh,jianz[i].xingming,jianz[i].yfa[0],jianz[i].yfa[1],jianz[i].yfa[2],jianz[i].yko[0],jianz[i].yko[1],jianz[i].yko[2],jianz[i].shifa);
		}

	}
	if(xuanz=='2')
	{
		for(i=0;i<x-1;i++)
		{
			k=i;
			for(j=i+1;j<x;j++)
			{
				if(strcmp(jianz[k].xingming,jianz[j].xingming)>0)
				{
					k=j;
				}
			}
			if(k!=i)
			{
				gong=jianz[i];
				jianz[i]=jianz[k];
				jianz[k]=gong;
			}
		}
		puts("ȫ��������Ϣ����:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","���˹���","��������","��λ����","н������","ְ�����","�����","���շ�","ˮ���","ʵ������");
		for(i=0;i<x;i++)
		{
			printf("%-11s%-10s%-9d%-9d%-9d%-7d%-7d%-7d%-9d\n",jianz[i].gongh,jianz[i].xingming,jianz[i].yfa[0],jianz[i].yfa[1],jianz[i].yfa[2],jianz[i].yko[0],jianz[i].yko[1],jianz[i].yko[2],jianz[i].shifa);
		}
	}
	if(xuanz=='3')
	{
		for(i=0;i<x-1;i++)
		{
			k=i;
			for(j=i+1;j<x;j++)
			{
				if(jianz[k].shifa>jianz[j].shifa)
				{
					k=j;
				}
			}
			if(k!=i)
			{
				gong=jianz[i];
				jianz[i]=jianz[k];
				jianz[k]=gong;
			}
		}
		puts("ȫ��������Ϣ����:");
		printf("%-11s%-10s%-9s%-9s%-9s%-7s%-7s%-7s%-9s\n","���˹���","��������","��λ����","н������","ְ�����","�����","���շ�","ˮ���","ʵ������");
		for(i=0;i<x;i++)
		{
			printf("%-11s%-10s%-9d%-9d%-9d%-7d%-7d%-7d%-9d\n",jianz[i].gongh,jianz[i].xingming,jianz[i].yfa[0],jianz[i].yfa[1],jianz[i].yfa[2],jianz[i].yko[0],jianz[i].yko[1],jianz[i].yko[2],jianz[i].shifa);
		}
	}
	free(jianz);
}
void xiougai(FILE *fp)
{
	int x=0,flag=0,weizhi;
	int i,flag1,flag2;
	char xuanz,queren;
	char gonghao[11];
	struct gongren gong;
	struct gongren *jianz;
	fseek(fp,0L,0);
	while(fread(&gong,sizeof(struct gongren),1,fp)==1)
	{
		x++;
	}
	jianz=(struct gongren *)malloc(x*sizeof(struct gongren));
	fseek(fp,0L,0);
	for(i=0;i<x;i++)
	{
		fread(&jianz[i],sizeof(struct gongren),1,fp);
	}
	printf("��������Ҫ�޸ĵĹ��˵Ĺ���\n");
	gets(gonghao);
	for(i=0;i<x;i++)
	{
		if(strcmp(gonghao,jianz[i].gongh)==0)
		{
			flag++;
			weizhi=i;
			break;
		}
	}
	if(flag>0)
	{
		gong=jianz[weizhi];
		puts("�ù��˵���Ϣ���£�");
		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","��������",jianz[weizhi].xingming,"���˹���",jianz[weizhi].gongh,"��λ����",jianz[weizhi].yfa[0],"н������",jianz[weizhi].yfa[1],"ְ�����",jianz[weizhi].yfa[2],"�����",jianz[weizhi].yko[0],"���շ�",jianz[weizhi].yko[1],"ˮ���",jianz[weizhi].yko[2],"ʵ������",jianz[weizhi].shifa);
		printf("%s\n%s\n%s\n%s\n%s\n%s\n","1):�޸ĸù��˵Ĺ���","2):�޸ĸù��˵�����","3):�޸ĸù��˵� ��λ���ʡ�н�����ʡ�ְ�����","4):�޸ĸù��˵� ����ѡ����շѡ�ˮ���","5):ȫ���޸�","0):�����޸�");
		puts("��ѡ��");
		xuanz=getchar();
		eatline();
		while(strchr("123450",xuanz)==NULL)
		{
			puts("��������ȷѡ����� 1�� 2�� ...");
			xuanz=getchar();
			eatline();
		}
		if(xuanz=='1')
		{
			puts("������ù��˵Ĺ���:");
			while(1)
			{
				flag1=0;
				gets(gong.gongh);
				for(i=0;i<x;i++)
				{
					if(strcmp(gong.gongh,jianz[i].gongh)==0)
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
				gets(gong.xingming);
				for(i=0;i<x;i++)
				{
					if(strcmp(gong.xingming,jianz[i].xingming)==0)
					{
						flag2++;
						break;
					}
				}
				if(flag==0)
					break;
				else
					printf("�Ѵ��ڸù���!\n��������빤������\n");
			}
		}
		if(xuanz=='3')
		{
			printf("����������ù����µ� ��λ���ʡ�н�����ʡ�ְ�����(�ÿո����)\n");
			while((scanf("%d %d %d",&gong.yfa[0],&gong.yfa[1],&gong.yfa[2]))!=3)
			{
				fflush(stdin);
				puts("�����������������������������ַ�,������������ȷ�Ĺ���");
				scanf("%d %d %d",&gong.yfa[0],&gong.yfa[1],&gong.yfa[2]);
			}
			gong.shifa=gong.yfa[0]+gong.yfa[1]+gong.yfa[2]-gong.yko[0]-gong.yko[1]-gong.yko[2];
			fflush(stdin);
		}
		if(xuanz=='4')
		{
			puts("����������ù����µ� ����ѡ����շѡ�ˮ���(�ÿո����)");
			while((scanf("%d %d %d",&gong.yko[0],&gong.yko[1],&gong.yko[2]))!=3)
			{
				fflush(stdin);
				puts("�����������������������������ַ�,������������ȷ�Ĺ���");
				scanf("%d %d %d",&gong.yko[0],&gong.yko[1],&gong.yko[2]);
			}
			gong.shifa=gong.yfa[0]+gong.yfa[1]+gong.yfa[2]-gong.yko[0]-gong.yko[1]-gong.yko[2];
			fflush(stdin);
		}
		if(xuanz=='5')
		{
			puts("��������ù��˵�����:");
			gets(gong.xingming);
			puts("������ù��˵Ĺ���:");
			gets(gong.gongh);
			puts("��������������ù��˵� ��λ���ʡ�н�����ʡ�ְ�����(�ÿո����)");
			while((scanf("%d %d %d",&gong.yfa[0],&gong.yfa[1],&gong.yfa[2]))!=3)
			{
				fflush(stdin);
				puts("�����������������������������ַ�,������������ȷ�Ĺ���");
				scanf("%d %d %d",&gong.yfa[0],&gong.yfa[1],&gong.yfa[2]);
			}
			fflush(stdin);
			puts("��������������ù��˵� ����ѡ����շѡ�ˮ���(�ÿո����)");
			while((scanf("%d %d %d",&gong.yko[0],&gong.yko[1],&gong.yko[2]))!=3)
			{
				fflush(stdin);
				puts("�����������������������������ַ�,������������ȷ�Ĺ���");
				scanf("%d %d %d",&gong.yko[0],&gong.yko[1],&gong.yko[2]);
			}
			fflush(stdin);
			gong.shifa=gong.yfa[0]+gong.yfa[1]+gong.yfa[2]-gong.yko[0]-gong.yko[1]-gong.yko[2];
		}
		if(xuanz=='0')
		{
			puts("��ѡ�����޸�");
		}
		system("cls");
		printf("���ù��˵���Ϣ����:\n");
		printf("%-s:%-16s\n%-s:%-16s\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n%-s:%-16d\n","��������",gong.xingming,"���˹���",gong.gongh,"��λ����",gong.yfa[0],"н������",gong.yfa[1],"ְ�����",gong.yfa[2],"�����",gong.yko[0],"���շ�",gong.yko[1],"ˮ���",gong.yko[2],"ʵ������",gong.shifa);
		printf("�Ƿ�ȷ���޸�?\ny):ȷ��\nn):ȡ��\n��ѡ��ѡ��\n");
		queren=getchar();
		eatline();
		while(strchr("yn",queren)==NULL)
		{
			puts("��������ȷѡ��,  y �� n");
			queren=getchar();
			eatline();
		}
		if(queren=='y')
		{
			fseek(fp,sizeof(struct gongren)*weizhi,0);
			fwrite(&gong,sizeof(struct gongren),1,fp);
			puts("�޸ĳɹ�");
		}
		if(queren=='n')
		{
			puts("�޸���ȡ��");
		}
	}
	else
		puts("û�иù��ˣ�");
	free(jianz);
}
	
