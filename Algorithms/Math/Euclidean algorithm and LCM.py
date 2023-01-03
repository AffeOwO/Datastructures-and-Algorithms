def euclidean(int1, int2):
    if int2 == 0:
        return int1
    return euclidean(int2, int1 % int2)


def LCM(int1, int2):
    return int1 / euclidean(int1,int2) * int2


if __name__ == "__main__":
    ...