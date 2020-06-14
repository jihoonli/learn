
.text
.global _start

_start:
	/* 设置内存:sp栈 */
	//ldr sp, =4096	/* nand启动 */
	ldr sp, =0x40000000+4096	/* nor启动 */

	/* 调用.c里面的main函数 */
	bl main	/* bl跳转指令，返回函数的地址到halt */

halt:
	b halt







