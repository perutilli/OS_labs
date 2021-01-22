#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int a, b;

void sig_handler(int sig) {
	if (sig == SIGUSR1) {
		printf("%d\n", a - b);
	}
	else if (sig == SIGUSR2) {
		printf("%d\n", a + b);
	}
	return;
}

int main(int argc, char* argv[]) {
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);

	while(1);

	return 0;
}	
