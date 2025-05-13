a,b,c=map(int,input().split())

maior=int((a+b+abs(a-b))/2)
if maior > c:
    print(f'{maior} eh o maior')
else:
    print(f'{c} eh o maior')
