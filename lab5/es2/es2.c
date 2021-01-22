#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char* argv[]) {
	pid_t pid = atoi(argv[1]);

	if (strcmp(argv[2], "somma") == 0) {
		kill(pid, SIGUSR2);
	}
	else if (strcmp(argv[2], "differenza") == 0) {
	       kill(pid, SIGUSR1);
	}
	else if	 (strcmp(argv[2], "fine") == 0) {
	       kill(pid, SIGINT);
	}

	return 0;
}

