#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mysql.h>
void insert_data(char *name,char* sex,int  age)
{
	MYSQL* fd = mysql_init(NULL);
	if(mysql_real_connect(fd,"127.0.0.1","root","123456","db_http",3306,NULL,0)==NULL)
	{
		printf("connect failed\n");
		return ;
	}
	printf("<http>\n");
	printf("<h3>connect successful</h3>\n");
	printf("name:%s\n",name);
	printf("sex:%s\n",sex);
	printf("age:%d\n",age);
	char sql[1024];
	sprintf(sql,"insert into stu(name,sex,age) values('%s','%s','%d')",name,sex,age);
	printf("insert query:%s\n",sql);
	printf("</http>\n");
	mysql_query(fd,sql);
	mysql_close(fd);

}
int main()
{
	char method[24];
	char buff[1024];
	if(getenv("METHOD")!=NULL)
	{
	
		strcpy(method,getenv("METHOD"));
		if(strcasecmp(method,"GET")==0)
		{
			strcpy(buff,getenv("QUERY_STRING"));

		}
		else if(strcasecmp(method,"POST")==0)
		{
			int content_length = atoi(getenv("CONTENT_LENGTH"));
			int i =0;
			char c;
			for(;i<content_length;i++)
			{
				read(0,&c,1);
				buff[i] = c;

			}
			buff[i] = '\0';
		}
		char name[10];
		char sex[5];
		char age[3];

		strtok(buff,"=&");
		strcpy(name,strtok(NULL,"=&"));
		strtok(NULL,"=&");
		strcpy(sex,strtok(NULL,"=&"));
		strtok(NULL,"=&");
		strcpy(age,strtok(NULL,"=&"));
		insert_data(name,sex,atoi(age));
			
		}
	return 0;
}
