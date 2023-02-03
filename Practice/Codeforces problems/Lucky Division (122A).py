n = int(input())

temp = str(n)
sety = set(temp)
if len(sety) == 1 and ("7" in sety or "4" in sety):
    print("YES")
elif len(sety) == 2 and sety == {"4", "7"}:
    print("YES")
elif n % 4 == 0 or n % 7 == 0 or n % 44 == 0 or n % 47 == 0 or n % 74 == 0 or n % 77 == 0 or n % 447 == 0 or n % 474 == 0 or n % 444 == 0 or n % 477 == 0:
    print("YES")
else:
    print("NO")