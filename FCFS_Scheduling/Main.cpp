#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>

void main()
{
    int n, b[10], w[10], i, j, h;
    int stime[10];
    int stmp, btmp;
    float avg = 0;
    system("cls");
    printf("\n\tJOB SCHEDULING ALGORITHM[FCFS]");
    printf("\n\t*****************************************************\n");
    printf("\nEnter howmany jobs:");
    scanf("%d", &n);

    printf("\nEnter burst time and arrival time for corresponding job....\n");
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d burst time:", i + 1);
        scanf("%d", &b[i]);
        printf("\nProcess %d arrival time:", i + 1);
        scanf("%d", &stime[i]);
    }

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (stime[i] > stime[j]) {
                stmp=stime[i];
                stime[i] = stime[j];
                stime[j] = stmp;
                btmp = b[i];
                b[i] = b[j];
                b[j] = btmp;
            }
        }
    }

    w[0] = 0;

    printf("\nprocess 1 waiting time is 0");
    for (i = 1; i < n; i++)
    {
        w[i] = b[i - 1] + w[i - 1] + stime[i-1] - stime[i];
        printf("\nProcess %d waiting time: %d", i + 1, w[i]);
        avg += w[i];
    }

    printf("\ntotal waiting time:%f", avg);

    printf("\n\nthe average waiting time is:%f\n", avg / n);
    printf("\nGaunt Chart\n * **************************************\n\n\t");
        h = 22;

    for (i = 0; i < n; i++)
    {
        printf("%d", b[i]);
        for (j = 1; j <= b[i]; j++)
            printf("%c", h);
    }
    printf("\n\t");
    for (i = 0; i < n; i++)
    {
        printf("%d", w[i]);
        for (j = 1; j <= w[i]; j++)
            printf("%c", h);
        Sleep(1000);
    }
    _getch();
}