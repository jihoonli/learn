/* ��ҵ������S5��ȫ��led�� */
/* S5->EINT19->GPG11 */
#include "s3c2440_soc.h"
void delay(volatile int d)
{
	while (d--);
}

int main(void)
{
	int val;
	/* ����GPFCON��GPF4/5/6����Ϊ������� */
	GPFCON &= ~((3<<8) | (3<<10) | (3<<12));
	GPFCON |= ((1<<8) | (1<<10) | (1<<12));

	/* ����S5��������Ϊ�������� 
	 * GPF11(Ss)
	 */
	GPGCON &= ~((3<<22)); /* GPFG3 */
	
	/* ѭ������ */
	while (1) {
		val = GPGDAT;
		if (val & (1<<11)) { /* s5-->gp */
			/* �ɿ����ߵ�ƽ */
			GPFDAT |= (7<<4)
		} else {
			/* ���£�bit4 5 6����͵�ƽ����led */
			GPFDAT &= ~(7<<4)
		}
	}
	return 0;
}











