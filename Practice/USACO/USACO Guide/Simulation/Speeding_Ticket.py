class Road:
    def __init__(self, roadsegments):
        self.road_segments = roadsegments

    def get_speed_limit(self, position):
        counter = 0
        for segment_length, speed_limit in [map(int, i.split(' ')) for i in self.road_segments]:
            if counter <= position < counter + segment_length:
                return speed_limit
            counter += segment_length


fin = open('speeding.in', 'r')
fout = open('speeding.out', 'w')

data = fin.read().splitlines()
n, m = map(int, data[0].split(' '))
road_segments = data[1:n + 1]
bessie_travel = data[n + 1:n + 1 + m]

road = Road(road_segments)

cur_counter = 0
max_speeding = 0
for length, speed in [map(int, i.split(' ')) for i in bessie_travel]:
    for i in range(length):
        max_speeding, cur_counter = max(max_speeding, max(speed - road.get_speed_limit(cur_counter), 0)), cur_counter + 1

fout.write(str(max_speeding) + '\n')
