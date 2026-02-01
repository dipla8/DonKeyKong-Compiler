.data
	t: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
	xovl: .space 4
.text
	.globl main, deez
main:
	addi $sp, $sp, -16
	sw $ra, 12($sp)
	sw $fp, 8($sp)
	addi $fp, $sp, 16

	rest goes here

	lw $ra, 12($sp)
	lw $fp, 8($sp)
	addi $sp, $sp, 16
	j $ra
deez:
	addi $sp, $sp, -12
	sw $ra, 8($sp)
	sw $fp, 4($sp)
	addi $fp, $sp, 12

	rest goes here

	lw $ra, 8($sp)
	lw $fp, 4($sp)
	addi $sp, $sp, 12
	j $ra
