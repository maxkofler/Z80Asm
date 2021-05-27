NOP
LOOP:
    ld, b, 56H
    ld, bc, FUN
    NOP
    NOP
    add hl, bc
    ex af, af'
    rlca
FUN:
    NOP