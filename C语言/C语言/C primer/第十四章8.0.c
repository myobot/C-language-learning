#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void member(const struct seat seats[],int n);
void elist(const struct seat seats[],int n,int p[],int y[]);
void alist(const struct seat seats[],int n);
void assign(struct seat seats[],int n);
void Delete(struct seat seats[],int n);
void menu(void);
void eatline(void);
struct seat
{
	char hao;
	char biao;
	char keren[20];
};
int main()
{
	struct seat seats[12];
	int flag=0,p[12],y[1];
	char c;
	FILE *fp;
	if((fp=fopen("seat.txt","r+"))==NULL)
	{
		printf("打开文件失败\n");
		exit(1);
	}
	while(1)
	{	
		menu();
		rewind(fp);
		fread(&seats[0],sizeof(struct seat),12,fp);
		printf("请输入选项\n");
		fflush(stdin);
		c=tolower(getchar());
		eatline();
		while(strchr("abcdef",c)==NULL)
		{
			puts("输入有误，请输入正确选项，例如 a , b , c , d , e , f");
			c=tolower(getchar());
			eatline();
		}
		switch(c)
		{
			case 'a': member(seats,12);break;
			case 'b': elist(seats,12,p,y);break;
			case 'c': alist(seats,12);break;
			case 'd': assign(seats,12);break;
			case 'e': Delete(seats,12);break;
			case 'f': flag++;break;
		}
		rewind(fp);
		fwrite(&seats[0],sizeof(struct seat),12,fp);
		system("pause");
		system("cls");
		if(flag>0)
		{
			break;
		}
	}
	puts("再见");
	if(fclose(fp)!=0)
		printf("文件关闭失败\n");
	return 0;
}
void member(const struct seat seats[],int n)
{
	int i,j=0;
	for(i=0;i<n;i++)
	{
		if(seats[i].biao=='0')
			j++;
	}
	printf("一共有%d个空位子\n",j);
}
void elist(const struct seat seats[],int n,int p[],int y[])
{
	int i,j=0,k=0;
	printf("目前空位子有:\n");
	for(i=0;i<n;i++)
	{
		if(seats[i].biao=='0')
		{
			p[j]=i;
			j++;
			y[0]=j;
			printf("第%-2d位  ",i+1);
			k++;
			if(k%4==0)
				printf("\n");
		}
	}
}
void alist(const struct seat seats[],int n)
{
	int i,as[12],j=0;
	char ke[12][20];
	for(i=0;i<n;i++)
	{
		if(seats[i].biao=='1')
		{
			as[j]=i;
			strcpy(ke[j],seats[i].keren);
			j++;
		}
	}
	if(j==0)
	{
		printf("所有座位都还没有被预定!\n");
	}
	else
	{
		printf("已经预定的座位有:\n");
		for(i=0;i<j;i++)
		{
			printf("第%-2d位  %s \n",as[i]+1,ke[i]);
		}
	}
}
void assign(struct seat seats[],int n)
{
	struct seat assignd;
	int x,p[12],y[1],i,flag,j,flag1=0;
	char queren,xingming[20];
	elist(seats,n,p,y);
	printf("\n请输入您要预定的座位号\n");
	while(1)
	{
		flag=0;
		if(scanf("%d",&x)!=1)
		{
			printf("请输入正确的座位号,请重新输入\n");
			continue;
		}
		for(i=0;i<=y[0];i++)
		{
			if((x-1)==p[i])
			{
				flag++;
				break;
			}
		}
		if(flag>0)
		{	
			printf("您要预定的座位号为%d\n是否确认？，确认请输入 y ,取消预定请输入 n \n",x);
			eatline();
			while(1)
			{
				queren=getchar();
				eatline();
				if(queren=='y')
				{
					printf("现在请输入您的身份信息\n请输入您的姓名:\n");
					gets(xingming);
					for(j=0;j<n;j++)
					{
						if(strcmp(xingming,seats[i].keren)==0)
						{
							printf("您已经预订一个座位了\n,请不要重复预订\n");
							flag1=1;
							break;
						}
					}
					if(flag1==0)
					{
						strcpy(seats[x-1].keren,xingming);
						seats[x-1].biao='1';
				//		assignd.hao=x+'0';
			//			assignd.biao='1';
				//		seats[x-1]=assignd;
						printf("您已成功预订座位!\n");
						break;
					}
					else
					{
						printf("再见\n");
						break;
					}
				}
				if(queren=='n')
				{
					printf("您取消了预定\n");
					break;
				}
				else
					printf("请输入 y 或 n ,确认或取消\n");
			}
			eatline();
			break;
		}
		if(flag==0)
			printf("该座位已经被预定，请预定上述空座位\n");
	}
}
void Delete(struct seat seats[],int n)
{
	int x=-1;
	int i;
	char xingming[20];
	char ch;
	printf("请输入您的姓名\n");
	gets(xingming);
	for(i=0;i<n;i++)
	{
		if(strcmp(xingming,seats[i].keren)==0)
			x=i+1;
	}
	if(x==-1)
	{
		printf("您没有预定座位！\n");
	}
	else
	{
		printf("您预订的座位是:第%d位\n您是否想要取消预定？ 输入 y 取消预定，输入 n 不取消预定\n",x);
		while(1)
		{
			ch=getchar();
			if(ch=='y')
			{
				puts("您已成功取消预定");
				seats[x-1].biao='0';
				break;
			}
			if(ch=='n')
			{
				puts("感谢您选择我们！");
				break;
			}
			else
				printf("请输入 y 或 n\n");
		}
	}
}
void menu(void)
{
	printf("欢迎您登陆巨人航空公司消定订票系统\n");
	printf("a)空座位数\nb)空座位列表\nc)已预订座位列表\nd)预定座位\ne)取消预定\nf)退出\n");
}
void eatline(void)
{
	while(getchar()!='\n')
		continue;
}
