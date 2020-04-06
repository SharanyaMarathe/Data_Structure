#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20
struct stack
{
   char items[size];
   int top;
};
typedef struct stack stk1;
void push(char ,stk1 *);
char pop(stk1 *);
int isfull(stk1 *);
int isempty(stk1 *);
char TOP(stk1 *);
int isoperand(char );
int inputpre(char );
int stkpre(char );
void inf_pos(char inf[],char pos[]);

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
    {
      case '+':
      case '-':
      case '*':
      case '/':
      case '$':
      case '^':
      case '(':
      case ')': return 0;break;
      default: return 1;break;
    }
   }
int inputpre(char opr)
  {
     switch(opr)
     {
          case '+':
          case '-':return 1;break;
          case '*':
          case '/':return 3;break;
          case '$':
          case '^':return 6;break;
          case '(':return 9;break;
          case ')':return 0;break;
          default:return 7;break;
      }
   }
 int stkpre(char opr) 
   {
     switch(opr)
     {
          case '+':
          case '-':return 2;break;
          case '*':
          case '/':return 4;break;
          case '$':
          case '^':return 5;break;
          case '(':return 0;break;
          default:return 8;break;
        
      }
   }  
void main()
{
   char infix[20],postfix[20];
    printf("\nEnter the infix expression: ");
    scanf("%s",infix);
    inf_pos(infix,postfix);
     printf("\nInfix expression is %s",infix);
     printf("\nPostfix expression is %s",postfix);
}
 void inf_pos(char inf[],char pos[])
  {
      stk1 oprstk;
      char symb;
     int i=0,j=0;
       oprstk.top=-1;
     while((symb=inf[i++])!='\0')
      { 
          if(isoperand(symb))
            pos[j++]=symb;
          else
        {
           while(!isempty(&oprstk) && stkpre(TOP(&oprstk))>inputpre(symb))
           {
              if(symb==')')
               {
                  while(TOP(&oprstk)!='(')
                 { 
                    pos[j++]=pop(&oprstk);
                 }
                    
                       pop(&oprstk);  
                     break;
                }
               else
                  pos[j++]=pop(&oprstk);
            }
         
             if(symb!=')')
               push(symb,&oprstk);
        } }     
           while(!isempty(&oprstk))
            {
                pos[j++]=pop(&oprstk);
             }
           
                 pos[j]='\0';
   
 }     
