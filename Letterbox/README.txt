Trabalho 2 TP2 2019/2
Exercises in programming style
Style 12 - Letterbox

How to compile the program:
g++ -o exec -std=c++11 -g -pedantic -Wall letterbox.cpp 

How to execute the program:
./exec ./pride-and-prejudice.txt

Letterbox é um estilo de programacao em que dividimos o programa em modulos(classes)
e para fazer a comunicação entre as classes(troca de mensagens), envia-se um vetor de strings
como ser fosse uma carta para a outra classe, que recebe como uma função Dispatch(), lê a string
e encaminha para a função correta, por isso o nome Letterbox(caixa de correio)