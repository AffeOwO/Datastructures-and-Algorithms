for _ in range(int(input())):
    monsters, att_dmg = map(int, input().split())
    h = list(map(int, input().split()))
    p = list(map(int, input().split()))

    h_p = sorted([[h[i], p[i]] for i in range(monsters)], key=lambda x: x[1], reverse=True)

    cur_dealt = 0
    while True:
        if att_dmg <= 0:
            print("NO")
            break
        cur_dealt += att_dmg
        while h_p:
            if h_p[-1][0] - cur_dealt > 0:
                att_dmg -= h_p[-1][1]
                break
            h_p.pop()
        else:
            print("YES")
            break