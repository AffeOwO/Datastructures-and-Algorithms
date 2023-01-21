n, p, q, r, s = map(int, input().split())
arr = list(map(int, input().split()))

sol = arr[:p-1] + arr[r-1:s] + arr[q:r-1] + arr[p-1:q] + arr[s:]

print(*sol)