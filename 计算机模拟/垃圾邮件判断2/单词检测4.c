#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Danci
{
	char d[20];
};
int main()
{
	int i=0,j,p,i1,ji=0,sum=0;
	char c[20]={'\0'},c1[20],ch,n,ch1,file[41],*chp;
	struct Danci *danci;
	FILE *fp;
//	printf("���������\n");
	printf("������Ҫ�򿪵��ļ�(��ȷ�����ļ���Դ�ļ������ļ�����)\n");
	gets(file);
	if((fp=fopen(file,"r"))==NULL)
	{
		printf("���ļ�ʧ��!\n");
		exit(1);
	}
	while(1)
	{
		if((fscanf(fp,"%c",&ch1))==1)
		{
			ji++;
		//	printf("%c",ch1);
		}
		else
			break;
	}
	chp=(char*)malloc(ji*sizeof(char));
	danci=(struct Danci *)malloc(sizeof(struct Danci)*14746);
	if(chp==NULL)
	{
		printf("�ڴ治�㣬��������ʧ�ܣ�\n");
		exit(1);
	}
	rewind(fp);
	for(i=0;i<ji;i++)
	{
		if((fscanf(fp,"%c",&chp[i]))!=1)
			break;
	}

/*	for(i=0;i<N;i++)
	{	
		x[i]=getchar();
		if(x[i]=='0')
		{
			k=i;
			break;
		}
	}*/
//	while((ch=getchar())!='\n')
//		continue;
	
	
		for(i=0,j=0,p=0;i<=ji;i++,j++)
		{
			c[j]=chp[i];
		//	if(chp[i]>=32&&chp[i]<=47||chp[i]=='?'||chp[i]=='0')
			if(chp[i]==' ')
			{
				c[j]='\0';
				
				
				strcpy(danci[sum].d,c);
				sum++;
				for(i1=0;i1<j;i1++)
				{
					c[i1]='\0';
				}
				j=-1;
				i++;
				while(chp[i]==' ')
					i++;
				i--;
			}	
		}
	
	
	for(i=0,j=0;i<sum;i++,j++)
	{
		
		printf("%16s",danci[i].d);
		if(j%5==0)
			printf("\n");
	}
	printf("\n����%d����ĸ\n%d������\n",ji,sum);


/*	while(1)
	{
		printf("����%d����ĸ\n",ji);
		printf("\n������Ҫ���ҵĵ���:\n");
		gets(c1);
		for(i=0,j=0,p=0;i<=ji;i++,j++)
		{
			c[j]=chp[i];
			if(chp[i]>=32&&chp[i]<=47||chp[i]=='?'||chp[i]=='0')
			{
				c[j]='\0';
				if(strcmp(c1,c)==0)
				{
					p++;
				}
				for(i1=0;i1<j;i1++)
				{
					c[i1]='\0';
				}
				j=-1;
			}
		}
		if(p==0)
			printf("û�д˵���\n");
		if(p>0)
			printf("�д˵��ʣ���%d��\n",p);
		printf("�Ƿ�������������ʣ����� y ����������� y �������ַ�(�����)����\n");
		scanf("%c",&n);
		while((ch=getchar())!='\n')
			continue;
		if(n!='y')
			break;
		system("pause");
		system("cls");
//		for(i=0;i<ji;i++)
	//		printf("%c",chp[i]);
		printf("\n");
	}*/
	if(fclose(fp)!=0)
		printf("�ر��ļ�ʧ��!\n");
	free(chp);
	free(danci);
	printf("�ݰ�\n");
	return 0;
}