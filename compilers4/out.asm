.data
	t: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
	xovl: .space 4
.text
	.globl main, one
main:
	addi $sp, $sp, -16
	sw $ra, 12($sp)
	sw $fp, 8($sp)
	addi $fp, $sp, 16

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

	lw $ra, 12($sp)
	lw $fp, 8($sp)
	addi $sp, $sp, 16
	j $ra
one:
	addi $sp, $sp, -12
	sw $ra, 8($sp)
	sw $fp, 4($sp)
	addi $fp, $sp, 12

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

	lw $ra, 8($sp)
	lw $fp, 4($sp)
	addi $sp, $sp, 12
	j $ra
