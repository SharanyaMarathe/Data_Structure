/*parenthesis check*/
#include<stdio.h>
#include<stdlib.h>
#define size 30
struct stack
{
   char items[size];
   int top;
};
typedef struct stack stk;
 void push(char ,stk * );
  char pop(stk * );
int isempty(stk *);
void push(char symb,stk *s)
{
    int item;
   if(s->top==size-1)
     printf("\nstack full");
   else
    s->items[++s->top]=item;
 }
char pop(stk *s)
{
    if(isempty(s))
    printf("\nStack full");
    else 
      return s->items[s->top--];
}
int isempty(stk *s) 
{
   if(s->top==-1)
   return 1;
   else
 return 0;  
} 
void main()
{   
   int i;
   char exp[40],symb;
   stk oprstk;
   oprstk.top=-1;
   printf("\nEnter the expression: ");
   scanf("%s",exp);
  while((symb=exp[i++])!='\0')
  {
     if(symb=='('||symb=='{'||symb=='[')
      {
         push(symb,&oprstk);
       }
    
    else 
      {
          if(symb==')' || symb=='}' || symb==']')
         {
           if(isempty(&oprstk))
           { printf("\nOpen parenthesis is missing");}
          
           else
             pop(&oprstk);
         }
      }
   
        if (isempty(&oprstk))
       {
         printf("\nClose psrenthesis is missing");
        } 
}}
