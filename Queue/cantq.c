#include<stdio.h>
#include<stdlib.h>
#define size 4
typedef struct
{
   int items[size];
   int f,r;
}Q2;
typedef struct
{
   int items[10];
   int f,r;
}Q1;
void insert_rare1(Q1 *);void insert_rare(Q2 *);
void display(Q2);
void display1(Q1);
void canti(Q1 *,Q2 *);
void main()
{
  int ch;
  Q1 q1; Q2 q2;
   q1.f=0;q1.r=-1;q2.f=0;q2.r=-1;
  int j;
   printf("\nEnter Queue 1 items: ");
    insert_rare1(&q1);
    printf("\nEnter Queue 2 items: ");
    insert_rare(&q2);
   printf("concatinated\n");for(j=0;j<size;j++)
 {
   canti(&q1,&q2);
  }
  display1(q1);
  printf("\n");
  display(q2);


}
void insert_rare(Q2 *q2)
{
    int i,item;
   if(q2->r==size-1)
    {    
      printf("\nQueue full");
       return;
    } 
  else 
  {
        for(i=0;i<size;i++)
    {
    printf("\nEnter the item to be added: ");scanf("%d",&item);
    q2->items[++(q2->r)]=item;
    }
  }
}
void insert_rare1(Q1 *q1)
{
    int i,item;
   if(q1->r==size-1)
    {    
      printf("\nQueue full");
       return;
    } 
  else 
  {
        for(i=0;i<4;i++)
    {
    printf("\nEnter the item to be added: ");scanf("%d",&item);
    q1->items[++(q1->r)]=item;
    }
  }
}
void canti(Q1 *q1,Q2 *q2)
{
    int x,v;
  /*for(v=q2->f;v<=q2->r;v++)*/    while(!((q2->f)>(q2->r)))
  {
   x=q2->items[(q2->f)++];
   q1->items[++(q1->r)]=x;
  }
  return;  
}
 void display(Q2 q2)
{
    if((q2.f)>(q2.r))
      {printf("\nempty");}
   else
  {
   int i;
   for(i=0;i<=q2.r;i++)
   printf("%d\t\t",q2.items[i]);printf("\n");
   }
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

