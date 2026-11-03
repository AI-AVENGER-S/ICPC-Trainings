lst = sorted(set(map(int, input().split(','))))

answer = []

first = lst[0]
last = lst[0]

for i in range(1, len(lst)):
    if last + 1 == lst[i]:
        last = lst[i]
    else:
        if first == last:
            answer.append(str(first))
        else:
            answer.append(f"{first}-{last}")
        
        first = lst[i]
        last = lst[i]

if first == last:
    answer.append(str(first))
else:
    answer.append(f"{first}-{last}")

print(','.join(answer))
