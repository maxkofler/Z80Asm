loop:
    ld a, 0xF2
    ld a,0xF3
    ld  a 0xF4
    call fun
    rjmp fun

fun:
    ret