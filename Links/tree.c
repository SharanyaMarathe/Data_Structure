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

struct Stack
{
    node items[20];
    int top;
};

typedef struct Stack stack;

void push (node cn, stack *s )
{
    if(s->top==19)
    {
        printf("\nStack full\n");
        return;
    }
    s->items[++s->top]=cn;
}

node pop(stack *s)
{
    return s->items[s->top--];
}   



void display(node root)
{
    node cn;
    stack s;
    s.top=-1;
    if(root==NULL)
    {
        printf("\nEmpty\n");
        return;
    }
    cn=root;
    for(;;)
    {
        while(cn!=NULL)
        {
            printf("%d", cn->info);
            push(cn, &s);
            cn=cn->llink;
        }
        if(s.top!=-1)
        {
            cn=pop(&s);
            cn=cn->rlink;
        }
        else return;
    }
}
void count (node root)
{
    if(root==NULL)
        return;
    c++;
    printf("%d", c);
    count(root->llink);
    count(root->rlink);

}


int max(int a,int b)
{
   if(a==b)
      return a;
   else if(a<b)
    return b;
   else
    return a;
}
int hi(node R)
{
   if(R==NULL)
    return -1;
   else
    return (1+max(hi(R->l),hi(R->r)));
}


void leafnodes(node r)
{
    if (r==NULL)
        return;
    if (r->llink == NULL && r->rlink == NULL)
    {
        m++;
        return;
    }
    else n++;
    leafnodes(r->llink);
    leafnodes(r->rlink);
}

node copy(node r)
{
    node t;
    if (r==NULL)
        return NULL;
    t = (node)malloc (sizeof(struct Node));
    t->info = r->info;
    t->llink = copy(r->llink);
    t->rlink = copy(r->rlink);
    return t;
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

node search(node root, int key)
{
    node ns;
    if (root==NULL)
        return NULL;
    if(root->info == key)
    {
        printf("\nKey exists");
        return root;
    }
    ns=search(root->llink, key);
    if (ns==NULL)
    {
        ns=search(root->rlink, key);
        return ns;
    }
}

void main()
{
    int ch, key,i;
    node r, root;
    int cnt=0;
    printf("1:Insert\n2:Display\n3:Count\n4:Search key\n");
    for(;;){
    printf("\nEnter choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1: r=Insert(r); break;
        case 2: display(r); break;
        case 3: c=0; count(r); printf("\nTotal number of nodes = %d\n", c); break;
        case 4: printf("\nEnter key to be searched: ");
            scanf("%d", &key);
            if(search(r,key)==NULL) printf("Key not found\n");
            break;
        case 5: printf("\nCopied as: "); display(copy(r)); break;
        case 6: m=n=0; leafnodes(r); printf("\nLeaf nodes = %d and non leaf nodes = %d\n", m, n); break;
        case 7: r = delete(i, r); break;
        default: exit(0);
    }
    }
}
