all:
	arm-linux-gcc -c -o led.o led.c
	arm-linux-gcc -c -o start.o start.S
	arm-linux-ld -Ttext 0 start.o led.o -o led.elf	#链接.o
	arm-linux-objcopy -O binary -S led.elf led.bin	#将unix可执行文件.elf 转换成 二进制文件.bin
	arm-linux-objdump -D led.elf > led.dis	#反汇编
clean:
	rm *.bin *.o *.elf *.dis
