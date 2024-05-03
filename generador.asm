section .data
    buffer db 101 dup(0) ; Buffer para almacenar la cadena de texto aleatoria
    buffer_len equ $ - buffer ; Longitud máxima de la cadena

section .bss
    random_seed resq 1 ; Semilla para el generador de números aleatorios (64 bits)

section .text
    global generate_password

generate_password:
    push rbp
    mov rbp, rsp

    ; Inicialización de la semilla para el generador de números aleatorios
    mov eax, 0x2d31
    xor edx, edx
    mov rcx, 1
    mov rdi, random_seed
    syscall ; Llamada al sistema para obtener un número aleatorio (64 bits)
    
    ; Generar texto aleatorio
    mov rcx, buffer_len ; Número de caracteres a generar
    mov rsi, buffer ; Puntero al buffer de texto

generate_random_text:
    ; Generar un número aleatorio en el rango ASCII imprimible (32-126)
    mov rax, [random_seed]
    imul rax, rax, 0x7FED5B9D
    add rax, 0xCBD
    mov [random_seed], rax
    and rax, 0x7F ; Limitar el número al rango 0-127
    add rax, 32 ; Ajustar al rango ASCII imprimible (32-126)

    ; Almacenar el carácter generado en el buffer
    mov [rsi], al
    inc rsi

    loop generate_random_text ; Repetir hasta que se genere la longitud deseada

    ; Terminar la cadena con un byte nulo
    mov byte [rsi], 0

    pop rbp
    ret
