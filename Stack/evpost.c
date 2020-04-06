#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define size 20
struct stack
{
   float items[size];
   int top;
};
typedef struct stack stk1;
void push(char ,stk1 *);
char pop(stk1 *);
int isfull(stk1 *);
int isempty(stk1 *);
char TOP(stk1 *);
int isoperand(char );
float evaluate(char []);
float compute(float ,float ,char );
void push(char opr,stk1 *s)
 {
    if(isfull(s))
       printf("\nstackfull");
    else 
      s->items[++s->top]=opr;
  }
  char pop(stk1 *s) 
 { 
      if(isempty(s))
        printf("\nstack empty");
      else
       return  s->items[s->top--];
  }
 int isfull(stk1 *s)
 {
    if(s->top==size-1)
     return 1;
     else
      return 0;
 }
 int isempty(stk1 *s)
  {
     if(s->top==-1)
      return 1;
      else
       return 0;
   }
char TOP(stk1 *s)
  {
     if(isempty(s))
       printf("stack empty");
     else
       return s->items[s->top]; 
   }
int isoperand(char symb)
{
     switch(symb)
    { case '+':
      case '-':
      case '*':
      case '/':
      case '$':
      case '^':return 0;break;
      
      default: return 1;break;
    }
}
void main()
{
   char infix[20],postfix[20];float result;
    printf("\nEnter the postfix expression: ");
    scanf("%s",postfix);
    result=evaluate(postfix);
     printf("\nResult is %f",result);
}
float evaluate(char pos[])
{
      stk1 oprstk;int i=0;
       oprstk.top=-1;
        char symb; 
       float digit,op1,op2;
      while((symb=pos[i++])!='\0')
        {   
          if(isoperand(symb))
           { digit=symb-'0';
             push(digit,&oprstk);
           }
       else
          op2=pop(&oprstk);
          op1=pop(&oprstk);
           push(compute(op1,op2,symb),&oprstk);
         }
      return TOP(&oprstk);
}
float compute(float op1,float op2,char opr)
{
      switch(opr)
      {
           case '+':return op1+op2;
           case '-':return op1-op2;
           case '*':return op1*op2;
           case '/':return op1/op2;
           case '$':
           case '^':return pow(op1,op2);
       }
}







