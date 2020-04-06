#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 4
typedef struct
{
   int items[size];
   int f,r;
}Queue;int num;

Queue Q1,Q2,Q3,Q4;
void insert_rare(Queue *,int);

void display(Queue );
void main()
{
  
  
   Q1.f=0;Q1.r=-1;Q2.f=0;Q2.r=-1;Q3.f=0;Q3.r=-1;Q4.f=0;Q4.r=-1;
int i,f;
     
    for(i=0;i<=50;i++)
      
    { f=(rand())%5;
      
       num=f/10;
    scanf("%d",&num);printf("\n\n");
     if(num<10)
        { printf("\n");insert_rare(&Q1,num);display(Q1);}
      else if(num>10 && num<20)
         {insert_rare(&Q2,num);display(Q2);}
     else  if(num>20 && num<30)
         {insert_rare(&Q3,num);display(Q3);}
     else if(num>30 && num<100)
         {insert_rare(&Q4,num);display(Q4);}
     }

     
}
void insert_rare(Queue *Q1,int num)
{
    int item;
   if(Q1->r==size-1)
    {    
      printf("\nQueue full");
       return;
    } 
  else 
  
    Q1->items[++(Q1->r)]=num;printf("\n\n");
     
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
