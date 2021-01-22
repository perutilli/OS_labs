#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void first_type() {
	srand(time(NULL));
	while(1) {
		int n = rand() % 100;
		printf("%d ", n);
		fflush(NULL);
		sleep(10);	
	}

	exit(1);
}

void second_type() {
	srand(time(NULL));
	for(int j = 0; j < 50; j++) {
		int n = rand() % 100;
		printf("%d : %d; ", n, n*n);
		fflush(NULL);
		sleep(10);	
	}
	exit(1);
}

int main() {
	
	pid_t pid;
	pid_t pids_first_type[3];
	int stato;

	for (int i = 0; i < 3; i++) {
		pid = fork();
		if (pid == 0) {
			//CHILD
			first_type();		
		}
		else {
			pids_first_type[i] = pid;
		}
	}
	
	for(int i = 0; i < 3; i++) {
		pid = fork();
		if (pid == 0) {
			second_type();
		}
	}

	while (1) {
		pid = wait(&stato);
		printf("terminated child with pid %d\n", pid);
		int is_first_type = 0;
		for (int i = 0; i < 3; i++) {
			if (pid == pids_first_type[i]) {
				is_first_type = 1;
				break;
			}
		}
		
		if (is_first_type) {
			if(fork() == 0) {
				first_type();
			}
		} 
		else {
			if(fork() == 0) {
				second_type();
			}
		}
		
	}

	return(0);

}

