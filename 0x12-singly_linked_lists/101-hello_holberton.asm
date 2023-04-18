section .data
    hello: db "Hello, Holberton", 0Ah
    format: db "%s", 0

section .text
    extern printf
    extern exit

    section .bss
        buffer resb 32

    section .text
    global main

main:
    push rbp
    mov rbp, rsp

    ; Copy the message to the buffer
    mov rdi, buffer
    mov rsi, hello
    call copy_string

    ; Print the message using printf
    mov rdi, format
    mov rsi, buffer
    xor eax, eax
    call printf

    ; Exit the program
    xor edi, edi
    call exit

copy_string:
    push rbp
    mov rbp, rsp

    ; Copy string byte by byte
    .loop:
        mov al, byte [rsi]
        mov byte [rdi], al
        inc rsi
        inc rdi
        cmp byte [rsi - 1], 0
        jne .loop

    ; Return pointer to destination buffer
    mov rax, rdi
    mov rsp, rbp
    pop rbp
    ret

