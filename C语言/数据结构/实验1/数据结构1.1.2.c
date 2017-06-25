#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 200
char zqsr(char *c);
struct student * Sequenlist(void);
void tongji(struct student *l);
int charu(struct student *l);
int shanchu(struct student *l);
struct xinxi1
{
	int xuehao;
	char xingming[10];
	int shuxue;
	int yingyu;
	float pingjun;
};
struct student
{
	struct xinxi1 xinxi[N];
	int last;
};
char zqsr(char *c)
{
	char xz;
	xz=getchar();
	fflush(stdin);
	while(strchr(c,xz)==NULL)
	{
		printf("��������ȷ��ѡ��\n");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}
struct student * Sequenlist(void)
{
	int i=0;
	struct student *l;
	l=(struct student *)malloc(sizeof(struct student));
	l->last=-1;
	printf("�������һ��ѧ����ѧ��:\n");
	while(scanf("%d",&l->xinxi[i].xuehao)==1&&l->xinxi[i].xuehao!=0)
	{
		fflush(stdin);
		printf("�������ѧ����������\n");
		gets(l->xinxi[i].xingming);fflush(stdin);
		printf("�������ѧ������ѧ�ɼ�:\n");
		while(scanf("%d",&l->xinxi[i].shuxue)!=1)
		{
			printf("������������������\n");
			fflush(stdin);
		}
		fflush(stdin);
		printf("�������ѧ����Ӣ��ɼ�:\n");
		while(scanf("%d",&l->xinxi[i].yingyu)!=1)
		{
			printf("������������������\n");
			fflush(stdin);
		}
		fflush(stdin);
		l->xinxi[i].pingjun=(l->xinxi[i].yingyu+l->xinxi[i].shuxue)/2.0;
		i++;
		l->last++;
		printf("������������һ��ѧ����ѧ�ţ�����0��������\n");
	}
	return l;
}
void tongji(struct student *l)
{
	int sum1=0,sum2=0,i;
	printf("%10s%6s%16s%16s%16s\n","ѧ��","����","��ѧ�ɼ�","Ӣ��ɼ�","ƽ���ɼ�");
	for(i=0;i<l->last+1;i++)
	{
		printf("%10d%6s%16d%16d%16f\n",l->xinxi[i].xuehao,l->xinxi[i].xingming,l->xinxi[i].shuxue,l->xinxi[i].yingyu,l->xinxi[i].pingjun);
		sum1+=l->xinxi[i].shuxue;
		sum2+=l->xinxi[i].yingyu;
	}
	printf("\n\nӢ����ƽ���ɼ�Ϊ: %4f\n\n��ѧ��ƽ���ɼ�Ϊ: %4f\n\n",(sum1*1.0)/(l->last+1),(sum2*1.0)/(l->last+1));
}
int charu(struct student *l)
{
	int i,x;
	struct xinxi1 New;
	printf("������Ҫ�����λ��:\n");
	while(scanf("%d",&x)!=1)
	{
		printf("��������������������ȷ��λ��\n");
		fflush(stdin);
	}
	fflush(stdin);
	if(x<1||x>l->last+2)
	{
		printf("����λ�÷Ƿ�\n");
		return 0;
	}
	printf("������Ҫ����ѧ����ѧ��:\n");
	while(scanf("%d",&New.xuehao)!=1)
	{
		printf("��������,������������ȷ��ѧ��\n");
		fflush(stdin);
	}
	fflush(stdin);
	printf("�������ѧ��������\n");
	gets(New.xingming);fflush(stdin);
	printf("�������ѧ������ѧ�ɼ���Ӣ��ɼ����ÿո����\n");
	while(scanf("%d %d",&New.shuxue,&New.yingyu)!=2)
	{
		printf("��������������������ȷ�ĳɼ����ÿո����\n");
		fflush(stdin);
	}
	fflush(stdin);
	New.pingjun=(New.shuxue+New.yingyu)/2.0;
	system("pause");system("cls");
	for(i=l->last;i>=x-1;i--)
		l->xinxi[i+1]=l->xinxi[i];
	l->xinxi[x-1]=New;
	l->last++;
	printf("�Ѳ����ѧ��\n");
	return 1;
}
int chazhao(struct student *l)
{
	int x,i;
	printf("������Ҫ���ҵ�ѧ����ѧ��\n");
	while(scanf("%d",&x)!=1)
	{
		printf("��������������������ȷ��ѧ��\n");
		fflush(stdin);
	}
	fflush(stdin);
	for(i=0;i<l->last+1;i++)
	{
		if(l->xinxi[i].xuehao==x)
			break;
	}
	if(i>l->last)
	{
		printf("δ�ҵ���ѧ��\n");
		return 0;
	}
	else
	{
		printf("��ѧ������ϢΪ:\n");
		printf("ѧ��:%d\n����:%s\n��ѧ�ɼ�:%d\nӢ��ɼ�:%d\n",l->xinxi[i].xuehao,l->xinxi[i].xingming,l->xinxi[i].shuxue,l->xinxi[i].yingyu);
		return 1;
	}
}
int shanchu(struct student *l)
{
	int x,i,j;
	printf("������Ҫ���ҵ�ѧ����ѧ��\n");
	while(scanf("%d",&x)!=1)
	{
		printf("��������������������ȷ��ѧ��\n");
		fflush(stdin);
	}
	fflush(stdin);
	for(i=0;i<l->last+1;i++)
	{
		if(l->xinxi[i].xuehao==x)
			break;
	}
	if(i>l->last)
	{
		printf("δ�ҵ���ѧ��\n");
		return 0;
	}
	else
	{
		printf("��ѧ���ڵ�%4dλ\n",i+1);
		for(j=i+1;j<(l->last+1);j++)
			l->xinxi[j-1]=l->xinxi[j];
		l->last--;
		system("pause");
		printf("�Գɹ�ɾ��\n");
		return 1;
	}
}
void paixu(struct student *l)
{
	int i,j,k;
	struct xinxi1 swap,a;
	for(i=0;i<(l->last+1);i++)
	{
		k=i;
		a=l->xinxi[i];
		for(j=i+1;j<l->last+1;j++)
		{
			if(a.pingjun<l->xinxi[j].pingjun)
			{
				a=l->xinxi[j];
				k=j;
			}
		}
		if(k!=i)
		{
			swap=l->xinxi[i];
			l->xinxi[i]=l->xinxi[k];
			l->xinxi[k]=swap;
		}
	}
	printf("���������\n");
}
void menu(void)
{
	printf("1)�����ɼ�������ѧ���ɼ�\n\n2)ͳ��ѧ���ɼ�\n\n3)����һ���µ�ѧ���ɼ�\n\n4)����ѧ���ɼ�\n\n5)ɾ��һ��ѧ���ɼ�\n\n6)��ѧ���ɼ�������������\n\n0)�˳�\n\n��ѡ��:\n");
}
int main()
{
	int i;
	char xz;
	struct student *l;
	while(1)
	{
		menu();
		xz=zqsr("1234560");
		switch(xz)
		{
			case '1':system("cls");
				l=Sequenlist();system("pause");system("cls");break;
			case '2':system("cls");
				tongji(l);system("pause");system("cls");break;
			case '3':system("cls");
				charu(l);system("pause");system("cls");break;
			case '4':system("cls");
				chazhao(l);system("pause");system("cls");break;
			case '5':system("cls");
				shanchu(l);system("pause");system("cls");break;
			case '6':system("cls");
				paixu(l);system("pause");system("cls");break;
			case '0':i++;break;
		}
		if(i>0)
			break;
	}
	return 0;
}
