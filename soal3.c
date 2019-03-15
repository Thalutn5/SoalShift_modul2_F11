#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	pid_t child_1;
	pid_t child_2;
	pid_t child_3;
	int ada;
	int fd[2];
	int gus;
	pipe(fd);
		child_1 = fork(); //buat ngunzip
		if (child_1 == 0) {
		execlp("unzip", "unzip", "campur2.zip", NULL);

	}
		else {
		child_2 = fork(); // buat bikin file dengan nama daftar.txt
		if (child_2 == 0) {
		execlp("touch", "touch", "daftar.txt", NULL);

	}
		else{
		child_3 = fork(); //buat ngelist yang format .txt
		if (child_3 == 0) {
		dup2(fd[1], 1); //file descriptor
		execlp("ls", "ls", "campur2", NULL);

		} else {
		while(wait(&ada)>0) ;  //di wait agar tidak berbarengan
		char gus [1000]; // tempat nyimpen.txt sementara

		close(fd[1]);
		FILE* temp= fdopen(fd[0], "r"); //untuk buka directori "read"
		FILE *daftar = fopen("daftar.txt", "w"); // buka file trs ditulis
		int i= 0;
		while (fgets(gus, sizeof(gus), temp) != NULL) { //buat ngambil datanya di dalem gus
		if (strstr(&gus[strlen(gus)-5], ".txt") != NULL) //un
		fprintf(daftar, "%s", gus);
		}
	fclose(daftar);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
}
}
}
}
