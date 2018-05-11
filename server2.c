#include"comm.h"
int main(void)
{
	int msgid = createMsgQueue();
	char buf[1024];
	while(1)
	{
		buf[0] = 0;
		recvMsg(msgid, CLIENT_TYPE, buf);
		printf("client# %s\n", buf);
		printf("please enter# ");
		fflush(stdout);
		ssize_t s = read(0, buf, sizeof(buf));
		if(s>0)
		{	
			buf[s-1] = 0;
			sendMsg(msgid, SERVER_TYPE, buf);
			printf("sending done, wait recvv..\n");
		}
	}	
	destroyMsgQueue(msgid);
	return 0;
}
