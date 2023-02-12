sumsq = 5050**2
sqsum = 0
for i in range(101):
    sqsum += i**2
print(abs(sumsq-sqsum))