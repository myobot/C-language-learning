#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define N 200
int Rand(void);
struct list* Sequenlist(void);
void menu(void);
int print(struct list *l);
int insert(struct list *l);
int Delete(struct list *l);
void Sort(struct list *l);
char zqsr(char *c);
struct Data
{
	int shu;
};
struct list
{
	struct Data data[N];
	int last;
};
char zqsr(char *c)
{
	char xz;
	xz=getchar();
	fflush(stdin);
	while(strchr(c,xz)==NULL)
	{
		puts("请重新输入正确选项:");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}
int Rand(void)
{
	int x;
	srand((unsigned)time(0));					//不能在循环函数中调用？
	x=rand()%101;
	return x;
}
struct list* Sequenlist(void)
{
	int r,i,j;
	struct list *L;
	srand((unsigned)time(0));
	L=(struct list*)malloc(sizeof(struct list));
	L->last=-1;
	for(i=0,j=0;i<50;i++)
	{
		r=rand()%101;
		if(r%2==0)
		{
			L->data[j].shu=r;
			j++;
			L->last++;
		}
	}
	return L;
}
void menu(void)
{
	printf("1) 初始化一个顺序表,并随机生成50个数将偶数存如顺序表\n2) 输出顺序表所有元素，并显示长度\n3) 插入一个1~100内的随机数\n4) 删除\n5) 升序排列顺序表\n\n0) 退出\n\n请选择：\n");
}
int print(struct list *l)
{
	int i,j;
	for(i=0,j=1;i<=l->last;i++,j++)
	{
		printf("%4d",l->data[i].shu);
		if(j%5==0)
			printf("\n");
	}
	return (l->last+1);
}
int insert(struct list *l)
{
	int x,j,r;
	char xz;
	while(1)
	{
		printf("请输入要插入的位置:\n");
		while(scanf("%d",&x)!=1)
		{
			fflush(stdin);
			printf("输入有误，请重新输入正确数字!\n");
		}
		fflush(stdin);
		if((l->last+1)>=N)
		{
			printf("此顺序表已满，请先去删除后在插入\n");
			return 0;
		}
		if(x<1||x>l->last+2)
		{
			printf("输入位置非法，\n1) 重新输入\n\n2) 不再插入\n\n请选择:\n");
			xz=zqsr("12");
			if(xz=='2')
				return 0;
			else
				continue;
		}
		r=Rand();
		printf("随机生成的数为%4d\n",r);
		for(j=l->last;j>=x-1;j--)
			l->data[j+1].shu=l->data[j].shu;
		l->data[x-1].shu=r;
		l->last++;
		system("pause");
		printf("插入成功\n");
		break;
	}
	return 1;
}
			
int Delete(struct list *l)
{
	int i,x,p,j;
	char xz,xz1;
	printf("1)按查找删除\n\n2)按位置删除\n\n请选择:\n\n");
	xz1=zqsr("12");
	if(xz1=='2')
	{
		while(1)
		{
			printf("请输入要删除的位置:\n");
			while(scanf("%d",&x)!=1)
			{
				fflush(stdin);
				printf("输入有误，请重新输入正确的位置\n");
			}
			fflush(stdin);
			if(x<1||x>l->last+1)
			{
				printf("输入位置非法\n\n1)重新输入\n\n2)不再删除\n\n请选择:\n");
				xz=zqsr("12");
				if(xz=='2')
					return 0;
				else
					continue;
			}
			else
				break;
		}
		for(i=x;i<(l->last+1);i++)
			l->data[i-1].shu=l->data[i].shu;
		l->last--;
	}
	else
	{
		printf("请输入要删除的数据:\n");
		scanf("%d",&p);fflush(stdin);
		for(i=0,j=201;i<(l->last+1);i++)
		{
			if(p==l->data[i].shu)
			{
				j=i;
				break;
			}
		}
		if(j<=l->last)
		{
			printf("此数在第%4d位上\n",j+1);
			for(i=j+1;i<(l->last+1);i++)
				l->data[i-1].shu=l->data[i].shu;
			l->last--;
			system("pause");
			printf("已成功删除\n");
			return 1;
		}
		else
		{
			printf("未找到此数\n");
			return 0;
		}
	}
	return 1;
}
void Sort(struct list *l)
{
	int i,x,j,k,p,jishu;
	for(i=0;i<l->last+1;i++)
	{
		x=l->data[i].shu;
		k=i;
		for(j=i+1;j<l->last+1;j++)
		{
			if(x<l->data[j].shu)
			{
				k=j;
				x=l->data[j].shu;
			}
		}
		if(k!=i)
		{
			p=l->data[i].shu;
			l->data[i].shu=l->data[k].shu;
			l->data[k].shu=p;
		}
	}
	printf("排序已完成，此时顺序表内容如下:\n");
	system("pause");
	jishu=print(l);
	printf("\n共计%4d个元素\n",jishu);
}
	
int main()
{
	int k,i;
	char xz;
	struct list *l;
	while(1)
	{
		k=0;
		menu();
		xz=zqsr("123450");
		switch(xz)
		{
			case '1':system("cls");
				l=Sequenlist();printf("顺序表已建好\n");system("pause");system("cls");break;
			case '2':system("cls");
				i=print(l);printf("\n共计%4d个元素\n",i);
				system("pause");system("cls");break;
			case '3':system("cls");insert(l);system("pause");system("cls");break;
			case '4':system("cls");
				Delete(l);system("pause");system("cls");break;
			case '5':system("cls");Sort(l);system("pause");system("cls");break;
			case '0':k++;break;
		}
		if(k>0)
			break;
	}
	return 0;
}



	
