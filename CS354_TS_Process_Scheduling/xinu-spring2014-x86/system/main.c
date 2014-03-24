/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

//BEG Lab1_______________________________________________________
/*void printsegaddress();
void printprocstks();
void myprogA();*/
//END Lab1_______________________________________________________

//Lab2
//void printloop(char);

//incorrect: long host2netl_asm(long);

int main(int argc, char **argv)
{
	uint32 retval;

	/*
	kprintf("main: calling getlocalip\n");
	retval = getlocalip();

	if (retval == SYSERR) {
		kprintf("I'm here to stop!\n");
	} else {
		kprintf("I'm here to continue!\n");
		kprintf("\n\n###########################################################\n\n");
		kprintf("IP address is %d.%d.%d.%d   %08x\n\r",
			(retval>>24)&0xff, (retval>>16)&0xff, (retval>>8)&0xff,
		 	retval&0xff,retval);

	    	kprintf("Subnet mask is %d.%d.%d.%d and router is %d.%d.%d.%d\n\r",
			(NetData.addrmask>>24)&0xff, (NetData.addrmask>>16)&0xff,
			(NetData.addrmask>> 8)&0xff,  NetData.addrmask&0xff,
			(NetData.routeraddr>>24)&0xff, (NetData.routeraddr>>16)&0xff,
			(NetData.routeraddr>> 8)&0xff, NetData.routeraddr&0xff);
	}
	*/
	
	//BEG Lab1_______________________________________________________
	/*kprintf("%x\n",host2netl_asm (0x12345678));
	//long test_asm_val;
	//long testa = 3;
	//test_asm_val = host2netl_asm(testa);
	//kprintf("host2netl_asm: %s \r\n\r\n", test_asm_val);
	printsegaddress();
	printprocstks();
	myprogA();

	kprintf("\r\nSpawning Processes...\r\n");
	resume(create(myprogA,1024,20,"Process A",0));
	//resume(create(myprogA,1024,20,"Process 2",0));
	printprocstks();*/
	//END Lab1_______________________________________________________
	

	//BEG Lab2_______________________________________________________
	//1024, 20priority, nameProcess, 1 arg, char
	
	uint32 pidA, pidB,pidC;
	pidA = create(printloop,1024,10,"Process A",1,'A');
	pidB = create(printloop,1024,10,"Process B",1,'B');
	pidC = create(printloop,1024,10,"Process C",1,'C');
	/*pidA = create(printloop,1024,6,"Process A",1,'A');
	pidB = create(printloop,1024,8,"Process B",1,'B');
	pidC = create(printloop,1024,10,"Process C",1,'C');*/
	
	kprintf("P\r\n");
	resume(pidA);
	kprintf("P\r\n");
	resume(pidB);
	kprintf("P\r\n");
	resume(pidC);
	
	//sleep for 5 seconds
	//sleepms(5000);
	sleepms(5000);
	
	
	//END Lab2_______________________________________________________

	//comment out while(1);
	//while (1);
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */
	recvclr();
	while (TRUE) {
		retval = receive();
		kprintf("\n\n\rMain process recreating shell\n\n\r");
		resume(create(shell, 4096, 1, "shell", 1, CONSOLE));
	}

	return OK;
}
