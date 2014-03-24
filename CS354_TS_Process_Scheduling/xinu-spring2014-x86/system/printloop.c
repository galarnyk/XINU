/* printloop.c - printloop */

#include <xinu.h>
#include <string.h>

/*------------------------------------------------------------------------
*  printloop
*------------------------------------------------------------------------
*/

#define OUTERB	10
//#define INNERB	1000000
#define INNERB	10
void printloop(char val)
{
	/* Check to make sure pid is valid */
	//pid32   pid;
	
	//kprintf("printloop()\r\n\r\n");
	
	int i, j;		
	for(i=0;i<OUTERB;i++){
		kprintf("%c",val);
		for(j=0;j<INNERB;j++);
		//sleepms(1);	
	}
		
	/*
	for(pid=0;pid<NPROC;pid++){
		if(!isbadpid(pid)){
			// Fetching process specific info and displaying
			kprintf("Process Name: %s \r\n", proctab[pid].prname);
			kprintf("Stack \r\n");
			kprintf("\tpid: %d \r\n", pid);
			kprintf("\tBase: %x \r\n", proctab[pid].prstkbase);
			kprintf("\tLen: %x \r\n", proctab[pid].prstkbase - proctab[pid].prstkptr);
			kprintf("\tLimit: %d \r\n", proctab[pid].prstklen);
			kprintf("\tStack Pointer: %x \r\n\r\n", proctab[pid].prstkptr);
		}
	}
	*/
}
