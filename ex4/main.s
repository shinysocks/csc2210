# Noah Dinan - CSC2210
# Exercise 4
# February 17

.data
num:
    .ascii "42"

.global main
.text

# 3x^3 - 2x^2 + (x - 1)
main:
    mov  $4, %eax    # put 4 in eax
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

    # attempt to output %ebx to STDOUT
    mov $1, %rax     # set call code to 1 (SYS_WRITE)
    mov $1, %rdi     # set output location to destination index (STDOUT)
    mov $num, %rbx
    mov %rbx, %rsi
    mov $8, %rdx     # number of bytes to output
    syscall

    # return
    mov $0, %rax
    ret
