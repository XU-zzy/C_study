	.file	"test_1.c"
	.intel_syntax noprefix
	.text
	.section	.rodata
.LC0:
	.string	"Hello, I'm fun!"
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
.L2:
	lea	rdi, .LC0[rip]
	call	puts@PLT
	mov	edi, 1
	call	sleep@PLT
	jmp	.L2
	.cfi_endproc
.LFE0:
	.size	fun, .-fun
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -32[rbp], 0
	mov	QWORD PTR -24[rbp], 0
	mov	DWORD PTR -16[rbp], 0
	lea	rax, fun[rip]
	mov	DWORD PTR -12[rbp], eax
	lea	rax, fun[rip]
	mov	DWORD PTR -8[rbp], eax
	lea	rax, fun[rip]
	mov	DWORD PTR -4[rbp], eax
	mov	eax, 0
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
