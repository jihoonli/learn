
.text
.global _start

_start:

	/* 关看门狗，防复位 */
	ldr r0, =0x53000000
	ldr r1, =0
	str r1, [r0]

	/* 设置内存:sp栈 */
	/* 分辨是nor/nand启动
	 * 写0到0地址，再读出来
	 * 如果得到0表示0地址上的内容被修改了(nor不能修改),它对应ram，这就是nand启动，否则就是nor启动
	 */
	mov r1,#0
	ldr r0, [r1] /* 独读出原来0地址的值备份 */
	str r1, [r1] /* 0->[0],如果[0]被修改为0了，就是nand启动*/
	ldr r2, [r1] /* r2=[0] */
	cmp r1, r2	 /* r1==r2?如果相等表明是nand启动 */
	ldr sp, =0x40000000+4096	/* 先假设是nor启动 */
	moveq sp, #4096 /* nand启动 */
	streq r0, [r1] /* 恢复原来的值 */
	
	bl main

halt:
	b halt







