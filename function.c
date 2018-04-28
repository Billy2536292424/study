#include<assert.h>
const char* my_itoa(int iNumber)
{
   static  char buf[100] = {};
   int i = 0;
   do{
    int t = iNumber%10;
    iNumber/=10;
    buf[i++] = t +'0';

   }while(iNumber);
           buf[i] = '/0';
           return buf;
}
int strlen(char *s)
{
    return assert(s),(*s==0) ? 0:strlen(s+1)+1;
}
