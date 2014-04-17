/* host2netl_asm.S - host2netl_asm */

/*------------------------------------------------------------------------
 * host2netl_asm -  call is ctxsw(&h2nbytel)
 *------------------------------------------------------------------------
 */

/*http://www.unixwiz.net/techtips/win32-callconv-asm.html*/

.text  
.globl host2netl_asm
	.type	host2netl_asm, @function
host2netl_asm:
	pushl	%ebp		/*Save and update the %ebp */
	movl	%esp, %ebp	/*push ebp	mov  ebp, esp    // ebp « esp*/
	movl	0x8(%ebp), %eax 	/*8(%ebp) is first function parameter */
	bswap	%eax
	popl	%ebp		/*#Restore the old base pointer */
	ret
