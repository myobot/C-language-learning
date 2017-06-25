#include<iostream>
using namespace std;
template<typename T>
T max_(T a[],int n)
{
	int i;
	T max=a[0];
	for(i=1;i<n;i++)
	{
		if(max<a[i])
			max=a[i];
	}
	return max;
}
template<typename T>
T min_(T a[],int n)
{
	int i;
	T min=a[0];
	for(i=1;i<n;i++)
	{
		if(min>a[i])
			min=a[i];
	}
	return min;
}
template<typename T>
void sort(T data[],int n)
{
	int i,j;
	T swap;
	cout <<"排序前:\n";
	for(i=0;i<n;i++)
		cout <<data[i]<<"  ";
	for(i=0;i<n;i++)
	{
		swap=data[i];
		for(j=i-1;j>=0&&swap<data[j];j--)
			data[j+1]=data[j];
		data[j+1]=swap;
	}
	cout <<"\n排序后:\n";
	for(i=0;i<n;i++)
		cout <<data[i]<<"  ";
}
template<typename T>
void daozhi(T data[],int n)
{
	int i,j;
	T swap;
	cout <<"倒置前：\n";
	for(i=0;i<n;i++)
		cout <<data[i]<<"  ";
	for(i=0,j=n-1;i<n/2;i++,j--)
	{
		swap=data[i];
		data[i]=data[j];
		data[j]=swap;
	}
	cout <<"\n倒置后：\n";
	for(i=0;i<n;i++)
		cout <<data[i]<<"  ";
}
template<typename T>
void chazhao(T data[],int n)
{
	int i,mark=0;
	T a;
	cout <<"\n请输入要查找的值\n";
	cin >>a;
	for(i=0;i<n;i++)
	{
		if(a==data[i])
		{
			mark=1;
			break;
		}
	}
	if(mark==1)
	{
		cout <<"数组中有此值,在第"<<i<<"位\n";
	}
	else 
	{
		cout <<"没有找到\n";
	}
}
template<typename T>
T sum_(T data[],int n)
{
	T sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		sum+=data[i];
	}
	return sum;
}


int main()
{
	int a[5]={9,34,1345,21,3},amax,amin,sum;
	double b[5]={67.34,1234.5,123.66,154.33,453.66},bmax,bmin;
	char c[5]={'a','5','t','T','!'},cmax,cmin;
	amax=max_(a,5);
	amin=min_(a,5);
	bmax=max_(b,5);
	bmin=min_(b,5);
	cmax=max_(c,5);
	cmin=min_(c,5);
	sort(a,5);
	daozhi(b,5);
	chazhao(c,5);
	sum=sum_(a,5);
	printf("%d  %d\n%lf  %lf\n%c  %c\n",amax,amin,bmax,bmin,cmax,cmin);
	printf("sum a=%d\n",sum);

	return 0;
}

