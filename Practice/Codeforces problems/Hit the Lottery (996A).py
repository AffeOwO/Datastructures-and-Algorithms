num = int(input())

sol = 0
sol += (num // 100)
num = num % 100
sol += (num // 20)
num = num % 20
sol += (num // 10)
num = num % 10
sol += (num // 5)
num = num % 5
sol += num

print(sol)