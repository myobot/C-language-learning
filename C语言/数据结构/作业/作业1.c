#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct data 
{
	int shu;
	struct data *next;
};
struct data *chulian(void)
{
	struct data *p,*f,*e,*head,*q;
	int i,swap;
	head=(struct data *)malloc(sizeof(struct data));
	head->next=NULL;
	for(i=0;i<30;i++)
	{
		p=(struct data *)malloc(sizeof(struct data));
		p->shu=rand()%100+1;
		p->next=head->next;
		head->next=p;
	}
	p=head->next;
	while(p)
	{
		q=p->next;
		f=p;e=q;
		while(q)
		{
			if(f->shu>q->shu)
			{
				f=q;
			}
			q=q->next;
		}
		if(f->next!=e)
		{
			swap=p->shu;
			p->shu=f->shu;
			f->shu=swap;
		}
		p=p->next;
	}
	return head;
}
void shanchu(struct data *head,int mi,int ma)
{
	struct data *p,*q;
	p=head->next;
	q=head;
	while(p)
	{
		if(p->shu>mi&&p->shu<ma)
		{
			q->next=p->next;
			free(p);
			p=q->next;
		}
		else
		{
			p=p->next;
			q=q->next;
		}
	}
}
void print(struct data *head)
{
	struct data *p;
	p=head->next;
	while(p)
	{
		printf("%4d",p->shu);
		p=p->next;
	}
}
		
int main()
{
	struct data *head;
	int x,y;
	head=chulian();
	print(head);
	printf("\n«Î ‰»Î∑∂Œß:\n");
	scanf("%d %d",&x,&y);
	shanchu(head,x,y);
	print(head);
	printf("\n");
	return 0;
}
