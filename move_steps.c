#include <stdio.h>  
char move_steps(char *msg ,int steps)  
{  
	int i=0;  
	int len=strlen(msg);  
	steps=steps%len;  //保证移动的位数在字符串长度范围内  
	while(steps)  
	{  
		char tmp=msg[0];  
		for(i=0;i<len-1;i++)  
		{  
			msg[i]=msg[i+1];  //每个元素向前挪动位  
		}  
		msg[i]=tmp;  //这时，i已经加到最后一个空出来的位置，则将开始保存的那个元素再赋值给这个空出来的位置  
		steps--;  
	}  
	//return msg;  
}  
int main()  
{  
	char msg[]="abcde123";  
	move_steps(msg ,10);  
	printf("%s",msg);  
	return 0;  
}  
