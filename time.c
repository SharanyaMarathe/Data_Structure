/*time*/
#include<stdio.h>
#include<stdlib.h>
struct Time
{  
      int hrs,min,sec;
};
 typedef struct Time TIME;
 void show(TIME*);
 void read(TIME*);
 void incriment(TIME*);
 void add(TIME*,TIME*);
 void main()
 {
    TIME t,u;
     int ch;
     for(;;)
    {
      printf("1:read\n2:show\n3:incriment\n4:add\n5:exit");
      printf("\nEnter the choice: ");
        scanf("%d",&ch);
      switch(ch)
     {  
         case 1:read(&t);break;
         case 2:show(&t);break;
         case 3:incriment(&t);show(&t);break;
         case 4:read(&t);read(&u);add(&t,&u);show(&t);break;
         default:exit(0);
      }
    }
  }
void read(TIME *t)
   {  
      printf("\nEnter the time in hours,minute,second");
      scanf("%d%d%d",&t->hrs,&t->min,&t->sec);
    }
void show(TIME *t)
   {
      printf("\nThe time is %d:%d:%d",t->hrs,t->min,t->sec);
   }
void incriment(TIME *t)
   {
      t->sec++;
      if(t->sec==60)
          {
            t->sec=0;
             t->min++;
           }
       if(t->min==60)
          {
              t->min=0;
               t->hrs++;
               if(t->hrs==24)
                 t->hrs=0;
           }
     }
void add(TIME *t,TIME *u)
   {
       t->hrs=t->hrs+u->hrs;
       t->min=t->min+u->min;
       t->sec=t->sec+u->sec;
        while(t->sec>60)
          {
            t->sec=t->sec-60;
             t->min++;
           }
       while(t->min>60)
          {
              t->min=t->min-60;
               t->hrs++;
         
           }
     }


