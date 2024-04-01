.data
	prompt: .asciiz "Enter number (-69 to finish): "
	newline: .asciiz "\n"
	maxNumbers: .word 10
	maximum: .word 0
  # Biggest signed 32-bit integer
	minimum: .word 2147483647
	sum: .word 0
	maximumStr: .asciiz "Maximum is: "
	minimumStr: .asciiz "Minimum is: "
	sumStr: .asciiz "Sum is: "
	
.text 
	main:
		# Initialise input counter to 0
		li $t1, 0
		lw $t4, maxNumbers
		
		loop:
			# Prompt user
			li $v0, 4
			la $a0, prompt
			syscall
			
			# Read input from user and move it to $t2
			li $v0, 5
			syscall
			move $t2, $v0
			
			# Check if user wants to finish
			li $t3, -69
			beq $t2, $t3, exitLoop
			
			# Update the maximum number
			lw $t5, maximum
			bgt $t2, $t5, updateMaximum
			j checkMinimum
			
		updateMaximum:
			sw $t2, maximum
			j checkMinimum
			
		checkMinimum:
			lw $t5, minimum
			blt $t2, $t5, updateMinimum
			j sumAndLoop
			
		updateMinimum:
			sw $t2, minimum
			
		sumAndLoop:
			lw $t6, sum
			add $t6, $t6, $t2
			sw $t6, sum
			 
			# Increment input counter
			addi $t1, $t1, 1
			 
			# Check if all 10 numbers have been read
			bge $t1, $t4, exitLoop
			
			# We go again
			j loop
			
		exitLoop:
      # Output Maximum
	  	la $a0, maximumStr
      lw $a1, maximum
      jal smolprintf 

      # Output Minimum
			la $a0, minimumStr 
      lw $a1, minimum 
      jal smolprintf 

      # Output Sum 
			la $a0, sumStr 
      lw $a1, sum 
      jal smolprintf 

			# Exit program
			li $v0, 10
      syscall	 

# Subprogram for integer output
# Arguments: 
#   $a0: String to print
#   $a1: Integer to print 
smolprintf:
  li $v0, 4
  syscall

  li $v0, 1
  move $a0, $a1
  syscall

  li $v0, 4
  la $a0, newline
  syscall

  jr $ra
