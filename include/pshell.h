/*
	pshell
*/
#ifndef __PSHELL_H__
#define __PSHELL_H__

#include <stdio.h>
#include <sys/types.h> 	/* pid_t */
#include <unistd.h> 	/* fork() */
#include <stdlib.h>		/* exit() */
#include <sys/wait.h>	/* wait() */


int Pbash(void);
	
#endif /* ifndef __PSHELL_H__*/
