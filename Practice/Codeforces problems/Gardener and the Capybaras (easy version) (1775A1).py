for _ in range(int(input())):
    s = input()  # 3 weird animals
    n = len(s)
    two = s[:2]
    if two in ("aa", "bb", "ba"):
        print(s[0],s[1],s[2:])
    else:  # "ab"
        if "a" not in s[1:]:
            print(s[:n-3+1], s[n-2], s[n-1])
        else:
            strings = [s[0], ""]
            for i in s[1:]:
                if i == "a" and len(strings) == 2:
                    strings.append("")
                strings[-1] += i
            print(" ".join(strings))