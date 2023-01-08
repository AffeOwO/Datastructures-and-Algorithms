songs_num, second_after_start = map(int, input().split())
songs = list(map(int, input().split()))

temp = second_after_start % sum(songs)

temp2 = 0
temp3 = 0
temp4 = temp
for index, i in enumerate(songs):
    temp3 += i
    if temp2 <= temp < temp3:
        print(index+1, temp4)
        exit()
    temp2 += i
    temp4 -= i