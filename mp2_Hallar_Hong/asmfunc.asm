;assemly part using x86-64

section .data
msg db "Hello world", 13, 10, 0
section .text
bits 64
default rel
global asmhello
extern printf

asmhello:
	sub rsp, 8*5
	lea rcx, [msg]
	call printf
	add rsp, 8*5
	ret

