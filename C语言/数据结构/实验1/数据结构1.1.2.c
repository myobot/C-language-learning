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
		printf("请输入正确的选项\n");
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
	printf("请输入第一名学生的学号:\n");
	while(scanf("%d",&l->xinxi[i].xuehao)==1&&l->xinxi[i].xuehao!=0)
	{
		fflush(stdin);
		printf("请输入该学生的姓名：\n");
		gets(l->xinxi[i].xingming);fflush(stdin);
		printf("请输入该学生的数学成绩:\n");
		while(scanf("%d",&l->xinxi[i].shuxue)!=1)
		{
			printf("输入有误请重新输入\n");
			fflush(stdin);
		}
		fflush(stdin);
		printf("请输入该学生的英语成绩:\n");
		while(scanf("%d",&l->xinxi[i].yingyu)!=1)
		{
			printf("输入有误请重新输入\n");
			fflush(stdin);
		}
		fflush(stdin);
		l->xinxi[i].pingjun=(l->xinxi[i].yingyu+l->xinxi[i].shuxue)/2.0;
		i++;
		l->last++;
		printf("现在请输入下一个学生的学号，输入0结束输入\n");
	}
	return l;
}
void tongji(struct student *l)
{
	int sum1=0,sum2=0,i;
	printf("%10s%6s%16s%16s%16s\n","学号","姓名","数学成绩","英语成绩","平均成绩");
	for(i=0;i<l->last+1;i++)
	{
		printf("%10d%6s%16d%16d%16f\n",l->xinxi[i].xuehao,l->xinxi[i].xingming,l->xinxi[i].shuxue,l->xinxi[i].yingyu,l->xinxi[i].pingjun);
		sum1+=l->xinxi[i].shuxue;
		sum2+=l->xinxi[i].yingyu;
	}
	printf("\n\n英语总平均成绩为: %4f\n\n数学总平均成绩为: %4f\n\n",(sum1*1.0)/(l->last+1),(sum2*1.0)/(l->last+1));
}
int charu(struct student *l)
{
	int i,x;
	struct xinxi1 New;
	printf("请输入要插入的位置:\n");
	while(scanf("%d",&x)!=1)
	{
		printf("输入有误请重新输入正确的位置\n");
		fflush(stdin);
	}
	fflush(stdin);
	if(x<1||x>l->last+2)
	{
		printf("输入位置非法\n");
		return 0;
	}
	printf("请输入要插入学生的学号:\n");
	while(scanf("%d",&New.xuehao)!=1)
	{
		printf("输入有误,请重新输入正确的学号\n");
		fflush(stdin);
	}
	fflush(stdin);
	printf("请输入此学生的姓名\n");
	gets(New.xingming);fflush(stdin);
	printf("请输入此学生的数学成绩和英语成绩，用空格隔开\n");
	while(scanf("%d %d",&New.shuxue,&New.yingyu)!=2)
	{
		printf("输入有误，请重新输入正确的成绩，用空格隔开\n");
		fflush(stdin);
	}
	fflush(stdin);
	New.pingjun=(New.shuxue+New.yingyu)/2.0;
	system("pause");system("cls");
	for(i=l->last;i>=x-1;i--)
		l->xinxi[i+1]=l->xinxi[i];
	l->xinxi[x-1]=New;
	l->last++;
	printf("已插入该学生\n");
	return 1;
}
int chazhao(struct student *l)
{
	int x,i;
	printf("请输入要查找的学生的学号\n");
	while(scanf("%d",&x)!=1)
	{
		printf("输入有误，请重新输入正确的学号\n");
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
		printf("未找到此学生\n");
		return 0;
	}
	else
	{
		printf("此学生的信息为:\n");
		printf("学号:%d\n姓名:%s\n数学成绩:%d\n英语成绩:%d\n",l->xinxi[i].xuehao,l->xinxi[i].xingming,l->xinxi[i].shuxue,l->xinxi[i].yingyu);
		return 1;
	}
}
int shanchu(struct student *l)
{
	int x,i,j;
	printf("请输入要查找的学生的学号\n");
	while(scanf("%d",&x)!=1)
	{
		printf("输入有误，请重新输入正确的学号\n");
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
		printf("未找到此学生\n");
		return 0;
	}
	else
	{
		printf("该学生在第%4d位\n",i+1);
		for(j=i+1;j<(l->last+1);j++)
			l->xinxi[j-1]=l->xinxi[j];
		l->last--;
		system("pause");
		printf("以成功删除\n");
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
	printf("排序已完成\n");
}
void menu(void)
{
	printf("1)创建成绩表并输入学生成绩\n\n2)统计学生成绩\n\n3)插入一个新的学生成绩\n\n4)查找学生成绩\n\n5)删除一个学生成绩\n\n6)将学生成绩进行升序排列\n\n0)退出\n\n请选择:\n");
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
