
#include<stdio.h>
#include<stdlib.h>
int n;
 int fact(int N)
{
    if(N==0)
    return 1;
    else 
   return N*fact(N-1);
}
int seq(int n,int i)
{
   if(i==n)
     exit(0);
    
    else
    while(i!=n)
      return n*seq(n-1,i);
}
int nm(int n,int i)
 {
     
    if(n==0)
      return 1;
    if(n==1)
      return n;
    else
    
     
    return  (seq(n,i)/fact(i));
    
}
void main()
{
   int x,i=0;
   printf("\nEnter the number : ");
   scanf("%d",&n);
    for(;;) 
    {
         x=nm(n,i);
         printf("%d\t\t",x);
          i++;

       }
}  
  
    
               

 

