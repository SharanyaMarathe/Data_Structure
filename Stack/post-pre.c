/*post to pre*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 30
struct stack
{
   char items[size][10];
   int top;
};
typedef struct stack stk;
char pos_pre(char *,char *);
void push(char  [],stk *);
char *pop(stk *);
int isfull(stk *);
int isempty(stk *);
char *TOP(stk *);
void push(char opnd[],stk *s)
 {
     
    if(isfull(s))
       printf("\nstackfull");
    else 
     strcpy(s->items[++s->top],opnd); 
      
  }
  char *pop(stk *s) 
 {     
      char *item;  
      if(isempty(s))
        printf("\nstack empty");
      else
        item =  s->items[s->top--];
          return item;
        
  }

 int isfull(stk *s)
 {
    if(s->top==size-1)
     return 1;
     else
      return 0;
 }
 int isempty(stk *s)
  {
     if(s->top==-1)
      return 1;
      else
       return 0;
   }
char *TOP(stk *s)
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
   char prefix[20],postfix[20];
    printf("\nEnter the postfix expression: ");
    scanf("%s",postfix);
    pos_pre(postfix,prefix);
     printf("\nResult is %s",prefix);
}
char pos_pre(char pos[],char pre[])
{
      stk oprstk;int i=0;
       oprstk.top=-1;
        char symb;char temp[2]; 
       char *op1,*op2;
      while((symb=pos[i++])!='\0')
        {   
          if(isoperand(symb))
           { temp[0]=symb;
            temp[1]='\0';
             push(temp,&oprstk);
           }
       else
         {
          temp[0]=symb;
            temp[1]='\0';
             
          op2=pop(&oprstk);
          op1=pop(&oprstk);
          strcpy(pre,temp);
          strcat(pre,op1);
          strcat(pre,op2);
           push(pre,&oprstk);
       }  }
      return *TOP(&oprstk);
}
