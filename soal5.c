#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/wait.h>

int main() {
  pid_t pid, sid, forkan;

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

  int iterasi = 30;
  char univ[256];
  char univ2[256];
  while(1) {
    	// main program here
	time_t ddd = time(NULL);
	char folderawal[256]="/home/thalutn5/modul2/soal5/log/";
  	char time[30];
  	struct tm waktu = *localtime(&ddd);
  	if(iterasi % 30 == 0)
	{
		sprintf(time, "%02d:%02d:%04d-%02d:%02d",waktu.tm_mday,waktu.tm_mon+1,waktu.tm_year+1900,waktu.tm_hour,waktu.tm_min);
		strcat(folderawal, time);
		mkdir(folderawal, 0777);
		strcpy(univ, folderawal);
	}
	char log[30];
	strcpy(univ2, univ);
	sprintf(log, "/log%d.log",(iterasi%30)+1);
	strcat(univ2, log);
	forkan = fork();
	if(forkan == 0 )
	{
		char *cp[4] = {"cp", "/var/log/syslog", univ2, NULL};
		execv("/bin/cp", cp);
	}
    iterasi++;
    sleep(60);
  }
  exit(EXIT_SUCCESS);
}
