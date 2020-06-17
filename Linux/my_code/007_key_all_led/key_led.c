/* 作业，按下S5，全部led亮 */
/* S5->EINT19->GPG11 */
#include "s3c2440_soc.h"
void delay(volatile int d)
{
	while (d--);
}

int main(void)
{
	int val;
	/* 设置GPFCON让GPF4/5/6配置为输出引脚 */
	GPFCON &= ~((3<<8) | (3<<10) | (3<<12));
	GPFCON |= ((1<<8) | (1<<10) | (1<<12));

	/* 配置S5按键引脚为输入引脚 
	 * GPF11(Ss)
	 */
	GPGCON &= ~((3<<22)); /* GPFG3 */
	
	/* 循环点亮 */
	while (1) {
		val = GPGDAT;
		if (val & (1<<11)) { /* s5-->gp */
			/* 松开，高电平 */
			GPFDAT |= (7<<4)
		} else {
			/* 按下，bit4 5 6输出低电平点亮led */
			GPFDAT &= ~(7<<4)
		}
	}
	return 0;
}











