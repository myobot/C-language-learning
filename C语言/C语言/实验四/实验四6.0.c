#include<stdio.h>

int main()

{
	int ix,isum;

	isum=0;

	printf("������һ����\n");

	//scanf("%d",&ix);

	while(1)
	{
		scanf("%d",&ix);

		if(ix==0||ix<0)
			break;
		else
		{
			if(ix%2==0)
				isum=isum+ix;
			
		}
	}
	printf("%d\n",isum);

	return 0;

}