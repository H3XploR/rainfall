#include <stdio.h>
static void run(void){
	printf("abcdefghijklmnopqrstuvwxyz");
}

int main(void){
	char buffer[9];
	gets(buffer);
	printf("buffer: %s\n", buffer);
	return 0;
}
