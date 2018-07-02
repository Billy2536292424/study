#if 0
#include<unistd.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
int main(int argc, char* argv[])
{
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock<0)
    {
        perror("socket\n");
        return 2;
    }
   struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(atoi(argv[2]));
    local.sin_addr.s_addr = inet_addr(argv[1]);
    if(bind(sock, (struct sockaddr*)&local,sizeof(local))<0)
    {

        perror("bind");
        return 3;
    }
    char buf[1024];
    struct sockaddr_in client;
    while(1)
    {
        socklen_t len = sizeof(client);
        ssize_t s = recvfrom(sock, buf, sizeof(buf)-1,0,(struct sockaddr*)&client,&len);
        if(s>0)
        {
            buf[s] = 0;
            printf("[%s:%d]:%s\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port),buf);
            sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&client, sizeof(client));

        }

    }
    
}
#endif
#if 1
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#define _PORT_ 9999
#define _BACKLOG_ 10
int main()
{
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
    {
        printf("create socket error,error is:%d,errstring is:%s\n",errno,strerror(errno));
    }
    struct sockaddr_in server_socket;
    struct sockaddr_in client_socket;
    bzero(&server_socket,sizeof(server_socket));
    server_socket.sin_family=AF_INET;
    server_socket.sin_addr.s_addr = htonl(INADDR_ANY);
    server_socket.sin_port = htons(_PORT_);
    if(bind(sock,(struct sockaddr*)&server_socket,sizeof(struct sockaddr_in))<0)
    {
        printf("bind error,error code is:%d,error string is :%s\n",errno,strerror(errno));
        close(sock);
        return 1;
    }
    if(listen(sock,_BACKLOG_)<0)
    {
        printf("listen error,error code is:%d,errstring is : %s\n",errno, strerror(errno));
        close(sock);
        return 2;
    }
    printf("bind and listen success,wait accept..\n");
    for(;;)
    {
        socklen_t len = 0;
        int client_sock = accept(sock,(struct sockaddr*)&client_sock,&len);
        if(client_sock<0)
        {
            printf("accept error,errno id: %d,errstring id:%s\n",errno,strerror(errno));
            close(sock);
            return 3;
        }
    char buf_ip[INET_ADDRSTRLEN];
    memset(buf_ip,'\0',sizeof(buf_ip));
    inet_ntop(AF_INET,&client_socket.sin_addr,buf_ip,sizeof(buf_ip));
    printf("get connet,ip is : %s port is:%d\n",buf_ip,ntohs(client_socket.sin_port));
    while(1)
    {
        char buf[1024];
        memset(buf,'\0',sizeof(buf));
        read(client_sock,buf,sizeof(buf));
        printf("client:#%s\n",buf);
        printf("server :$");
        memset(buf,'\0',sizeof(buf));
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1]='\0';
        write(client_sock,buf,strlen(buf)+1);
        printf("please wait...\n");
    }
    }
close(sock);
return 0;
}
#endif
