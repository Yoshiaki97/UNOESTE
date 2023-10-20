from Biblioteca.Funcoes import *
try:
    arquivo = open("notas_estudantes.dat","r")
except:
    arquivo = open("notas_estudantes.dat","w")
    arquivo.write('jose 10 5 2 3 4\n')
    arquivo.write('pedro 3 6 9 2\n')
    arquivo.write('suzana 8 2 7 4 3 7 4 1 2 9 1 7\n')
    arquivo.write('gisela 2 8 2 5 6 7\n')
    arquivo.write('joao 4 3 5 7 6')
    arquivo.close()
    arquivo = open("notas_estudantes.dat","r")

lista_alunos=[]
for linha in arquivo:
    dado=linha.split()
    nome=dado[0]
    notas=[]
    for nota in dado[1:]:
        notas.append(float(nota))
    lista_alunos.append({'Nome':nome,'Notas':notas})
arquivo.close()
#print(lista_alunos)

Mais5(lista_alunos)#Questao a

Media(lista_alunos)#Questao b

MaiorNota(lista_alunos)#Questao c