#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {

	char c;

	FILE* input = fopen(argv[1], "r");
	FILE* output = fopen(argv[2], "w");

	while((c = fgetc(input)) != EOF) {
		fputc(c, output);
	}

	fclose(input);
	fclose(output);
}

