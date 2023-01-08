# passed

anzahl = int(input())
chr1 = list("HDCS")
chr2 = list("A23456789TJQK")

paare = []
for i in range(anzahl):
    pair = input()
    if len(pair) != 2:
        print("No")
        exit()
    if pair[0] not in chr1 or pair[1] not in chr2:
        print("No")
        exit()
    if pair in paare:
        print("No")
        exit()
    paare.append(pair)


print("Yes")