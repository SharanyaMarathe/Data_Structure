#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
    int co,px,py,pz;
    struct Node *link;
};
typedef struct Node *node;

node getnode()
{
    node x;
    x=(node)malloc(sizeof(struct Node));
    if (x == NULL)
        printf("memory insufficient\n");
    else
       return x;
}
node insert(int cf,int px,int py,int pz,node p)
{
    
    node ln,t;
   
    t=getnode();
     t->co=cf;t->px=px;t->py=py;
    t->pz=pz;
    ln = p;
    while(ln->link!=NULL)
       
        {
         ln=ln->link;}
    ln->link=t;
   
    
    return p;
}

node read(node p)
{
   int px,py,pz, cf=0;
   
   for(;;)
   {
       printf("\nEnter the co.eff(zero for terminate): ");
      scanf("%d",&cf);
      if(cf==0)
         {
          
           break;
          }
     printf("\nEnter powers of x,y and z: ");scanf("%d %d %d",&px,&py,&pz);
    
   p= insert(cf,px,py,pz,p);
  }
   return p; 
}
node display(node p)
{ if(p->link==NULL)
   {printf("\nEmpty");
     exit(0);
   }
  node t;
   t=p->link;
  while(t!=NULL)
  {   
        printf("%dx^%dy^%dz^%d",t->co,t->px,t->py,t->pz);
     t=t->link;
    printf("\t");
   if(t!=NULL && (t->co)>0)
      printf("+");printf("\t");  }

}
/*node add(node p1,node p2,node p3)
{
    node n1,n2;int x1,x2,y1,y2,z1,z2,cf1,cf2,cf;
    n1=p1;
   while(n1!=NULL)
   {
         x1=pn1->px;y1=n1->py;z1=n1->pz;
         cf1=n1->co;
       n2=p2;
      while(n2!=NULL)
      {
          x2=n2->px;y2=n2->py;z2=n2->pz;
         cf2=n2->co;
        if(x1==x2 || y1==y2 ||z1==z2)
         n2=n2->link;
      }
      if(n2!=NULL)
      {
          cf=cf1+cf2;
}*/

int eval(node p)
{
    int x,y,z,sum=0;int g,h,k;
    printf("\nEnter the values for X,Y and Z: ");scanf("%d %d %d",&x,&y,&z);
    node t;
    t=p;
    while(t!=NULL)
  
    {
       g=pow(x,p->px);h=pow(y,p->py);k= pow(z,p->pz);
      sum=sum+(t->co * g*h*k);
       t=t->link;
     }
    return sum;
}
          
void main()
{
   node p1;float res;
   p1=getnode();
    p1->link==NULL;
    printf("\nEnter 1st polynomial: ");
    p1=read(p1);
    display(p1);
    printf("\nEvalaute: %d",eval(p1));
}

