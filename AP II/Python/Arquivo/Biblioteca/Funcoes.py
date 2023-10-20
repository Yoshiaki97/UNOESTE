def Mais5 (lista):
    print('---------------------------')
    print('Questao a: ')
    for aluno in lista:
        if len(aluno['Notas'])>5:
            print(aluno['Nome'])
def Media (lista):
    print('---------------------------')
    print('Questao b: ')
    for aluno in lista:
        media=sum(aluno['Notas'])/len(aluno['Notas'])
        print('{:8} média: {:.2f}'.format(aluno['Nome'],media))
def MaiorNota (lista):
    print('---------------------------')
    print('Questao c: ')
    for aluno in lista:
        maior=max(aluno['Notas'])
        print('{:8} Maior nota: {:.2f}'.format(aluno['Nome'],maior))