
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20


struct stack2
{
     char items[size][10];
      int top;
};
 typedef struct stack2 stk2;
void push2(char [] ,stk2 *);
void pop2(stk2 *);
int isfull2(stk2 *);
int isempty2(stk2 *); 
void display(char [],stk2 *);
char *TOP2(stk2 *);
 int main()
{ 
     char opnd[size];int ch,top;
   stk2 s;
     s.top=-1;
     for(;;)
   {
     printf("1:push\n2:pop\n3:stcktop\n4:display\n");
     printf("\nEnter the choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
          case 1: push2(opnd,&s);display(opnd,&s);break;
          case 2: pop2(&s);display(opnd,&s);break;
          //case 3: stacktop(opnd,s);display(opnd,&s);break;
          case 4: display(opnd,&s);break;
          default:exit(0);  
      }
    }
}
void push2(char opnd[],stk2 *s1)
 {
     
    if(isfull2(s1))
       printf("\nstackfull");
    else 
    printf("\nEnter the string: ");scanf("%s",opnd);
     strcpy(s1->items[++s1->top],opnd); 
      
  }
  void pop2(stk2 *s1) 
 {     
      char *item;  
      if(isempty2(s1))
        printf("\nstack empty");
      else
       { item =  s1->items[s1->top--];
          printf("\n%s deleted\n",item);
        }
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
void display(char s[],stk2 *s1)
     { 
          int i;  
         if(isempty2(s1))
        { printf("\nstack empty");return;}
        else
         for(i=s1->top;i>=0;i--)
       
            printf("%s\n",s1->items[i]);
       }
 
      
    
