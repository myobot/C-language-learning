#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void shuchuqipan(char qipan[][3]);
int duiyizhe(char qipan[][3]);
int diannao(char qipan[][3]);
int diannaojiance(char qipan[][3]);
int jiance(char qipan[][3]);
int shengfu(char qipan[][3]);
int main()
{
	int i,j,shengyu,k;
	char qipan[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			qipan[i][j]=' ';
	}
	while(1)
	{
		shengyu=jiance(qipan);
		if(shengyu==0)
		{
			printf("ƽ��\n");
			break;
		}		
		if((k=diannao(qipan))!=0)
			break;
		shengyu=jiance(qipan);
		if(shengyu==0)
		{
			printf("ƽ��\n");
			break;
		}
		if(shengyu!=0)
		{
			printf("������\n");system("pause");	system("cls");
		}
		if((k=duiyizhe(qipan))!=0)
			break;	
		else
		{
			printf("�������ǵ�������\n");system("pause");
		}
	}
	if(k==1)
		puts("��Ӯ��!\1");
	if(k==2)
		puts("������!");
	return 0;
}
void shuchuqipan(char qipan[][3])
{
	int i,j;
	printf("----------\n");
	for(i=0;i<3;i++)
	{
		printf("|");
		for(j=0;j<3;j++)
			printf("%2c|",qipan[i][j]);
		printf("\n----------\n");
	}
}
int duiyizhe(char qipan[][3])
{
	int yi,er;
	char queren;
	shuchuqipan(qipan);
	printf("\n\n������Ҫ�����ӷ���ĵ�λ��(�� 1,2 ,�ö��Ÿ���):\n");
	while(1)
	{
		while((scanf("%d,%d",&yi,&er)!=2)||(yi<0||yi>3||er<0||er>3))
		{
			fflush(stdin);
			system("cls");shuchuqipan(qipan);
			printf("��������ȷ��λ��!���Ͻ�Ϊ 1,1 ���½�Ϊ 3,3 \n�벻ҪԽ�磬����������\n");
		}
		fflush(stdin);
		if(qipan[yi-1][er-1]=='X'||qipan[yi-1][er-1]=='O')
		{
			printf("��λ���Ѿ�������!\n����������λ��\n");
			system("cls");shuchuqipan(qipan);
			continue;
		}
		printf("�����λ��Ϊ(%d,%d)\n\n�Ƿ�ȷ��?\n\ny)ȷ��\n\nn)��������\n\n��ѡ��:\n",yi,er);
		queren=getchar();
		fflush(stdin);
		while(strchr("yn",queren)==NULL)
		{
			printf("��������,������������ȷ��ѡ�� y��n\n");
			queren=getchar();
			fflush(stdin);
		}
		if(queren=='y')
		{
			system("cls");
			qipan[yi-1][er-1]='X';
			shuchuqipan(qipan);
			if(shengfu(qipan)==1)
				return 1;
			else
			{
				return 0;
			}
		}
		else
		{
			printf("���������룬Ҫ�����λ��\n");
			continue;
		}
	}
}
int diannao(char qipan[][3])
{
	
	int kongwei[9][2];
	int i,j,k,weizhi,flag,flag1;
	int k1,k2,k3,k4,p,e;
	int k5,k6,k7,k8;
	for(i=0,k=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(qipan[i][j]==' ')
			{
				kongwei[k][0]=i;
				kongwei[k][1]=j;
				k++;
			}
		}
	}
	flag=0;
	system("cls");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(qipan[i][j]=='O')
			{
				k1=0;k2=0;k3=0;k4=0;flag=0;k5=0;k6=0;k7=0;k8=0;
				for(p=0;p<3;p++)
				{
					if(j+p<3)								//��ֹԽ��
					{
						if(qipan[i][j+p]=='O')
						{
							k5++;
							if(k5==2)
								break;
						}
					}
					if(i+p<3)
					{
						if(qipan[i+p][j]=='O')
						{
							k6++;
							if(k6==2)
								break;
						}
					}
					if(i+p<3&&j+p<3)
					{
						if(qipan[i+p][j+p]=='O')
						{
							k7++;
							if(k7==2)
								break;
						}
					}
					if(i+p<3&&j-p>=0)
					{
						if(qipan[i+p][j-p]=='O')
						{
							k8++;
							if(k8==2)
								break;
						}
					}
				}
				if(k5==2)
				{
					for(e=0;e<3;e++)
					{
						if(qipan[i][e]==' ')
						{
							qipan[i][e]='O';
							flag++;
							break;
						}
					}
				}
				if(k6==2)
				{
					for(e=0;e<3;e++)
					{
						if(qipan[e][j]==' ')
						{
							qipan[e][j]='O';
							flag++;
							break;
						}
					}
				}
				if(k7==2)
				{
					for(e=0;e<3;e++)
					{
						if(qipan[e][e]==' ')
						{
							qipan[e][e]='O';
							flag++;
							break;
						}
					}
				}
				if(k8==2)
				{
					for(e=-2;e<3;e++)
					{
						if(i+e<3&&i+e>=0&&j-e>=0&&j-e<3)
						{
							if(qipan[i+e][j-e]==' ')
							{
								qipan[i+e][j-e]='O';
								flag++;
								break;
							}
						}
					}
				}
			}
			if(flag>0)
				break;
		}
		if(flag>0)
		{
			shuchuqipan(qipan);
			break;
		}
	}
	flag1=0;
	if(flag==0)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(qipan[i][j]=='X')
				{
					k1=0;k2=0;k3=0;k4=0;k5=0;k6=0;k7=0;k8=0;
					for(p=0;p<3;p++)
					{
						if(j+p<3)								//��ֹԽ��
						{
							if(qipan[i][j+p]=='X')
							{
								k1++;
								if(k1==2)
									break;
							}
						}
						if(i+p<3)
						{
							if(qipan[i+p][j]=='X')
							{
								k2++;
								if(k2==2)
									break;
							}
						}
						if(i+p<3&&j+p<3)
						{
							if(qipan[i+p][j+p]=='X')
							{
								k3++;
								if(k3==2)
									break;
							}
						}
						if(i+p<3&&j-p>=0)
						{
							if(qipan[i+p][j-p]=='X')
							{
								k4++;
								if(k4==2)
									break;
							}
						}
					}
					if(k1==2)
					{
						for(e=0;e<3;e++)
						{
							if(qipan[i][e]==' ')
							{
								qipan[i][e]='O';
								flag1++;
								break;
							}
						}
					}
					if(k2==2)			//&&k3<2&&k4<2&&k1<2
					{
						for(e=0;e<3;e++)
						{
							if(qipan[e][j]==' ')
							{
								qipan[e][j]='O';
								flag1++;
								break;
							}
						}
					}
					if(k3==2)			//&&k4<2&&k1<2&&k2<2
					{
						for(e=0;e<3;e++)
						{
							if(qipan[e][e]==' ')
							{
								qipan[e][e]='O';
								flag1++;
								break;
							}
						}
					}
					if(k4==2)			//&&k1<2&&k2<2&&k3<2
					{
						for(e=-2;e<3;e++)
						{
							if(i+e<3&&i+e>=0&&j-e>=0&&j-e<3)
							{
								if(qipan[i+e][j-e]==' ')
								{
									qipan[i+e][j-e]='O';
									flag1++;
									break;
								}
							}
						}
					}
				}
				if(flag1>0)
					break;
			}
			if(flag1>0)
			{
				shuchuqipan(qipan);
				break;
			}
		}
	}
	if(flag==0&&flag1==0)
	{
		srand((unsigned)time(0));
		weizhi=rand()%k;
		qipan[kongwei[weizhi][0]][kongwei[weizhi][1]]='O';
		shuchuqipan(qipan);
	}
	if(shengfu(qipan)==2)
		return 2;
	else
	{
		return 0;
	}
}
int jiance(char qipan[][3])
{
	int i,j,k;
	for(i=0,k=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(qipan[i][j]==' ')
				k++;
		}
	}
	return k;
}
int shengfu(char qipan[][3])
{
	int i;
	int j,k11,k12,k13,k14,k21,k22,k23,k24,p;
/*	for(i=0;i<3;i++)
	{
		if(qipan[i][0]==qipan[i][1]&&qipan[i][0]==qipan[i][2]&&qipan[i][1]==qipan[i][2]&&qipan[i][0]=='X')
			return 1;
		if(qipan[i][0]==qipan[i][1]&&qipan[i][0]==qipan[i][2]&&qipan[i][1]==qipan[i][2]&&qipan[i][0]=='X')
			return 2;
		if(qipan[0][i]==qipan[1][i]&&qipan[0][i]==qipan[2][i]&&qipan[1][i]==qipan[2][i]&&qipan[0][i]=='X')
			return 1;
		if(qipan[0][i]==qipan[1][i]&&qipan[0][i]==qipan[2][i]&&qipan[1][i]==qipan[2][i]&&qipan[0][i]=='X')
			return 2;
	}
	if(qipan[0][0]==qipan[1][1]&&qipan[0][0]==qipan[2][2]&&qipan[1][1]==qipan[2][2]&&qipan[0][0]=='X')
		return 1;
	if(qipan[0][0]==qipan[1][1]&&qipan[0][0]==qipan[2][2]&&qipan[1][1]==qipan[2][2]&&qipan[0][0]=='X')
		return 2;
	if(qipan[0][2]==qipan[1][1]&&qipan[0][2]==qipan[2][0]&&qipan[1][1]==qipan[2][0]&&qipan[1][1]=='X')
		return 1;
	if(qipan[0][2]==qipan[1][1]&&qipan[0][2]==qipan[2][0]&&qipan[1][1]==qipan[2][0]&&qipan[1][1]=='X')
		return 1;*/
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(qipan[i][j]!=' ')
			{
				k11=0;k12=0;k13=0;k14=0;k21=0;k22=0;k23=0;k24=0;
				for(p=0;p<3;p++)
				{
					if(j+p<3)
					{
						if(qipan[i][j+p]=='X')
							k11++;
						if(qipan[i][j+p]=='O')
							k21++;
					}
					if(i+p<3)
					{
						if(qipan[i+p][j]=='X')
							k12++;
						if(qipan[i+p][j]=='O')
							k22++;
					}
					if(i+p<3&&j+p<3)
					{
						if(qipan[i+p][j+p]=='X')
							k13++;
						if(qipan[i+p][j+p]=='O')
							k23++;
					}
					if(i+p<3&&j-p>=0)
					{
						if(qipan[i+p][j-p]=='X')
							k14++;
						if(qipan[i+p][j-p]=='O')
							k24++;
					}
				}
				if(k11==3||k12==3||k13==3||k14==3)
					return 1;
				if(k21==3||k22==3||k23==3||k24==3)
					return 2;
			}
		}
	}
	return 0;
}



