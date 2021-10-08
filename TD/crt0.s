.syntax unified
.thumb

.global _start
_start:
    ldr sp, =_stack
    bl init_bss
    bl main

