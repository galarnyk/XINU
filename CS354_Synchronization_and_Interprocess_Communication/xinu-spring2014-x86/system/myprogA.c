#include<xinu.h>

int myfuncA(int, int);

void myprogA()
{
	kprintf("\r\nmyprogA\r\n");
	kprintf("Run-Time Stack Address: %x\r\n", &proctab[currpid].prstkptr);
	int x;
	for(x=1;x<10000;x++){
		x = x+0;
	}
	x = myfuncA(1, 2);
}

int myfuncA(int a, int b)
{
	kprintf("\r\nmyfuncA\r\n");

	kprintf("Run-Time Stack Address: %x\r\n", &proctab[currpid].prstkptr);
	int x;
	for(x=1;x<10000;x++){
		x = x+0;
	}
	return a+b;
}
