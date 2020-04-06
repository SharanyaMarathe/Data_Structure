/*void pointer*/
#include<stdio.h>
#include<stdlib.h>
void * lorger(void *p1,void *p2);
void main()
{
     void *l;
     int id1,id2; int ch;
     float fd1,fd2;
     for(;;)
     {
        printf("\n1:lorgest of integers\n2:lorgest of real numbers");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1:  printf("\nEnter 2 integers: ");scanf("%d%d",&id1,&id2);
                    l=lorger(&id1,&id2);
                    printf("\nlorgest is %d",*((int*)l));
                     break;
           case 2:  printf("\nEnter 2 real numbers: ");scanf("%f%f",&fd1,&fd2);
                    l=lorger(&fd1,&fd2);
                    printf("\nlorgest is %f",*((float*)l));
                     break;
            default: exit(0);
         }


       }
}
 void * lorger(void * p1,void * p2)
   {
         if(p1>p2)
          return p1;
         else
           return p2;

    } 
