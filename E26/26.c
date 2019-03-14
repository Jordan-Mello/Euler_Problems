#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void inputF(unsigned long int input);

int main(void)
{
    unsigned long int input = 0;

    inputF(input);

    return 0;
}
void inputF(unsigned long int input)
{
    char *temp = malloc(sizeof(char) * 15);
    printf("Phone number (enter only numbers):");

    fgets(temp, 15, stdin); //tried scanf, it sucks tbh for stuff like this
    if(temp[0] == '\n') //you can add extra conditions if you need (this just detects enter)
    {
        inputF(input);
    }
    else
    {
        input = strtoul(temp, &temp, 10); //makes string to int (technically integer == unsigned long int)
        if(input != 0)
        {
            printf("%lu", input); //you can check for negatives if need be
        }
    }
    free(temp);


}
