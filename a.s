	.file	"a.c"
	.intel_syntax noprefix
	.text
	.section	.rodata
.LC0:
	.string	"aaa"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR -16[rbp], 1
	mov	DWORD PTR -12[rbp], 2
	mov	DWORD PTR -8[rbp], 3
	mov	DWORD PTR -4[rbp], 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	mov	DWORD PTR -16[rbp+rax*4], 0
	lea	rax, .LC0[rip]
	mov	rdi, rax
	call	puts@PLT
	add	DWORD PTR -4[rbp], 1
.L2:
	cmp	DWORD PTR -4[rbp], 3
	jle	.L3
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
