#include <stdio.h>
#include <string.h>
#include "interface.h"
int main()
{
	printf("running example!");

	enum { kMaxArgs = 64 };
	int argc = 0;
	char *argv[kMaxArgs];

	char commandLine[200] = "samtools faidx ../storage/shared/samtool/ex1.fa";

	char *p2 = strtok(commandLine, " ");
	
	while (p2 && argc < kMaxArgs-1)
	  {
	    argv[argc++] = p2;
	    p2 = strtok(0, " ");
	  }
	argv[argc] = 0;

    int result = init_samtools(argc,argv);

	return 0;
}

