#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void printArray(float *initialArray, int i);
int main(void)
{

    float l = 1000000000;
    float all[1000];
    float in = 0;
    for(int i = 0; i < 1000; i++)
    {

        all[i] = l / in;
        in++;
    }
    printArray(all, 1000);
    return 0;
}
void printArray(float *initialArray, int i)
{
    printf("Array: ");
    for(int k = 0; k < i ; k++)
    {
        printf("%d: %f\n", k, initialArray[k]);
    }
    printf("\n");
}