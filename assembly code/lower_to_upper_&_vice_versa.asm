.MODEL small
.STACK 100H
.DATA
.CODE

main proc
    mov ah, 1
    int 21h
    mov bl, al
    
    mov dl, 10
    mov ah, 2
    int 21h
    
    mov dl, 13
    mov ah, 2
    int 21h
    
    cmp bl, 97
    jge lower
    
    add bl, 32
    mov ah, 2
    mov dl, bl
    int 21h
    jmp exit
    
    lower:
    sub bl, 32
    mov ah, 2
    mov dl, bl
    int 21h
    
    exit:
    mov ah, 4ch
    int 21h
    
    main endp
END MAIN
    