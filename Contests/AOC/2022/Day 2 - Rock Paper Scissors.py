# first column = enemy play
# A = Rock, B = Paper, C = Scissor
# second column = what you should play
# x = Rock, Y = Paper, Z = Scissor

# Score: Rock = 1, Paper = 2, Scissor = 3
# Score : Loose = 0, Draw = 3, Win = 6

# part 1
score = 0

while True:
    try:
        opponent, your = input().split()
    except ValueError:
        break

    translation = {"A": "Rock", "B": "Paper", "C": "Scissor", "X": "Rock", "Y": "Paper", "Z": "Scissor"}
    opponent, your = translation[opponent], translation[your]
    if opponent == your:
        score += 3
    elif (opponent == "Rock" and your == "Paper") or (opponent == "Paper" and your == "Scissor") or (opponent == "Scissor" and your == "Rock"):
        score += 6
    score += ["Rock", "Paper", "Scissor"].index(your) + 1
print(score)


# score is still the same
# outcome: X = Loose, Y = Draw, Z = Win

# part 2
score = 0

while True:
    try:
        opponent, outcome = input().split()
    except ValueError:
        break

    translation = {"A": "Rock", "B": "Paper", "C": "Scissor"}
    opponent = translation[opponent]
    if outcome == "X":
        if opponent == "Rock":
            score += 3
        else:
            score += ["Rock", "Paper", "Scissor"].index(opponent)
    elif outcome == "Y":
        score += ["Rock", "Paper", "Scissor"].index(opponent) + 1
        score += 3
    else:
        if opponent == "Scissor":
            score += 1
        else:
            score += ["Rock", "Paper", "Scissor"].index(opponent) + 2
        score += 6
print(score)