#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
struct number * creat(void);
void Long(struct number *head);
struct number *shanchu(struct number *head);
void print(struct number *head);
char zqsr(char *c);
struct number
{
	int shu;
	struct number *next;
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
void print(struct number *head)
{
	struct number *p=head;
	while(p)
	{
		printf("%4d",p->shu);
		p=p->next;
	}
	printf("\n");
}
struct number * creat(void)
{
	int i;
	struct number *head=NULL,*prve,*creat;
	srand((unsigned)time(0));
	for(i=0;i<15;i++)
	{
		creat=(struct number*)malloc(sizeof(struct number));
		if(head==NULL)
			head=creat;
		else
			prve->next=creat;
		creat->shu=rand()%200;
		creat->next=NULL;
		prve=creat;
	}
	printf("����������Ϊ:\n");
	print(head);
	return head;
}
void Long(struct number *head)
{
	int i=0;
	struct number *p;
	p=head;
	while(p)
	{	
		i++;
		p=p->next;
	}
	head->shu=i;
	printf("����Ϊ:%4d\n",i);
}
struct number *shanchu(struct number *head)
{
	int x;
	struct number *p,*f,*q;
	p=head;
	print(head);
	printf("\n������Ҫɾ������:\n");
	while(scanf("%d",&x)!=1)
	{
		printf("��������������������ȷ������\n");
		fflush(stdin);
	}
	fflush(stdin);
/*	while(p->next)
	{
		if(head->shu==x)
		{
			head=p->next;
			p=head;
		}
		else
		{
			if(x==p->next->shu)
			{
				f=p;q=p;
				p=p->next;
				f->next=p->next;
				free(q);
			}
		}
		p=p->next;
	}*/
	while(p)
	{
		if(head->shu==x)
		{
			q=head;
			head=p->next;
			p=head;
			free(q);
		}
		else
		{
			if(x==p->shu)
			{
				q=p->next;
				p->shu=p->next->shu;
				p->next=p->next->next;
				free(q);
			}
		}
		p=p->next;
	}



	printf("\nɾ��������Ϊ:\n");
	print(head);
	return head;
}
void paixu(struct number *head)
{
	int i=0,j=0,swap;
	struct number *p,*q,*f,*e;
	p=head;
/*	while(p)
	{
		j++;
		p=p->next;
	}
	for(i=0;i<j;i++)
	{
		k=i;
		for(p=i+i;p<j;p++)
		{
			if(*/
	while(p)
	{
		q=p->next;
		f=p;e=q;
		while(q)
		{
			if(f->shu>q->shu)
			{
				f=q;
			}
			q=q->next;
		}
		if(f->next!=e)
		{
			swap=p->shu;
			p->shu=f->shu;
			f->shu=swap;
		}
		p=p->next;
	}
	printf("����������Ϊ:\n");
	print(head);
}
int main()
{
	int i;
	char xz;
	struct number *head=NULL;
	while(1)
	{
		i=0;
		printf("1)����һ����20����������\n\n2)��������ĳ��ȣ������ȷŵ�ͷ������\n\n3)ɾ������ֵ\n\n4)��������\n\n0)�˳�\n\n��ѡ��:\n");
		xz=zqsr("12340");
		switch(xz)
		{
			case '1':system("cls");
					head=creat();system("pause");system("cls");break;
			case '2':system("cls");
					Long(head);system("pause");system("cls");break;
			case '3':system("cls");
					head=shanchu(head);system("pause");system("cls");break;
			case '4':system("cls");
					paixu(head);system("pause");system("cls");break;
			case '0':i++;break;
		}
		if(i>0)
			break;
	}
	return 0;
}
		
				

	