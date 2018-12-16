/*hellothread.c*/
/*pthread create example*/
#include <stdio.h>
#include <pthread.h>

void *hello_thread (void *arg)
{
	printf ("Thread: Hello, World!\n");
	return arg;
}

int main()
{
	pthread_t tid;
	int status;

	/*Thread Create*/
	status = pthread_create (&tid, NULL, hello_thread, NULL);
	if (status!=0)
		perror ("Create thread");
	pthread_exit (NULL);
}
