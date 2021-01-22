#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	for(int i = 0; i < 3; i++) {
		if (fork() != 0) {
			exit(0);
		} else {
			printf("%d\n", getpid());
		}
	}

	return(0);

}

