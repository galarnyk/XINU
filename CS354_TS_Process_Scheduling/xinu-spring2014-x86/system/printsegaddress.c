#include <xinu.h>

void printsegaddress()
{
	kprintf("\r\nprintsegaddress() \r\n");
	kprintf("Address end of: \r\n");
	kprintf("\ttext: %x \r\n", (int)&etext-1);
	kprintf("\tdata: %x \r\n", (int)&edata-1);
	kprintf("\tbss: %x \r\n", (int)&end-1);
	 
	kprintf("Address 4 bytes before: \r\n");
	kprintf("\ttext: %x \r\n", (int)&etext-5);
	kprintf("\tdata: %x \r\n", (int)&edata-5);
	kprintf("\tbss: %x \r\n", (int)&end-5);
	 
	kprintf("Address 4 bytes after: \r\n");
	kprintf("\ttext: %x \r\n", (int)&etext+3);
	kprintf("\tdata: %x \r\n", (int)&edata+3);
	kprintf("\tbss: %x \r\n\r\n", (int)&end+3);
}
