Lista_Alunos = []

print("-----------MENU------------")
print("[1] Adicionar Aluno/Notas")
print("[2] Atualizar notas")
print("[3] Média do aluno")
print("[4] Listar Todos")
print("[5] Maior Média")
print("[6] Menor Média")
print("[0] Sair")

op = int(input("\nOpção: "))

while op != 0:
    if op == 1:
        print("---------------------------")
        nome = input("Nome: ").title()  # Deixa a primeira letra de cada palavra em maiúscula e o resto minúscula
        while nome != '':
            achou = False
            for aluno in Lista_Alunos:  # Busca do Nome
                if aluno['Nome'] == nome:
                    achou = True
            if not achou:  # Se não achou
                notas = []  # lista de notas
                i = 0
                while i < 3:  # laço das 3 notas
                    valor = float(input("Nota {}: ".format(i + 1))
                                  )
                    if 0 <= valor <= 10:
                        notas.append(valor)
                        i += 1
                    else:
                        print("Nota Invalida !")
                alunos = {'Nome': nome, 'Notas': notas}  # Dicionario alunos recebe Nome e a lista notas
                Lista_Alunos.append(alunos)  # Lista de alunos recebe o Dicionario alunos
            else:
                print("Nome já existente !")
            print("---------------------------")
            nome = input("Nome: ").title()
    elif op == 2:
        print("---------------------------")
        if len(Lista_Alunos) > 0:
            nome = input("Nome: ").title()
            while nome != '':
                achou = False
                for aluno in Lista_Alunos:  # Laço para buscar o nome
                    if aluno['Nome'] == nome:  # se nome do aluno(cadastrado), for igual a nome(digitado), eh pq Achou
                        achou = True
                        i = 0
                        notas = []  # Cria lista de notas
                        while i < 3:  # Laço de alteração das 3 notas
                            valor = float(input(
                                "Nota {}: {} -> ".format(i + 1, aluno['Notas'][i])))

                            if 0 <= valor <= 10:
                                notas.append(valor)
                                i += 1
                            else:
                                print("Nota Invalida !")
                        aluno['Notas'] = notas  # Notas do aluno recebe as notas atualizadas
                if not achou:
                    print("Nome não encontrado !")
                print("---------------------------")
                nome = input("Nome: ").title()
        else:
            print("Não há alunos registrados.")
    elif op == 3:
        print("---------------------------")
        if len(Lista_Alunos) > 0:
            nome = input("Nome: ").title()
            while nome != '':
                achou = False
                for aluno in Lista_Alunos:
                    if aluno['Nome'] == nome:
                        achou = True
                        notas = aluno['Notas']  # notas recebe as Notas do aluno que encontrou
                        media = sum(notas) / len(notas)  # sum=soma e len=quantidade
                        print("Media do {}: {:.2f}".format(nome, media))
                if not achou:
                    print("Nome não encontrado !")
                print("---------------------------")
                nome = input("Nome: ").title()
        else:
            print("Não há alunos registrados.")
    elif op == 4:
        if len(Lista_Alunos) > 0:
            for aluno in Lista_Alunos:
                print("---------------------------")
                print("Nome:", aluno['Nome'])
                print("Notas:", aluno['Notas'])
        else:
            print("---------------------------")
            print("Não há alunos registrados.")
    elif op == 5:
        print("---------------------------")
        if len(Lista_Alunos) > 0:
            aluno_maior_media = max(Lista_Alunos, key=lambda x: sum(x['Notas']) / len(x['Notas']))#vi esse key=lambda em um site de python e curti e quis usar aqui, é uma funçao anonima,  pega um aluno representado por x e calcula a média das notas desse aluno com sum(x['Notas']) / len(x['Notas']).
            media = sum(aluno_maior_media['Notas']) / len(aluno_maior_media['Notas'])
            print(f"Aluno com a maior média: {aluno_maior_media['Nome']} (Média: {media})")
        else:
            print("Não há alunos registrados.")
    elif op == 6:
        print("---------------------------")
        if len(Lista_Alunos) > 0:
            aluno_menor_media = min(Lista_Alunos, key=lambda x: sum(x['Notas']) / len(x['Notas']))
            media = sum(aluno_menor_media['Notas']) / len(aluno_menor_media['Notas'])
            print(f"Aluno com a menor média: {aluno_menor_media['Nome']} (Média: {media})")
        else:
            print("Não há alunos registrados.")

    print("-----------MENU------------")
    print("[1] Adicionar Aluno/Notas")
    print("[2] Atualizar notas")
    print("[3] Média do aluno")
    print("[4] Listar Todos")
    print("[5] Maior Média")
    print("[6] Menor Média")
    print("[0] Sair")

    op = int(input("\nOpção: "))
