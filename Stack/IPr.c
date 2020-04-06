#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20
struct stack1
{
   char items[size];
   int top;
};
typedef struct stack1 stk1;
void push1(char ,stk1 *);
char pop1(stk1 *);
int isfull1(stk1 *);
int isempty1(stk1 *);
int TOP1(stk1 *);
int isoperand(char );
int inputpre(char );
int stkpre(char );
void inf_pre(char inf[],char pre[]);
struct stack2
{
     char items[size][10];
      int top;
};
 typedef struct stack2 stk2;
void push2(char [] ,stk2 *);
char *pop2(stk2 *);
int isfull2(stk2 *);
int isempty2(stk2 *);
char *TOP2(stk2 *);
void parexp(stk2 *,stk1 *);
 void push1(char opr,stk1 *s)
 {
    if(isfull1(s))
       printf("\nstackfull");
    else 
      s->items[++s->top]=opr;
  }
  char pop1(stk1 *s) 
 {
      if(isempty1(s))
        printf("\nstack empty");
      else
       return  s->items[s->top--];
  }
 int isfull1(stk1 *s)
 {
    if(s->top==size-1)
     return 1;
     else
      return 0;
 }
 int isempty1(stk1 *s)
  {
     if(s->top==-1)
      return 1;
      else
       return 0;
   }
int TOP1(stk1 *s)
  {
     if(isempty1(s))
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
void push2(char opnd[],stk2 *s1)
 {
     
    if(isfull2(s1))
       printf("\nstackfull");
    else 
     strcpy(s1->items[++s1->top],opnd); 
      
  }
  char *pop2(stk2 *s1) 
 {     
      char *item;  
      if(isempty2(s1))
        printf("\nstack empty");
      else
        item =  s1->items[s1->top--];
          return item;
        
  }
 int isfull2(stk2 *s1)
 {
    if(s1->top==size-1)
     return 1;
     else
      return 0;
 }
 int isempty2(stk2 * s1)
  {
     if(s1->top==-1)
      return 1;
      else
       return 0;
   }
char *TOP2(stk2 *s1)
  {
     if(isempty2(s1))
       printf("stack empty");
     else
      
       return (s1->items[s1->top]); 
   } 
void main()
{
   char infix[20],prefix[20];
    printf("\nEnter the infix expression: ");
    scanf("%s",infix);
    inf_pre(infix,prefix);
     printf("\nInfix expression is %s",infix);
     printf("\nPrefix expression is %s",prefix);
}
 void inf_pre(char inf[],char pre[])
  {
      stk1 oprstk;
      stk2 opndstk;
      char temp[2];
      char symb;
     int i=0,j=0;
       oprstk.top=-1;opndstk.top=-1;
     while((symb=inf[i++])!='\0')
      { 
          if(isoperand(symb))
         {  temp[0]=symb;
            temp[1]='\0';
           push2(temp,&opndstk);
         }       
          else
        {
           while(!isempty1(&oprstk) && stkpre(TOP1(&oprstk))>inputpre(symb))
           {
              if(symb==')')
               {
                  while(TOP1(&oprstk)!='(')
                 {  parexp(&opndstk,&oprstk);}
                    
                       pop1(&oprstk);  
                     break;
                }
               else
                  parexp(&opndstk,&oprstk);
            }
         
             if(symb!=')')
               push1(symb,&oprstk);
        } }     
           while(!isempty1(&oprstk))
            {
                parexp(&opndstk,&oprstk);
                 strcpy (pre,TOP2(&opndstk));
            }         
   
 }     
void parexp(stk2 *s1,stk1 *s)
  {
 
     char *op1,*op2,opr,t[2],pre[20];
     opr=pop1(s);
     t[0]=opr;
      t[1]='\0';
     op2=pop2(s1);
      op1=pop2(s1);
      
     strcpy(pre,t);
     strcat(pre,op1);
     strcat(pre,op2);
   push2(pre,s1);
}




