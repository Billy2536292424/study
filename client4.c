#if 0
#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
int main(int argc, char* argv[])
{
    int sock = socket(AF_INET, SOCK_DGRAM,0);
    if(sock<0)
    {
        perror("socket");
        return 2;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);
    char buf[1024];
    struct sockaddr_in peer;
    while(1)
    {
        socklen_t len = sizeof(peer);
        printf("Please Enter#:");
        fflush(stdout);
        ssize_t s = read(0, buf, sizeof(buf)-1);
        if(s>0)
        {
            buf[s-1] = 0;
            sendto(sock, buf, strlen(buf),0,(struct sockaddr*)&server, sizeof(server));
            ssize_t _s = recvfrom(sock, buf, sizeof(buf)-1,0,(struct sockaddr*)&peer,&len);
            if(_s>0)
            {
                buf[_s]=0;
                printf("server echo# %s\n", buf);

            }
        }
    }

}
#endif
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<errno.h>
#include<string.h>
#define SERVER_PORT 9999
//#define SERVER_IP "192.168.0.111"
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage :client: IP\n");
        return 1;

    }
    char* str = argv[1];
    char buf[1024];
    memset(buf, '\0',sizeof(buf));
    struct sockaddr_in server_sock;
    int sock = socket(AF_INET,SOCK_STREAM,0);
    bzero(&server_sock,sizeof(server_sock));
    server_sock.sin_family = AF_INET;
    inet_pton(AF_INET,argv[1],&server_sock.sin_addr);
    server_sock.sin_port = htons(SERVER_PORT);
  
  int ret = connect(sock,(struct sockaddr*)&server_sock,sizeof(server_sock));
    if(ret<0)
    {
        printf("connect failed...,errno is:%d,errstring is :%s\n",errno,strerror(errno));
        return 1;
    }
    printf("connect success...\n");
    while(1)
    {
        printf("client:#");
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1]= '\0';
        write(sock,buf,sizeof(buf));
        if(strncasecmp(buf,"quit",4)==0)
        {
            printf("quit!\n");
            break;
        }
        printf("please wait...\n");
        read(sock,buf,sizeof(buf));
        printf("server:$%s\n",buf);

    }
    close(sock);
    return 0;
}
