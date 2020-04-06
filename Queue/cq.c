#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 4
typedef struct
{
   int items[size];
   int f,r,c;
}Queue;
void insert_rare(Queue *);
void delet_front(Queue *);
void display(Queue );
void main()
{
  int ch;
  Queue Q;
   Q.f=0;Q.r=-1;Q.c=0;
   for(;;)
  {
   printf("\n1:insertion through rare\n2:deletion through front\n3:display\n4:exit"); 
    printf("\nEnter the choice: ");scanf("%d",&ch);
   switch(ch)
    {
       case 1:insert_rare(&Q);break;
       case 2:delet_front(&Q);break;
       case 3:display(Q);break;
        default:exit(0); 
    }
  }
}
void insert_rare(Queue *Q)
{
    int item;
   if(Q->c==size)
    {    
      printf("\nQueue full");
       return;
    } 
  else 
    printf("\nEnter the item to be added: ");scanf("%d",&item);
     Q->r=((Q->r)+1) % size;
    Q->items[(Q->r)]=item;
    ++(Q->c);
}
void delet_front(Queue *Q)
{
   if((Q->c)==0)
       {
         printf("\nQueue empty");
          return;
        } 
   else
  { printf("%d deleted",Q->items[(Q->f)]);
    
    (Q->f)=((Q->f)+1) % size;
   (Q->c)--;
  }
}
 void display(Queue Q)
{
    int i;
 if((Q.c)==0)
       {
        printf("\nQueue empty");
        return;
        } 
  else
     for(i=1;i<=Q.c;i++)
    {  printf("%d\n",Q.items[Q.f]);
    (Q.f)=((Q.f)+1)%size;
  }
}
