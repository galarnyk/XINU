/* cpuintensive.c -  */

#include <xinu.h>
#include <stdarg.h>
#include <string.h>

void cpuintensive() 
{
	int i;
	int j;
	int fun;
	for (i=0; i<LOOP1; i++) {
		for (j=0; j<LOOP2; j++) {
			// insert code that performs memory copy (slow) and/or
			// ALU operations (fast)
			// note: this loop consumes significant CPU cycles
			fun = (i + j)+1 * 100 / 100 - i;
		}
		// using kprintf print the pid followed the outer loop count i,
		// the process's priority and remaining time slice (preempt)
		kprintf("\r\ncpuintensive() pid: %d	i: %d	prprio: %d	TS remain: %d", currpid, i, proctab[currpid].prprio, preempt);
	}
}
