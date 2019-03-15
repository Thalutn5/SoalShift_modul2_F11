#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

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

  while(1) {
    // main program here
 	struct stat info; //mencari informasi
        struct passwd *pwd ; //karena yang direturn pwd getpwuid sebuah strurt menuju passw ngambil owner
        struct group *group;
        char folderawal[256];
        strcpy(folderawal, "/home/thalutn5/modul2/soal2/hatiku/elen.ku");
        char cari[256]="www-data";
        stat(folderawal, &info); //ngambil info dari sebuah file di folder
        pwd = getpwuid(info.st_uid); //menambil id user lalu disimpan di tempat yg ditunjuk pwd && info = tempat nyimpen info sebuah file
        group =  getgrgid(info.st_gid); //mengambil id grup dari owner lalu disimpan di tempat yang ditunjuk gruop

	int if1 = (strcmp(pwd->pw_name, cari));
	int if2 = (strcmp(group->gr_name, cari));
        if((if1==0) && (if2==0))
        { remove(folderawal); }

	sleep(3);
  }

  exit(EXIT_SUCCESS);
}
