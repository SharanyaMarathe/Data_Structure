/*stack implication*/
#include<stdio.h>
#include<stdlib.h>
#define size 5
void push(int[],int*);
void pop(int[],int*);
void stacktop(int[],int);
void display(int[],int*);
 int main()
{ 
     int items[size],ch,top;
   
     top=-1;
     for(;;)
   {
     printf("1:push\n2:pop\n3:stcktop\n4:display\n");
     printf("\nEnter the choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
          case 1: push(items,&top);display(items,&top);break;
          case 2: pop(items,&top);display(items,&top);break;
          case 3: stacktop(items,top);display(items,&top);break;
          case 4: display(items,&top);break;
          default:exit(0);  
      }
    }
}
  void push(int s[],int *t)
    {
         int item;
         if(*t==size-1)
           { 
              printf("\nstack full");return;
            }
          else
          printf("\nEnter item to be add to the stack");
           scanf("%d",&item);
           ++(*t);
           s[*t]=item;
     }
  void pop(int s[],int *t)
    {
        if(*t==-1)
        { printf("\nstack empty");return;}
        else
            printf("\ndeleted %d",s[*t]);
             (*t)--;
     }
   void stacktop(int s[],int t)
     {   if(t==-1)
         { printf("\nstack empty");return;}
        else
            printf("\nstack top %d",s[t]);
      }
    void display(int s[],int *t)
     { 
          int i;  
         if(*t==-1)
        { printf("\nstack empty");return;}
        else
         for(i=*t;i>=0;i--)
       
            printf("%d\n",s[i]);
       }
 
      
    


                   
