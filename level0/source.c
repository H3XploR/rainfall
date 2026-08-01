#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
	char tmp[3];
	const char *bash = "/bin/sh";
	for (int i = 0; i < 3; i++){
		tmp[i] = argv[1][i];
	}
	int nb_pass = atoi(tmp);
	if (nb_pass == 423){
		char* command = strdup(bash);
		gid_t egid = getegid();
		gid_t euid = geteuid();
		setresgid(egid, egid, egid);
		setresuid(euid, euid, euid);
		execv(command, NULL);
	}
	else
		printf("No !");
	return 0;
}
