#include<stdio.h>
#include<stdlib.h>
struct data
{
	int x;
	struct data *next;
};
struct data *chushihua(int n)
{
	int i;
	struct data *p,*New,*head=NULL;
	for(i=0;i<n;i++)
	{
		New=(struct data *)malloc(sizeof(struct data));
		if(head==NULL)
			head=New;
		else
			p->next=New;
		New->x=i+1;
		New->next=NULL;
		p=New;
	}
	return head;
}
struct data * shanchu(struct data *head,int weizhi)
{
	int i;
	struct data *p=head,*q;
	if(weizhi==1)
	{
		q=head;
		head=head->next;
		printf("%d位离开\n",q->x);
		free(q);
	}
	else
	{
		for(i=0;i<weizhi-2;i++)
		{
			p=p->next;
		}
		q=p->next;
		printf("%d位离开\n",q->x);
		p->next=q->next;
		free(q);
	}
	return head;
}

int main()
{
	int i,n,m,k,j,weizhi;
	struct data *head,*p;
	printf("请输入人数N和传递次数M(用空格隔开)\n");
	while((scanf("%d %d",&n,&m)!=2)&&n>=1&&m>=0)
	{
		printf("输入有误请重新输入\n");
		fflush(stdin);
	}
	fflush(stdin);
	head=chushihua(n);
	p=head;
	k=n;j=0;weizhi=1;
	while(k-1)
	{
		weizhi=(weizhi+m)%(n-j);
		if(weizhi==0)
			weizhi=k;
		head=shanchu(head,weizhi);
		k--;
		j++;
	}
	printf("%d位获胜\n",head->x);
	return 0;
}

		
