#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student * luru(void);
void tongji(struct student *head);
struct student * charu(struct student *head);
struct student * shanchu(struct student *head);
char zqsr(char *c);
void paixu(struct student *head);
struct student
{
	int xuehao;
	char xingming[10];
	int shuxue;
	int yingyu;
	double pingjun;
	struct student *next;
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
struct student * luru(void)
{
	struct student *head=NULL,*prve,*creat;
	printf("�������һ��ѧ������Ϣ:\n");
	printf("ѧ��:");
	creat=(struct student *)malloc(sizeof(struct student));
	while(scanf("%d",&creat->xuehao)==1&&creat->xuehao!=0)
	{	
		fflush(stdin);
		printf("����:");
		gets(creat->xingming);fflush(stdin);
		printf("��ѧ�ɼ�:");
		while(scanf("%d",&creat->shuxue)!=1)
		{
			printf("��������������������ȷ����ѧ�ɼ�\n");
			fflush(stdin);
		}
		fflush(stdin);
		printf("Ӣ��ɼ�:");
		while(scanf("%d",&creat->yingyu)!=1)
		{
			printf("��������������������ȷ��Ӣ��ɼ�\n");
			fflush(stdin);
		}
		fflush(stdin);
		creat->pingjun=(creat->shuxue+creat->yingyu)/2.0;
		if(head==NULL)
			head=creat;
		else
			prve->next=creat;
		creat->next=NULL;
		prve=creat;
		creat=(struct student *)malloc(sizeof(struct student));
		system("cls");
		printf("������������һ��ѧ������Ϣ:\n");
		printf("ѧ��:\n");
	}
	return head;
}
void tongji(struct student *head)
{
	struct student *p=head;
	printf("%10s%6s%16s%16s%16s\n","ѧ��","����","��ѧ�ɼ�","Ӣ��ɼ�","ƽ���ɼ�");
	while(p)	
	{
		printf("%10d%6s%16d%16d%16lf\n",p->xuehao,p->xingming,p->shuxue,p->yingyu,p->pingjun);
		p=p->next;
	}
}
struct student * charu(struct student *head)
{
	int i=0,x;
	struct student *p,*New,*f;
	printf("������Ҫ�����λ��\n");
	p=head;
	while(p)
	{
		i++;
		p=p->next;
	}
	while(scanf("%d",&x)!=1||x<1||x>i+1)
	{
		printf("������������������Ҫ�����λ��\n");
		fflush(stdin);
	}
	fflush(stdin);
	New=(struct student *)malloc(sizeof(struct student));
	printf("����������Ҫ�����ѧ������Ϣ\n");
	printf("ѧ��:");
	while(scanf("%d",&New->xuehao)!=1)
	{
		printf("��������������������ȷ����ѧ�ɼ�\n");
		fflush(stdin);
	}
	fflush(stdin);
	printf("����:");
	gets(New->xingming);fflush(stdin);
	printf("��ѧ�ɼ�:");
	while(scanf("%d",&New->shuxue)!=1)
	{
		printf("��������������������ȷ����ѧ�ɼ�\n");
		fflush(stdin);
	}
	fflush(stdin);
	printf("Ӣ��ɼ�:");
	while(scanf("%d",&New->yingyu)!=1)
	{
		printf("��������������������ȷ��Ӣ��ɼ�\n");
		fflush(stdin);
	}
	fflush(stdin);
	New->pingjun=(New->shuxue+New->yingyu)/2.0;
	p=head;
	if(x==1)
	{
		New->next=p;
		head=New;
	}
	else
	{
		for(i=0;i<x-2;i++)
			p=p->next;
		f=p->next;
		p->next=New;
		New->next=f;
	}
	return head;
}
void chazhao(struct student *head)
{
	int x,flag=0;
	struct student *p=head;
	printf("������Ҫ���ҵ�ѧ��:\n");
	while(scanf("%d",&x)!=1)
	{
		printf("��������������������ȷ��ѧ��\n");
		fflush(stdin);
	}
	fflush(stdin);
	while(p)
	{
		if(p->xuehao==x)
		{
			printf("��ѧ������ϢΪ:\n");
			printf("ѧ��:    %d\n����:    %s\n��ѧ�ɼ�:%d\nӢ��ɼ�:%d\n",p->xuehao,p->xingming,p->shuxue,p->yingyu,p->pingjun);
			flag++;
		}
		p=p->next;
	}
	if(flag==0)
		printf("δ�ҵ���ѧ��!\n");
}
struct student * shanchu(struct student *head)
{
	int x,flag=0,i=0,j;
	struct student *p,*f;
	printf("������Ҫ���ҵ�ѧ��:\n");
	while(scanf("%d",&x)!=1)
	{
		printf("��������������������ȷ��ѧ��\n");
		fflush(stdin);
	}
	fflush(stdin);
	p=head;
	while(p)
	{
		if(p->xuehao==x)
		{
			printf("��ѧ������ϢΪ:\n");
			printf("ѧ��:    %d\n����:    %s\n��ѧ�ɼ�:%d\nӢ��ɼ�:%d\n",p->xuehao,p->xingming,p->shuxue,p->yingyu,p->pingjun);
			flag++;
			break;
		}
		i++;
		p=p->next;
	}
	if(flag==0)
		printf("δ�ҵ���ѧ��!\n");
	else
	{
		if(p==head)
		{
			f=p;
			head=head->next;
			free(f);
		}
		else
		{
			p=head;
			for(j=0;j<i-1;j++)
			{
				p=p->next;
			}
			f=p->next;
			p->next=p->next->next;
			free(f);
		}
			printf("�ѳɹ�ɾ��!\n");
	}
	return head;
}
void paixu(struct student *head)
{
	struct student *k,*p,*q,*f,*swap;
	p=head;
	swap=(struct student*)malloc(sizeof(struct student));
	while(p)
	{
		q=p->next;
		f=q;k=p;
		while(q)
		{
			if(k->pingjun<q->pingjun)
				k=q;
			q=q->next;
		}
		if(k->next!=f)
		{
			swap->xuehao=p->xuehao;
			strcpy(swap->xingming,p->xingming);
			swap->shuxue=p->shuxue;
			swap->yingyu=p->yingyu;
			swap->pingjun=p->pingjun;
			p->xuehao=k->xuehao;
			strcpy(p->xingming,k->xingming);
			p->shuxue=k->shuxue;
			p->yingyu=k->yingyu;
			p->pingjun=k->pingjun;
			k->xuehao=swap->xuehao;
			strcpy(k->xingming,swap->xingming);
			k->shuxue=swap->shuxue;
			k->yingyu=swap->yingyu;
			k->pingjun=swap->pingjun;
		}
		p=p->next;
	}
	printf("���������!\n");
}
	







	




int main()
{
	int i;
	char xz;
	struct student *head;
	while(1)
	{
		i=0;
		printf("1����������¼��ѧ���ɼ�\n\n2��ͳ��ѧ���ɼ�\n\n3������ѧ���ɼ�\n\n4������ѧ���ɼ�\n\n5��ɾ��һ��ѧ���ɼ�\n\n6����ѧ���ɼ���ƽ���ɼ�����\n\n0���˳�\n\n��ѡ��:\n\n");
		xz=zqsr("1234560");
		switch(xz)
		{
			case '1':system("cls");
					head=luru();system("pause");system("cls");break;
			case '2':system("cls");
					tongji(head);system("pause");system("cls");break;
			case '3':system("cls");
					head=charu(head);system("pause");system("cls");break;
			case '4':system("cls");
					chazhao(head);system("pause");system("cls");break;
			case '5':system("cls");
					head=shanchu(head);system("pause");system("cls");break;
			case '6':system("cls");
					paixu(head);system("pause");system("cls");break;
			case '0':system("cls");i++;break;
		}
		if(i>0)
			break;
	}
	printf("�ټ�\n");
	return 0;
}



