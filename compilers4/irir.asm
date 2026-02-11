start one
addi $t1, fp, 4
sw 1, 0($t1)
L1:
andi $t1, $a2, 1
beq $t1, $0, esc2
ori $t2, $t1, 1
bneq $t2, $0, esc2
esc2:
bne $t2, $0, L3
subi $a2, $a2, 1
jal L2
L3:
start main
addi $t1, fp, 8
sw 5, 0($t1)
li $t1, 5
li $t1, 0x5
fcvt.s.w $fa0, $t1
li $a0, 5
mv $a1, $t1
addi $ra, $pc, 4
jal one
li $a0 1
