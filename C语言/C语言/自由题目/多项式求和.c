#include<stdio.h>
#include<stdlib.h>
int Scnaf();
struct dxs jia(struct dxs geshu[],int e);
struct dxs
{
	int duo[8][2];
/*	int yi[2];
	int er[2];
	int san[2];
	int si[2];
	int wu[2];
	int liu[2];
	int qi[2];
	int ba[2];*/
};
int Scanf()
{
	int i;
	while(scanf("%d",&i)!=1)
	{
		printf("������������������\n");
		fflush(stdin);
	}
	fflush(stdin);
	return i;
}

int main()
{
	int i,j,k;
	struct dxs geshu[6],he;
	printf("������һ���ж��ٸ�����ʽ:\n");
	while(scanf("%d",&k)!=1||k<0||k>6)
	{
		printf("������������������(��ȷ������С��6��)\n");
		fflush(stdin);
	}
	fflush(stdin);
	for(i=0;i<k;i++)
	{
		printf("�����������%d�������Եĳ�����:\n",i+1);
		geshu[i].duo[0][0]=Scanf();
		geshu[i].duo[0][1]=0;
		for(j=1;j<=7;j++)
		{
			printf("�����������%d������ʽ��ָ��Ϊ%d��ϵ��:\n",i+1,j);
			geshu[i].duo[j][0]=Scanf();
			geshu[i].duo[j][1]=j;
		}
		system("cls");
	}
	he=jia(geshu,k);
	for(i=0;i<8;i++)
	{
		if(he.duo[i][1]==0)
			printf("(%d)",he.duo[i][0]);
		if(he.duo[i][0]!=0)
		{
			printf("(%d) * X^%d",he.duo[i][0],he.duo[i][1]);
		}
		if(i<7)
			printf(" + ");
	}
	printf("\n");
}
struct dxs jia(struct dxs geshu[],int e)
{
	int i,j;
	struct dxs he;
	for(i=0;i<8;i++)
	{
		he.duo[i][0]=0;
		he.duo[i][1]=i;
	}
	for(i=0;i<e;i++)
	{
		for(j=0;j<8;j++)
		{
			he.duo[j][0]+=geshu[i].duo[j][0];
		}
	}
	return he;
}

		