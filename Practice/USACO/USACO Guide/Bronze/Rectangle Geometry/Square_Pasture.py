fin = open("square.in").read().splitlines()
fout = open("square.out", "w")
fin = [list(map(int, i.split())) for i in fin]
sol = max((max((fin[0][2], fin[1][2])) - min((fin[0][0], fin[1][0])),
           max((fin[0][3], fin[1][3])) - min((fin[0][1], fin[1][1]))))

fout.write(f"{sol**2}\n")