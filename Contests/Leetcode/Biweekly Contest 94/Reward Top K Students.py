class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str],
                    student_id: List[int], k: int) -> List[int]:
        # pos 3+ neg 1-
        temp = [[student_id[i], report[i], 0] for i in range(len(report))]

        for index, i in enumerate(temp):
            for o in i[1].split():
                if o in positive_feedback:
                    temp[index][-1] += 3
                elif o in negative_feedback:
                    temp[index][-1] -= 1
        sol = [[0, float(-inf)] for _ in range(k)]
        for i in temp:
            if i[-1] > sol[-1][-1]:
                for index, o in enumerate(sol):
                    if i[-1] > o[-1]:
                        sol.insert(index, [i[0], i[-1]])
                        sol.pop()
                        break

        for _ in range(k):
            for index, i in enumerate(sol[:-1]):
                if sol[index][-1] == sol[index + 1][-1] and sol[index][0] > sol[index + 1][0]:
                    sol[index], sol[index + 1] = sol[index + 1], sol[index]

        sol = [i[0] for i in sol]
        return sol