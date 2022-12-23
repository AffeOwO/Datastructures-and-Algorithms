def to_base_10(num, base):
    sol = 0
    num = str(num)
    for index in range(len(num)):
        sol += int(num[(index+1)*-1]) *  base**index
    return sol