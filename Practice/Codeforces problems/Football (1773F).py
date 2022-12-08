matches = int(input())
int1 = int(input())
int2 = int(input())

draws = 0
match_list = []

if matches == 1:
    if int1 == int2:
        draws += 1
        match_list.append(f"{int1}:{int2}")

elif int1 + int2 < matches:
    draws += (matches - int1 - int2)
    # todo

else:
    # todo
    pass


print(draws)
for result in match_list:
    print(result)