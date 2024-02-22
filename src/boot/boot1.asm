[BITS 32]
[EXTERN initKernel]

global _start

_start:
	cli
	call initKernel

	jmp $
	RET