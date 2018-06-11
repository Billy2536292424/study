 
 //检测当前客户机是大端还是小端存储
 #include <stdio.h>
 /*union Un
 {
 	int i;
 	char j;
 }un;*/

 int check_sev()
 {
 	
 	//int i = 1;
 	//return *((char*)&i);
	 union Un
	 {
		 int i; 
		 char j;
	 }un;
	un.i = 1;
	return un.j;
 
 }

 int main()
 {
 	int ret = check_sev();
 	if (1==ret)
 	{
 		printf("小端\n");
 	}
 	else
 		printf("大端\n");
 	
 	return 0;
 }
