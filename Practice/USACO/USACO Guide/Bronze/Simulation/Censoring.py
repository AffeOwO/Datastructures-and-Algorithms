fin = open("censor.in").read().splitlines()
fout = open("censor.out", "w")

string, snippet = fin
n = len(snippet)
sol = ""
for i in string:
    sol += i
    if len(sol) < n: continue
    if sol[-n:] == snippet: sol = sol[:-n]

fout.write(f"{sol}\n")