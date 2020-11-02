	.file	"1.c"
	.text
	.comm	A,4,4
	.globl	B
	.bss
	.align 4
	.type	B, @object
	.size	B, 4
B:
	.zero	4
	.globl	C
	.data
	.align 4
	.type	C, @object
	.size	C, 4
C:
	.long	2
	.local	D
	.comm	D,4,4
	.local	E
	.comm	E,4,4
	.align 4
	.type	F, @object
	.size	F, 4
F:
	.long	4
	.globl	G
	.section	.rodata
	.align 4
	.type	G, @object
	.size	G, 4
G:
	.long	5
	.globl	H
	.type	H, @object
	.size	H, 1
H:
	.byte	6
.LC0:
	.string	"123456"
.LC1:
	.string	"PID is :%d\n\n"
.LC2:
	.string	"int A\tA_ addr = %p\n"
.LC3:
	.string	"int B = 0   B_ addr = %p\n"
.LC4:
	.string	"int C = 2   C_ addr = %p\n"
.LC5:
	.string	"static int  D_ addr = %p\n"
.LC6:
	.string	"static int E = 0 E_addr = %p\n"
.LC7:
	.string	"static int F = 4 F_addr = %p\n"
.LC8:
	.string	"const int G = 5 G_addr %p\n"
	.align 8
.LC9:
	.string	"const char H = 6 H_ addr = %p\n"
.LC10:
	.string	"int a a_addr%p\n"
.LC11:
	.string	"int b = 0 b_addr = %p\n"
.LC12:
	.string	"int c = 2 c_addr = %p\n"
.LC13:
	.string	"static int d d_addr = %p\n"
.LC14:
	.string	"static int e =0  e_addr %p\n"
.LC15:
	.string	"static int f = 4 addr = %p\n"
.LC16:
	.string	"const int g= 5 g_addr = %p\n"
	.align 8
.LC17:
	.string	"char char1[] = 'abcde'\t\t\tchar1_ addr = %p\n"
	.align 8
.LC18:
	.string	"char char1[] = 'abcde'\t\t\t&char1_ addr = %p\n"
	.align 8
.LC19:
	.string	"char *cptr = '1' \t\t\tcptr_ addr = %p\n"
	.align 8
.LC20:
	.string	"value of the cptr\t\t\tcptr_ value = 0x%p\n"
	.align 8
.LC21:
	.string	"value of %p\t\t\t value_ 0\321\205%p = %d\n"
	.align 8
.LC22:
	.string	"int* heap = malloc(sizeof(int )*4)\theap_ addr%p\n"
	.align 8
.LC23:
	.string	"int* heap = malloc(sizeof(int)*4)\t&heap_ addr = %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -44(%rbp)
	movl	$2, -40(%rbp)
	movl	$5, -36(%rbp)
	movl	$1684234849, -14(%rbp)
	movw	$101, -10(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -32(%rbp)
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, -24(%rbp)
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	A(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	B(%rip), %rsi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	C(%rip), %rsi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	D(%rip), %rsi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	E(%rip), %rsi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	F(%rip), %rsi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	G(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	H(%rip), %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10, %edi
	call	putchar@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	d.3378(%rip), %rsi
	leaq	.LC13(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	e.3379(%rip), %rsi
	leaq	.LC14(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	f.3380(%rip), %rsi
	leaq	.LC15(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC16(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10, %edi
	call	putchar@PLT
	leaq	-14(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC17(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-14(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC18(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC19(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC20(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %ecx
	movq	-32(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC21(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC22(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC23(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.local	d.3378
	.comm	d.3378,4,4
	.local	e.3379
	.comm	e.3379,4,4
	.data
	.align 4
	.type	f.3380, @object
	.size	f.3380, 4
f.3380:
	.long	4
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
