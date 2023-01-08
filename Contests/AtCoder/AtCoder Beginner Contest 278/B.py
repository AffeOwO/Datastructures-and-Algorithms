def valid_time(hour, minute):
    if 0 <= hour <= 23 and 0 <= minute <= 59:
        return True
    return False


def confusing():
    hour, minute = input().split()
    temp_h, temp_m = hour[:-1] + minute[0], hour[-1] + minute[1:]
    # special cases
    if 23 > int(hour) >= 20 and int(minute) == 40:
        print(int(hour)+1, 0)
        return 0
    if valid_time(int(temp_h), int(temp_m)):
        print(int(hour), int(minute))
        return 0
    while int(hour[-1]) > 5 and int(hour) < 21:
        hour = int(hour) + 1
    if valid_time(int(hour), int(temp_m)):
        print(int(hour), int(minute))
        return 0
    print(temp_h, temp_m)


confusing()


# map(int, input().split())
# Let A be the tens digit of h, B be the ones digit of h, C be the tens digit of m, and D be the ones digit of m
# hour[-1] && minute[0]
# AB:CD