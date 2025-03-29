# Noah Dinan - CSC2210
# Exercise 4
# February 17

.global main
.text

# 3x^3 - 2x^2 + (x - 1)
main:
    mov  $10, %eax   # put 4 in eax
    mov  $25, %ebx
    sub %ebx, %eax
    ret
