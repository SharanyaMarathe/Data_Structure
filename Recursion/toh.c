/*tower of hanio*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void towerofhanoi(int ,char ,char ,char );
void main()
{
    int n; char s,t,d;
     printf("\nEnter the number of disk: ");
     scanf("%d",&n);
     towerofhanoi(n,'s','t','d');
}
void towerofhanoi(int n,char source,char temp,char destiny)
{
   if(n==1)
    {
       printf("\nMove disk %d from %c to %c",n,source,destiny);
       return;
     }
    towerofhanoi((n-1),source,destiny,temp);
      
          printf("\nMove disk %d from %c to %c",n,source,destiny);
       
       
          towerofhanoi((n-1),temp,source,destiny);
      
      printf("\nNumber of moves are %d",(int)(pow(2,n)-1));
}
