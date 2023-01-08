with open("input.in", "r", encoding="utf-8") as file:
    file = file.readlines()

    signal_sum = 0  # Find the signal strength during the 20th, 60th, 100th, 140th, 180th, and 220th cycles. What is the sum of these six signal strengths?
    cur_cycle = 0
    imp_cycles = (20, 60, 100, 140, 180, 220)
    x = 1
    rows = [""]

    for i in file:
        i = i.strip()
        if i == "noop":
            cur_cycle += 1
            if cur_cycle in imp_cycles:
                signal_sum += (cur_cycle * x)
            if len(rows[-1]) >= 40:
                rows.append("")
            if cur_cycle % 40 in (x, x + 1, x + 2):
                rows[-1] += "#"
            else:
                rows[-1] += "."
        else:
            _, i = i.split()
            i = int(i)
            for o in range(2):
                cur_cycle += 1
                if cur_cycle in imp_cycles:
                    signal_sum += (cur_cycle * x)
                if len(rows[-1]) >= 40:
                    rows.append("")
                if cur_cycle % 40 in (x, x + 1, x + 2):
                    rows[-1] += "#"
                else:
                    rows[-1] += "."
            x += i
    print(signal_sum, "\n")
    for row in rows:
        print(row)