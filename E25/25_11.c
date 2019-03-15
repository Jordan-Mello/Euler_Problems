#define _CRT_SECURE_NO_WARNINGS
#define a1 1
#define a2 1
#include <time.h>
    #if defined(HAVE_SYS_TIME_H) || defined(WOLF_C99)
        #include <sys/time.h>
    #endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int DIGITS = 75000; //should be about 1/4 - 1/3 of fibnum
int fibbognocchi(int *digits, int *p1, int *p2);
void printArray(int *initialArray, int i);
int main(void)
{
    int *digits = malloc(sizeof(int) * DIGITS);
    int *p1 = malloc(sizeof(int) * DIGITS);
    int *p2 = malloc(sizeof(int) * DIGITS);
    printf("Would you like to calculate a specific fibonacci number (enter s) or a certain digit length (enter d)?:");
    
    char in[2];
    fgets(in, 2, stdin);
    in[1] = '\0';
    if(in[0] == 's')
    {
        printf("Please enter the desired Fibonacci number: ");
        scanf("%d", &DIGITS);
        printf("\nNow calculating Fibonacci number %d", DIGITS);
    }
    else if (in[0] == 'd')
    {
        scanf("%d", &DIGITS);
        printf("d\n");
    }
    else
    {
        printf("Error with input, please try again. Enter 0 to exit.\n");
    }
    for(int i = 0; i < DIGITS; i++)
    {
        digits[i] = 0;
        p1[i] = 0;
        p2[i] = 0;
    }
    p1[DIGITS - 1] = 1;
    p2[DIGITS - 1] = 1;
    fibbognocchi(digits, p1, p2);
    return 0;
}
int fibbognocchi(int *digits, int *p1, int *p2)
{
    int count = 0;
    int fibNum = 250000; //fib(x)
    int fibDiv = fibNum / 100; //used for % printing
    int divTemp = 0; //^
    int i = 0; //index for arrays
    int f = DIGITS - 1; //seperate index for digits
    int temp = 0;
    int temp2 = 0;
    clock_t start = clock();
    clock_t end;
    double time_elapsed_in_seconds;

    for (int k = 0; k < fibNum; k++)
    {
        f = DIGITS - 1;
        for(i = DIGITS - 1; i >= 0; i--)
        {
            if (p1[i] + p2[i] + temp < 10)
            {
                temp2 = p1[i] + p2[i] + temp;
                digits[f] = temp2;
                temp2 = 0;
                temp = 0;
            }
            else
            {
                temp = p1[i] + p2[i] + temp;
                digits[f] = (temp % 10);
                temp = temp / 10;
            }
            f--;
        }
        memcpy(p2, p1, DIGITS * sizeof(int));
        memcpy(p1, digits, DIGITS * sizeof(int));
        if(k == divTemp) //gives % completion
        {
            divTemp = fibDiv + divTemp;
            count++;
            printf("%d%%\n", count);
        }
    }
    printArray(digits, DIGITS); //prints array
    end = clock();
    //calculation for time taken to calculate
    time_elapsed_in_seconds = (end - start) / (double)CLOCKS_PER_SEC;
    printf("Seconds elapsed from start of program: %.2f", time_elapsed_in_seconds);
    getchar();
    return 0;
}
void printArray(int *initialArray, int i)
{
    printf("Array: ");
    for(int k = 0; k < i ; k++)
    {
        printf("%d", initialArray[k]);
    }
    printf("\n");
}
