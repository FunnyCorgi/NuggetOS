mov ah, 0x0e;tty mode

;set up stack
mov sp, 0x8000
mov bp, sp

;stack is set now set up, put the chars for the string 'Now booting NuggetOS'
push 'S'
push 'O'
push 't'
push 'e'
push 'g'
push 'g'
push 'u'
push 'N'
push ' '
push 'g'
push 'n'
push 'i'
push 't'
push 'o'
push 'o'
push 'b'
push ' '
push 'w'
push 'o'
push 'N'

print_stack_char_loop
  pop bx
  mov al, bl
  int 0x10
  cmp al, 'N'
  jne print_stack_char_loop
done:
  jmp $

times 510 - ($-$$) db 0
dw 0xaa55
