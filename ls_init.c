#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>

int main()
{
	char *command = "ls ./data_raw > ls.txt";
	system(command);
	return 0;
}