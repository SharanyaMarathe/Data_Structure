
#include<stdio.h>
#include<stdlib.h>

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



n insertbp(n LN)
{
  n NN,PN,CN;int p,c,i;
  NN=getnode();
  printf("enter info");
  scanf("%d",&NN->info);
  printf("enter pos");
  scanf("%d",&p);
   if(LN!=NULL&&p==1)
   {
     NN->link=LN->link;
     LN->link=NN;
     return LN;
    }
  if(p==1)
   {
     NN->link=NN;
     return NN;
    }

 if(LN==NULL)
   {
	printf("No node present \n");
     exit(0);
    }

PN=LN->link;
CN=PN->link;


c=2;
while(CN!=LN)
{
  PN=CN;
  CN=CN->link;
  c++;
}

if(c != 2)
{
c++;
}

else if (c == 2 && PN != CN)
{
	c++;
}

if(p>c)
{
	printf("Invalid Position \n");
	return LN;
}

else if(p<c)
{
	PN=LN->link;
	CN=PN->link;

		for(i=2; i<p ; i++)
		{
		PN=CN;
		CN=CN->link;
		}

  PN->link=NN;
  NN->link=CN;
  return LN;
}

else
{
	NN->link = LN->link;
	LN->link = NN;
	LN = NN;
	return LN;
}

}


n delbp(n LN)
{
  n PN,CN,FN;int p,i;
  int c=0;
  printf("enter pos");
  scanf("%d",&p);
  if(LN==NULL)
   {
     printf("Empty List \n");
     exit(0);
   }
  if(p==1)
  {
    FN=LN->link;
    LN->link=FN->link;
    printf("deletde %d",FN->info);
    free(FN);
    return LN;
  }

  c=2;

  PN=LN->link;
  CN=PN->link;

while(CN!=LN)
{
  PN=CN;
  CN=CN->link;
  c++;
}



if(p>c)
{
	printf("Invalid Position \n");
	return LN;
}

else if(p<c)
{
	PN=LN->link;
	CN=PN->link;

		for(i=2; i<p ; i++)
		{
		PN=CN;
		CN=CN->link;
		}

  PN->link=CN->link;
  printf ("%d is deleted \n",CN->info);
  free(CN);

  return LN;
}

else
{
	PN->link=CN->link;
	LN = PN;
	free(CN);
}
}

n delbk(n LN)
{
  int k,flag=0 ;
  n T,F,pn,L;
  printf("enter key");
  scanf("%d",&k);
  if(LN==NULL){
   printf("emp");
     exit(0);
   }
  F=LN->link;
  if(F->info==k)
  {
   T=F;
    F=F->link;
     printf("del %d",F->info);
    free(T);
   return LN;
  }

 pn=LN->link;
 L = LN;
 
    while(pn !=LN && flag == 0)
  {
	printf("Inside While \n");
   if(pn->info==k)
   {
       flag =1;
   }
   if (flag == 0)
	{
	    L = pn;	
	    pn=pn->link;
	}
  }

printf ("Outside while loop \n");
    if(pn->link==LN)
     {
       printf("not found");
     }
   if(pn->info==k)
   {
     T=pn;
     L->link=T->link;

     printf("deleted %d",T->info);
      free(T);
      return LN;
    }
   else 
{
printf("invalid");
return LN;
}

printf ("End of code \n");
   }
       

void display(n LN)
{
 n FN;
 if(LN==NULL)
{
printf("\nemp\n");
 return;
}

  FN=LN->link;

do
{
  
  printf("%d",FN->info);
  FN=FN->link;
}while(FN!=LN->link);
}


void main()
{
n last=NULL;int ch;
for(;;)
{
  printf("\n1:insert by pos\n2:dispaly\n3:delet by pos\n4:delet by key\n5:exit\n");
 printf("enter ch: ");
 scanf("%d",&ch);
 switch(ch)
{
case 1:last=insertbp(last);display(last);break;
case 2:display(last);break;
case 3:last=delbp(last);display(last);break;
 case 4:last=delbk(last);display(last);break;
default:exit(0);
  }
 }
}



