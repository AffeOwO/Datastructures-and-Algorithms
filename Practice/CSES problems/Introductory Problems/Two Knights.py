n = int(input())

for k in range(1, n+1):
    side = k  # length of board
    k *= k  # number of squares
    default = (k*(k-1))//2  # if knights were allowed to attack each other
    # corner, next-to-corner, outer-edge, inner-edge, rest
    types = (4, 8, (side - 4) * 4 + 4, (side-2) * 4 - 8, (side - 2)**2 - 4 - ((side-2) * 4 - 8))
    # squares blocked by above type
    blocked_num = 2, 3, 4, 6, 8

    if k in (1, 4):
        print(default)  # no squares are blocking other squares on n<=2
    elif k == 9:
        print(default - 2 * types[0])  # only type of square which is blocking other squares are corners
    else:
        blocked = 0
        for i in range(len(types)):
            blocked += (types[i] * blocked_num[i])
        print(default - blocked//2)  # //2 because above loop is adding some positions which are already added

