.model small
.stack 100h
.data
    array db 7, 5, 3, 9, 0, 1, 2
    size equ 7
    maxVal db 0
    msg db 0dh, 0ah, 'Largest number is: $'
    
.code
main proc
    mov ax, @data
    mov ds, ax
    
    
    mov al, array
    mov maxVal, al
    
    mov cx, size
    mov si, offset array+1
    
    loop_start:
        mov al, byte ptr[si]
        cmp al, maxVal
        jle not_largest
        
        mov maxVal, al
        
    not_largest:
        inc si
        loop loop_start
        
    mov dl, offset msg
    mov ah, 09h
    int 21h
    
    mov dl, maxVal
    add dl, 30h
    mov ah, 02h
    int 21h
    
    exit:
    mov ah, 4ch
    int 21h
    
    main endp
end main
     