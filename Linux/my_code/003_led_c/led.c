

int main()
{
	unsigned int *pGPFCON = (unsigned int*)0x56000050;
	unsigned int *pGPFDAT = (unsigned int*)0x56000054;

	/* ���üĴ�������������͵�ƽ0 */
	*pGPFCON = 0x400;
	*pGPFDAT = 0;

	return 0;
}











