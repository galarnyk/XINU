/* iointensive.c -  */

#include <xinu.h>
#include <stdarg.h>

void iointensive() 
{
	int i;
	int j;
	for (i=0; i<LOOP1; i++) {
		// single call to sleepms which changes degree to which sleepms prone to blocking and voluntarily relinquishing the CPU
		sleepms(1000);

		kprintf("iointensive() pid: %d	i: %d	prprio: %d	TS remain: %d\r\n", currpid, i, proctab[currpid].prprio, preempt);
	}
}