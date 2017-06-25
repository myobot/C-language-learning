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
		printf("请输入正确的选项\n");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}
struct student * luru(void)
{
	struct student *head=NULL,*prve,*creat;
	printf("请输入第一个学生的信息:\n");
	printf("学号:");
	creat=(struct student *)malloc(sizeof(struct student));
	while(scanf("%d",&creat->xuehao)==1&&creat->xuehao!=0)
	{	
		fflush(stdin);
		printf("姓名:");
		gets(creat->xingming);fflush(stdin);
		printf("数学成绩:");
		while(scanf("%d",&creat->shuxue)!=1)
		{
			printf("输入有误，请重新输入正确的数学成绩\n");
			fflush(stdin);
		}
		fflush(stdin);
		printf("英语成绩:");
		while(scanf("%d",&creat->yingyu)!=1)
		{
			printf("输入有误，请重新输入正确的英语成绩\n");
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
		printf("现在请输入下一个学生的信息:\n");
		printf("学号:\n");
	}
	return head;
}
void tongji(struct student *head)
{
	struct student *p=head;
	printf("%10s%6s%16s%16s%16s\n","学号","姓名","数学成绩","英语成绩","平均成绩");
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
	printf("请输入要插入的位置\n");
	p=head;
	while(p)
	{
		i++;
		p=p->next;
	}
	while(scanf("%d",&x)!=1||x<1||x>i+1)
	{
		printf("输入有误，请重新输入要插入的位置\n");
		fflush(stdin);
	}
	fflush(stdin);
	New=(struct student *)malloc(sizeof(struct student));
	printf("现在请输入要插入的学生的信息\n");
	printf("学号:");
	while(scanf("%d",&New->xuehao)!=1)
	{
		printf("输入有误，请重新输入正确的数学成绩\n");
		fflush(stdin);
	}
	fflush(stdin);
	printf("姓名:");
	gets(New->xingming);fflush(stdin);
	printf("数学成绩:");
	while(scanf("%d",&New->shuxue)!=1)
	{
		printf("输入有误，请重新输入正确的数学成绩\n");
		fflush(stdin);
	}
	fflush(stdin);
	printf("英语成绩:");
	while(scanf("%d",&New->yingyu)!=1)
	{
		printf("输入有误，请重新输入正确的英语成绩\n");
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
	printf("请输入要查找的学号:\n");
	while(scanf("%d",&x)!=1)
	{
		printf("输入有误，请重新输入正确的学号\n");
		fflush(stdin);
	}
	fflush(stdin);
	while(p)
	{
		if(p->xuehao==x)
		{
			printf("此学生的信息为:\n");
			printf("学号:    %d\n姓名:    %s\n数学成绩:%d\n英语成绩:%d\n",p->xuehao,p->xingming,p->shuxue,p->yingyu,p->pingjun);
			flag++;
		}
		p=p->next;
	}
	if(flag==0)
		printf("未找到此学生!\n");
}
struct student * shanchu(struct student *head)
{
	int x,flag=0,i=0,j;
	struct student *p,*f;
	printf("请输入要查找的学号:\n");
	while(scanf("%d",&x)!=1)
	{
		printf("输入有误，请重新输入正确的学号\n");
		fflush(stdin);
	}
	fflush(stdin);
	p=head;
	while(p)
	{
		if(p->xuehao==x)
		{
			printf("此学生的信息为:\n");
			printf("学号:    %d\n姓名:    %s\n数学成绩:%d\n英语成绩:%d\n",p->xuehao,p->xingming,p->shuxue,p->yingyu,p->pingjun);
			flag++;
			break;
		}
		i++;
		p=p->next;
	}
	if(flag==0)
		printf("未找到此学生!\n");
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
			printf("已成功删除!\n");
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
	printf("排序已完成!\n");
}
	







	




int main()
{
	int i;
	char xz;
	struct student *head;
	while(1)
	{
		i=0;
		printf("1）建立链表并录入学生成绩\n\n2）统计学生成绩\n\n3）插入学生成绩\n\n4）查找学生成绩\n\n5）删除一个学生成绩\n\n6）将学生成绩按平均成绩排序\n\n0）退出\n\n请选择:\n\n");
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
	printf("再见\n");
	return 0;
}



