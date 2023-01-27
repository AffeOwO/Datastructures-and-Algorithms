for _ in range(int(input())):
    temp = list(input())

    N, M = map(int, input().split())
    is_true = True
    if N > 1:
        for _ in range(M):
            num, output = input().split()
            if num[1] == "1" and output == "1":
                pass
            elif num[0] == "0" and output == "0":
                pass
            elif num[0] == "0" and output == "1":
                is_true = False
            elif output == "1" and num[0] != "0" and num[1] != "1":
                pass
            else:
                is_true = False
    else:
        for _ in range(M):
            num, output = input().split()
            if num[0] == "0" and output == "0":
                pass
            elif num[0] == "0" and output == "1":
                is_true = False
            elif output == "1":
                pass
            else:
                is_true = False

    if is_true:
        print("OK")
    else:
        print("LIE")


