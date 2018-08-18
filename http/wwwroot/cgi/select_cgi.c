#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mysql.h>
#include<unistd.h>
void select_data()
{
	MYSQL* fd = mysql_init(NULL);
	if(mysql_real_connect(fd,"127.0.0.1","root","123456","db_http",3306,NULL,0)==NULL)
	{
		printf("connect fail\n");

	}
	printf("connect success");
	char sql[1024];
	sprintf(sql,"select * from stu");
	mysql_query(fd,sql);

	MYSQL_RES* res = mysql_store_result(fd);
	int row = mysql_num_rows(res);
	int col = mysql_num_fields(res);
	MYSQL_FIELD* field = mysql_fetch_fields(res);
	printf("<html>\n");
	printf("<table border=\"1\">\n");
	int i = 0;
	printf("<tr>\n");
	for(;i<col;i++)
	{
		printf("<td>%s</td>",field[i].name);

	}
	printf("</tr>\n");
	for(i=0;i<row;i++)
	{
		MYSQL_ROW rowdata = mysql_fetch_row(res);
		int j = 0;
		printf("<tr>");
		for(;j<col;j++)
		{
			printf("<td>%s</td>",rowdata[j]);
		}
		printf("</tr>\n");
	}
	printf("</table>");
	printf("</html>");
	mysql_close(fd);
}
int main()
{
	select_data();
	return 0;
}
