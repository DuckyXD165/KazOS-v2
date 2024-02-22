[BITS 32]
[EXTERN initKernel]

global _start

_start:
	sti

	call initKernel

	jmp $
	RET