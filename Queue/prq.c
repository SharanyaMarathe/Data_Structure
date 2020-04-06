/*prq*/
#include<stdio.h>
#include<stdlib.h>
#define size 4
typedef struct
{
   int items[size];
   int f,r;
}Queue;
void insmin(Queue *);
void delet(Queue *);
void insert_rare(Queue *);
void delmin(Queue *);
void display(Queue );
void main()
{
  int ch;
  Queue Q;
   Q.f=0;Q.r=-1;
   for(;;)
  {
   printf("\n1:insertion minimum\n2:deletion \n3:insertion through rare\n4:deletion of minimum itemdisplay\n5:display\n6:exit"); 
    printf("\nEnter the choice: ");scanf("%d",&ch);
   switch(ch)
    {
       case 1:insmin(&Q);break;
       case 2:delet(&Q);break;
       case 3:insert_rare(&Q);break;
       case 4:delmin(&Q);break;
       case 5:display(Q);break;
        default:exit(0); 
    }
  }
}
void delet(Queue *Q)
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
void insmin(Queue *Q)
{
    int i,item;
   if(Q->r==size-1)
    {    
      printf("\nQueue full");
       return;
    } 
  else 
   { printf("\nEnter the item to be added: ");scanf("%d",&item);
      i=Q->r;
      while(i>=Q->f && Q->items[i]>item)
       {
         Q->items[i+1]=Q->items[i];
          i--;
        }
      Q->items[++i]=item;
        Q->r++;

   }          
}   


void insert_rare(Queue *Q)
{
    int item;
   if(Q->r==size-1)
    {    
      printf("\nQueue full");
       return;
    } 
  else 
    printf("\nEnter the item to be added: ");scanf("%d",&item);
    Q->items[++(Q->r)]=item;
}

void delmin(Queue *Q)
{
    if((Q->f)>(Q->r))
       {
         printf("\nQueue empty");
          return;
        } 
    int i,loc,min;
      min=Q->items[Q->f];
      loc=Q->f;
      i=Q->f+1;
     while(i<=Q->r)
      {
       if((Q->items[i]) < min)
        {
          min=Q->items[i];
             loc=i;
         }
            i++;
       }
       printf("\n%d is deleted",min);
   i=loc;
     while(i < (Q->r))
  {
    Q->items[i]=Q->items[i+1];
     i++;
  }
   Q->r--;
}

            
