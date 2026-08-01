#include <string.h>
#include <stdio.h>

int main(int argc, char** argv){
	const char* mdp = "mot_de_passe";
	if (strcmp(mdp, argv[1]) == 0){
		printf("correct\n");
	}
	printf("No !");
	return 0;
}
