"""
ID: yamato berner (affeowo1)
TASK: friday
LANG: PYTHON3
"""

def is_leap(x):
    if x % 100 == 0 and x % 400 != 0:
        return False
    return x % 4 == 0

fin = open("friday.in", "r")
fout = open("friday.out", "w")

fin = fin.readlines()
year = 1900
years = int(fin[0])
sol = {"sat": 0, "sun": 0, "mon": 0, "tue": 0, "wed": 0, "thu": 0, "fri": 0}
cur_weekday = "sat"
cur_day = 13
week_days = ["mon", "tue", "wed", "thu", "fri", "sat", "sun"]
months = {"jan": 31, "feb": -1, "mar": 31, "apr": 30, "may": 31, "jun": 30, "jul": 31, "aug": 31, "sep": 30, "oct": 31, "nov": 30, "dec": 31}


for _ in range(years):
    if is_leap(year):
        months["feb"] = 29
    else:
        months["feb"] = 28
    for o in months:
        sol[cur_weekday] += 1
        cur_day += months[o]
        cur_weekday = week_days[cur_day % 7 - 1]


    year += 1

for i in sol:
    fout.write(f"{sol[i]}")
    if i != "fri":
        fout.write(" ")
    else:
        fout.write("\n")
fout.close()