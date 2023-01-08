# fail
class Solution:
    def splitMessage(self, message: str, limit: int) -> List[str]:
        cur_page = 1

        def all_pages():
            test = len(message) / (limit - 3 - 2)

            if test <= 9:
                return test if test % 1 == 0 else round(test + 0.5)
            else:
                return len(message) / (limit - 3)

        all_pages = all_pages()
        sol = []
        while message:
            temp = ""
            while len(temp) + 3 + len(str(cur_page)) + len(str(all_pages)) != limit:
                try:
                    temp += message[0]
                except IndexError:
                    break
                message = message[1:]
            cur_part = f"{temp}<{cur_page}/{all_pages}>"
            sol.append(cur_part)
            cur_page += 1

        return sol
