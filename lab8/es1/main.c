#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

struct thread_params {
	FILE* file_in;
	FILE* file_out;
};

// returns len of vect
int read_file(FILE* file_in, int** vect) {
	int n_lines;
	fscanf(file_in, "%d", &n_lines);
        *vect = (int*) malloc(n_lines * sizeof(int));
	for (int i = 0; i < n_lines; i++) {
		fscanf(file_in, "%d", &((*vect)[i]));
	}
	
	return n_lines;
}

void sort() {}

void write_file(FILE* file_out, int* vect, int len) {
	for (int i = 0; i < len; i++) {
		fprintf(file_out, "%d\n", vect[i]);
	}
}

void* thread_fun(void* args) {
	struct thread_params* data = (struct thread_params*) args;
	int len;
	int* numbers;

	len = read_file(data->file_in, &numbers);
	write_file(data->file_out, numbers, len);

	pthread_exit(NULL);
}

int main(int argc, char** argv) {
	int n_threads = (argc - 1) / 2;
	pthread_t* thread_ids = (pthread_t*) malloc(n_threads * sizeof(pthread_t));
	struct thread_params* thread_data = malloc(n_threads * sizeof(struct thread_params));
	for (int i = 0; i < n_threads; i++) {
		thread_data[i].file_in = fopen(argv[1 + 2*i], "r");
		thread_data[i].file_out = fopen(argv[2 + 2*i], "w");
	}
	
	for (int i = 0; i < n_threads; i++) {
		pthread_create(&thread_ids[i], NULL, &thread_fun, (void*)& thread_data[i]);
	}

	for (int i = 0; i < n_threads; i++) {
		pthread_join(thread_ids[i], NULL);
	}

	return 0;
}



