#include<stdio.h>
#include<stdlib.h>

struct node
{

  int info;
  struct node *link;
};
typedef struct node *NODE;
 
 NODE getnode()
 {
  NODE X;
  X=(NODE)malloc(sizeof(struct node));
  if(X==NULL)
    {
      printf("empty");
      exit(0);
     }
   else return X;
 }


NODE insertrear(NODE FN)
{ int ch;
  NODE NN,LN;
  NN=getnode();
 
  printf("\nenter info:");
  scanf("%d",&NN->info);
  NN->link=NULL;
  if(FN==NULL)
    {
     
      return NN;
     }
   else
      LN=FN;
    while(LN->link!=NULL)
    {
      LN=LN->link;
     }
   LN->link=NN;
   return FN;
}

NODE delete(NODE FN)
{  NODE T,E,P=NULL;
   T=FN;
  while(T->link!=NULL && T->info>0)
  { P=T;
    T=T->link;}
    if(T->info<0)
    {
      E=T;
    while(E->link!=NULL)
  
    { E=E->link;
       printf("\ndeleted %d\n",E->info);
      free(E);}
    }
 P->link=NULL;
   
 
// T->link=NULL;
  return FN;
}
 void display(NODE FN)
{NODE TN;
   if(FN==NULL)
   {
     printf("\nempty\n");
     return;
    }
  TN=FN;
  while(TN!=NULL)
  { printf("\n%d\t",TN->info);
    TN=TN->link;
  }

 }
 
void main()
{
 NODE F;int ch;
 F=NULL;
 // printf("enter 100 to end");
//  while(F->info!=100)
 for(ch=0;ch<5;ch++)
{
 F=insertrear(F);}
 display(F);
 F=delete(F);
 display(F);
}
