NOP
LOOP:
    ld, b, 56H
    ld, bc, GAMING
    NOP
    NOP
    add hl, bc
    ex af, af'
    rlca

GAMING:
    NOP