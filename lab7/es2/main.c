#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char string[21];

void* thread_fun(void* args) {
	while (1) {
		if (strcmp(string, "house") == 0 || strcmp(string, "casa") == 0) {
			printf("Casa rilevata\n");
		}
		else if (strcmp(string, "exit") == 0) {
			exit(0);
		}
		sleep(1);
	}
}

int main() {
	pthread_t thread_id;

	pthread_create(&thread_id, NULL, &thread_fun, NULL);
	while (1) {
		printf("Inserire parola: ");
		scanf("%s", string);
	}
	return 0;
}



