#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *llink;
    struct Node *rlink;
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


node DeleteByKey(node h)
{
    int key;
    node k;
    if (h->info==0)
    {
        printf("Header info : %d\nList Empty\n", h->info);
        return h;
    }
    printf("Enter key ");
    scanf("%d", &key);
    k = h->rlink;
    while (k!=h)
    {
        if(k->info == key)
          {  k->llink->rlink = k->rlink;
              k->rlink->llink = k->llink;
             printf("\n%d deleted\n", k->info);
            free(k);
           h->info--;return h;
          }
      else
          {  k = k->rlink;}
    }

    if(k->info!=key)
        printf("Invalid\n");
        return NULL;
}
    //else
   // {
       /* k->llink->rlink = k->rlink;
        k->rlink->llink = k->llink;
    }
    printf("\n%d deleted\n", k->info);
    free(k);
    h->info--;
    return h;*/



node Display(node h)
{
    node temp;
    if(h->info==0)
    {
        printf("List empty:)\n");
        return NULL;
    }
    temp = h->rlink;
    while(temp->rlink!=h->rlink)
    {
        printf("%d\t", temp->info);
        temp = temp->rlink;
    }
}


node InsertFront (node h)
{
    node new;
    new = getnode();
    new->rlink = h->rlink;
    new->llink = h;
    h->rlink = new;
    new->rlink->llink = new;
    h->info++;
    return h;
}


node InsertRear (node h)
{
    node new;
    new = getnode();
    new->llink = h->llink;
    new->rlink = h;
    h->llink = new;
    new->llink->rlink = new;
    h->info++;
    return h;
}

node DeleteFront (node h)
{
    node temp;
    if(h->llink == h->rlink)
    {
        printf("List empty:)\n");
        return h;
    }
    temp = h->rlink;
    h->rlink = temp->rlink;
    temp->rlink->llink = h;printf("%d is deleted",temp->info);
    free(temp);
    h->info--;
    return h;
}

node DeleteRear (node h)
{
    node temp;
    if(h->llink == h->rlink)
        {
                printf("List empty:)\n");
                return h;
        }
    temp=h->llink;
    h->llink = temp->llink;
    temp->llink->rlink = h;printf("%d is deleted",temp->info);
    free(temp);
    h->info--;
    return h;
}



void main()
{
    node head;
    int ch;
    head = getnode();
    //head->info = 0;
    head->llink = head->rlink = head;
    printf("\tDouble linked list\n");
    printf("1:Insert front\n2:Insert rear\n3:Delete front\n4:Delete rear\n5:Delete by key\n6:Display\n");
    for(;;)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: head = InsertFront(head);Display(head);break;
                        case 2: head = InsertRear(head);Display(head);break;
                        case 5: head = DeleteByKey(head);Display(head);break;
                        case 3: head = DeleteFront(head);Display(head);break;
                        case 4: head = DeleteRear(head);Display(head);break;
            default: exit(0);
        }
    }
}
