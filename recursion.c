// recusrsion

#include<stdio.h>

void printNumRecursion(int num)
{
if(num==0)    return;
printf("%d\n",num);
printNumRecursion(num-1);
}

int main()
{
printNumRecursion(10);
return 0;
}