#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char** argv) {

	char buf[BUFSIZE];
	int valid_chars;
	int file_in = open(argv[1], O_RDONLY);
	int file_out = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	while((valid_chars = read(file_in, buf, BUFSIZE)) > 0) {
		write(file_out, buf, valid_chars);
	}

	close(file_in);
	close(file_out);
}	
