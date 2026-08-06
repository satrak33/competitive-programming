# Only python is acceptable(((((
# The worst input imaginable

from collections import defaultdict


def dfs(a, b, grid, t) -> int:
    stack = [(a, b, t)]
    res = 0
    while stack:
        work = stack.pop()

        a = work[0]
        b = work[1]
        t = work[2]

        if a < 0 or a >= len(grid):
            continue
        if b < 0 or b >= len(grid[a]):
            continue

        if grid[a][b] == " ":
            grid[a][b] = "*"
            res += t

            stack.append((a - 1, b, not t))
            stack.append((a, b - 1, not t))
            stack.append((a + 1, b, not t))
            stack.append((a, b + 1, not t))
    return res


def components(grid: str) -> list[tuple[int, int]]:
    new_grid = ""
    i = 1
    for c in grid:
        if c == "\n":
            new_grid += c
            i = 1
        elif i % 3 != 0:
            new_grid += c
            i += 1
        else:
            i = 1

    arr_grid = [[i for i in x] for x in new_grid.split("\n")]

    result = defaultdict(int)
    for i in range(len(arr_grid)):
        for j in range(len(arr_grid[i])):
            if arr_grid[i][j] == " ":
                size = dfs(i, j, arr_grid, 1)
                result[size] += 1

    r = []
    for i in sorted(result.keys(), reverse=True):
        r.append((i, result[i]))

    return r


if __name__ == "__main__":
    print(components("+--+--+--+\n|        |\n+  +  +  +\n|        |\n+--+--+--+"))
