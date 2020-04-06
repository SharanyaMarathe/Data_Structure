#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
   struct node *l,*r;
    char data;
};
//typedef struct node *N;
  struct node *bt(int);void *max(int);void *min(int);
void io(struct node *);
char arr[]={'a','b','c','d','\0','\0','\0','\0','\0','\0'};
int lc[]={1,-1,3,-1,-1,-1,-1,-1,-1,-1};
int rc[]={2,3,-1,-1,-1,-1,-1,-1,-1,-1};
int main()
 {
   struct node *root;//*root1;
    int ch;
    system("clear");
    root=bt(0);
     printf("\n\nin order traversal: \n");
    io(root);
   for(;;){
    printf("\nEnter the choice: ");scanf("%d",&ch);
    switch(ch)
  {
 
     case 1: max(0);break;
     case 2: min(0);break;
    default: exit(0);
  }
   
  } 

    return 0;
}
struct node *bt(int index)
{
    struct node *t1=NULL;
    if(index!=-1)
    {
       t1=(struct node *)malloc(sizeof(struct node));
       t1->l=bt(lc[index]);t1->r=bt(rc[index]);

       
       t1->data=arr[index];t1->r=bt(rc[index]);
      
    }
   return t1;
}
void io(struct node *root)
{
   if(root!=NULL)
   {
       io(root->l);
       printf("%c\t",root->data);
       io(root->r);
   }
}
  /* struct node *t=NULL;
  t=(struct node *)malloc(sizeof(struct node));
       t->l=bt(lc[index]);t->r=bt(rc[index]);*/
  
void *max(int index)
{
    struct node *t=NULL;
    if(index!=-1)
    {
       t=(struct node *)malloc(sizeof(struct node));
       t->l=bt(lc[index]);t->r=bt(rc[index]);
  
      if(t->l!=NULL && t->r!=NULL)
       {t->data=arr[index];
     printf("\nThe maximal element is: %c",t->data);}
    }
     //min(0);
}
void *min(int index)
{
    struct node *t=NULL;
    if(index!=-1)
    {
       t=(struct node *)malloc(sizeof(struct node));
       t->l=bt(lc[index]); t->r=bt(rc[index]);
  
      do
       {   t->l=bt(lc[index]); 
         t->r=bt(rc[index]);
       }while(t->l==NULL && t->r==NULL);
          t->data=arr[index];
     printf("\nThe minimal element is: %c",t->data);
    }
}



