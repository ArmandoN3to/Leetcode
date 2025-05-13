palavra=str(input())

if palavra[::-1] == palavra:
    print(f"{palavra} -> sim")

else:
    print(f"{palavra} -> nao")
