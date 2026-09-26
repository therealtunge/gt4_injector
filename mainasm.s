
.globl __start

__start:
	j cstart
	#j 0x00100000
	#xori $a0,$0,0xFFFF #a0 = 0x01000000
	