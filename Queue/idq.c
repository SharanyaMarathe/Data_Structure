#include<stdio.h>
#include<stdlib.h>
#define size 2
typedef struct
{
   int items[size];
   int f,r;
}Q1,Q2;
  int x,y; 
void insert_rare1(Q1 *);void insert_rare(Q2 *);
//void insert_front(Queue *);
int delet_front(Q2 *);
int delet_front1(Q1 *);
//void display(Queue );
void main()
{
  int a,x,y,i,j;int c=0;Q1 q1; q1.f=0;q1.r=-1;Q2 q2;q2.f=0;q2.r=-1;
   for(a=0;a<size;a++)
  {
     insert_rare1(&q1);insert_rare(&q2);
   }
    for(i=q1.f;i<=q1.r;i++)
   {
      x=delet_front1(&q1);
    
  for(j=q2.f;j<=q2.r;j++)
  {
   y=delet_front(&q2);
   //c++; 
  }
  
  for(i=0;i<size;i++)
  {
   if(x==y)
   {printf("true");}
   else
   {printf("nnn");}
  } }
}
void insert_rare1(Q1 *q1)
{
     int item;
   if(q1->r==size-1)
    {    
      printf("\nQueue full");
       return;
    } 
  else 
    printf("\nEnter the item to be added: ");scanf("%d",&item);
    q1->items[++(q1->r)]=item;
}
void insert_rare(Q2 *q2)
{
    int item;
   if(q2->r==size-1)
    {    
      printf("\nQueue full");
       return;
    } 
  else 
    printf("\nEnter the item to be added: ");scanf("%d",&item);
    q2->items[++(q2->r)]=item;
}
int delet_front1(Q1 *q1)
{
  /* if((Q->f)>(Q->r))
       {
         printf("\nQueue empty");
          return;
        } 
   else*/
  x= q1->items[(q1->f++)];
    
    /*if((Q->f)>(Q->r))
   {Q->f=0;
   Q->r=-1;}*/
}
int delet_front(Q2 *q2)
{
  /* if((Q->f)>(Q->r))
       {
         printf("\nQueue empty");
          return;
        } 
   else*/
  y= q2->items[(q2->f++)];
    
    /*if((Q->f)>(Q->r))
   {Q->f=0;
   Q->r=-1;}*/
}
 /*void display(Queue Q)
{
    int i;
  if((Q.f)>(Q.r))
       {
        printf("\nQueue empty");
        return;
        } 
  else
     for(i=Q.f;i<=Q.r;i++)
      printf("%d\n",Q.items[i]);
}*/
