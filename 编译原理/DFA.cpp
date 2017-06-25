/*
------作者------王占伟
------时间------20160421
------名称------DFA
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRINGEND '\0'		//字符串结束标志	
#define MAXZNUM 100			//最多状态数
#define ZTYPE 2				//状态种类（非终结，终结）
#define MAXFUHAO 100		//最多符号数
#define MAXCHUAN 10000		//字符串最大长度
#define MAXCI 100			//字符串所含单词最多数
#define MAXLENGTH 100		//单个单词最长数

int Znum,Fnum;
void chushihua(int zhuanhuan[MAXZNUM][MAXFUHAO],char zhuangtai[MAXZNUM][ZTYPE],char fuhao[MAXFUHAO])
{
	zhuangtai[0][0]='0';		//状态初始化，二维数组[0]存储状态名[1]存储状态种类
	zhuangtai[0][1]=0;
	zhuangtai[1][0]='1';
	zhuangtai[1][1]=0;
	zhuangtai[2][0]='2';
	zhuangtai[2][1]=0;
	zhuangtai[3][0]='3';
	zhuangtai[3][1]=1;
	fuhao[0]='a';				//符号初始化
	fuhao[1]='b';
	fuhao[2]='c';
	fuhao[3]='d';
	zhuanhuan[0][0]=1;			//转换矩阵初始化	//-1表示不到达，-2表示到达终结状态
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
	Znum=4;						//状态数
	Fnum=4;						//符号数
}

int ztzh(int zhuanhuan[MAXZNUM][MAXFUHAO],char fuhao[MAXFUHAO],int nowzt,char f)		//状态转换函数
{

	int i;
	for(i=0;i<Fnum;i++)
	{
		if(fuhao[i]==f)
			break;
	}
	if(i==Fnum)		//如果符号不在其中，返回字符串错误
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
	printf("请输入字符串:");
	gets(chuan);
	nowzt=0;
	while(chuan[i]!=STRINGEND)
	{
		nextzt=ztzh(zhuanhuan,fuhao,nowzt,chuan[i]);
		if(nextzt!=-1&&nextzt!=-2)
		{
			ci[cinum][length++]=chuan[i];		//依次存字符
		}
		else if(nextzt==-2)
		{
			ci[cinum][length++]=chuan[i];		
			ci[cinum++][length]='\0';			//加结束符'\0'
			length=0;							//长度置0
		}
		else
		{
			printf("输入字符串第%d个有误\n",i+1);
			return;
		}
		if(nextzt!=-2)							//如果没有遇到终结状态
			nowzt=nextzt;						//now状态等于下一个状态（下一次循环为now状态）
		else									//如果遇到终结状态
			nowzt=0;							//now置为初始状态
		i++;
	}
	if(nowzt!=0)
	{
		printf("最后一个单词有误\n");
		
	}
	printf("检测完毕,共有%d个单词\n",cinum);
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




	




