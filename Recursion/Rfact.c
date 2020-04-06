/*factorial of N */
#include<stdio.h>
#include<stdlib.h>
 int fact(int N)
{
    if(N==0)
    return 1;
    else 
   return N*fact(N-1);
}
void main()
{
   int n,f;
   printf("\nEnter the number : ");
   scanf("%d",&n);
   f=n*fact(n-1);
   printf("\nFactorial of %d is %d",n,f);
 }
