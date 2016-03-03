#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char **envp)
{
	int rv = 9;
	
	rv = system("/home/developer/o/pshell/src/./pshell_test");
	if(rv != 0);
	{
		return(1);
	}
	return(0);
}
