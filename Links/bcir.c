#include<stdio.h>
#include<stdlib.h>

struct Node
{
        int info;
        struct Node *link;
};
typedef struct Node *node;

node getnode()
{
        node x;
        x=(node)malloc(sizeof(struct Node));
        if (x == NULL)
                printf("memory insufficient\n");
        else{
                printf("\nEnter info\n");
                scanf("%d", &x->info);
        }
        return x;
}

node FrontInsert(node last)
{
    node new;
    new=getnode();
    if(last==NULL)
    {
        new->link = new;
        return new;
    }
    new->link = last->link;
    last->link = new;
    return last;
}

node RearInsert(node last)
{
    node new;
    new = getnode();
    if(last==NULL)
    {
        new->link = new;
        return new;
    }
    new->link = last->link;
    last->link = new;
    last = new;
    return last;
}

node DeleteFront(node last)
{
    node temp;
    if(last == NULL)
    {
        printf("List Empty:)\n");
        return NULL;
    }
    if(last==last->link)
    {      
        printf("%d deleted\n", last->info);
        free(last);
        return NULL;
    }
    temp = last->link;
    last->link = temp->link;
    free(temp);
    return last;
}


node DeleteRear(node last)
{
    node pre;
    if(last == NULL)
    {
        printf("List empty:)\n");
        return NULL;
    }
    if(last->link==last)
    {
        free(last);
        return NULL;
    }
    pre = last->link;
    while(pre->link!=last)
        pre = pre->link;
    pre->link = last->link;
    free(last);
    return pre;
}
node deletkey(node last)
{
   /*if(last==NULL)
    {
        printf("List empty:)\n");
        return NULL;
    }*/
   node pn,t;int key;
   printf("\nEnter the key to be deleted: ");scanf("%d",&key);
   pn=last;
   
  //while(pn->link!=pn)
  do
  {
    /*if(last==NULL)
    {
        printf("List empty:)\n");
        return NULL;
    }*/
    if(pn->link->info==key)
    { t=pn->link;
      pn->link=t->link;
      printf("\n%d is deleted",t->info);
      free(t);return last;
    }
    else
       pn=pn->link;
  } while(pn->link!=pn);
  if(pn->link==pn)
  { printf("doesnt\n");
    return NULL;}
  
  
     /* t=pn->link;
      pn->link=t->link;
      printf("\n%d is deleted",t->info);
    free(t);return last;**/
  
}
node insertorder(node last)
{
    node nn,pn;
    nn=getnode();
       if(last==NULL)
      {
       nn->link=nn;
        return nn;
      }
     if((nn->info)<(last->link->info))
      {
         nn->link=last->link;
         last->link=nn;
         return last;
       }
     else
     {
         pn=last->link;
        while(pn!=last && (pn->info)<(nn->info))
       {  pn=pn->link;  }
       //while(pn!=last->link && (pn->info)<(nn->info));
        nn->link=pn->link;
        pn->link=nn;
        return last;
      }//while(pn->link!=last && (pn->info)<(nn->info))
}

node Display(node last)
{
    if(last == NULL)
    {
        printf("List empty:)\n");
        return NULL;
    }
    node trace;
    trace = last->link;
    do{
        printf("%d\t", trace->info);
        trace=trace->link;
    }while (trace!=last->link);
}



void main()
{
    node last=NULL;
    int ch;
    printf("\tCircular single linked list\n");
    printf("1:Insert front\n2:Insert rear\n3:Delete front\n4:Delete rear\n5:Delet by key\n6:insert order\n7:display\n");
    for(;;)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:last=FrontInsert(last);Display(last);break;
                        case 2:last=RearInsert(last);Display(last);break;
                        case 3:last=DeleteFront(last);Display(last);break;
                        case 4:last=DeleteRear(last);Display(last);break;
                        case 5:last=deletkey(last);Display(last);break;
                            case 6:last=insertorder(last);Display(last);break;
                        case 7:last=Display(last);break;
                        default:exit(0);break;
        }
    }
}
