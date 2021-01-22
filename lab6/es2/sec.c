#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	char string[100];
	scanf("%s", string);
	for (int i = 0; i < strlen(string); i++) {
		string[i] += 'A' - 'a';
	}
	printf("%s", string);
	return 0;
}
