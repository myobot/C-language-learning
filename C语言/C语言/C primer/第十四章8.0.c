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
		printf("���ļ�ʧ��\n");
		exit(1);
	}
	while(1)
	{	
		menu();
		rewind(fp);
		fread(&seats[0],sizeof(struct seat),12,fp);
		printf("������ѡ��\n");
		fflush(stdin);
		c=tolower(getchar());
		eatline();
		while(strchr("abcdef",c)==NULL)
		{
			puts("����������������ȷѡ����� a , b , c , d , e , f");
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
	puts("�ټ�");
	if(fclose(fp)!=0)
		printf("�ļ��ر�ʧ��\n");
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
	printf("һ����%d����λ��\n",j);
}
void elist(const struct seat seats[],int n,int p[],int y[])
{
	int i,j=0,k=0;
	printf("Ŀǰ��λ����:\n");
	for(i=0;i<n;i++)
	{
		if(seats[i].biao=='0')
		{
			p[j]=i;
			j++;
			y[0]=j;
			printf("��%-2dλ  ",i+1);
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
		printf("������λ����û�б�Ԥ��!\n");
	}
	else
	{
		printf("�Ѿ�Ԥ������λ��:\n");
		for(i=0;i<j;i++)
		{
			printf("��%-2dλ  %s \n",as[i]+1,ke[i]);
		}
	}
}
void assign(struct seat seats[],int n)
{
	struct seat assignd;
	int x,p[12],y[1],i,flag,j,flag1=0;
	char queren,xingming[20];
	elist(seats,n,p,y);
	printf("\n��������ҪԤ������λ��\n");
	while(1)
	{
		flag=0;
		if(scanf("%d",&x)!=1)
		{
			printf("��������ȷ����λ��,����������\n");
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
			printf("��ҪԤ������λ��Ϊ%d\n�Ƿ�ȷ�ϣ���ȷ�������� y ,ȡ��Ԥ�������� n \n",x);
			eatline();
			while(1)
			{
				queren=getchar();
				eatline();
				if(queren=='y')
				{
					printf("�������������������Ϣ\n��������������:\n");
					gets(xingming);
					for(j=0;j<n;j++)
					{
						if(strcmp(xingming,seats[i].keren)==0)
						{
							printf("���Ѿ�Ԥ��һ����λ��\n,�벻Ҫ�ظ�Ԥ��\n");
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
						printf("���ѳɹ�Ԥ����λ!\n");
						break;
					}
					else
					{
						printf("�ټ�\n");
						break;
					}
				}
				if(queren=='n')
				{
					printf("��ȡ����Ԥ��\n");
					break;
				}
				else
					printf("������ y �� n ,ȷ�ϻ�ȡ��\n");
			}
			eatline();
			break;
		}
		if(flag==0)
			printf("����λ�Ѿ���Ԥ������Ԥ����������λ\n");
	}
}
void Delete(struct seat seats[],int n)
{
	int x=-1;
	int i;
	char xingming[20];
	char ch;
	printf("��������������\n");
	gets(xingming);
	for(i=0;i<n;i++)
	{
		if(strcmp(xingming,seats[i].keren)==0)
			x=i+1;
	}
	if(x==-1)
	{
		printf("��û��Ԥ����λ��\n");
	}
	else
	{
		printf("��Ԥ������λ��:��%dλ\n���Ƿ���Ҫȡ��Ԥ���� ���� y ȡ��Ԥ�������� n ��ȡ��Ԥ��\n",x);
		while(1)
		{
			ch=getchar();
			if(ch=='y')
			{
				puts("���ѳɹ�ȡ��Ԥ��");
				seats[x-1].biao='0';
				break;
			}
			if(ch=='n')
			{
				puts("��л��ѡ�����ǣ�");
				break;
			}
			else
				printf("������ y �� n\n");
		}
	}
}
void menu(void)
{
	printf("��ӭ����½���˺��չ�˾������Ʊϵͳ\n");
	printf("a)����λ��\nb)����λ�б�\nc)��Ԥ����λ�б�\nd)Ԥ����λ\ne)ȡ��Ԥ��\nf)�˳�\n");
}
void eatline(void)
{
	while(getchar()!='\n')
		continue;
}
