;assemly part using x86-64
section .data
print_ans db "%d: A=%.1f, X[%d]=%.1f, Y[%d]=%.1f, Y[%d]=%.1f\n", 0

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
		xorps xmm1, xmm1
        xor rax, rax
	    mov rax, 0
	

L1:
	movsd xmm0, [rcx]					;A
	mulsd xmm0, [rdx+8*rax]		        ;A*X[i]
	vaddsd xmm1, xmm0, [r8+8*rax]		;A*X[i] + Y[i]
	movsd [r9+8*rax], xmm1		        ;store answer  to Z[i]
    xorps xmm1, xmm1
	xorps xmm0, xmm0

	inc rax
	cmp rax, [rbp+32]
	jne L1
	
	pop rbp
	pop rsi
	ret

