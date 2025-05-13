n = int(input())
ovelhas = list(map(int, input().split()))

visitados = [False] * n
i = 0

while 0 <= i < n:
    if not visitados[i]:
        visitados[i] = True  
        
    if ovelhas[i] > 0:
        ovelhas[i] -= 1

        ovelhas_antes = ovelhas[i] + 1

        if ovelhas_antes % 2 != 0:
            i += 1
        else:
            i -= 1

    else:
        break
    

print(sum(visitados), sum(ovelhas))
