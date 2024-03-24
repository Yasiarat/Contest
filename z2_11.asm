; Ратова Ярослава   группа 105  задание 2
extern io_print_udec, io_get_udec, io_newline, io_get_dec, io_print_dec
section .bss
    n resd 1; резервируем 4 байта = 32 бита
    
section .data
    cnt dd 0; счётчик 
    k dd 0;
    
    ker dd 0;
    nul dd 0; счётчик нулей

    cnk dd 0;
section .text
    
; для чился 1** считаем С из n по k для 1*, где n = nul, k = ker
global c_n_k
c_n_k:
    mov eax, 0;
    mov ebx, [ker]
    cmp dword[nul], ebx
    jb .c_out
    je .c_e
    
    mov ebx, 1;
    mov eax, 1;
.L:
    cmp ebx, [ker]
    ja .c_out
    
    
    
    mul dword[nul];
    dec dword[nul];
    div ebx;
    
    inc ebx
    jmp .L
.c_e:
    mov eax, 1
    jmp .c_out   
.c_out: 
              
    ret    
    
global main
main:
    mov ebp, esp; for correct debugging
    call io_get_udec
    mov [n], eax; 
    call io_get_udec; 
    mov [k], eax;
    mov [ker], eax;
    
    
    
    xor ecx, ecx; счётчик
    xor edx, edx
    xor esi, esi; счётчик сдвига
    xor edi, edi
    
    cmp eax, 32; если k > 32 - невозможно
    ja .exit
    
    mov edi, 0b10000000;0x80000000;
    mov esi, 7;31; счётчик нулей
 
; циклом находим старший бит   
.first_bit:
    test [n], edi
    jnz .f_exit
    dec esi;
    shr edi, 1; сдвигаем вправо
    jmp .first_bit
    
 
.f_exit:
    cmp esi, [k]; если в макс числе нет k нулей - невозможно
    jb .exit
    
    mov [cnt], esi;
    cmp dword[k], 0
    jbe .exit
    
    mov dword[cnt], 0; 
    
    mov [nul], esi; сохраняем количество нулей
    dec dword[nul]; посчитаем число сочетаний для числа на разряд меньшего максимального
    
    call c_n_k;
    
    
    mov [cnt], eax; сохраняем число сочетаний в счётчик
    
    shr edi, 1;
    mov ebx, [k]
    mov dword[ker], ebx;  
    
    
.second_step:
    cmp esi, 0; если мы дошли до конца - выходим из цикла
    je .out

    test [n], edi; если проверяемый бит = 1
    jnz .one
    
    cmp dword[ker], 0; если нужное количество нулей уже есть, а тут опять 0 - выходим
    je .exit
    
    dec dword[ker]; если встретили 0 - уменьшаем нужное колчиество нулей
    dec esi; идём на следующий бит
    shr edi, 1
    
    jmp .second_step
.one:
    dec esi; ищем число сочетаний для оставшихся бит
    mov [nul], esi; теперь n - номер текущего бита справа - 1
    
    call c_n_k;   
    
    add [cnt], eax;
    shr edi, 1
    
    jmp .second_step

.out:
    test esi, 0xFFFFFFFF
    jnz .exit;
    
    inc dword[cnt]
    jmp .exit
    
.exit:
    mov eax, [cnt]; 
    
    call io_print_udec
    xor eax, eax
    ret
