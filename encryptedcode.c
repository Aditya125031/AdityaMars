#include <stdio.h>
#include <string.h>
#include <ctype.h>
void decode(char code[])//goes through every index of the array and subtracts their ASCII values with the succeeding index no i.e 1 for 0 index
{
    int temp;
    for(int i=0;code[i]!='\0';i++)
    {
        code[i] = toupper(code[i]);
        temp=(int)code[i];//stores the ascii value at ith index of original code
        printf("%c",(char)(temp-i-1));
    }
}
int main()
{
    char code[100];initializing a character array for input
    scanf("%s",code);
    decode(code);
}
