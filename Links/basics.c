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

node insert_front (node f)
{
    node nn;
    nn=getnode();
    nn->link=f;
    return nn;
}

node insert_rear (node f)
{
    node nn, ln;
    nn=getnode();
    nn->link=NULL;
    if(f==NULL)
        return nn;
    ln = f;
    while(ln->link!=NULL)
        ln=ln->link;
    ln->link=nn;
    return f;
}

node insert_pos (node f)
{
    node pn,cn,nn;
    int count, pos;
    nn=getnode();
    printf("Enter the position: \n");
    scanf("%d", &pos);
    if (f == NULL && pos==1){
        nn->link=NULL;
        return nn;
    }
    if (f==NULL)
        printf("Invalid position");
    if (pos==1)
    {
        nn->link=f;
        return nn;
    }
    else
    {
        pn = f;
        cn=f->link;
        count = 2;
        while(count < pos && cn!=NULL)
        {
            pn = cn;
            cn=cn->link;
            count++;
        }
        if (count == pos)
        {
            pn->link=nn;
            nn->link=cn;
        }
        else
            printf("Not valid insertion\n");
            return f;   
    }
}

node insertorder(node f)
{
    node nn,pn;
    nn=getnode();
       if(f==NULL)
      {
    nn->link=NULL;
    return nn;
      }
     if((nn->info)<(f->info))
      {
         nn->link=f;
         return nn;
       }
     else
     {
         pn=f;
        while(pn->link!=NULL && (pn->link->info)<(nn->info))
        {pn=pn->link;}
        nn->link=pn->link;
        pn->link=nn;
        return f;
      }

}

node display (node f)
{
    node t;
    if (f==NULL)
        printf("list empty\n");
    else{
        t = f;
        while (t!=NULL){
            printf("%d\t", t->info);
            t=t->link;
        }
    }
}


node reverse(node f)
{
    node t, ln;
    ln = NULL;   
    while (f!=NULL)
    {
        t=f;
        f=f->link;
        t->link=ln;
        ln=t;
    }
}

/*node concatenate(node l1,node l2)
{
    node ln;
    int i;
    for(i=0;i<3;i++)
      {
          l1 =insert_front(l1);
       }display(l1);}
        for(i=0;i<3;i++)
      {
            l2 = insert_front(l2);display(l2);
      }
                    
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
   
 
     
     ln=l1;
    while(ln->link!=NULL)
        {    ln=ln->link;  }

    ln->link=l2;
    return l1;
}*/

void main()
{
    int ch;
    node first=NULL;node l1=NULL;node l2=NULL;
    for(;;){
    printf("1:Insert front\n2:Insert rear\n3:Insert by position\n4:Insert in order\n5:Delete by position\n6:Reverse\n7:concatenate\n");
   
   
        printf("\nEnter choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:first=insert_front(first);display(first); break;
            case 2:first=insert_rear(first); display(first); break;
            case 3:first=insert_pos(first); display(first); break;
            case 4:first=insertorder(first);display(first);break;
            case 5:first=reverse(first); display(first); break;
            //case 6:first=concatenate(l1,l2); display(first); break;
            default:exit(0);
        }
    }
}
	


