.model small
.stack 100h
.data
    count dw 4
    numbers db 2, 3, 1, 2
    sum dw 0
    average dw 0
    msg db "Average: $"
    
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov cx, count
    mov si, offset numbers
    mov bx, 0h
    
    L1:
    mov al, byte ptr[si]
    add bx, ax
    inc si
    loop L1
    
    mov ax, bx
    cwd
    idiv count
    
    mov sum, bx
    mov average, ax
    
    mov dx, offset msg
    mov ah, 09h
    int 21h
    
    mov dx, average
    add dx, 30h
    mov ah, 02h
    int 21h
    
    mov ah, 4ch
    int 21h
    main endp
end main
