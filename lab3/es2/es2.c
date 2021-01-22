#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define N_CHLD 3

int main() {

	for(int i = 0; i < N_CHLD; i++) {
		if (fork() == 0) {
			printf("%d\n", getpid());
			exit(0);
		}
	}

	return(0);
}
