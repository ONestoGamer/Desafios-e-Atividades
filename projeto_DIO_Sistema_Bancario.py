# Projeto prático DIO - Sistema Bancário
''' Este projeto tem como objetivo simular um sistema bancário simples,
onde é possível, realizar depósitos, saques e consultar o extrato.
O projeto foi desenvolvido utilizando a linguagem Python e tem como foco a
prática de orientação a objetos, encapsulamento, funções e abstração.'''

# Autor: Ernesto Santana
# Data: 31/08/2025

menu = """
### Bem vindo ao Banco ONesto ###

Escolha uma opção:

1. Depositar
2. Sacar
3. Extrato
4. Sair
"""
saldo = 0
limite = 500
extrato = ""
quantidade_saque = 0
QUANTIDADE_MAX_SAQUES = 3

while True:
    opcao = input(menu) # Exibe o menu e aguarda a opção do usuário

    if opcao == "1": 

        valor = float(input("Informe o valor do depósito: ")) # valor do depósito

        if valor > 0:   # Verifica se o valor do depósito é válido
            saldo += valor # Atualiza o saldo
            extrato += f"Depósito: R$ {valor:.2f}\n" # Adiciona ao extrato
            print("Depósito realizado com sucesso!") # Confirmação do depósito

        else: # Caso o valor do depósito seja inválido
            print("Valor inválido para depósito.") # Mensagem de erro

    elif opcao == "2":

        valor = float(input("Informe o valor do saque: ")) # valor do saque

        if 0 < valor <= saldo: # Verifica se o valor do saque é válido
            if valor > limite:
                print("Valor do saque ultrapassa o limite permitido.")
            else:
                saldo -= valor # Atualiza o saldo
                extrato += f"Saque: R$ {valor:.2f}\n" # Adiciona ao extrato
                quantidade_saque += 1 # Atualiza a quantidade de saques
                print("Saque realizado com sucesso!") # Confirmação do saque

        elif valor > saldo: # Verifica se o saldo é suficiente
            print("Saldo insuficiente para saque.") # Mensagem de erro

        elif quantidade_saque >= QUANTIDADE_MAX_SAQUES: # Verifica se o limite de saques foi atingido
            print("Limite de saques diários atingido.")

        else: # Caso o valor do saque seja inválido
            print("Valor inválido para saque.") # Mensagem de erro

    elif opcao == "3": # Consultar extrato
        print("=== Extrato ===") # Cabeçalho do extrato
        print("Não houve nenhuma movimentação." if not extrato else extrato)
        print(f"Saldo atual: R$ {saldo:.2f}") # Exibe o saldo atual
        print("================") 

    elif opcao == "4":
        print("Saindo...")
        break

    else:
        print("Opção inválida. Tente novamente.") # Mensagem de erro caso informe uma opção inválida
