;assemly part using x86-64
section .data

section .text
bits 64
default rel
global daxpy

;A in rcx
;X in rdx
;Y in r8
;Z in r9
;size in [rbp+32]

daxpy:
	push rsi
    push rbp
    mov rbp, rsp
	add rbp, 16
	add rbp, 8

mov rax, 0

L1:
	movsd xmm5, xmm0					;moved A from xmm0 to xmm5
	mulsd xmm5, [rdx+8*rax]		        ;A*X[i]
	vaddsd xmm1, xmm5, [r8+8*rax]		;A*X[i] + Y[i]
	movsd [r9+8*rax], xmm1		        ;store answer  to Z[i]
    xorpd xmm1, xmm1
	xorpd xmm5, xmm5

	inc rax
	cmp rax, [rbp+32]
	jne L1
	
	pop rbp
	pop rsi
	ret