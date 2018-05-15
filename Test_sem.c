#include"comm.h"
int main(void)
{
	int semid = createSemSet(1);
	initSem(semid, 0, 1);
	pid_t id = fork();
	if(id<0){
		perror("fork");
		return -1;

	}
	else if(id == 0){
		//child
		int _semid = getSemSet(1);
		while(1){
			P(_semid, 0);
			printf("A");
			fflush(stdout);			
			usleep(123456);
			printf("A ");
			fflush(stdout);
			usleep(321456);
			V(_semid, 0);
		}
	}else{
	//parent
	while(1){
		
			P(semid, 0);
			printf("B");
			fflush(stdout);			

			usleep(223456);
			printf("B ");
			fflush(stdout);
			usleep(121456);
			V(semid, 0);
	}
	wait(NULL);

	}	
	destroySemSet(semid);
	return 0;
}
