
/*
 *	电亮LED2:gpf5
 */
.text
.global _start
_start:
/* 配置GPF4为输出引脚 
 * 把0x400写到地址0x56000050
 */
 	ldr r0,=0x56000050
 	ldr r1,=0x400
 	str r1,[r0]
 
/* 配置GPF4为输出低电平 
 * 把0写到0x56000054
 */
 	ldr r0,=0x56000054
 	ldr r1,=0
 	str r1,[r0]
LOOP:
	b LOOP










