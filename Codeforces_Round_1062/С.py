t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    evens = []
    odds = []
    for num in a:
        if num % 2 == 0:
            evens.append(num)
        else:
            odds.append(num)

    if not evens:
        print(" ".join(map(str, odds)))
    elif not odds:
        print(" ".join(map(str, evens)))
    else:
        evens.sort()
        odds.sort()

        result = []
        i, j = 0, 0
        while i < len(evens) and j < len(odds):
            if evens[i] < odds[j]:
                result.append(evens[i])
                i += 1
            else:
                result.append(odds[j])
                j += 1

        result.extend(evens[i:])
        result.extend(odds[j:])

        print(" ".join(map(str, result)))
