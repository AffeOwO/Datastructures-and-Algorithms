matches = int(input())
int1 = int(input())
int2 = int(input())

match_list = []

if matches == 1:
    if int1 == int2:
        draws = 1
    else:
        draws = 0
    match_list.append(f"{int1}:{int2}")

elif int1 + int2 < matches:
    draws = (matches - int1 - int2)
    for _ in range(int1):
        match_list.append("1:0")
    for _ in range(int2):
        match_list.append("0:1")
    for _ in range(draws):
        match_list.append("0:0")

else:
    draws = 0
    if int1 >= matches:
        if int2 > 0:
            match_list.append(f"0:{int2}")
        else:
            match_list.append("1:0")
            int1 -= 1
        if matches == 2:
            match_list.append(f"{int1}:0")
        else:
            for i in range(matches - 2):
                match_list.append("1:0")
                int1 -= 1
            if int1 > 0:
                match_list.append(f"{int1}:0")

    elif int2 >= matches:
        if int1 > 0:
            match_list.append(f"{int1}:0")
        else:
            match_list.append("0:1")
            int2 -= 1
        if matches == 2:
            match_list.append(f"0:{int2}")
        else:
            for i in range(matches - 2):
                match_list.append("0:1")
                int2 -= 1
            if int2 > 0:
                match_list.append(f"0:{int2}")
    else:
        for _ in range(int1):
            match_list.append("1:0")
        for _ in range(matches-int1-1):
            match_list.append("0:1")
            int2 -= 1
        match_list.append(f"0:{int2}")

print(draws)
for result in match_list:
    print(result)