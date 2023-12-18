num = int(input())
cows = sorted(map(int, input().split()), reverse=True)

max_pay = [[0,0]]

for index, i in enumerate(cows):
    temp = (index+1) * i
    if temp >= max_pay[-1][0]:
        max_pay.append([temp, i])

print(*max_pay[-1])