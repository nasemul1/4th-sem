.model small
.stack 100h
.data
    message db 0dh, 0ah, 'Enter a number: $'   
    even_message db 0dh, 0ah, 'Number is even. $'
    odd_message db 0dh, 0ah, 'Number is odd. $'
    
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov dx, offset message
    mov ah, 09h
    int 21h
    
    mov ah, 01h
    int 21h
    sub al, 30h
    
    test al, 01h
    jnz odd
    
    mov dx, offset even_message
    mov ah, 09h
    int 21h
    jmp exit
    
    odd:
    mov dx, offset odd_message
    mov ah, 09h
    int 21h
    
    exit:
    mov ah, 4ch
    int 21h
    
    main endp
end main