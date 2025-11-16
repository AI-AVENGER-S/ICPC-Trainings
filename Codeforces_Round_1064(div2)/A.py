t = int(input())

for _ in range(t):
    n = int(input())
    q = input()
    counter = 0
    for i in range(len(q) - 1):
        if q[i] != q[-1]:
            counter += 1
    print(counter)

