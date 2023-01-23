fin, fout = open("billboard.in"), open("billboard.out", "w")

x1, y1, x2, y2 = map(int, fin.readline().split())
x3, y3, x4, y4 = map(int, fin.readline().split())

tl_corner = x3 <= x1 and y4 >= y2
tr_corner = y4 >= y2 and x4 >= x2
br_corner = x4 >= x2 and y3 <= y1
bl_corner = y3 <= y1 and x3 <= x1

corner_num = sum([tl_corner, tr_corner, br_corner, bl_corner])
if bl_corner and tr_corner:
	fout.write(str(0))

elif corner_num in [0, 1]:
	fout.write(str(abs(x2 - x1) * abs(y2 - y1)))

elif br_corner and tr_corner:
	fout.write(str(abs(y2 - y1) * abs(x2 - x4)))

elif bl_corner and tl_corner:
	fout.write(str(abs(y2 - y1) * abs(x2 - x4)))

elif tr_corner and tl_corner:
	fout.write(str(abs(x2 - x1) * abs(y3 - y1)))

elif br_corner and bl_corner:
	fout.write(str(abs(x2 - x1) * abs(y3 - y1)))