from PIL import Image
from sys import argv

img = Image.open(argv[1], "r")
w, h = img.size

mat = list(img.getdata())
mat = [mat[i:i+w] for i in range(0, len(mat), w)]

sol = chr(mat[0][0][0])
cur = [mat[0][0][2]%h, mat[0][0][1]%w]


while True:
    sol += chr(mat[cur[0]][cur[1]][0])
    if mat[cur[0]][cur[1]][1] == 0 and mat[cur[0]][cur[1]][2] == 0: break
    cur = [(cur[0] + mat[cur[0]][cur[1]][2])%h, (cur[1] + mat[cur[0]][cur[1]][1])%w]

print(sol)