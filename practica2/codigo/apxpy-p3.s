
    .data
x:  .dword 0,1,2,3,4,5,6,7,8,9
    .dword 10,11,12,13,14,15

y:  .dword 100,100,100,100,100,100,100,100,100,100
    .dword 100,100,100,100,100,100

# Vector z

z:  .space 128

# Escalar a
a:  .dword -10

# El codigo
    .text

start:
    addi t0,gp,x
    addi t3,gp,y
    addi t1,gp,y
    addi t2,gp,z
    ld t4,a(gp)

loop:
    ld a0,0(t0)
    addi t0,t0,8
    add a0,t4,a0
    ld a1,0(t1)
    addi t1,t1,8
    add a1,a0,a1
    slt t5,t0,t3
    sd a1,0(t2)
    addi t2,t2,8
    bnez t5,loop   # bne t5,zero,loop
	
    ori a7,zero,10   # Fin de programa
    ecall
	
