#include<stdio.h>
#include<mysql.h>
void test()
{
	MYSQL* fd = mysql_init(NULL);
	if(mysql_real_connect(fd,"127.0.0.1","root"\
				,"123456","db_http",3306,NULL,0)==NULL)
	{
		printf("connect failed\n");
		return;	
	}
	printf("connect successful\n");
	const char* sql = "insert into stu(name,sex,age) \
					   values(\"cheng\",\"male\",\"20\")";
	mysql_query(fd,sql);
	printf("mysql client version:%s\n",mysql_get_client_info());
	mysql_close(fd);
}
int main()
{
	test();
	return 0;
}
