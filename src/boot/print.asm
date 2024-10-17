print:
    pusha

; keep this in mind:
; while (string[i] != 0) { print string[i]; i++ }

; the comparison for string end (null byte)
start_print_std:
    mov al, [bx] ; 'bx' is the base address for the string
    cmp al, 0 
    je done_print_std

    ; the part where we print with the BIOS help
    mov ah, 0x0e
    int 0x10 ; 'al' already contains the char

    ; increment pointer and do next loop
    add bx, 1
    jmp start_print_std

done_print_std:
    popa
    ret



