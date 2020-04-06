/*factorial of N */
#include<stdio.h>
#include<stdlib.h>
 int fib(int N)
{   
    if(N==0)
     return 0;
     if(N==1)
    return 1;
    else 
   return fib(N-1)+fib(N-2);
   
}
void main()
{
   int n,f,i;
   printf("\nEnter the number : ");
   scanf("%d",&n);
   f=fib(n);
   printf("\nFib of %d is %d\n\n",n,f);
  for(i=0;i<n;i++)
   printf("%d\n",fib(i));
 }
