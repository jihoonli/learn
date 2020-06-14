all:
	arm-linux-gcc -c -o key_led.o key_led.c
	arm-linux-gcc -c -o start.o start.S
	arm-linux-ld -Ttext 0 start.o key_led.o -o key_led.elf	#链接.o
	arm-linux-objcopy -O binary -S key_led.elf key_led.bin	#将unix可执行文件.elf 转换成 二进制文件.bin
	arm-linux-objdump -D key_led.elf > key_led.dis	#反汇编
clean:
	rm *.bin *.o *.elf *.dis
