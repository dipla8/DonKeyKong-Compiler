start deez
addi $t1, fp, 4
sw 1, $t1
li $a2, 1
L1:
bne ==, $0, L2
subi $a2, $a2, 1
jal L1
L2:
jr $ra
start main
li $t0, 0
li $t1, 1
li $t2, 4
mul $t3, $t1, $t2
add $t0, $t3, $t0
mul $t1, $t5, $t1
li $t4, 0
mul $t5, $t1, $t4
add $t0, $t5, $t0
mul $t1, $t2, $t1
li $t6, 4
mul $t0, $t0, $t6
add $t7, $t0, $gp
lw $t8, 0($t6)
addi $t1, fp, 44
sw 5, $t1
li $a0, 5.000000
li $a1, 5
li $a2, +
addi $ra, $pc, 4
jal deez
addi $t1, fp, 44
sw 5, $t1
li $a0 1
