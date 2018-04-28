#include<assert.h>
int myatoi(const char* strNum)
{
    assert(strNUm);
    int iNumber = 0;
    int i = 0;
    do{
        iNumber = iNUmber*10+strNUm[i]-'0';
        i++;
    }while(strNUm[i]!=0);
    return iNumber;
        
}
