.model small
.stack 100h
.data
    msg1 db 0dh, 0ah, 'Enter first number: $'
    msg2 db 0dh, 0ah, 'Enter second number: $'
    msg3 db 0dh, 0ah, 'Smaller number is: $'
    
.code
main proc
    mov ax, @data
    mov ds, ax
    
    ;print first message
    mov dx, offset msg1 
    mov ah, 09h
    int 21h
    
    ;input first number
    mov ah, 01h
    int 21h
    mov bl, al
    
    ;print new line
    mov dx, offset msg2
    mov ah, 09h
    int 21h
    
    ;input second number
    mov ah, 01h
    int 21h
    mov cl, al
    
    ;compare
    cmp bl, cl
    jge second_smaller
    
    ;print smaller message
    mov dx, offset msg3
    mov ah, 09h
    int 21h
    
    mov dl, bl
    mov ah, 02h
    int 21h
    jmp exit
    
    second_smaller:
    ;print smaller message
    mov dx, offset msg3
    mov ah, 09h
    int 21h
    
    mov dl, cl
    mov ah, 02h
    int 21h
    
    exit:
    mov ah, 4ch
    int 21h
    
    main endp
end main