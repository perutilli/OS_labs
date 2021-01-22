#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUF_SIZE 50

void sig_hand(){}
int main() {
	pid_t son1, son2;
	char buf[BUF_SIZE];
	int file_son_1 = open("son1.txt", O_RDONLY);
	int file_son_2 = open("son2.txt", O_RDONLY);
	int status;

	signal(SIGALRM, sig_hand);

	son1 = fork();
	if (son1 == 0) {
		pause();
		read(file_son_1, buf, BUF_SIZE);
		write(2, buf, BUF_SIZE);
		printf("\n");
		exit(1);
	}
	printf("First son: %d\n", son1);
	
	son2 = fork();
	if (son2 == 0) {	
		read(file_son_2, buf, BUF_SIZE);
		write(2, buf, BUF_SIZE);
		printf("\n");
		sleep(5);
		exit(1);
	}
	printf("Second son: %d\n", son2);
	
	while (wait(&status) != son2);	
	
	kill(son1, SIGALRM);

	close(file_son_1);
	close(file_son_2);
	
	return 0;
}
