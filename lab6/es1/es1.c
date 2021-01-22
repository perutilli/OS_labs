#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	int pipe_fd[2], pid;
	char end[] = "END\n";
	char line[100];

	pipe(pipe_fd);
	
	pid = fork();
	if(pid == 0) {
		FILE* fp = fopen("file.txt", "r");
		while(fgets(line, 100, fp) != NULL) {
			//printf("%s", line);
			write(pipe_fd[1], line, strlen(line));
		}	
		write(pipe_fd[1], end, 4);
		fclose(fp);
	}
	else {
		while (1) {
			if (read(pipe_fd[0], line, 100) > 0) {
				if (strncmp(line, "END", 3) == 0) {
					exit(0);
				}
				printf("%s", line);
			}
		}
	}

	return 0;
}
