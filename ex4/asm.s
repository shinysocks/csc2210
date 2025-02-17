# Noah Dinan - CSC2210
# Exercise 4
# February 17

.data
.text
.global main
# 3x^3 - 2x^2 + (x - 1)
main:
    mov  $-4, %eax    # put 4 in eax
    mov  %eax, %edx
    mov  %eax, %ecx
    mov  %eax, %ebx

    sub  $1, %edx     # edx now holds (x - 1)

    imul %ecx, %ecx
    imul $2, %ecx     # ecx now holds (2x^2)

    imul %ebx, %ebx
    imul %eax, %ebx
    imul $3, %ebx     # ebx now holds (3x^3)

    sub  %ecx, %ebx
    add  %edx, %ebx

    mov  %ebx, %eax   # mov back to return register (eax)
    ret
