numero_casos=int(input())
for x in range(numero_casos):
    numero_de_alunos=int(input())
    notas=input().split()

    original=[int(x) for x in input().split(' ')]
    ordenado=sorted(original,reverse=True)

    resposta=0

    for i in range(numero_de_alunos):
        if(original[i]==ordenado[i]):
            resposta+=1

print(resposta)