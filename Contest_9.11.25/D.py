a = list(map(int, input().split()))

parents = [
    [2, 3, 4, 5],
    [2, 3, 4, 5],
    [0, 1, 4, 5],
    [0, 1, 4, 5],
    [0, 1, 2, 3],
    [0, 1, 2, 3],
]

max_num = 0

def find_max(current_index: int, path_indices: list):
    global max_num

    path = path_indices + [current_index]

    if len(path) == 6:
        num_str = "".join(str(a[i]) for i in path)
        current_num = int(num_str)

        if current_num > max_num:
            max_num = current_num
        return

    for ind_other_digit in parents[current_index]:
        if ind_other_digit not in path:
            find_max(ind_other_digit, path)


for start_index in range(6):
    find_max(start_index, [])

print(max_num)
