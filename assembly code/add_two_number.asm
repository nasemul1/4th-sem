.model small
.stack 100h
.data
.code
main proc
    mov ah,01h
    int 21h
    mov bl, al
    
    mov dl, 10
    mov ah, 02h
    int 21h
    
    mov dl, 13
    mov ah, 02h
    int 21h
    
    mov ah, 01h
    int 21h
    
    add bl, al
    sub bl, 30h
    
    mov dl, 10
    mov ah, 02h
    int 21h
    
    mov dl, 13
    mov ah, 02h
    int 21h
    
    mov dl, bl
    mov ah, 02h
    int 21h
    
    main endp
end main