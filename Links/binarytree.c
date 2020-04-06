#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c,m,n;

struct Node
{
    int info;
    struct Node *llink;
    struct Node *rlink;
};

typedef struct Node *node;

node getnode()
{
    node new;
    new = (node)malloc (sizeof(struct Node));
    printf("\nEnter info: ");
    scanf("%d",&new->info);
    return new;
}

node Insert (node root)
{
    node new, cn, pn;
    int i;
    char dir[10];
    new = getnode();
    if (root == NULL)
        return new;
    printf("\nEnter direction: ");
    scanf("%s", dir);
    pn=NULL;
    cn=root;
    for(i=0;i<strlen(dir);i++)
    {
        if(cn==NULL)break;
        pn=cn;
        if(dir[i]=='L')
                     cn=cn->llink;
        else
            cn=cn->rlink;
    }
    if ((cn!=NULL)||i!=strlen(dir))
    {
        printf("Insertion not possible\n");
        return root;
    }
    if (dir[i-1]=='L')
        pn->llink = new;
    else pn->rlink = new;
    return root;
}  
void display(node R)
 {
     if(R==NULL)
        return;
       printf("%d",R->info);
      display(R->l);
      display(R->r);
 } 
node delete(int item,node R)
{
   node CN,PN,SN,q;
   if(R==NULL)
   {
     printf("EMPTY TREE\n");
     return R;
   }
  printf("\nenter item to be deleted:");
  scanf("%d",&item);
  PN=NULL;
  CN=R;
  while(CN!=NULL)
  {
    if(item==CN->info)
    break;
    PN=CN;
    CN=(item<CN->info)?CN->llink:CN->rlink;
  }
  if(CN==NULL)
  {
   printf("ITEM NOT FOUND");
   return R;
  }
 if(CN->llink==NULL)
  q=CN->rlink;
 else if(CN->rlink==NULL)
  q=CN->llink;
 else
  {
    SN=CN->llink;
    while(SN->llink!=NULL)
    SN=SN->llink;
    SN->llink=CN->llink;
    q=CN->rlink;
  }
 if(SN==NULL)
   return q;
 if(CN==PN->llink)
  PN->llink=q;
 else
  PN->rlink=q;
  printf("\ndeleted %d",CN->info);
  free(CN);
 return R;
}
 int ch, key,i;
    node r, root;
    int cnt=0;
    printf("1:Insert\n2:Display\n3:delet\n4:exit\n");
    for(;;){
    printf("\nEnter choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1: r=Insert(r); break;
        case 2: display(r); break;
        
        case 3: r = delete(i, r); break;
        default: exit(0);
    }
    }
}
