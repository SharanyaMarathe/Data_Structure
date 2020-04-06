/*stack implication*/
#include<stdio.h>
#include<stdlib.h>
void push(int*,int*);
void pop(int*,int*);
void display(int*,int*);int size;int *items;
 void main()
{ 
     
     int ch,top;
     printf("\nEnter the size of stack: ");
     scanf("%d",&size);
    items=(int*)malloc(sizeof(int)*size);
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
          case 3: display(items,&top);break;
          default:exit(0);  
      }
    }
}
  void push(int *ps,int *t)
    {
         int item;
         if(*t==size-1)
           { 
              printf("\nstack full");return;
            }
          else
           printf("\nEnter the item to be added : ");
           scanf("%d",&item);
           ++(*t);
           *(ps+(*t))=*items;
     }
  void pop(int *ps,int *t)
    {
        if(*t==-1)
        { printf("\nstack empty");return;}
        else
            printf("\ndeleted %d",*(ps+(*t)));
             (*t)--;
     }
  /* void stacktop(int ps,int t)
     {   if(t==-1)
         { printf("\nstack empty");return;}
        else
            printf("\nstack top %d",(ps+t));
      }*/
    void display(int *ps,int *t)
     { 
          int i;  
         if(*t==-1)
        { printf("\nstack empty");return;}
        else
         for(i=*t;i>=0;i--)
       
            printf("%d\n",*(ps+i));
       }
 
      
    


                   
