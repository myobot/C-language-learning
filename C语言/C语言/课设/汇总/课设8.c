#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char zqsr(char *c);
void diancai8(char *diancai,int *geshu);
void chakan8(char *diancai,int *geshu);
void tiancai8(char *diancai,int *geshu);
void jiancai8(char *diancai,int *geshu);
void jiesuan8(char *diancai,int *geshu);
void keshediba(void);
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
const int caijia[10]={3,10,18,15,88,12,8,48,58,25};
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
	printf("�ݰ�\n");
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


				






