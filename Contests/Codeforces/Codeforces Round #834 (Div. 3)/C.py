# correact
test_cases = int(input())

for i in range(test_cases):
    min_temp, max_temp, min_change = map(int, input().split())
    initial_temp, final_temp = map(int, input().split())

    if initial_temp == final_temp:
        print(0)
        continue
    if initial_temp + min_change == final_temp:
        print(1)
        continue
    if initial_temp - min_change == final_temp:
        print(1)
        continue
    if initial_temp + min_change > max_temp and initial_temp - min_change < min_temp:
        print(-1)
        continue
    if final_temp - min_change < min_temp and final_temp + min_change > max_temp:
        print(-1)
        continue
    if initial_temp > final_temp:
        if initial_temp - final_temp >= min_change:
            print(1)
            continue
        elif initial_temp + min_change <= max_temp:
            print(2)
            continue
        elif initial_temp - min_change - (initial_temp - final_temp) >= min_temp:
            print(2)
            continue
        print(3)
    if final_temp > initial_temp:
        if final_temp - initial_temp >= min_change:
            print(1)
            continue
        elif initial_temp + min_change + (final_temp - initial_temp) <= max_temp:
            print(2)
            continue
        elif initial_temp - min_change >= min_temp:
            print(2)
            continue
        print(3)
