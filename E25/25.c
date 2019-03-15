#define _CRT_SECURE_NO_WARNINGS
#define a1 1
#define a2 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int DIGITS = 200000; //only overridden in main, given user input
int fibbognocchi(int *digits, int *p1, int *p2);
void printArray(int *initialArray, int i);
int main(void)
{
    // printf("Would you like to calculate a specific fibonacci number (enter s) or a certain digit length (enter d)?:");
    
    // char in[2];
    // fgets(in, 2, stdin);
    // in[1] = '\0';
    // if(in[0] == 's')
    // {
    //     printf("Please enter the desired Fibonacci number: ");
    //     scanf("%d", &DIGITS);
    //     printf("\nNow calculating Fibonacci number %d", DIGITS);
    // }
    // else if (in[0] == 'd')
    // {
    //     printf("d\n");
    // }
    // else
    // {
    //     printf("Error with input, please try again. Enter 0 to exit.\n");
    // }
    // getchar();
    int *digits = malloc(sizeof(int) * DIGITS);
    int *p1 = malloc(sizeof(int) * DIGITS);
    int *p2 = malloc(sizeof(int) * DIGITS);
    for(int i = 0; i < DIGITS; i++)
    {
        digits[i] = 0;
        p1[i] = 0;
        p2[i] = 0;
    }
    p1[DIGITS - 1] = 1;
    p2[DIGITS - 1] = 1;
    fibbognocchi(digits, p1, p2);
    //printArray(digits, DIGITS); 
    //use 1d array representation, with 0-9 in eac h spot, and when given  + number that makes it too big, add 1 to next spot (pass whole array back and forth, loop as needed)
    return 0;
}
int fibbognocchi(int *digits, int *p1, int *p2)
{
    int i = 0;
    int f = DIGITS - 1;
    int temp = 0;
    int temp2 = 0;
    for (int k = 0; k < 99999; k++)
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
                f--;
            }
            else
            {
                temp = p1[i] + p2[i] + temp;
                digits[f] = (temp % 10);
                temp = temp / 10;
                f--;                    
            }
        }
        memcpy(p2, p1, DIGITS * sizeof(int));
        memcpy(p1, digits, DIGITS * sizeof(int));
    }
                        printArray(digits, DIGITS);

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