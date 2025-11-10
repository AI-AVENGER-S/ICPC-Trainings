a = int(input())
res = 0
count = 0
for i in range(a):
    line = input()
    if line.startswith("Ask read_token and wait"):
        count += 1
    elif line.startswith("Set") and line.endswith("to answer"):
        if count > 0:
            parts = line.split()
            name = parts[1]
            res += len(name)
            count -= 1
print(res)
