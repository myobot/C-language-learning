#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
int next_x(double P[])
{
	double r, p1, p2, p3;
	r = (double)rand() / RAND_MAX;
	p1 = P[0];
	p2 = p1+ P[1];
	p3 = p2 + P[2];
	if (r <= p1)
		return 0;
	else if (r <= p2)
		return 1;
	else if (r <= p3)
		return 2;
	else
		return 3;

}
int main()
{
	double P[4][4] = { { 0.5, 0.1, 0.2, 0.2 }, { 0.2, 0.4, 0.2, 0.2 }, { 0.3, 0.2, 0.4, 0.1 }, { 0.2, 0.3, 0.1, 0.4 } };
	double SM[4] = { 0, 0, 0, 0 }, EM[4];
	int N = 365, M = 3, S[4] = {0,0,0,0}, x = 1, i, k;
	srand((unsigned int)time(0));
	for (k = 0; k < M; k++)
	{
		for (i = 0; i < N; i++)
		{
			switch (x)
			{
				case 0:
				{
						  S[0]++;
						  x = next_x(P[0]);
				}
					break;
				case 1:
				{
						  S[1]++;
						  x = next_x(P[1]);
				}
					break;
				case 2:
				{
						  S[2]++;
						  x = next_x(P[2]);
				}
					break;
				case 3:
				{
						  S[3]++;
						  x = next_x(P[3]);
				}
					break;
			}

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
