mov ah, 0x0e;tty mode

;we are now preparing to jump to 32 bit mode, then the kernel once it's loaded
mov al, 'W'
int 0x10
mov al, 'o'
int 0x10
mov al, 'r'
int 0x10
mov al, 'k'
int 0x10
mov al, 's'
int 0x10
mov al, '!'
int 0x10
jmp $

times 510 - ($-$$) db 0
dw 0xaa55
