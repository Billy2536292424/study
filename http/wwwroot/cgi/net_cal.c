#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void cal_net(char* buf)
{
	int data1;
	int data2;

	sscanf(buf,"first_data=%d&second_data=%d",&data1,&data2);
	printf("<html>\n");
	printf("<head>");
	printf("<meta charset=\"UTF-8\">");
	printf("<title></title>");
	printf("<style>");
	printf("body{text-align:center}");
	printf("</style>");
	printf("</head>");
	printf("<body style=\"background-color:PowderBlue;\">");
	printf("<table border=\"1\"\
			align=\"center\" cellpadding=\"10\" width=\"400px\" height=\"300px\">");
	printf("<tr> <td>%d</td> <td>+</td> <td>%d<td> <td>=</td> <td>%d</td></br>\n",data1,data2,data1+data2);
	printf("<tr> <td>%d</td> <td>-</td> <td>%d<td> <td>=</td> <td>%d</td></br>\n",data1,data2,data1-data2);
	printf("<tr> <td>%d</td> <td>*</td> <td>%d<td> <td>=</td> <td>%d</td></br>\n",data1,data2,data1*data2);
	printf("<tr> <td>%d</td> <td>%</td> <td>%d<td> <td>=</td> <td>%d</td></br>\n",data1,data2,data1%data2);
	printf("<tr> <td>%d</td> <td>/</td> <td>%d<td> <td>=</td> <td>%d</td></br>\n",data1,data2,data1/data2);
	printf("</table>");
	printf("<br>");
	printf("<div>");
	printf("</div>");
	printf("</body>");

	printf("</br>");
	printf("</html>\n");
}
int main()
{
	char method[32];
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
			int content_len=atoi(getenv("CONTENT_LENGTH"));
			char ch;
			int i = 0;
			for(;i<content_len;i++)
			{
				read(0,&ch,1);
				buff[i]=ch;
			}
			buff[i]='\0';
		}
		else
		{
			return 404;
		}
		printf("%s\n %s\n",method,buff);
		cal_net(buff);
		return 200;
	}
	
	return 404;
}
