/* resched.c - resched */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  resched  -  Reschedule processor to highest priority eligible process
 *------------------------------------------------------------------------
 */
void	resched(void)		/* assumes interrupts are disabled	*/
{
	struct procent *ptold;	/* ptr to table entry for old process	*/
	struct procent *ptnew;	/* ptr to table entry for new process	*/

	/* If rescheduling is deferred, record attempt and return */

	if (Defer.ndefers > 0) {
		Defer.attempt = TRUE;
		return;
	}

	/* Point to process table entry for the current (old) process */

	ptold = &proctab[currpid];

	if (ptold->prstate == PR_CURR) {  /* process remains running */
		
		//lab3 Kalena mod for process starvation Following block of code
//		kalenaList[currpid] += tstab[ptold->prprio].ts_quantum;	
		ptold->prprio = tstab[ptold->prprio].ts_tqexp;				//ADD
		
//		if (kalenaList[currpid] > 300) {					
//			if (ptold->prprio > 0 && ptold->prprio < 60) {
//				kalenaList[currpid] = 0;
//				ptold->prprio = 1;
//			}
//		}
		
		//Reset TS to right quantum
		if (ptold->prprio > firstkey(readylist)) {
			preempt = tstab[ptold->prprio].ts_quantum;	//lab3 Kalena mod
			return;
		}

		/* Old process will no longer remain current */
		ptold->prstate = PR_READY;
		insert(currpid, readylist, ptold->prprio);
	
	
	} else if(ptold->prstate == PR_SLEEP) {
//		kalenaList[currpid] += (tstab[ptold->prprio].ts_quantum - preempt);
		ptold->prprio = tstab[ptold->prprio].ts_slpret;				//ADD
		
//		if (kalenaList[currpid] > 300) {
//			if (ptold->prprio > 0 && ptold->prprio < 60) {
//				kalenaList[currpid] = 0;
//				ptold->prprio = 1;
//			}
//		}
	}

	/* Force context switch to highest priority ready process */

	currpid = dequeue(readylist);
	ptnew = &proctab[currpid];
	ptnew->prstate = PR_CURR;
	//preempt = QUANTUM;		/* reset time slice for process	*/
	preempt = tstab[ptnew->prprio].ts_quantum;	/* LAB3 ADD */
	ctxsw(&ptold->prstkptr, &ptnew->prstkptr);

	/* Old process returns here when resumed */

	return;
}
