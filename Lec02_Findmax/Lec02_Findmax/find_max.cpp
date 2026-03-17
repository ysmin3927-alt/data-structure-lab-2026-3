#include<stdio.h>

int findArrayMax(int score[], int n)//자료구조: 배열 array, n은 배열 길이
{
	int tmp = score[0];
	for (int i = 1; i < n; i++)
	{
		if (score[i] > tmp)
		{
			tmp = score[i];
		}
	}
	return tmp;
}


void main()
{
	int score[5] = { 90, 80, 95, 85, 70 };
	int out;
	out = findArrayMax(score, 5);
	printf("result = %d", out);

}