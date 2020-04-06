/*queue using linked list*/
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
  NODE x;
   x=(NODE)malloc(sizeof(struct node));
  if(x==NULL)
   {
      printf("\nOut of memory");
      exit(0);
    }
  else
     printf("\nenter info: ");scanf("%d",&x->info);
 return x;
}
NODE delet_rare(NODE F)
{
        NODE ln,pln;
   if(F==NULL)
  {
        printf("\nList empty");
        return NULL;
  }
  if(F->link==NULL)
    {
       printf("%d is deleted",F->info);
         free(F);
       return NULL;
     } 
   else
     {
         ln=F;pln=NULL;
         //F=F->link;
         while(ln->link!=NULL)
        {
           pln=ln;
          ln= ln->link;
         }
         
           printf("\n%d is deleted\n",ln->info);
           free(ln);
           pln->link=NULL;
           return F;
       }

}
NODE insert_front(NODE F)
{
   NODE NN;
  NN=getnode();
   
  
  NN->link=F;
   return NN;
}
       
void display(NODE F)
{
   NODE t;
    if(F==NULL)
  {
       printf("\nlist empty");
       return;
   }
 printf("\ncontents of singly linked list is: ");
    t = F;
    while(t!=NULL)
    {
       printf("\n%d\n",t->info);
        t = t->link;
         
     }
}
void main()
{
   NODE first;first=NULL;
    int ch,item;
   for(;;)
   {
       printf("\n1:insertfront\n2:deletion\n3:display\n4:exit");
       printf("\nEnter choice: ");scanf("%d",&ch);
       switch(ch)
       {
         case 1: first=insert_front(first);
                 break;
           case 2: first=delet_rare(first);break;
           case 3: display(first);break;
       default: exit(0);
     }
   }
}

 
