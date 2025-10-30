#include <stdio.h>

int main()
{
   int var = 20;
   int* ip;
   
   ip = &var;
   
   printf("Adress of var:%p\n",&var);
   printf("value of ip:%p\n",ip);
   printf("Adress of ip:%p\n",&ip);
   printf("value of *ip:%d\n",*ip);

    return 0;
}
