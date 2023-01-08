unimportant, times = map(int, input().split())
my_list = input().split()

for i in range(times):
    my_list.pop(0)
    my_list.append("0")

print(" ".join(my_list))