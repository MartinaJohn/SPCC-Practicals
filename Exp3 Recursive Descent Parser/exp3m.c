#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void E(), Edash(), T(), Tdash(), F();
const char *cursor;
char string[64];
int i = 0;
bool error = false;

void E()
{
    T();
    Edash();
}

void Edash()
{
    if (*cursor == '+')
    {
        cursor++;
        T();
        Edash();
    }
}
void T()
{
    F();
    Tdash();
}
void Tdash()
{
    if (*cursor == '*')
    {
        cursor++;
        F();
        Tdash();
    }
}
void F()
{
    if (*cursor == 'i')
    {
        cursor++;
        cursor++;
    }
    else if (*cursor == '(')
    {
        cursor++;
        E();
        if (*cursor == ')')
        {
            cursor++;
        }
        else
        {
            error = true;
        }
    }
    else
    {
        error = true;
    }
}

int main()
{
    printf("Enter the string: ");
    scanf("%s", string);
    cursor = string;
    E();
    if (error == true)
    {
        printf("Error in parsing string.\n");
    }
    else
    {
        printf("String is successfully parsed.\n");
    }
    return 0;
}
