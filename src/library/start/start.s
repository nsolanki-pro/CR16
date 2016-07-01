
# CR16C/CR16CPLUS
# Initial startup code for initializing stack bss etc.

	.text
	.section .initcr16,"ax"
	.globl		_main
	.globl		_exit
	.globl		_start


	# _start is main entry point for CR16 based microcontroller.
_start:


	# Setup stack pointer for interrupt & C codes.
	# __STACK_START is stack address as derived from controller ld script
	movd	$__STACK_START, (sp)
	movd	$__ISTACK_START, (r1,r0)
	lprd	(r1,r0), isp


	# Set nterrupt dispatch table width.
	spr	cfg, r0	
	orw	$0x110, r0
	lpr	r0, cfg

	# set intbase.
	movd	$__dispatch_table, (r1,r0)
	lprd	(r1,r0), intbase

	# Set srgc to Zero, r2 holds argc
	# Set argc to Zero, (r4,r3) holds argv
	# Then jump to main function
	movw	$0, r2
	movw	$0, r3
	movw	$0, r4
	bal	(ra), _main

	# We are not expecting to return from main & hence end here with infinit
	# loop.
	br	_exit

__eop:
	movw	$0x410, r0
	excp	bpt
	.word 0xFFFF

