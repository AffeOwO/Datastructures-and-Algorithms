fin = open("pails.in").read()
fout = open("pails.out", "w")

X, Y, M = map(int, fin.split())
temp = M//Y
sol = (Y * temp) + ((M - temp*Y) // X) * X
cnt = {"small": (M - temp*Y) // X, "medium": temp}

while cnt["medium"] > 0:
    cnt["medium"] -= 1
    temp = M - (Y * cnt["medium"]) - (X * cnt["small"])
    cnt["small"] += (temp // X)
    cur = (Y * cnt["medium"]) + (X * cnt["small"])
    if cur > sol: sol = cur

fout.write(f"{sol}\n")