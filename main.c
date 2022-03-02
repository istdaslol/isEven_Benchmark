#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define COUNT 1

typedef bool (*isEven_func) (int);

bool isEven1(int i)
{
	return (i & 0x1) != 0x1;
}

bool isEven2(int i)
{
	bool isEven = true;
	int j;
	for (j = 0; j < i; j++)
	{
		isEven = !isEven;
	}
	return isEven;
}

bool isEven3 (int i)
{
	return i % 2 == 0;
}

void test(isEven_func iE)
{
	int i;
	for (i = 0; i <= COUNT; i++)
	{
		printf("%d is %s\n", i, iE(i) ? "Even" : "Odd");
	}
}

int main()
{
	// block to test isEven1
	clock_t isEven1_start = clock();
	test((isEven_func)isEven1);
	clock_t isEven1_end = clock();

	// block to test isEven2
	clock_t isEven2_start = clock();
	test((isEven_func)isEven2);
	clock_t isEven2_end = clock();

	// block to test isEven3
	clock_t isEven3_start = clock();
	test((isEven_func)isEven3);
	clock_t isEven3_end = clock();

	printf("isEven1 took %.2f Seconds for %d Numbers\n",
			((float) (isEven1_end - isEven1_start) / CLOCKS_PER_SEC),
			COUNT);
	printf("isEven2 took %.2f Seconds for %d Numbers\n",
			((float) (isEven2_end - isEven2_start) / CLOCKS_PER_SEC),
			COUNT);
	printf("isEven3 took %.2f Seconds for %d Numbers\n",
			((float) (isEven3_end - isEven3_start) / CLOCKS_PER_SEC),
			COUNT);
	return 0;
}
