#include<stdio.h>
#include<stdlib.h>
struct stack
{
	char x;
	struct stack *next;
};
struct stack *chustack(void)
{
	struct stack *top;
	top=(struct stack *)malloc(sizeof(struct stack));
	top->next=NULL;
	return top;
}
void push(struct stack *top,char x)
{
	struct stack *p;
	p=(struct stack *)malloc(sizeof(struct stack));
	p->next=top->next;
	p->x=x;
	top->next=p;
}
char pop(struct stack *top)
{
	char c;
	struct stack *p;
	p=top->next;
	if(p==NULL)
		return '\0';
	c=p->x;
	top->next=p->next;
	free(p);
	return c;
}
int panduan(char zifu[])
{
	int i=0,k;
	char c;
	struct stack *top;
	top=chustack();
	c=zifu[i];
	while(c!='@')
	{
		push(top,c);
		i++;
		c=zifu[i];
	}
	k=i+1;
	while(zifu[k]!='\0')
	{
		c=pop(top);
		if(c=='\0')
			return 0;
		if(c!=zifu[k])
			return 0;
		k++;
	}
	if(top->next!=NULL)
		return 0;
	return 1;
}
int main()
{
	char zifu[100];
	printf("请输入字符串:\n");
	gets(zifu);
	fflush(stdin);
	if(panduan(zifu)==0)
		printf("不是\n");
	else
		printf("是\n");
	return 0;
}

		


