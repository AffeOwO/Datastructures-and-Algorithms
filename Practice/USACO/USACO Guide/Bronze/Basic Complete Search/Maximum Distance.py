n = int(input())
xs = list(map(int, input().split()))
ys = list(map(int, input().split()))
maxi = -1

# pythagorean theorem sqrt which isn't needed since we have to square it again -> sqrt(n)**2 = n
# we are looking for the squared euclidean distance which is the manhatten distance

for index in range(n):
    for index2 in range(index+1, n):
        temp = (xs[index] - xs[index2])**2 + (ys[index] - ys[index2])**2
        if temp > maxi: maxi = temp

print(maxi)