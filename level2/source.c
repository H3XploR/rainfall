#include <stdio.h>

void p(void){
	unsigned int nombre_magique = 0x9090c3c9;
	fflush(stdout);

	char buffer[100];
	gets(); //stdin
	if ((nombre_magique & 0xb0000000) != 0xb0000000){

	}
	printf("%p\n"); //affiche (0x804854a)
	exit(1);
}

int main(void){
	p();
	return 0;
}
