#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <time.h>
#include <string.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  int iterasi=1;

  while(1) {
    	// main program here
    	char fileawal[256];
	strcpy(fileawal, "/home/thalutn5/Documents/makanan/makan_enak.txt");
	char filebaru[256];
	strcpy(filebaru, "/home/thalutn5/Documents/makanan/makan_sehat");
	char ganti[3];
	sprintf(ganti, "%d",iterasi);
	struct stat info;
	stat(fileawal, &info);
	strcat(filebaru, ganti);
	strcat(filebaru, ".txt");

	if(difftime(time(NULL), info.st_atime)<=30) //timenull waktu pada saat programnya berjalan, waktu filenya diakses terakhir
	{
		FILE *newfile = fopen(filebaru, "w");
		fclose(newfile);
		iterasi=iterasi+1;
	}
	sleep(5);
  }

  exit(EXIT_SUCCESS);
}
