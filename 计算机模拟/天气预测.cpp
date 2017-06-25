#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
int next_x(double P[])
{
	double r, p1, p2, p3;			//p1,p2,p3  �ֱ�Ϊ�ۼӸ���ֵ
	r = (double)rand() / RAND_MAX;	//����0-1֮�������
	p1 = P[0];
	p2 = p1+ P[1];
	p3 = p2 + P[2];					//��ʦ p1,p2,p3
	if (r <= p1)					//r����0-p1֮��  Ϊ����
		return 0;
	else if (r <= p2)				//r����p1-p2֮�� Ϊ����
		return 1;
	else if (r <= p3)				//r����p2-p3֮�� Ϊ����
		return 2;
	else							//r����p3-1֮��Ϊ ����
		return 3;

}
int main()
{
	double P[4][4] = { { 0.5, 0.1, 0.2, 0.2 }, { 0.2, 0.4, 0.2, 0.2 }, { 0.3, 0.2, 0.4, 0.1 }, { 0.2, 0.3, 0.1, 0.4 } };
	//ת�ƾ����ʼ��
	double SM[4] = { 0, 0, 0, 0 }, EM[4];
	//SMΪM������ƽ����Ӧ������EMΪ������ռ�������ٷֱ�
	int N = 365, M = 3, S[4] = {0,0,0,0}, x = 1, i, k;
	//N ÿ������������M �������	S��¼�����ж�Ӧ��������x���� i������ k������
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
