def get_candidates(x, y, puzzle):
    used = set()
    dx = x - x % 3
    dy = y - y % 3

    for i in range(9):
        b, a = divmod(i, 3)
        used.add(puzzle[y][i])
        used.add(puzzle[i][x])
        used.add(puzzle[dy + b][dx + a])

    used.discard(0)
    return set(range(1, 10)) - used


def solve(puzzle):
    minx = -1
    miny = -1
    minc = set(range(1, 10))

    for y in range(9):
        for x in range(9):
            if puzzle[y][x]:
                continue

            candidates = get_candidates(x, y, puzzle)
            if len(candidates) < len(minc):
                miny = y
                minx = x
                minc = candidates

    if minx >= 0:
        for i in minc:
            puzzle[miny][minx] = i
            if solve(puzzle):
                return puzzle

        puzzle[miny][minx] = 0
        return False

    return puzzle
