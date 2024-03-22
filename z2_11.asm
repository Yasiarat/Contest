; Ратова Ярослава   группа 105  задание 2
extern io_print_udec, io_get_udec, io_newline, io_get_dec, io_print_dec
section .data
    
section .text
    
global main
main:
    mov ebp, esp; for correct debugging
    call io_get_udec
    mov ebx, eax; 
    call io_get_udec; eax = k, ebx = n
    xor ecx, ecx; счётчик
    xor edx, edx
    xor esi, esi; счётчик сдвига
    xor edi, edi
    
    cmp eax, 32; если k > 32 - невозможно
    ja .exit
    
    mov edx, 0x80000000
    mov esi, 31; 
 
; циклом находим старший бит   
.first_bit:
    test ebx, edx
    jnz .f_exit
    dec esi;
    shr edx, 1; сдвигаем вправо
    jmp .first_bit
    
 
.f_exit:
    cmp esi, eax; если в макс числе нет k нулей - невозможно
    jb .exit
    
    mov [ebp-4], eax; положим k в стэк
    mov edi, eax;
    dec edi

; для чился 1**** считаем С из n по k для 1***
.k!:
    cmp edi, 1;
    je .n!
    
    
    
       
          
.exit:
    mov eax, ecx; 
    
    call io_print_udec
    xor eax, eax
    ret