for _ in range(int(input())):
    N, K = map(int, input().split())
    cows = list(input())
    diff_cows = len(set(cows))

    patches_needed = 0
    cows_after = []


    if K == 0:
        patches_needed = N
        cows_after = cows
    elif diff_cows == 1:
        temp = K*2+1
        temp2 = N % temp

        patches_needed = N//temp
        for _ in range(patches_needed):
            for _ in range(K):
                cows_after.append(".")
            cows_after.append(cows[0])
            for _ in range(K):
                cows_after.append(".")
        if temp2 != 0:
            patches_needed += 1
            for _ in range(temp2//2):
                cows_after.append(".")
            cows_after.append(cows[0])
            for _ in range(temp2-temp2//2-1):
                cows_after.append(".")
    else:
        ...


    print(patches_needed)
    print("".join(cows_after))
