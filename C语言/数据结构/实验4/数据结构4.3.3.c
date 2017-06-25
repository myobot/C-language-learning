#include<stdio.h>
#include<stdlib.h>
/
struct data
{
	int junrusj;
	int jye;
	int weizhi;
	int dengdaisj;
	struct data *next;
};
struct queue
{
	struct data *front;
	struct data *rear;
};
struct fwt
{
	int xuhao;
	int jiaoyie;
	int sum;
	int mark;
	int geshu;
	int jiaoyisj;
	int ksfw;
};