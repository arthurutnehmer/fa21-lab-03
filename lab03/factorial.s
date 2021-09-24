.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
	#Iterator 
	addi a1, x0, 1
    #Saved value
	addi a2, x0, 1
    #Our N value +1
    addi a3, a0, 1
    
    #Do while out n value is not equal to iterator
    loop:
    	beq a3, a1, exit
        mul a2, a2, a1
        addi a1, a1, 1
        jal x0, loop
        
    exit:
    	add a0, a2, x0
        jr ra

