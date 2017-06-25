#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void hbmenu(void);
void cdmenu(void);
void eatline(void);
void member(FILE *fp,int x);
void elist(FILE *fp,int x,int p[],int y[]);
void alist(FILE *fp,int x);
void assign(FILE *fp,int weizhi);
void Delete(FILE *fp,int weizhi);
struct seat
{
	char hao;
	char biao;
	char keren[20];
};
struct hangban
{
	char hhao[4];
	struct seat seats[12];
};
int main()
{
	int flag=0,flag1,flag2=0;
	int hbwz;
	int p[12],y[1];
	FILE *fp;
	char hbxz,cdxz;
	char hb[4][4]={{"102"},{"311"},{"444"},{"519"}};
	if((fp=fopen("seat2.txt","r+"))==NULL)
	{
		puts("���ļ�ʧ��!");
		exit(1);
	}
	while(1)
	{
		hbmenu();
		puts("������Ҫѡ��ĺ����Ӧ���");
		hbxz=getchar();
		eatline();
		while(strchr("12340",hbxz)==NULL)
		{
			puts("����������������ȷѡ����� 1 , 2 , 3 , 4 , 0");
			hbxz=getchar();
			eatline();
		}
		if(hbxz=='0')
		{
			break;
		}
		else
		{
			hbwz=(int)hbxz-49;
			system("pause");
			system("cls");
			while(1)
			{
				flag1=0;flag2=0;
				printf("��ӭ��½���˺��չ�˾��Ʊϵͳ\n��ѡ���˵� %s ����\n",hb[hbwz]);
				cdmenu();
				puts("������ѡ��");
				cdxz=tolower(getchar());
				eatline();
				while(strchr("abcdefg",cdxz)==NULL)
				{
					puts("����������������ȷѡ����� a , b , c , d , e , f, g");
					cdxz=tolower(getchar());
					eatline();
				}
				switch(cdxz)
				{
					case 'a':member(fp,hbwz);break;
					case 'b':elist(fp,hbwz,p,y);break;
					case 'c':alist(fp,hbwz);break;
					case 'd':assign(fp,hbwz);break;
					case 'e':Delete(fp,hbwz);break;
					case 'f':flag1++;break;//�˳�������ѡ��
					case 'g':flag2++;break;//�˳�����
				}
				fflush(stdin);
				system("pause");
				system("cls");
				if(flag1>0)
					break;
				if(flag2>0)
					break;
			}
		}
		if(flag2>0)
			break;
	}
	puts("�ټ�");
	if(fclose(fp)!=0)
	{
		printf("�ر��ļ�ʧ��\n");
	}
	return 0;
}
void hbmenu(void)
{
	char hb[4][4]={{"102"},{"311"},{"444"},{"519"}};
	int i;
	for(i=0;i<4;i++)
	{
		printf("%d>: %s ����\n",i+1,hb[i]);
	}
	printf("0>: �˳�����\n");
}
void cdmenu(void)
{
	printf("a)����λ��\nb)����λ�б�\nc)��Ԥ����λ�б�\nd)Ԥ����λ\ne)ȡ��Ԥ��\nf)�˳�������ѡ��˵�\ng)�˳�����\n");
}
void eatline(void)
{
	while(getchar()!='\n')
		continue;
}
void member(FILE *fp,int x)
{
	struct hangban hhangban;
	int i,j=0;
	rewind(fp);
	fseek(fp,sizeof(struct hangban)*x,0);
	fread(&hhangban,sizeof(struct hangban),1,fp);
	for(i=0;i<12;i++)
	{
		if(hhangban.seats[i].biao=='0')
			j++;
	}
	printf("һ����%d������λ\n",j);
}
void elist(FILE *fp,int x,int p[],int y[])
{
	struct hangban hhangban;
	int i,j=0,flag=0;
	rewind(fp);
	fseek(fp,sizeof(struct hangban)*x,0);
	fread(&hhangban,sizeof(struct hangban),1,fp);
	printf("Ŀǰ��λ����:\n");
	for(i=0;i<12;i++)
	{
		if(hhangban.seats[i].biao=='0')
		{
			p[j]=i;
			j++;
			y[0]=j;
			printf("��%2dλ   ",i+1);
		//	flag++;
			if(++flag%6==0)
				printf("\n");
		}
	}
}
void alist(FILE *fp,int x)
{
	struct hangban hhangban;
	int i,as[12],j=0;
	char ke[12][10];
	rewind(fp);
	fseek(fp,sizeof(struct hangban)*x,0);
	fread(&hhangban,sizeof(struct hangban),1,fp);
	for(i=0;i<12;i++)
	{
		if(hhangban.seats[i].biao=='1')
		{
			as[j]=i;
			strcpy(ke[j],hhangban.seats[i].keren);
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
			printf("��%dλ  %s \n",as[i]+1,ke[i]);
		}
	}
}
void assign(FILE *fp,int weizhi)
{
	struct hangban hhangban;
	struct seat sseat;
	int x,p[12],y[1],i,flag,flag1=0,j=0;
	char queren,xingming[20];
	char hb[4][4]={{"102"},{"311"},{"444"},{"519"}};
	elist(fp,weizhi,p,y);
	rewind(fp);
	fseek(fp,sizeof(struct hangban)*weizhi,0);
	fread(&hhangban,sizeof(struct hangban),1,fp);
	printf("\n��������ҪԤ������λ��\n");
	while(1)
	{
		flag=0;
		if(scanf("%d",&x)!=1||(x<=0||x>12))
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
			printf("��ҪԤ������λ��Ϊ%d\n�Ƿ�ȷ�ϣ���ȷ�������� y ��ȡ��Ԥ������ n \n",x);
			eatline();
			while(1)
			{
				queren=getchar();
				eatline();
				if(queren=='y')
				{
					printf("�������������������Ϣ\n��������������:\n");
					gets(xingming);
					for(i=0;i<12;i++)
					{
						if(strcmp(xingming,hhangban.seats[i].keren)==0)
						{
							flag1=1;
							break;
						}
					}
					if(1==flag1)
					{
						printf("���Ѿ�Ԥ����λ�ˣ��벻Ҫ�ظ�Ԥ��!\n");
						break;
					}
					if(0==flag1)
					{
						strcpy(sseat.keren,xingming);
						sseat.biao='1';
						fseek(fp,sizeof(struct hangban)*weizhi+sizeof(char)*4+sizeof(struct seat)*(x-1),0);
						fwrite(&sseat,sizeof(struct seat),1,fp);
						printf("���ѳɹ�Ԥ���� %s ����ĵ� %d ��λ��\n",hb[weizhi],x);
						break;
					}
				}
				if(queren=='n')
				{
					printf("��ȡ����Ԥ��\n");
					break;
				}
				else
					puts("������ y �� n ,ȷ�ϻ�ȡ��Ԥ��");
			}
			break;
		}
		if(flag==0)
			printf("����λ�Ѿ���Ԥ������Ԥ����������λ\n");
	}
}
void Delete(FILE *fp,int weizhi)
{
	struct hangban hhangban;
	int x=0;
	int i;
	char xingming[20];
	char ch,biao='0';
	rewind(fp);
	fseek(fp,sizeof(struct hangban)*weizhi,0);
	fread(&hhangban,sizeof(struct hangban),1,fp);
	puts("��������������");
	gets(xingming);
	for(i=0;i<12;i++)
	{
		if(strcmp(xingming,hhangban.seats[i].keren)==0)
		{
			x=i+1;
			break;
		}
	}
	if(x==0)
		puts("��û��Ԥ����λ");
	else
	{
		printf("��Ԥ�����ǵ� %d λ\n���Ƿ���Ҫȡ��Ԥ���� ���� y ȡ��Ԥ�������� n ��ȡ��Ԥ��\n",x);
		while(1)
		{
			ch=getchar();
			eatline();
			if(ch=='y')
			{
				fseek(fp,sizeof(struct hangban)*weizhi+sizeof(char)*4+sizeof(struct seat)*(x-1)+sizeof(char),0);
				fwrite(&biao,sizeof(char),1,fp);
				puts("���ѳɹ�ȡ��Ԥ��!");
				break;
			}
			if(ch=='n')
			{
				puts("��л��ѡ�����ǣ�");
				break;
			}
			else
				puts("������ y �� n");
		}
	}
}





				

