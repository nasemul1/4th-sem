.model small
.stack 100h
.code
main proc
    mov cx, 26
    mov dx, 65
    
    L1:
        mov ah, 02h
        int 21h
        inc dx
    loop L1
    
    mov dl, 10
    mov ah, 02h
    int 21h
    
    mov dl, 13
    mov ah, 02h
    int 21h
    
    mov cx, 26
    mov dx, 97
    
    L2:
        mov ah, 02h
        int 21h
        inc dx
    loop L2
    
    exit:
    mov ah, 4ch
    int 21h
    
    main endp
end main