def validate(x, y, puzzle):
    dx = x - x % 3
    dy = y - y % 3

    for i in range(9):
        b, a = divmod(i, 3)
        a += dx
        b += dy

        if i != x and puzzle[y][i] == puzzle[y][x]:
            return False
        if i != y and puzzle[i][x] == puzzle[y][x]:
            return False
        if a != x and b != y and puzzle[b][a] == puzzle[y][x]:
            return False

    return True


def solve(puzzle):
    for y in range(9):
        for x in range(9):
            if puzzle[y][x]:
                continue

            for i in range(1, 10):
                puzzle[y][x] = i
                if validate(x, y, puzzle) and solve(puzzle):
                    return True

            puzzle[y][x] = 0
            return False

    return True


def sudoku(puzzle):
    solve(puzzle)
    return puzzle
