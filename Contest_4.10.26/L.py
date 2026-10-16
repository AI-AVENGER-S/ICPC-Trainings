from bisect import (bisect_left, 
                    bisect_right)

n, q = map(int, input().split())
s = input()

positions = [[] for _ in range(26)]

for i, letter in enumerate(s):
    positions[ord(letter) - ord('a')].append(i)

INVALID = n
bad = [INVALID] * n

next_pos = [[INVALID] * 26 for _ in range(26)]

for i in range(n - 2, -1, -1):
    letter = ord(s[i]) - ord('a')
    next_letter = ord(s[i + 1]) - ord('a')  

    bad[i] = min(
        next_pos[letter][other]
        for other in range(26)
        if other != next_letter
    )

    next_pos[letter][next_letter] = i


for _ in range(q):
    l, r = map(int, input().split())
    l -= 1
    r -= 1

    max_letter_counter = [bisect_right(positions[letter], r) - bisect_left(positions[letter], l) for letter in range(26)]

    k = max(max_letter_counter)

    answer = 1

    for letter in range(26):
        if max_letter_counter[letter] != k:
            continue

        current = letter
        length = 1

        while True:
            letter_positions = positions[current]

            left_index = bisect_left(letter_positions, l)
            right_index = bisect_right(letter_positions, r) - 1

            first = letter_positions[left_index]
            last = letter_positions[right_index]

            if last == r or bad[first] <= r:
                break

            next_letter = ord(s[first + 1]) - ord('a')

            if max_letter_counter[next_letter] != k:
                break

            current = next_letter
            length += 1

        answer = max(answer, length)

    print(answer)