#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int main(int argc, char** argv) {
	int pipe_fd[2], pid, N;
	char tok[11];
	double ret_val = 0;

	N = atoi(argv[1]);

	pipe(pipe_fd);

	for (int i = 1; i < N; i++) {
		pid = fork();
		if (pid == 0) {
			// CHILD
			double res = exp(i) / i;
			sprintf(tok, "%10.4f", res);
			write(pipe_fd[1], tok, 10);
			exit(0);			
		}

	}

	for (int i = 1; i < N; i++) {
		read(pipe_fd[0], tok, 10);
		tok[10] = '\0';	
		ret_val += atof(tok);
	}
	
	printf("%f\n", ret_val);

	return 0;
}
