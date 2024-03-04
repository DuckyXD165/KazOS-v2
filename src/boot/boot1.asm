[BITS 32]
global _start
_start:
	cli
	mov eax, 0x1000
	mov cr3, eax ; Load 0x1000 into cr3
	mov dword [0x1000], 0x2003 ;first entry of PML4T points to PDPT
	mov dword [0x2000], 0x3003 ;first entry of PDPT points to PDT
	mov dword [0x3000], 0x4003 ;first entry of PDT points to PT


	mov ecx, 0
	.idmap:
		mov eax, 0x200000 ;page size - 2MiB
		mul ecx
		or eax, 10000011b
		mov [0x3000 + ecx * 8], eax ;place virtual address of page into page table (1:1 correspondence - identity map)

		inc ecx
		cmp ecx, 512
		jne .idmap

	mov eax, cr4
	or eax, 1 << 5
	mov cr4, eax

	mov ecx, 0xC0000080
	rdmsr
	or eax, 1 << 8
	wrmsr

	mov eax, cr0
	or eax, 1 << 31
	or eax, 1 << 16
	mov cr0, eax
	
	mov byte [gdt_cs + 6], 10101111b
	mov byte [gdt_ds + 6], 10101111b
	[BITS 64]
	[EXTERN initKernel]
    call initKernel
	jmp $
	RET


; GDT Flag/limit byte definitions
gdt_cs:
dw 0xffff
dw 0
db 0
db 10011010b
db 11001111b
db 0
gdt_ds:
dw 0xffff
dw 0
db 0
db 10010010b
db 11001111b
db 0
