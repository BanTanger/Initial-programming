#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

// crt_clock.c
// This example prompts for how long
// the program is to run and then continuously
// displays the elapsed time for that period.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sleep(clock_t wait);

int main(void)
{
    long    i = 6000000L;
    clock_t start, finish;
    double  duration;

    // Delay for a specified time.
    printf("Delay for three seconds\n");
    sleep((clock_t)3 * CLOCKS_PER_SEC);
    printf("Done!\n");

    // Measure the duration of an event.
    printf("Time to do %ld empty loops is ", i);
    start = clock();
    while (i--)
        ;
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%2.1f seconds\n", duration);
}

// Pauses for a specified number of milliseconds.
void sleep(clock_t wait)
{
    clock_t goal;
    goal = wait + clock();
    while (goal > clock())
        ;
}

//double f(int n, double a[], double x)
//{
//	int i = 0;
//	double p = a[n];
//	for (i = n; i > 0; i--)
//	{
//		p = a[i - 1] + x * p;
//	}
//	return p;
//}

//int main()
//{
//	double x = 1;
//	int n = 1;
//	double a[] = { 0 };
//	f(n, a[1],x);
//	return 0;
//}

//void printN(int N)
//{
//	int i = 0;
//	for (i = 1; i <= N; i++)
//	{
//		printf("%d ", i);
//	}
//}
//
//void printN(int N)
//{
//	if (N)
//	{
//		printN(N - 1);
//		printf("%d ", N);
//	}
//}

//int main()
//{
//	int N = 100000;
//	printN(N);
//	return 0;
//}