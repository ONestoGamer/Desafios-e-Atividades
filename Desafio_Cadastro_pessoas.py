# Neste desafio, temos a classe Pessoa com seus atributos que armazenam o nome e a idade de uma pessoa. 
# Implemente um método para retornar uma representação formatada dos dados da pessoa, 
# crie uma instância da pessoa e, por fim, chame o método para retornar as informações formatadas e imprimir o resultado. 
# O objetivo é utilizarmos formas para criar e manipular objetos com POO, usando atributos e métodos para encapsular dados e comportamentos.

class Pessoa:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def representacao(self):
        return f"Nome: {self.nome}, Idade: {self.idade} anos"
# criando um metodo para retornar a representação formatada dos dados da pessoa
    def representacao(self):
        return f"Nome: {self.nome}, Idade: {self.idade} anos"

# Criando uma instância da classe Pessoa
pessoa = Pessoa("Ernesto Santana", 30)
# Chamando o método para obter a representação formatada dos dados
info_formatada = pessoa.representacao()
print(info_formatada)