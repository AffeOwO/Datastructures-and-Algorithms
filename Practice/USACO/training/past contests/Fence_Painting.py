fin = list(map(int, open("paint.in").read().split()))
fout = open("paint.out")
total = 0
vals = fin

if vals[1]<vals[2] or vals[3]<vals[0]:
    total = vals[1]-vals[0]+vals[3]-vals[2]
else:
    total = max(vals) - min(vals)

fout.write(f"{total}\n")