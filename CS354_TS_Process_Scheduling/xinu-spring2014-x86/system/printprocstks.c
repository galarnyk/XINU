/* printprocstks.c - printprocstks */

#include <xinu.h>
#include <string.h>

/*------------------------------------------------------------------------
*  printprocstks
*------------------------------------------------------------------------
*/
void printprocstks()
{
	/* Check to make sure pid is valid */
	pid32   pid;
	
	kprintf("printprocstks()\r\n\r\n");
	
	for(pid=0;pid<NPROC;pid++){
		if(!isbadpid(pid)){
			/* Fetching process specific info and displaying*/
			kprintf("Process Name: %s \r\n", proctab[pid].prname);
			kprintf("Stack \r\n");
			kprintf("\tpid: %d \r\n", pid);
			kprintf("\tBase: %x \r\n", proctab[pid].prstkbase);
			kprintf("\tLen: %x \r\n", proctab[pid].prstkbase - proctab[pid].prstkptr);
			kprintf("\tLimit: %d \r\n", proctab[pid].prstklen);
			kprintf("\tStack Pointer: %x \r\n\r\n", proctab[pid].prstkptr);
		}
	}
}
