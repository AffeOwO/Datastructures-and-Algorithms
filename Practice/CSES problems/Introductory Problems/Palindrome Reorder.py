string = input()
n = len(string)
hashy = {}
for i in string:
    if i not in hashy: hashy[i] = 0
    hashy[i] += 1


sol = [[], []]
idk = "12321"
if n % 2 == 0:
    for i in hashy:
        if hashy[i] % 2 == 1:
            print("NO SOLUTION")
            exit()
        temp = hashy[i] // 2
        for _ in range(temp):
            sol[0].append(i)
            sol[1].append(i)
    sol = sol[0] + sol[1][::-1]
else:
    cnt = 0
    for i in hashy:
        if hashy[i] % 2 == 1:
            cnt += 1
            if cnt > 1:
                print("NO SOLUTION")
                exit()
        temp = hashy[i] // 2
        for _ in range(temp):
            sol[0].append(i)
            sol[1].append(i)
        if hashy[i] % 2 == 1:
            idk = i
    sol = sol[0] + [idk] + sol[1][::-1]
print("".join(sol))