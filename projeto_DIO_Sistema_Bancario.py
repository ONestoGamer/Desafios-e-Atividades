# Projeto prático DIO - Sistema Bancário
''' Este projeto tem como objetivo simular um sistema bancário simples,
onde é possível, realizar depósitos, saques e consultar o extrato.
O projeto foi desenvolvido utilizando a linguagem Python e tem como foco a
prática de orientação a objetos, encapsulamento, funções e abstração.'''
''' novas atualizações a serem implementadas depois da aula de data e hora no dia 01/09/2025: (percebi que tinha outras aulas antes dessa, a de POO)
- Adicionar limite de transações diárias = 10
- Mostrar a data e hora de cada transação no extrato
- Exibrir a mensagem após atingir o limite de operações diárias'''

# Autor: Ernesto Santana
# Data: 31/08/2025

import textwrap

def menu():
    menu = """ \n
    ### Bem vindo ao Banco ONesto ###

    \n ================ MENU ================

    1. Depositar
    2. Sacar
    3. Extrato
    4. Nova conta
    5. Novo usuário
    6. Listar contas
    7. Sair
    =>"""
    return input(textwrap.dedent(menu))

def depositar(saldo, valor, extrato, /):
    if valor > 0:
        saldo += valor
        extrato += f"Depósito: \tR$ {valor:.2f}\n"
        print("\n***Depósito realizado com sucesso!***")
    else:
        print("\n### Valor inválido para depósito. ###")
    return saldo, extrato

def sacar(*, saldo, valor, extrato, limite, numero_saques, limite_saques):
    excedeu_saldo = valor > saldo
    excedeu_limite = valor > limite
    excedeu_saques = numero_saques >= limite_saques

    if excedeu_saldo:
        print("\n### Operação falhou! Seu saldo é insuficiente para o saque. ###")

    elif excedeu_limite:
        print("\n### Operação falhou! Valor do saque ultrapassa o limite permitido. ###")

    elif excedeu_saques:
        print("\n### Limite de saques diários atingido. ###")

    elif valor > 0:
        saldo -= valor
        extrato += f"Saque: \t\tR$ {valor:.2f}\n"
        numero_saques += 1
        print("\n***Saque realizado com sucesso!***")

    else:
        print("\n### Operação falhou! Valor inválido para saque. ###")

    return saldo, extrato, numero_saques

def exibir_extrato(saldo, /, *, extrato):
    print("\n================ EXTRATO ================")
    print("Não foram realizadas movimentações." if not extrato else extrato)
    print(f"\nSaldo:\t\tR$ {saldo:.2f}")
    print("==========================================")

def criar_usuario(usuarios):
    cpf = input("Informe o CPF (somente números): ")
    usuario = filtrar_usuario(cpf, usuarios)

    if usuario:
        print("\n### Já existe usuário com esse CPF! ###")
        return

    nome = input("Informe o nome completo: ")
    data_nascimento = input("Informe a data de nascimento (dd/mm/aaaa): ")
    endereco = input("Informe o endereço (Rua, Nro - Bairro - Cidade/sigla Estado): ")

    usuarios.append({"nome": nome, "data_nascimento": data_nascimento, "cpf": cpf, "endereco": endereco})

    print("\n*** Usuário criado com sucesso! ***")

def filtrar_usuario(cpf, usuarios):
    usuarios_filtrados = [usuario for usuario in usuarios if usuario["cpf"] == cpf]
    return usuarios_filtrados[0] if usuarios_filtrados else None

def criar_conta(agencia, numero_conta, usuarios):
    cpf = input("Informe o CPF do usuário: ")
    usuario = filtrar_usuario(cpf, usuarios)

    if usuario:
        print("\n*** Conta criada com sucesso! ***")
        return {"agencia": agencia, "numero_conta": numero_conta, "usuario": usuario}

    print("\n### Usuário não encontrado, fluxo de criação de conta encerrado! ###")

def listar_contas(contas):
    for conta in contas:
        linha = f"""\
        Agência:\t{conta['agencia']}
        C/C:\t\t{conta['numero_conta']}
        Titular:\t{conta['usuario']['nome']}
        """
        print("=" * 100)
        print(textwrap.dedent(linha))

def main():
    LIMITE_SAQUES = 3
    AGENCIA = "0001"

    saldo = 0
    limite = 500
    extrato = ""
    quantidade_saque = 0
    usuarios = []
    contas = []
    QUANTIDADE_MAX_SAQUES = 3

    while True:
        opcao = menu() # Exibe o menu e aguarda a opção do usuário

        if opcao == "1": 

            valor = float(input("Informe o valor do depósito: ")) # valor do depósito
            saldo, extrato = depositar(saldo, valor, extrato)
        elif opcao == "2": # Sacar
            valor = float(input("Informe o valor do saque: ")) # valor do saque
            
            saldo, extrato, quantidade_saque = sacar(
                saldo=saldo, valor=valor, 
                extrato=extrato, limite=limite, 
                numero_saques=quantidade_saque, 
                limite_saques=LIMITE_SAQUES,)
            
        elif opcao == "3": 
            exibir_extrato(saldo, extrato=extrato) # Consultar extrato

        elif opcao == "4": # Nova conta
            numero_conta = len(contas) + 1 # Gera o número da conta
            conta = criar_conta(AGENCIA, numero_conta, usuarios)
            if conta:
                contas.append(conta)

        elif opcao == "5": # Novo usuário
            criar_usuario(usuarios)
        
        elif opcao == "6": # Listar contas
            listar_contas(contas)

        elif opcao == "7": # Sair
            print("Saindo...")
            break

        else:
            print("Opção inválida. Tente novamente.") # Mensagem de erro caso informe uma opção inválida
main()