#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
	char nama[] = {"killall", "soal5", NULL};
	execv("/usr/bin/killall", nama);
}
