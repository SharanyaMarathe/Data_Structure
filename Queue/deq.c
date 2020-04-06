#include<stdio.h>
#include<stdlib.h>
#define size 4
typedef struct
{
   int items[size];
   int f,r;
}Queue;
void insert_rare(Queue *);
void insert_front(Queue *);
void delet_rare(Queue *);
void delet_front(Queue *);
void display(Queue );
void main()
{
  int ch;
  Queue Q;
   Q.f=0;Q.r=-1;
   for(;;)
  {
   printf("\n1:insertion through rare\n2:deletion through front\n3:insertion through front\n4:deletion through rare\n5:display\n6:exit"); 
    printf("\nEnter the choice: ");scanf("%d",&ch);
   switch(ch)
    {
       case 1:insert_rare(&Q);break;
       case 2:delet_front(&Q);break;
       case 3:insert_front(&Q);break;
       case 4:delet_rare(&Q);break;
       case 5:display(Q);break;
        default:exit(0); 
    }
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
void delet_rare(Queue *Q)
{
   if((Q->f)>(Q->r))
       {
         printf("\nQueue empty");
          return;
        } 
   else
   printf("%d deleted",Q->items[(Q->r--)]);
}
void insert_front(Queue *Q)
{
    int item;
     
       
    printf("\nEnter the item to be added: ");scanf("%d",&item);
   if(Q->f==0 && Q->r==-1)
     { Q->items[++(Q->r)]=item;
        return; }
   
    else 
        { if((Q->f)!=0)
      
          { Q->items[--(Q->f)]=item;
            return;}
         }   
          
          printf("\nInsertion is not possible");
                 
            
           
}

   
    
