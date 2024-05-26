.model small
.stack 100h

.data
; No data segment needed in this program

.code
main proc
  ; Get a character from the user
  mov ah, 1 ; Interrupt for get character
  int 21h  ; Call DOS interrupt

  ; Check if the character is between 'a' and 'z' (lowercase)
  cmp al, 'a' ; Compare character with 'a'
  jl not_lowercase ; Jump if less than 'a' (not lowercase)
  cmp al, 'z' ; Compare character with 'z'
  jg not_lowercase ; Jump if greater than 'z' (not lowercase)

  ; Convert lowercase to uppercase (add 32)
  add al, 32

  jmp print_char

not_lowercase:
  ; Check if the character is between 'A' and 'Z' (uppercase)
  cmp al, 'A' ; Compare character with 'A'
  jl print_char ; Jump if less than 'A' (already a character)
  cmp al, 'Z' ; Compare character with 'Z'
  jg print_char ; Jump if greater than 'Z' (already a character)

  ; Convert uppercase to lowercase (subtract 32)
  sub al, 32

print_char:
  ; Print the converted character
  mov ah, 2 ; Interrupt for print character
  int 21h  ; Call DOS interrupt

  ; Exit program
  mov ah, 4ch ; Interrupt for terminate
  int 21h  ; Call DOS interrupt

main endp
end main
