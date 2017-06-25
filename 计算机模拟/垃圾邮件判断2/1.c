#include<stdio.h>
void main()
{
    int i,n;
    scanf("%d",&n);
    for(i=2;i<n;i++)
        if(n%i==0)break;
    if(i<n||n==1)puts("No");
    else puts("Yes");
}