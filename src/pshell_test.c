#include <string.h>

#include "pshell.h"

char *GetString(void);


#define MAX_SIZE 128
#define BUF_SIZE 32

int main(int argc, char* argv[], char** envp)
{
	/*pid_t child_pid;
	pid_t pid;*/
	int rv; /* return value */

	rv = Pbash();
	
	exit(rv);
}

int Pbash(void)
{
	char *s = 0;
	char *q = "exit";

	do
	{
		printf(">>");
		fflush(stdin);

		s = GetString();
		system(s);
		/*fgets(s, sizeof(s), stdin);
		fflush(stdin);
		printf("%s", s);

		fflush(stdin);*/

	}while(strncmp(s, q, strlen(q)));

	free(s);

	return(0);
}

char *GetString(void)
{
	unsigned int max_size = MAX_SIZE;
	char *buf = 0;
	char *minimal = 0;
	int c = 0; 					/* input from user */
	int counter = 0;
	int buf_size = BUF_SIZE;

	buf = (char*)realloc(buf, buf_size * sizeof(char));
	if(!buf)
	{
		return(NULL);
	}

	while((c =fgetc(stdin)) != '\n' && c != EOF)
	{
		if(counter < buf_size)
		{
			buf[counter++] = c;
		}
		else if(counter >= buf_size)
		{
			if(buf_size < max_size)
			{
				buf_size *= 2;
				buf = (char*)realloc(buf, buf_size * sizeof(char));
			}
			else
			{
				free(buf);

				return(NULL);
			}

			buf[counter++] = c;
		}
	}

	if(!counter && c == EOF)
	{
		free(buf);

		return(NULL);
	}

	minimal = (char*)malloc(sizeof(char) * (counter + 1));
	strncpy(minimal, buf, counter);
	free(buf);
	minimal[counter] = '\0';

	return(minimal);
}
