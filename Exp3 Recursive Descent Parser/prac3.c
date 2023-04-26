// #include <stdio.h>
// #include <stdlib.h>
// char exp[50];
// int i=0;
// int main(){
//     printf("EXP3\n");
//     printf("Enter the expression: ");
//     scanf("%s",exp);
//     int n=strlen(exp);
//     E(exp);
//     if(i==n){
//         printf("\nExpression ACCEPTED");

//     }
//     else{
//         printf("REJECTED");
//     }
// }
// void T(){
//     F();
//     Tdash();
// }
// void Edash(){
//     T();
//     Edash();
// }
// void E(exp){
//     T();
//     Edash();
// }

// void Tdash(){
//     if(exp[i]=='*')
// 	{
//          	i++;
//          	F();
//          	Tdash();
// 	}
// }
// void F(){
//     if(exp[i]=='(')
//     {
//         i++;
//         E();
//         if(exp[i]==')')
//             i++;
//         else
//             er();
//     }
//     else if(exp[i]=='i')
//     {
//         i++;
//         printf(i);
//     }
//     else
//         er();
// }
// void er(){
//     exit(0);
// }


#include<stdio.h>
#include<string.h>
int i = 0;
char exp[50];
void advance(){
    i++;
}
void pE()
{
    pT();
    pEdash();
}
void pEdash()
{
    if(exp[i] =='+')
    {
        advance();
        pT();
        pEdash();
    }
}
void pT()
{
    pF();
    pTdash();
}
void pTdash()
{
    if(exp[i] == '*')
    {
        advance();
        pF();
        pTdash();
    }
}
void pF()
{
    if(exp[i]=="id"){
        advance();
    }
    if(exp[i]=='(')
    {
        advance();
        pE();
        
        if(exp[i]==')')
            advance();
        else
            er();
    }
    else if(exp[i]=='i')
    {
        advance();
    }
    else
        er();
}
void er()
{
    exit(0);
}
int main()
{
    printf("Enter the expression: ");
    scanf("%s",exp);
    int n = strlen(exp);
    pE(exp);
    if(i == n)
        printf("Accepted");
    else
        printf("Rejected");
}