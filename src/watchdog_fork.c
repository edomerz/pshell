#include <stdio.h>
#include <sys/types.h> 	/* pid_t */
#include <unistd.h> 	/* fork() */
#include <stdlib.h>		/* exit() */
#include <sys/wait.h>	/* wait() */
	
int main(int argc, char* argv[], char** envp)
{
	/*pid_t child_pid;*/
	pid_t pid;
	int rv; /* return value */

	switch(pid = fork())
	{
		case -1:
		{
			perror("fork"); /* fork failed */

			exit(1);		/* parent exits */

			break;
		}
		case 0: /* child process */
		{
			printf("CHILD: this is the child process\n");
			printf("CHILD: my PID: %d\n", getpid());
			printf("CHILD: my parent PID: %d\n", getppid());

			rv = system("./pshell_test");

			/*printf("CHILD: enter my exit status ( 1 - 127)\n");
			scanf("%d", &rv);*/
			printf("CHILD: done\n");
			exit(rv);

			break;
		}
		default:
		{
			printf("PARENT: this is the parent process\n");
			printf("PARENT: my PID: %d\n", getpid());
			printf("PARENT: my child PID: %d\n", pid);
			printf("waiting...\n");
			wait(&rv);
			printf("PARENT: child exit status: %d\n", WEXITSTATUS(rv));
			printf("PARENT: also done\n");
		}
	}
	
	return(0);
}
