#include <stdio.h>
#include <pthread.h>

void *thread_fun(void *arg);
pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
int main()
{
	// create a new thread
	pthread_t mythread[3];
	int i;
	for(i = 0;i<3;i++)
	{
		pthread_create(&mythread[i],NULL,thread_fun,(void *)i);
	}
	while(i);
	return 0;
}

void *thread_fun(void *arg)
{
	pthread_mutex_lock(&mymutex);
	int i = 0;
	for(i = 0;i<5;i++)
	{
		printf("thraed num:%d\n",(int)arg);
	}
	pthread_mutex_unlock(&mymutex);
}
