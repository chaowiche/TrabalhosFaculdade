.data

 mensagem: .asciiz "Insira um valor natural diferente de 0"
 resultado: .asciiz "\nO fatorial do numero escolhido e "

 .text
 #Imprime a mensagem de pedir o valor
 li $v0, 4
 la $a0, mensagem
 syscall

 #Carrega o codigo de ler inteiros
 li $v0, 5
 syscall


 move $a0, $v0
 li $v0, 1
 syscall

 #jump para a funcao de fatorial
 jal fatorial
 move $a1, $v0

 #Imprime a mensagem de resultado
 li $v0, 4
 la $a0, resultado
 syscall

#imprime o inteiro que tanto queremos
 move $a0, $a1
 li $v0, 1
 syscall
   
   #exitzinho
   li $v0, 10
   syscall
 
 fatorial:   #Utilizacao de stack pointers!
       addi $sp, $sp-4
       sw $ra, ($sp)

       
      multiplica:
        beq $a0, $zero, retorno  #o $zero é um registrador que sempre armazena 0, o que pode acabar ajudando a economizar o espaço de um registrador
        mul $v0, $v0, $a0
        addi $a0, $a0, -1
        j multiplica #volta para o inicio da label de multiplicacao
  

    retorno:
    lw $ra, ($sp)
    jr $ra  #desvia para o ponto de onde foi chamado o procedimento