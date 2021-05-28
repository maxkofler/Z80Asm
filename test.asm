MAIN:
    ld a 5fh
    inc a
    ld c 01h
    dec c
    ld (FF69h) a
    ld sp 69F2h