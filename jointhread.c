/* jointhread.c */
/* pthread join example */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *join_thread (void *arg)
{
	return arg;
}

int main(int agrc, char *argv[])
{
	pthread_t tid;
	int argc, status;
	void *result;

	if (argc < 2) {
		fprintf (stderr, "Usage: jointhread <number>\n");
		exit(1);
	}
	argc = atoi (argv[1]);

	status = pthread_create (&tid, NULL, join_thread, &tid);
	if (status != 0) {
		fprintf (stderr, "Create thread: %d", status);
		exit(1);
	}
	status = pthread_join (tid, &result);
	if(status != 0) {

		fprintf (stderr, "Join thread: %d", status);
		exit (1);
	}
	return (long int)result;
}
