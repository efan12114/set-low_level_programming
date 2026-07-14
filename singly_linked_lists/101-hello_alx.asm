bits 64
global main
extern printf

section .text
main:
    	push rbp
    	mov rbp, rsp

    	; Set up arguments for printf
    	mov rdi, msg
    	mov rax, 0
    	call printf

    	; Clean up stack and return 0
    	mov rax, 0
    	mov rsp, rbp
    	pop rbp
    	ret

section .data
    	msg: db "Hello, Frontier", 10, 0
