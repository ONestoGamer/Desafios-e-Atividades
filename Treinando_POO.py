# O desafio consiste em implementar uma classe Calculadora que utilize os princípios da Programação Orientada a Objetos (POO). 
# A classe deve conter um método para realizar a operação de soma entre dois números inteiros, encapsulando assim a lógica matemática da adição.

#A entrada será composta por dois números inteiros fornecidos pelo usuário.
# A saída esperada é o resultado da soma dos dois números inteiros fornecidos como entrada.

num1 = int(input("Digite o primeiro número inteiro: "))
num2 = int(input("Digite o segundo número inteiro: "))

class Calculadora:
    def __init__(self):
        pass

    def somar(self, a, b):
        return a + b
    
calc = Calculadora()
resultado = calc.somar(num1, num2)
print("O resultado da soma é:", resultado)