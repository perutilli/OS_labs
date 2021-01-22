#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef enum {prime, not_prime} thread_res;

struct thread_params {
	int inf;
	int sup;
	int N;
};

void* thread_fun(void* args) {
	struct thread_params* data = (struct thread_params*) args;
	thread_res ret_status;
	for (int i = data->inf; i < data->sup; i++) {
		printf("%d\n", i);
		if ((data->N % i) == 0) {
			ret_status = not_prime;
			pthread_exit((void*) ret_status);
		}
	}
	ret_status = prime;
	pthread_exit((void*) ret_status);
}

int main(int argc, char** argv) {
	int n_threads = atoi(argv[2]);
	int N = atoi(argv[1]);
	int n_div = (N / 2 - 1) / n_threads;
	void* status;
	pthread_t* thread_ids = (pthread_t*) malloc(n_threads * sizeof(pthread_t));
	struct thread_params* thread_data = malloc(n_threads * sizeof(struct thread_params));
	
	for (int i = 0; i < n_threads; i++) {
		thread_data[i].inf = 2 + i * n_div;
		thread_data[i].sup = 2 + (i + 1) * n_div;
		if (i == n_threads - 1) {
			thread_data[i].sup = (N + 1)/2;
		}

		thread_data[i].N = N;
		
		printf("%d, %d\n", thread_data[i].inf, thread_data[i].sup);

		pthread_create(&thread_ids[i], NULL, &thread_fun, (void*)&
				thread_data[i]);
	}

	for (int i = 0; i < n_threads; i++) {
		pthread_join(thread_ids[i], &status);
		thread_res ret_status = (thread_res) status;
		printf("ret_status = %d\n", ret_status);
		if (ret_status == not_prime) {
			for (int j = i + 1; j < n_threads; j++) {
				pthread_cancel(thread_ids[j]);
			}
			printf("Il numero non è primo\n");
			exit(0);
		}
	}
	
	printf("il numero è primo\n");
	return 0;
}



