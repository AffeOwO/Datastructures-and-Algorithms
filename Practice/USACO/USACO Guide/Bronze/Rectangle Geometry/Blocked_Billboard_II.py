fin = open("billboard.in").read().splitlines()  # bad board, good board(overlay on bad)
fout = open("billboard.out", "w")

boxes = [list(map(int, i.split())) for i in fin]
sol = (boxes[0][2] - boxes[0][0]) * (boxes[0][3] - boxes[0][1])
if boxes[1][0] <= boxes[0][0] and boxes[1][2] >= boxes[0][2]:
    ...
elif boxes[1][1] <= boxes[0][1] and boxes[1][3] >= boxes[0][3]:
    ...

fout.write(f"{sol}\n")