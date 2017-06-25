#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
int next_x(double P[])
{
	double r, p1, p2, p3;			//p1,p2,p3  分别为累加概率值
	r = (double)rand() / RAND_MAX;	//生成0-1之间随机数
	p1 = P[0];
	p2 = p1+ P[1];
	p3 = p2 + P[2];					//出师 p1,p2,p3
	if (r <= p1)					//r落在0-p1之间  为雨天
		return 0;
	else if (r <= p2)				//r落在p1-p2之间 为晴天
		return 1;
	else if (r <= p3)				//r落在p2-p3之间 为阴天
		return 2;
	else							//r落在p3-1之间为 多云
		return 3;

}
int main()
{
	double P[4][4] = { { 0.5, 0.1, 0.2, 0.2 }, { 0.2, 0.4, 0.2, 0.2 }, { 0.3, 0.2, 0.4, 0.1 }, { 0.2, 0.3, 0.1, 0.4 } };
	//转移矩阵初始化
	double SM[4] = { 0, 0, 0, 0 }, EM[4];
	//SM为M次试验平均对应天数，EM为天数所占总天数百分比
	int N = 365, M = 3, S[4] = {0,0,0,0}, x = 1, i, k;
	//N 每次试验天数。M 试验次数	S记录试验中对应天气数，x天气 i计数器 k计数器
	srand((unsigned int)time(0));
	for (k = 0; k < M; k++)
	{
		for (i = 0; i < N; i++)
		{
			S[x]++;
			x=next_x(P[x]);

		}
		
	}
	for (i = 0; i < 4; i++)
	{
		SM[i] = (double)S[i] / M;		
		EM[i] = (double)S[i] / (M*N);
	}
	printf("%-8c%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", 'M', "N0", "S0", "S1", "S2", "S3", "E0", "E1", "E2", "E3");
	printf("%-8d%-8d", M, N);
	for (i = 0; i < 4; i++)
	{
		printf("%-8.2lf", SM[i]);
	}
	for (i = 0; i < 4; i++)
	{
		printf("%-8.2lf", EM[i]);
	}
	printf("\n");
	return 0;
}
