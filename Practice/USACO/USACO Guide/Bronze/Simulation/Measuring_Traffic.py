fin = open('traffic.in', 'r')
fout = open('traffic.out', 'w')
data = fin.read().splitlines()
n = int(data[0])
sensors = [i.split() for i in data[1:]]

upper, lower = float("inf"), float("-inf")
for status, lower_i, upper_i in sensors:
    upper_i = int(upper_i);
    lower_i = int(lower_i)
    if status == "none":
        upper = min(upper, upper_i)
        lower = max(lower, lower_i)
    if status == "on":
        upper += upper_i
        lower += lower_i
    if status == "off":
        upper -= lower_i
        lower -= upper_i

exit_data = str(max(0, lower)) + ' ' + str(max(0, lower, upper))

for status, lower_i, upper_i in reversed(sensors):
    upper_i = int(upper_i);
    lower_i = int(lower_i)
    if status == "none":
        upper = min(upper, upper_i)
        lower = max(lower, lower_i)
    if status == "off":
        upper += upper_i
        lower += lower_i
    if status == "on":
        upper -= lower_i
        lower -= upper_i

entrance_data = str(max(0, lower)) + ' ' + str(max(0, lower, upper))
fout.write(entrance_data + '\n' + exit_data + '\n')