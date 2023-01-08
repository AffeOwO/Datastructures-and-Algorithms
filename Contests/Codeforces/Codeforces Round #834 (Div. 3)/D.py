# fail
test_cases = int(input())

for _ in range(test_cases):
    old_price, max_increase = map(int, input().split())
    trailing_zeros = 0
    yass = 0
    for i in range(1, max_increase+1):
        if str(yass)[-1] != "0" and i == max_increase:
            yass = old_price * max_increase
        if old_price % 5 != 0:
            if i % 5 == 0:
                temp = old_price * i
                if len(str(temp)) - len(str(temp).rstrip('0')) >= trailing_zeros:
                    trailing_zeros = len(str(temp)) - len(str(temp).rstrip('0'))
                    yass = temp
        elif old_price % 10 == 5:
            if i % 2 == 0:
                temp = old_price * i
                if len(str(temp)) - len(str(temp).rstrip('0')) >= trailing_zeros:
                    trailing_zeros = len(str(temp)) - len(str(temp).rstrip('0'))
                    yass = temp
        else:
            temp = old_price * i
            if len(str(temp)) - len(str(temp).rstrip('0')) >= trailing_zeros:
                trailing_zeros = len(str(temp)) - len(str(temp).rstrip('0'))
                yass = temp
    print(yass)