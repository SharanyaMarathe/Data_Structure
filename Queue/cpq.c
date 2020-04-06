#include<stdio.h>
#include<stdlib.h>
#define size 4
typedef struct
{
   int items[size];
   int f,r;
}Q1,Q2;
void insert_rare(Q1 *);
void display(Q2);
void display1(Q1);
void copy(Q1 *,Q2 *);
void main()
{
  int ch;
  Q1 q1; Q2 q2;
   q1.f=0;q1.r=-1;q2.f=0;q2.r=-1;
  int j;
   insert_rare(&q1);
   printf("copy");for(j=0;j<size;j++)
 {
   copy(&q1,&q2);
  }
  display1(q1);
  printf("\n");
  display(q2);


}
void insert_rare(Q1 *q1)
{
    int i,item;
   if(q1->r==size-1)
    {    
      printf("\nQueue full");
       return;
    } 
  else 
  {
        for(i=0;i<size;i++)
    {
    printf("\nEnter the item to be added: ");scanf("%d",&item);
    q1->items[++(q1->r)]=item;
    }
  }
}
void copy(Q1 *q1,Q2 *q2)
{
    int x;
   x=q1->items[(q1->f)++];
   q2->items[++(q2->r)]=x;  
}
 void display(Q2 q2)
{
   int i;
   for(i=0;i<=q2.r;i++)
   printf("%d\t\t",q2.items[i]);printf("\n");
}
void display1(Q1 q1)
{
    if((q1.f)>(q1.r))
      {printf("\nempty");}
   else
     {
           int i;
          for(i=0;i<=q1.r;i++)
            printf("%d\t\t",q1.items[i]);printf("\n");
    }
}

