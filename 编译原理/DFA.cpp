/*
------����------��ռΰ
------ʱ��------20160421
------����------DFA
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRINGEND '\0'		//�ַ���������־	
#define MAXZNUM 100			//���״̬��
#define ZTYPE 2				//״̬���ࣨ���սᣬ�սᣩ
#define MAXFUHAO 100		//��������
#define MAXCHUAN 10000		//�ַ�����󳤶�
#define MAXCI 100			//�ַ����������������
#define MAXLENGTH 100		//�����������

int Znum,Fnum;
void chushihua(int zhuanhuan[MAXZNUM][MAXFUHAO],char zhuangtai[MAXZNUM][ZTYPE],char fuhao[MAXFUHAO])
{
	zhuangtai[0][0]='0';		//״̬��ʼ������ά����[0]�洢״̬��[1]�洢״̬����
	zhuangtai[0][1]=0;
	zhuangtai[1][0]='1';
	zhuangtai[1][1]=0;
	zhuangtai[2][0]='2';
	zhuangtai[2][1]=0;
	zhuangtai[3][0]='3';
	zhuangtai[3][1]=1;
	fuhao[0]='a';				//���ų�ʼ��
	fuhao[1]='b';
	fuhao[2]='c';
	fuhao[3]='d';
	zhuanhuan[0][0]=1;			//ת�������ʼ��	//-1��ʾ�����-2��ʾ�����ս�״̬
	zhuanhuan[0][1]=0;
	zhuanhuan[0][2]=-1;
	zhuanhuan[0][3]=-1;
	zhuanhuan[1][0]=-1;
	zhuanhuan[1][1]=-2;
	zhuanhuan[1][2]=1;
	zhuanhuan[1][3]=2;
	zhuanhuan[2][0]=1;
	zhuanhuan[2][1]=-1;
	zhuanhuan[2][2]=-1;
	zhuanhuan[2][3]=-1;

	zhuanhuan[3][0]=-2;
	zhuanhuan[3][1]=-2;
	zhuanhuan[3][2]=-2;
	zhuanhuan[3][3]=-2;
	Znum=4;						//״̬��
	Fnum=4;						//������
}

int ztzh(int zhuanhuan[MAXZNUM][MAXFUHAO],char fuhao[MAXFUHAO],int nowzt,char f)		//״̬ת������
{

	int i;
	for(i=0;i<Fnum;i++)
	{
		if(fuhao[i]==f)
			break;
	}
	if(i==Fnum)		//������Ų������У������ַ�������
		return -1;
	else
		return zhuanhuan[nowzt][i];
}
void jiancha(int zhuanhuan[MAXZNUM][MAXFUHAO],char zhuangtai[MAXZNUM][ZTYPE],char fuhao[MAXFUHAO])
{
	char chuan[MAXCHUAN];
	char ci[MAXCI][MAXLENGTH];
	int nowzt,nextzt,length=0,cinum=0;
	int i=0;
	printf("�������ַ���:");
	gets(chuan);
	nowzt=0;
	while(chuan[i]!=STRINGEND)
	{
		nextzt=ztzh(zhuanhuan,fuhao,nowzt,chuan[i]);
		if(nextzt!=-1&&nextzt!=-2)
		{
			ci[cinum][length++]=chuan[i];		//���δ��ַ�
		}
		else if(nextzt==-2)
		{
			ci[cinum][length++]=chuan[i];		
			ci[cinum++][length]='\0';			//�ӽ�����'\0'
			length=0;							//������0
		}
		else
		{
			printf("�����ַ�����%d������\n",i+1);
			return;
		}
		if(nextzt!=-2)							//���û�������ս�״̬
			nowzt=nextzt;						//now״̬������һ��״̬����һ��ѭ��Ϊnow״̬��
		else									//��������ս�״̬
			nowzt=0;							//now��Ϊ��ʼ״̬
		i++;
	}
	if(nowzt!=0)
	{
		printf("���һ����������\n");
		
	}
	printf("������,����%d������\n",cinum);
	for(i=0;i<cinum;i++)
	{
		puts(ci[i]);
	}
}
int main()
{
	int zhuanhuan[MAXZNUM][MAXFUHAO];
	char zhuangtai[MAXZNUM][ZTYPE],fuhao[MAXFUHAO];
	chushihua(zhuanhuan,zhuangtai,fuhao);
	jiancha(zhuanhuan,zhuangtai,fuhao);
	return 0;
}




	




