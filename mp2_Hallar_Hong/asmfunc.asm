;assemly part using x86-64
section .data
section .text
bits 64
default rel
global daxpy

;A in rdi
;X in rsi
;Y in rdx
;Z in rcx
;size in r8

daxpy:
	movsd xmm0, [rdi]		;scalar A
	mov eax, 0

L1:
	movsd xmm1, [rsi+8*rax]   ;X[i]
	mulsd xmm1, xmm0		  ;A*X[i]
	movsd xmm2, [rdx+8*rax]	  ;Y[i]
	vaddsd xmm3, xmm1, xmm2	  ; A*X[i] + Y[i]
	movsd [rcx+8*rax], xmm3
	xorps xmm3, xmm3

	inc eax
	cmp eax, r8d
	jne L1
	jmp END

END:
	nop
	ret

