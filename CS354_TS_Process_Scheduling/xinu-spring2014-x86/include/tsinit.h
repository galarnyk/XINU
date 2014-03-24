/* tsinit.h - which is read to initialize a kernel data structure */

#ifndef _TSINIT
#define _TSINIT

#define KalenaTS 3


typdef struct ts_ent {
  int ts_tqexp;         // new priority: CPU-intensive (time quantum expired)
  int ts_slpret;        // new priority: I/O-intensive (sleep return)
  int ts_quantum;       // new time slice
}TSTAB;

extern struct ts_ent tstab[];

#endif 
