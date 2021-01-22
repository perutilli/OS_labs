#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void* thread_1(void* args) {
	printf("elaborazione del primo thread\n");
	sleep(5);
	printf("il primo thread termina\n");
	pthread_exit(NULL);
}

void* thread_2(void* args) {
	printf("elaborazione del secondo thread\n");
	sleep(5);
	printf("il secondo thread termina\n");
	pthread_exit(NULL);
}

int main() {
	pthread_t thread_id_1, thread_id_2;

	pthread_create(&thread_id_1, NULL, &thread_1, NULL);
	printf("primo thread creato \n");
	pthread_create(&thread_id_2, NULL, &thread_2, NULL);
	printf("secondo thread creato \n");
	sleep(15);
	return 0;
}



