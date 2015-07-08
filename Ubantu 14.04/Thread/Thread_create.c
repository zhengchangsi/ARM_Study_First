#include <stdio.h>
#include <pthread.h>

void *thread_fun(void *arg);

int main()
{
	// create a new thread
	char message[] = "Hello ZCS";
	void *retval;
	pthread_t mythread;
	if(pthread_create(&mythread,NULL,thread_fun,(void *)message) == 0)
	{
		printf("success\n");
	}
	//thread wait
	pthread_join(mythread,&retval);
	printf("get result:%s\n",(char *)retval);
	return 0;
}

void *thread_fun(void *arg)
{
	printf("thraed get message:%s\n",(char *)arg);
	//thread exit
	pthread_exit("bye");
}
