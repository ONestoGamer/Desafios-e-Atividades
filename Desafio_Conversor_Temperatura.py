# Implemente uma classe ConversorTemperatura que converte temperaturas de Celsius para Fahrenheit. 
# A classe deve incluir um método chamado celsius_para_fahrenheit que realiza o cálculo de conversão.
# A fórmula para converter de Celsius para Fahrenheit é:
# Fahrenheit=(Celsius×95)+32Fahrenheit=(Celsius×59​)+32
# Você também deverá criar uma instância do conversor e utilizar essa instância para realizar a conversão.

celsius = float(input("Digite a temperatura em Celsius: "))

# Crie uma classe para converter temperaturas de Celsius para Fahrenheit e um método que realiza o cálculo de conversão:
class ConversorTemperatura:
    def __init__(self):
        pass

    def celsius_para_fahrenheit(self, celsius):
        fahrenheit = (celsius * 9/5) + 32
        return fahrenheit
# Crie uma instância do conversor e utilize essa instância para realizar a conversão:

conversor = ConversorTemperatura()  
fahrenheit = conversor.celsius_para_fahrenheit(celsius)
print(f"A temperatura em Fahrenheit é: {fahrenheit}")