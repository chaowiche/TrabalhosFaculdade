.data

.align 4
tabela: .space 24
mensagem1: .asciiz "Insira um inteiro: "
espaco: .asciiz " "
conteudo: .asciiz "\nValores ordenados: "


.text

main:

addi $s0,$zero,5 #adiciona o valor 5 ao registrador $zero (que sempre tem o valor zero) e armazena o resultado em $s0. Portanto, $s0 sera inicializado com o valor 5.
addi $t0,$zero,0 #inicializa $t0 com o valor zero.

#Aqui, serao lidos os valores inteiros que serao utilizados
in:
li $v0,4
la $a0,mensagem1 #exibe a mensagem1
syscall
li $v0,5
syscall
add $t1,$t0,$zero
sll $t1,$t0,2
add $t3,$v0,$zero
sw $t3,tabela ( $t1 )
addi $t0,$t0,1
slt $t1,$s0,$t0
beq $t1,$zero,in

#chama o algoritmo de ordenacao
la $a0,tabela
addi $a1,$s0,1 #a1=6
jal bs
#aqui, o endere�o da tabela e o tamanho da tabela s�o passados como argumentos para a fun��o bs

#depois da ordena��o, a tabela ordenada e impressa na tela.
li $v0,4
la $a0,conteudo
syscall
la $t0,tabela
#s0=5
add $t1,$zero,$zero
print:
lw $a0,0($t0)
li $v0,1
syscall
li $v0,4
la $a0,espaco
syscall
addi $t0,$t0,4
addi $t1,$t1,1
slt $t2,$s0,$t1
beq $t2,$zero,print

li $v0,10 #exitzinho
syscall

#algoritmo de ordena��o Bubble Sort. A tabela � ordenada em ordem crescente.
bs:
#a0=endereco da tabela
#a1=tamanho da tabela
add $t0,$zero,$zero #contador i = 0

loop1: #primeira parte do loop externo, que repete todos os elementos da tabela.
addi $t0,$t0,1 # incrementa no contador (i++)
bgt $t0,$a1,fimdoloop#se i � maior ou igual ao tamanho da tabela ($a1, encerra o loop externo

add $t1,$a1,$zero #contador j (representando a posi��o atual do segundo elemento na compara��o) com o tamanho da tabela.
loop2:

bge $t0,$t1,loop1 #se j <= i, volta para o loop1

#slt $t3,$t1,$t0
#bne $t3,$zero,loop1

addi $t1,$t1,-1 #decrementa no contador (i--)

mul $t4,$t1,4 #t4+a0=tabela[j] Calcula o deslocamento para acessar o elemento na posi��o j na tabela
addi $t3,$t4,-4 #t3+a0=tabela[j-1]  Calcula o deslocamento para acessar o elemento na posi��o j-1 na tabela.
add $t7,$t4,$a0 #t7=tabela[j] Calcula os endere�os dos elementos a serem comparados.
add $t8,$t3,$a0 #t8=tabela[j-1] mesma coisa que o anterior, mas com j-1
lw $t5,0($t7) #Carrega os valores dos elementos a serem comparados.
lw $t6,0($t8)

bgt $t5,$t6,loop2 #compara os elementos e, se estiverem fora de ordem, troca as posi��es.


sw $t5,0($t8) #Troca os elementos na tabela se necess�rio.
sw $t6,0($t7)
j loop2 # volta para o pr�ximo valor de j.

fimdoloop:
jr $ra # (volta para a posi��o no c�digo de onde a fun��o foi chamada).
