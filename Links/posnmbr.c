#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
  int info;
   struct node *link;
};
typedef struct node *n;

n getnode()
{
  n X;
  X=(n)malloc(sizeof(struct node));
  if(X==NULL)
   {
    printf("memfull\n");
     exit(0);
   }
  else return X;
}
n insertfront(int s,n N)
{
    n NN;
    N=getnode();
    N->info=s;
   return N;
}
n read(n N)
{
   char c;printf(".......");
  while((c = getchar() )!='\n')
 {
    if(isdigit(c))
     N=insertfront((c-'0'),N);
  }
   return N;
}
void display(n N)
{
   int a[N->info],i=0,j=0;
    n t=N->link;
     while(t!=NULL)
  {
    a[i++]=t->info;
          t=t->link;
  }
 for(j=i-1;j>=0;j--)
  {
     printf("%d",a[j]);
  }
}
void main()
{
    n N=NULL;
    int ch;
    for(;;)
  {
     printf("\n1:read\n2:display\n3:exit");
    printf("\nenter ch: ");printf(".......");scanf("%d",&ch);
     printf(".......");
   switch(ch)
   {
     case 1:printf(".......");N=read(N);display(N);break;
     case 2:display(N);break;
      default:exit(0);
   }
  }
}
