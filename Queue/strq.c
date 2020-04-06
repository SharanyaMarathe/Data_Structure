#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 4
typedef struct
{
   char items[size][10];
   int f,r;
}Queue;
void insert_rare(Queue *);
//void insert_front(Queue *);
//void delet_rare(Queue *);//
void delet_front(Queue *);
void display(Queue );
void main()
{
  int ch;
  Queue Q;
   Q.f=0;Q.r=-1;insert_rare(&Q);display(Q);
   /*for(;;)
  {
   printf("\n1:insertion through rare\n2:deletion through front\n3:display\n4:exit"); 
    printf("\nEnter the choice: ");scanf("%d",&ch);
   switch(ch)
    {
       case 1:break;
       case 2:delet_front(&Q);break;
       case 3:display(Q);break;
        default:exit(0); 
    }
  }*/
}
void insert_rare(Queue *Q)
{
    char item;
   if(Q->r==size-1)
    {    
      printf("\nQueue full");
       return;
    } 
  else 
    printf("\nEnter the string to be added: ");scanf("%s",&item);
    strcpy(&Q->items[++(Q->r)],&item);
}
void delet_front(Queue *Q)
{
   if((Q->f)>(Q->r))
       {
         printf("\nQueue empty");
          return;
        } 
   else
   printf("%d deleted",Q->items[(Q->f++)]);
    
    if((Q->f)>(Q->r))
   {Q->f=0;
   Q->r=-1;}
}
 void display(Queue Q)
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
}
