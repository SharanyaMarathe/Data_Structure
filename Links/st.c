/*stack using linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node 
{
   int info;
   struct node *link;
   struct node *r;
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
NODE insert_front(NODE F,int N)
{
   int i;
   NODE NN,t,cn;
  NN=getnode();t=F;cn=t;
   for(i=0;i<=N-1;i++)
   {   if(t!=NULL)
         {t=t->link;}
     }
    cn=t;
  
  t=t->link;cn->link=NN;NN->link=t;
   return F;
}
/*void destroy(NODE t) 
{
        
        NODE ln,temp;
        ln=t->l;
      t->l=ln->l;ln->l->r=t;
      /* while(t!=NULL)
      {
            temp=t;t->r->l=t->l;
            t=t->r;
           
          
          if(temp->l)
             temp->l=NULL;
           if(temp->r)
             temp->r=NULL;
       }
    }*/
/*NODE delet_front(NODE F)
{
    
    if(F->r=F)
     {
        printf("\nList empty"); 
        return NULL;
      }
   else
     {
        NODE T=F;
         while(T->r!=F)
      {
          if(T->info<0)
             { destroy(T);}
          else
            T=T->r;
        }
      } 
}*/
 
    
       
 
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
   NODE first;first=NULL;//getnode();//first->l=first->r=first;
    int ch,item,n;
   for(;;)
   {
       printf("\n1:insertion\n2:deletion\n3:display\n4:exit");
       printf("\nEnter choice: ");scanf("%d",&ch);
       switch(ch)
       {
         case 1: printf("\nEnter n: ");scanf("%d",&n);first=insert_front(first,n);
                 break;
           //case 2: first=delet_front(first);break;
           case 2: display(first);break;
       default: exit(0);
     }
   }
}

 
