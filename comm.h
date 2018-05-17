#ifndef __COMM_H__
#define __COMM_H__
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
#define PATHNAME "."
#define PROJ_ID 0X6666 
int createShm(int size);
int destroyShm(int shmid);
int getShm(int size);
#endif//__COMM_H__
#if 0
#define SERVER_TYPE 1
#define CLIENT_TYPE 2
struct msgbuf
{
	long mtype;
	char mtext[1024];
};
int createMsgQueue();
int getMsgQueue();
int destroyMsgQueue(int msgid);
int sendMsg(int msgid, int who, char* msg);
int recvMsg(int msgid, int recvType, char out[]);
#endif// __COMM_H__