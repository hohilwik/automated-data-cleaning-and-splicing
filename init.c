#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>

int main()
{
	system("mkdir data_raw");
	system("mkdir data_cleaned");
	system("mkdir data_spliced");
	system("mkdir graph_ind");
	system("mkdir graphs");
	
	return 0;
}