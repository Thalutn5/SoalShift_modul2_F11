#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <libgen.h>

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
        //printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        // main program here
        char namefile[256];
        char *namefile2;
        char namefile3[256];
        char namefile4[256];
        char namefile5[256] = "_grey.png";
        //char namefile6[10];
        //printf("gfd");
        DIR *d;
        //printf("asd");
        char folderakhir[256];
        char folderawal[256];
        // strcpy(folderakhir, "/home/thalutn5/modul2/soal1/gambar/");
        //strcpy(folderawal, "/home/thalutn5/modul2/soal1/");
        struct dirent *dir;
        d = opendir("/home/thalutn5/modul2/soal1");
        //printf("tes");
        if (d)
        {
            // printf("aaaaaaaaaaaaaaa");
            while ((dir = readdir(d)) != NULL)
            {
                    strcpy(folderakhir, "/home/thalutn5/modul2/soal1/gambar/");
                    strcpy(folderawal, "/home/thalutn5/modul2/soal1/");
                    strcpy(namefile, dir->d_name);
                    namefile2 = strrchr(namefile, '.');
                    strcpy(namefile4, namefile);
                    //printf("\n%s", namefile2);
                    if (namefile2 && (strcmp(namefile2, ".png")==0)){
                        *namefile2 = '\0';
                        strcpy(namefile3, namefile);
                        strcat(namefile3, namefile5);
                        strcat(folderakhir, namefile3);
                        strcat(folderawal, namefile4);
                        //printf("     ----- %s %s %s %s %s \n", namefile, namefile2, namefile3, namefile4, namefile5);
                        // printf("%s %s\n", folderawal, folderakhir);
                        rename(folderawal, folderakhir);
                    }
            }
            closedir(d);
        }

	sleep(30);
	}
  	exit(EXIT_SUCCESS);
}
