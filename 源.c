#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

main()
{
	int i, j;
	float g, sum, ave;
	for (i = 0; i < 6; i++)
	{
		sum = 0;
		for (j = 1; j <= 5; j++)
		{
			scanf("%f", &g);
			sum = sum + g;
		}
		ave = sum / 5;
		printf("第%d名学生的平均成绩：%f\n", i + 1, ave);
	}
}