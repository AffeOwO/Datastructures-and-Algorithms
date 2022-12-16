k, n, w = map(int, input().split())
needed = k*(w*(w+1)//2)
temp = needed-n
print(temp if temp >= 0 else 0)
